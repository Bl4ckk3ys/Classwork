#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

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

//Пример функционального полиморфизма
double Divide(double a, double b){
    return a/b;
}
int Divide(int a, int b){
    int res = a / b;
    return res;
}

template<typename T, typename D>
double DivideTemplate(T a, T b, D c){
    double res = 0;
    try{
        res = a/b;
    }catch(const char* message){
        std::cout << "Error" << std::endl;
    }
    return res;
}

void change_reference_value(int& a){
    a = 10000;
}
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

    const int const_a = 10;
    int b = 10;
    int c = 100;
    const int* const pointer_b = &b;//первый конст запрещает менять значение b, а второй менять указатель b
    //*pointer_b = 1;
    //pointer_b = &c;

    const int* const_pointer = &const_a;//указатель должен быть типа конст, если мы хотим содержать в нем указатель на константу
    
    double base_val = 100;
    int target_val = static_cast<int>(base_val);//Преобразование типов

    double res_div = Divide(10.0,10.0);
    int res_div_int = Divide(10,10);


    //double res_template = DivideTemplate(10,0,1.0);//пример вызова шаблонной функции
    //DivideTemplate(10,'a',1.0);//Ошибка, тк в щаблоне функции мы задали два первых параметра одного



    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    for (auto elem : array){
        std::cout<<elem<<std::endl;
    } //Новый механизм обхода массива



    std::cout << std::endl;
    std::cout << std::endl;

    int abc = 10;
    int& ref_abc = abc;
    change_reference_value(ref_abc);
    std::cout << ref_abc << std::endl;

    int dsa = 100;
    //ref_abc = dsa; //Нельзя, тк ссылка = конст указатель 


    int** matrix = new int*[5];
    for(int i =0;i++;i<5){
        matrix[i] = new int[5];
    }

    for(int i =0;i++;i<5){
        delete [] matrix[i];
    }
    delete [] matrix;

    std::mt19937 gen;//генерация рандомных чисел
    gen.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist;

    std::cout << dist(gen) << std::endl;
    

    return 0;
}