#pragma once
#include <iostream> 
#include <random>

class TempSensor{
    private:
        double _temp;
        void New_temp(){
            double del = -10 + rand() %20;
            _temp += del/10;
            if(_temp > MAX_TEMP) _temp = MAX_TEMP;
            if(_temp < MIN_TEMP) _temp = MIN_TEMP;
        }

    public:
        const double MAX_TEMP = 50;
        const double MIN_TEMP = -50;
        TempSensor(){
            _temp = MIN_TEMP + rand() % static_cast<int>(MAX_TEMP);
        }
        double operator()(){
            New_temp();
            return _temp;
        }
};