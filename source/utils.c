/* 
MIT License

Copyright (c) 2017 Tim Slator

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*---------------------------------------------------------------------------------------------------
   Description: This module provides utility macros and functions used by one more modules.
 *-------------------------------------------------------------------------------------------------*/    

/*---------------------------------------------------------------------------------------------------
 * Includes
 *-------------------------------------------------------------------------------------------------*/    
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
#include "config.h"
#include "pwm.h"

/*---------------------------------------------------------------------------------------------------
 * Macros
 *-------------------------------------------------------------------------------------------------*/    

/*---------------------------------------------------------------------------------------------------
 * Functions
 *-------------------------------------------------------------------------------------------------*/    


/*---------------------------------------------------------------------------------------------------
 * Name: MovingAverage
 * Description: Calculates an integer moving average.
 *  
 * Parameters: ma    - the integer moving average structure
 *             value - the new value to be averaged
 * Return: average
 * 
 *-------------------------------------------------------------------------------------------------*/
int32 MovingAverage(MOVING_AVERAGE_TYPE* ma, int32 value)
/*
MA*[i]= MA*[i-1] +X[i] - MA*[i-1]/N

where MA* is the moving average*N. 

MA[i]= MA*[i]/N
*/
{
    int32 ma_curr;
    
    ma_curr = ma->last + value - ma->last/ma->n;
    ma->last = ma_curr;
    
    return ma_curr/ma->n;
}

/*---------------------------------------------------------------------------------------------------
 * Name: MovingAverageFloat
 * Description: Calculates a floating point moving average.
 *  
 * Parameters: ma    - the floating point moving average structure
 *             value - the new value to be averaged
 * Return: average
 * 
 *-------------------------------------------------------------------------------------------------*/
float MovingAverageFloat(MOVING_AVERAGE_FLOAT_TYPE* ma, float value)
/*
MA*[i]= MA*[i-1] +X[i] - MA*[i-1]/N

where MA* is the moving average*N. 

MA[i]= MA*[i]/N
*/
{
    float ma_curr;
    
    ma_curr = ma->last + value - ma->last/ma->n;
    ma->last = ma_curr;
    
    return ma_curr/ma->n;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Uint16ToTwoBytes
 * Description: Converts uint16 to four bytes.  Note: endianess is preserved.
 *  
 * Parameters: value  - the uint16 value
 *             *bytes - the resulting byte array
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Uint16ToTwoBytes(uint16 value, uint8* bytes)
{
    /* Note: We are not changing the endianess, we're just getting a pointer to the first byte */
    
    uint8 *p_bytes = (uint8 *) &value;
    
    bytes[0] = p_bytes[0];
    bytes[1] = p_bytes[1];
}

/*---------------------------------------------------------------------------------------------------
 * Name: Uint32ToFourBytes
 * Description: Converts uint32 to four bytes.  Note: endianess is preserved.
 *  
 * Parameters: value  - the uint32 value
 *             *bytes - the resulting byte array
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Uint32ToFourBytes(uint32 value, uint8* bytes)
{
    /* Note: We are not changing the endianess, we're just getting a pointer to the first byte */

    uint8 *p_bytes = (uint8 *) &value;
    
    bytes[0] = p_bytes[0];
    bytes[1] = p_bytes[1];
    bytes[2] = p_bytes[2];
    bytes[3] = p_bytes[3];
}

/*---------------------------------------------------------------------------------------------------
 * Name: Int32ToFourBytes
 * Description: Converts an int32 to four bytes.  Note: endianess is preserved.
 *  
 * Parameters: value  - the int32 value
 *             *bytes - the resulting byte array
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Int32ToFourBytes(int32 value, uint8* bytes)
{
    Uint32ToFourBytes((uint32)value, bytes);
}

/*---------------------------------------------------------------------------------------------------
 * Name: FloatToFourBytes
 * Description: Converts a float 32 to four bytes.  Note: endianess is preserved.
 *  
 * Parameters: value  - the float 32 value
 *             *bytes - the resulting byte array
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void FloatToFourBytes(float value, uint8* bytes)
{
    /* Note: We are not changing the endianess, we're just getting a pointer to the first byte */

    uint8 *p_bytes = (uint8 *) &value;
    
    bytes[0] = p_bytes[0];
    bytes[1] = p_bytes[1];
    bytes[2] = p_bytes[2];
    bytes[3] = p_bytes[3];
}

