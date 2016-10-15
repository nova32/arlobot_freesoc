#include "pidatune.h"

static uint8 isMax, isMin;
static float *input, *output;
static float setpoint;
static float noiseBand;
static int controlType;
static uint8 running;
static unsigned long peak1, peak2, lastTime;
static int sampleTime;
static int nLookBack;
static int peakType;
static float lastInputs[101];
static float peaks[10];
static int peakCount;
static uint8 justchanged;
static uint8 justevaled;
static float absMax, absMin;
static float oStep;
static float outputStart;
static float Ku, Pu;

static void FinishUp()
{
    *output = outputStart;
    //we can generate tuning parameters!
    Ku = 4*(2*oStep)/((absMax-absMin)*3.14159);
    Pu = (float)(peak1-peak2) / 1000;

}

PID_ATune_Init(float* Input, float* Output)
{
	input = Input;
	output = Output;
	controlType =0 ; //default to PI
	noiseBand = 0.5;
	running = false;
	oStep = 30;
	SetLookbackSec(10);
	lastTime = millis();
	
}

void PID_ATune_Cancel()
{
	running = false;
} 
 
int PID_ATune_Runtime()
{
    justevaled=false;
    if(peakCount>9 && running)
    {
        running = false;
        FinishUp();
        return 1;
    }
    
    unsigned long now = millis();

    if((now-lastTime)<sampleTime) 
    {
        return false;
    }
    
    lastTime = now;
    float refVal = *input;
    justevaled=TRUE;
    
    if(!running)
    { //initialize working variables the first time around
        peakType = 0;
        peakCount=0;
        justchanged=false;
        absMax=refVal;
        absMin=refVal;
        setpoint = refVal;
        running = true;
        outputStart = *output;
        *output = outputStart+oStep;
    }
    else
    {
        if(refVal>absMax)absMax=refVal;
        if(refVal<absMin)absMin=refVal;
    }

    //oscillate the output base on the input's relation to the setpoint

    if (refVal>setpoint+noiseBand)
    {
        *output = outputStart-oStep;
    }
    else if (refVal<setpoint-noiseBand) 
    {
        *output = outputStart+oStep;
    }

    //bool isMax=true, isMin=true;
    isMax=true;isMin=true;
    //id peaks
    for(int i=nLookBack-1;i>=0;i--)
    {
        float val = lastInputs[i];
        if(isMax) 
        {
            isMax = refVal>val;
        }
        
        if(isMin) 
        {
            isMin = refVal<val;
        }
        lastInputs[i+1] = lastInputs[i];
    }
    
    lastInputs[0] = refVal;  
    if(nLookBack<9)
    {  //we don't want to trust the maxes or mins until the inputs array has been filled
        return 0;
    }

    if(isMax)
    {
        if(peakType==0)
        {
            peakType=1;
        }
        
        if(peakType==-1)
        {
          peakType = 1;
          justchanged=true;
          peak2 = peak1;
        }
        
        peak1 = now;
        peaks[peakCount] = refVal;

    }
    else if(isMin)
    {
        if(peakType==0)
        {
            peakType=-1;
        }
        
        if(peakType==1)
        {
          peakType=-1;
          peakCount++;
          justchanged=true;
        }

        if(peakCount<10)
        {
            peaks[peakCount] = refVal;
        }
    }

    if(justchanged && peakCount>2)
    { 
        //we've transitioned.  check if we can autotune based on the last peaks
        float avgSeparation = (abs(peaks[peakCount-1]-peaks[peakCount-2])+abs(peaks[peakCount-2]-peaks[peakCount-3]))/2;
        if( avgSeparation < 0.05*(absMax-absMin))
        {
            FinishUp();
            running = false;
            return 1;
        }
    }
    
    justchanged=false;
    return 0;
}

float PID_ATune_GetKp()
{
	return controlType==1 ? 0.6 * Ku : 0.4 * Ku;
}

float PID_ATune_GetKi()
{
	return controlType==1? 1.2*Ku / Pu : 0.48 * Ku / Pu;  // Ki = Kc/Ti
}

float PID_ATune_GetKd()
{
	return controlType==1? 0.075 * Ku * Pu : 0;  //Kd = Kc * Td
}

void PID_ATune_SetOutputStep(float Step)
{
	oStep = Step;
}

float PID_ATune_GetOutputStep()
{
	return oStep;
}

void PID_ATune_SetControlType(int Type) //0=PI, 1=PID
{
	controlType = Type;
}
int PID_ATune_GetControlType()
{
	return controlType;
}
	
void PID_ATune_SetNoiseBand(float Band)
{
	noiseBand = Band;
}

float PID_ATune_GetNoiseBand()
{
	return noiseBand;
}

void PID_ATune_SetLookbackSec(int value)
{
    if (value<1) value = 1;
	
	if(value<25)
	{
		nLookBack = value * 4;
		sampleTime = 250;
	}
	else
	{
		nLookBack = 100;
		sampleTime = value*10;
	}
}

int PID_ATune_GetLookbackSec()
{
    return nLookBack * sampleTime / 1000;
}
