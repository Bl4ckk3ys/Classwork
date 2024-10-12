#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>


class Item{
public:
    Item(){
        std::cout<<"Item is constructed"<<std::endl;
    }
    ~Item(){
        std::cout<<"Item is destructed"<<std::endl;
    }
    void Print(){
        std::cout<<"Item is printed"<<std::endl;
    }

};
void Foo(){
    int n = 0;
    
    try{
        Item* item = new Item();
        throw "error";
        delete item;
    }catch(...){
        std::cout << "EROR" << std::endl;
    }
}
void Bar(std::unique_ptr<Item> smart){
    smart.get()->Print();
}
int main(){
    std::shared_ptr<Item> sptr = std::make_shared<Item>();
    std::shared_ptr<Item> sptr2 = sptr;
    sptr2.reset();
    // size_t size = 10;
    // std::unique_ptr<int[]> u_ptr_smart = std::make_unique<int[]>(size);
    // u_ptr_smart[1] = 100;
    // std::cout<< u_ptr_smart[1] << std::endl;

    // Bar(std::move(u_ptr_smart));
    // std::cout<<"123"<<std::endl;
    // std::map<std::string, int> mapa;
    // std::vector<std::pair<std::string,int>> vectora;
    // for(int i =0; i < 1000000; i++){
    //     vectora.push_back(std::pair<std::string, int>(
    //         std::to_string(i), i*i));
    //     mapa[std::to_string(i)] = i*i;
    // }

    // std::string key = "500000";

    // auto elem = mapa[key];

    return 0;
}