/*---------------------------------------------------------------------------------------------------
 * Name: TwoBytesUint16
 * Description: Converts four bytes to uint16.  Note: endianess is preserved.
 *  
 * Parameters: *bytes - bytes to be converted
 * Return: uint16
 * 
 *-------------------------------------------------------------------------------------------------*/
uint16 TwoBytesToUint16(uint8* bytes)
{
    uint16 value = *((uint16 *) bytes);
    return value;
}

/*---------------------------------------------------------------------------------------------------
 * Name: TwoBytesInt16
 * Description: Converts four bytes to int16.  Note: endianess is preserved.
 *  
 * Parameters: *bytes - bytes to be converted
 * Return: int16
 * 
 *-------------------------------------------------------------------------------------------------*/
int16 TwoBytesInt16(uint8* bytes)
{
    return (int16) TwoBytesToUint16(bytes);
}

/*---------------------------------------------------------------------------------------------------
 * Name: FourBytesToUint32
 * Description: Converts four bytes to uint32.  Note: endianess is preserved.
 *  
 * Parameters: *bytes - bytes to be converted
 * Return: uint32
 * 
 *-------------------------------------------------------------------------------------------------*/
uint32 FourBytesToUint32(uint8* bytes)
{
    uint32 value = *((uint32 *) bytes);
    return value;
}

/*---------------------------------------------------------------------------------------------------
 * Name: FourBytesToInt32
 * Description: Converts four bytes to int32.  Note: endianess is preserved.
 *  
 * Parameters: *bytes - bytes to be converted
 * Return: int32
 * 
 *-------------------------------------------------------------------------------------------------*/
int32 FourBytesToInt32(uint8* bytes)
{
    return (int32) FourBytesToUint32(bytes);
}

/*---------------------------------------------------------------------------------------------------
 * Name: FourBytesToFloat
 * Description: Converts four bytes to float 32.  Note: endianess is preserved.
 *  
 * Parameters: *bytes - bytes to be converted
 * Return: floating point value
 * 
 *-------------------------------------------------------------------------------------------------*/
float FourBytesToFloat(uint8 *bytes)
{   
    float value = *((float *) bytes);    
    return value;
}

/*---------------------------------------------------------------------------------------------------
 * Name: BinaryRangeSearch
 * Description: Performs a binary search to find a range, i.e., lower and upper values, within which
 *              the search value falls.
 *  
 * Parameters: search       - the value for which a range is sought
 *             *data_points - the data points to be searched
 *             num_points   - the number of data points
 *             *lower_index - the resulting lower value index into the data points
 *             *upper_index - the resulting upper value index into the data points
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void BinaryRangeSearch(int16 search, int16 *data_points, uint8 num_points, uint8 *lower_index, uint8 *upper_index)
/*
    This is a binary search modified to return a range, e.g., lower and upper, when searching for an element.

    Performance:
    Array Size      log2N
        10            4
        50            6
       100            7
       500            9

*/
{
    uint8 first = 0;
    uint8 last = num_points - 1;
    uint8 middle = (first+last)/2;
    
    *lower_index = 0;
    *upper_index = 0;

    while (first <= last) {
        if (data_points[middle] < search)
        {
            first = middle + 1;
            *lower_index = middle;
        }
        else if (data_points[middle] == search) 
        {
            *lower_index = middle;
            *upper_index = middle;
            break;
        }
        else if (data_points[middle] > search)
        {            
            *upper_index = middle;
            last = middle;
            
            if (*upper_index - *lower_index == 1)
            {
                break;
            }
        }
        else
        {
            // There are no other possibilities :-)
        }
 
        middle = (first + last)/2;
   }
}

