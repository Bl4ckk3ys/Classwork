#pragma once
#include <iostream>
#include <random>

class PressureSensor{
    private:
        double _pressure;
        void Update(){
            double tmp = -10+rand()%20;
            _pressure += tmp;
            if(_pressure > MAX_PRESSURE) _pressure = MAX_PRESSURE;
            if(_pressure < MIN_PRESSURE) _pressure = MIN_PRESSURE;
        }
    public:
        const double MAX_PRESSURE = 900;
        const double MIN_PRESSURE = 600;
        PressureSensor(){
            _pressure = MIN_PRESSURE + rand()%static_cast<int>(MAX_PRESSURE-MIN_PRESSURE);
        }
      
        double operator()(){
            Update();
            return _pressure;
        }
};