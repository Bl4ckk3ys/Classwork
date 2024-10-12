#pragma once
#include "SensorsHandler.h"

int main(){
    srand(time(NULL));
    TempSensor temp1;
    std::cout << "Temperature: " << temp1() << std::endl;
    
    HumiditySensor humid1;
    std::cout << "Humidity: " << humid1() << std::endl;
    
    PressureSensor pres1;
    std::cout << "Pressure: " << pres1() << std::endl;
    
    ATH sens;
    auto f = sens();
    std::cout<< "ATH21: temp ~ " << std::get<0>(f) << " hum ~ " << std::get<1>(f) << std::endl;
    return 0;
}