/*---------------------------------------------------------------------------------------------------
 * Name: UniToDiff
 * Description: Converts unicycle linear/angular velocity to differential left/right velocity
 *  
 * Parameters: left     - the differential left velocity
 *             right    - the differential right velocity
 *             *linear  - the linear velocity
 *             *angular - the angular velocity
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void UniToDiff(float linear, float angular, float *left, float *right)
/*
    Vr = (2*V + W*L)/(2*R)
    Vl = (2*V - W*L)/(2*R)
    where 
        Vr - the velocity of the right wheel (rad/s)
        Vl - the velocity of the left wheel (rad/s)
        V - the linear velocity
        W - the angular velocity
        L - the separation of the left and right wheels
        R - the radius of the wheel
*/
{
    *left = (2*linear - angular*TRACK_WIDTH)/WHEEL_DIAMETER;
    *right = (2*linear + angular*TRACK_WIDTH)/WHEEL_DIAMETER;
}

/*---------------------------------------------------------------------------------------------------
 * Name: DiffToUni
 * Description: Converts differential left/right velocity to unicycle linear/angular 
 *              velocity
 *  
 * Parameters: left     - the differential left velocity (m/s)
 *             right    - the differential right velocity (m/s)
 *             *linear  - the linear velocity (m/s)
 *             *angular - the angular velocity (rad/s)
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void DiffToUni(float left, float right, float *linear, float *angular)
/*
    V = R/2 * (Vr + Vl)
    W = R/L * (Vr - Vl)
    where
        V - the linear velocity
        W - the angular velocity
        L - the separation of the left and right wheels
        R - the radius of the wheel
        Vr - the velocity of the right wheel
        Vl - the velocity of the left wheel

*/
{
    *linear = WHEEL_RADIUS * (right + left) / 2;
    *angular = WHEEL_RADIUS * (right - left) / TRACK_WIDTH;    
}

/*---------------------------------------------------------------------------------------------------
 * Name: Interpolate
 * Description: Performs linear interpolation between two points
 *  
 * Parameters: x  - input value
 *             x1 - point 1 x value
 *             x2 - point 2 x value
 *             y1 - point 1 y value
 *             y2 - point 2 y value
 * Return: interpolated output
 * 
 *-------------------------------------------------------------------------------------------------*/
int16 Interpolate(int16 x, int16 x1, int16 x2, uint16 y1, uint16 y2)
{
    /* Y = ( ( X - X1 )( Y2 - Y1) / ( X2 - X1) ) + Y1 */

    /* We are not guaranteed to not have duplicates in the array.
       
       Handle the cases where the values may be equal so we don't divide by zero and so we return a 
       reasonble pwm value.
     */
    if (x1 == x2)
    {
        if (y2 == y1)
        {
            return y1;
        }
        else
        {
            return (y2 - y1)/2 + y1;
        }
    }
    
    return ((x - x1)*((int16) y2 - (int16) y1))/(x2 - x1) + (int16) y1;
}

/*---------------------------------------------------------------------------------------------------
 * Name: CalcHeading
 * Description: Calculates the heading given left/right count, radius, width (distance between left/right
 *              wheels) and count/revolution.
 *  
 * Parameters: left_count    - the encoder count from the left wheel
 *             right_count   - the encoder count from the right wheel
 *             radius        - the radius of the wheel
 *             width         - the distance between left and right wheels
 *             count_per_rev - the encoder count per wheel revolution
 *             bias          - the bias adjustment
 * Return: heading
 * 
 *-------------------------------------------------------------------------------------------------*/
float CalcHeading(float left_count, float right_count, float radius, float width, float count_per_rev, float bias)
{
    return (bias * (right_count - left_count) * PI * radius)/(count_per_rev * width);
}

