// cpp.CA.PIDControllerSımpleDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <Windows.h>
#include <cstdlib>
#include <math.h>


double PIDController(double setpoint, double measured_value, bool& direct) {

    
    double Kp = 3;
    double Ki = 1;
    double Kd = 0.1;
    //double integral = 0;

    /*double dt = 1;
    double previous_error = 0;
    double integral = 0;
    double error = setpoint -  measured_value;
    integral = integral + error * dt;
    double derivative = (error - previous_error) / dt;
    double output = Kp * error + Ki * integral + Kd * derivative;
    previous_error = error;
    
    */
    double error = setpoint - measured_value;
    if (error>0)
    {
        double output = 0;

        output = error * Kp + error * Ki + error * Kd;
        return output;
    }
    else if (error  == 0)
    {
        return 0;
    }

    else
    {
        error = abs(error);
        double output = error * Kp + error * Ki + error * Kd;
        return output;
    }
    //hız
    
}

double angleOrientation(double angle) {

    return angle = std::fmod(angle, 360);
}


int main()
{
    double output = 0;
    double measuredValue = 0;
    double setp = 100;
    bool direction = false; //clockwise direction is false. Counter-clockwise is true
    while (true)
    {
        output = PIDController(setp, measuredValue, direction);
        if (measuredValue > setp) {
            for (size_t i = 0; i < output; i++)
            {
                measuredValue -= 0.2;
            }
        }
        else if (measuredValue < setp)
        {
            for (int i = 0; i < output; i++)
            {
                measuredValue += 0.21;
                Sleep(0);

            }
        }
        else
        {
            break;
        }
        
        std::cout << "Voltage:" << output <<  std::endl;
        //if (output <= 0) { break; }
    }
    std::cout << "Target Completed";
}
