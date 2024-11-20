#pragma once
#include "Stack.h"
#include "Table.h"

class CorrectChecker
{
private:
    Stack<int> _brackets;

public:
    bool CheckBrackets(const std::string s){
        Table <int, int> tableOfBrackets; 
        for(size_t i = 0; i < s.size(); i++){
            if(s[i]  == '('){
                _brackets.Push(i);
            } 
            if(s[i] == ')') {
                try{
                    tableOfBrackets.AppendRow(_brackets.Pop(), i);
                }
                catch(const char* error_message){
                    std::cout<< "Error with brackets"<<"\n";
                    return false;
                }
            } 
        }
        return _brackets.IsEmpty();
    };
    
    ~CorrectChecker();
};
