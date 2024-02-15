#include <iostream>

struct WithVeryBigName{
    int a = 0;
};

inline double MySqr(double a){//inline function подставляет код функции напрямую
    return a*a;
}

double Sum(double a, double b=10){
    return a+b;
}

enum BluetoothState{Connected,Disconnected,Connecting,Disconnecting};

int main(){
    auto mySruct = WithVeryBigName();
    int a = mySruct.a;
    double res1 = MySqr(10);
    double res2 = 10*10;

    double res3 = Sum(5);
    double res4 = Sum(5,20);
    //double res5 = Sum() //Ошибка
    bool flag = true;

    BluetoothState currentBluetoothState = BluetoothState::Connected;
    switch (currentBluetoothState){
    case BluetoothState::Connected:
    std::cout << "Device is Connected" << std::endl;
        break;
    case BluetoothState::Disconnected:
    std::cout << "Device is Disconnected" << std::endl;
        break;
    case BluetoothState::Connecting:
    std::cout << "Device is Connecting" << std::endl;
        break;
    case BluetoothState::Disconnecting:
    std::cout << "Device is Disconnecting" << std::endl;
        break;
    default: std::cout << "Undefined" << std::endl;
        break;
    }

    int* arr = new int[100];
    for (int i = 0;i++;i<100){
        arr[i] = i;
    }
    delete [] arr;
    //std::cin >> a;
    std::cout << a << std::endl;

    return 0;
}