/*---------------------------------------------------------------------------------------------------
 * Name: CpsToPwm
 * Description: Converts count/sec to PWM 
 *              This routine searches the count/sec array (cps_data) to find values immediately less 
 *              than and greater than the specified count/sec value (cps) to obtain the corresponding
 *              indicies - upper/lower.  The indicies are then used to interpolate a PWM value.
 *  
 * Parameters: cps       - the specified count/sec
 *             cps_data  - an array of count/sec values to be searched
 *             pwm_data  - an array of pwm values for selection
 *             data_size - the number of values in each array
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
uint16 CpsToPwm(int16 cps, int16 *cps_data, uint16 *pwm_data, uint8 data_size)
{   
    PWM_TYPE pwm = PWM_STOP;
    uint8 lower = 0;
    uint8 upper = 0;

    if (cps > 0 || cps < 0)
    {
        BinaryRangeSearch(cps, cps_data, data_size, &lower, &upper);
        
        pwm = Interpolate(cps, cps_data[lower], cps_data[upper], pwm_data[lower], pwm_data[upper]);

        return constrain(pwm, MIN_PWM_VALUE, MAX_PWM_VALUE);
    }

    //Ser_PutStringFormat("CpsToPwm: %d -> %d\r\n", cps, pwm);

    return pwm;
}

/*---------------------------------------------------------------------------------------------------
 * Name: NormalizeHeading
 * Description: Returns a heading ranging from -PI to Pi relative to the direction 
 *  
 * Parameters: heading - raw non-normalized heading as calculated in CalcHeading 
 *             direction - the direction of the rotation, i.e., CW or CCW 
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
float NormalizeHeading(float heading)
{
    float result = 0.0;

    result = heading;
    
    result -= (float)( (int)(result/TWOPI) ) * TWOPI;
    if (result < -PI) 
    { 
        result += TWOPI;
    }
    else if (result > PI)
    {
        result -= TWOPI; 
    }

    return result;
}

void CalcTriangularProfile(uint8 num_points, float lower_limit, float upper_limit, float *profile)
{
    uint8 mid_sample_offset;
    float delta;
    float value;
    uint8 ii;

    if (num_points % 2 == 0)
    {
        assert("Profile requires odd number of points");
    }

    /* Calculate the mid point */
    mid_sample_offset = num_points / 2;
    
    /* Calculate the delta step */
    delta = (upper_limit - lower_limit)/mid_sample_offset;
    
    /* Set the mid point */
    profile[mid_sample_offset] = upper_limit;
    
    /* Set the 'up' slope values */
    value = lower_limit;
    for (ii = 0; ii < mid_sample_offset; ++ii)
    {
        profile[ii] = value;
        value += delta;
    }
    
    /* Set the 'down' slope values */ 
    value = upper_limit;
    for (ii = mid_sample_offset; ii < num_points; ++ii)
    {
        profile[ii] = value;
        value -= delta;
    }
    
}

void EnsureAngularVelocity(float *v, float *w)
{
    /*
    Ensure specified angular velocity can be met by adjusting linear velocity
    :param v: Linear velocity
    :param w: Angular velocity
    :param track_width: Wheel base width
    :param wheel_radius: Wheel radius
    :param ang_wheel_max: Maximum allowed angular velocity
    :return: Linear/Angular velocity
    */

    float l_v_d;
    float r_v_d;
    float max_rl_v;
    float min_rl_v;
    float temp_v;
    float temp_w;
    float l_v;
    float r_v;

    temp_v = *v;
    temp_w = *w;
    
    UniToDiff(temp_v, temp_w, &l_v_d, &r_v_d);

    max_rl_v = max(l_v_d, r_v_d);
    min_rl_v = min(l_v_d, r_v_d);

    l_v = 0;
    r_v = 0;

    //print("{:6.3f} {:6.3f} {:6.3f} {:6.3f} {:6.3f}".format(l_v_d, r_v_d, track_width, wheel_radius, ang_wheel_max))

    /* Only adjust if v and w are non-zero
    */
    if (temp_v != 0.0 && temp_w != 0.0)
    {
        if (max_rl_v > MAX_WHEEL_RADIAN_PER_SECOND)
        {
            r_v = r_v_d - (max_rl_v - MAX_WHEEL_RADIAN_PER_SECOND);
            l_v = l_v_d - (max_rl_v - MAX_WHEEL_RADIAN_PER_SECOND);
        }
        else if (min_rl_v < -MAX_WHEEL_RADIAN_PER_SECOND)
        {
            r_v = r_v_d - (min_rl_v + MAX_WHEEL_RADIAN_PER_SECOND);
            l_v = l_v_d - (min_rl_v + MAX_WHEEL_RADIAN_PER_SECOND);
        }
        else
        {
            l_v = l_v_d;
            r_v = r_v_d;
        }

        DiffToUni(l_v, r_v, &temp_v, &temp_w);

        *v = temp_v;
        *w = temp_w;
    }
}

/* [] END OF FILE */
