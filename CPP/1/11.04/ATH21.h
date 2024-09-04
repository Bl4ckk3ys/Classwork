#pragma once
#include "TempSensor.h"
#include "HumiditySensor.h"
#include <tuple>

class ATH{
    private:
        TempSensor _temp;
        HumiditySensor _hum;
    public:

        double GetTemp(){
            return _temp();
        }

        double GetHum(){
            return _hum();
        }   

        std::tuple<double,double> operator()(){
            return std::tuple<double,double>(_temp(),_hum());
        }
};