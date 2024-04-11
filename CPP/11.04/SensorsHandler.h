#pragma once
#include "TempSensor.h"
#include "HumiditySensor.h"
#include "PressureSensor.h"
#include "ATH21.h"

class SensorsHandler{
    private:
        TempSensor** Temp_array = new TempSensor*[10];
        HumiditySensor** Temp_array = new HumiditySensor*[10];
    public:
};