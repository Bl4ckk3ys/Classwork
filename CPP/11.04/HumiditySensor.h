#pragma once
#include <iostream>
#include <random>
class HumiditySensor{
    private:
        double _humidity;
        void Update(){
            double tmp = -10 + rand()%20;
            _humidity += tmp / 10;
            if(_humidity > MAX_HUMIDITY) _humidity = MAX_HUMIDITY;
            if(_humidity < 0 ) _humidity = 0;
        }
    public:
        const double MAX_HUMIDITY = 100;
        HumiditySensor(){
            _humidity = rand() % static_cast<int>(MAX_HUMIDITY);
        }

        double operator()(){
            Update();
            return _humidity;
        }
};