#pragma once
#include <iostream>
#include "Stack.h"
#include "Table.h"
#include <string>
#include <cctype>
#include <cmath> 

class Formula{
private:
    std::string _expression;
    Stack<char> _calcStack;// стэк для подсчетов
    std::string _postfix;
    Table <char, int> _priority = Table<char, int>("Operation", "Priority") ;
    bool CheckBrackets();
    bool CheckFormula();
    void EnterVariableValues();//ввод значения переменных в выражении
public:
    Formula(const std::string& exp){
        _expression = exp;
        _priority.AppendRow('(',0);
        _priority.AppendRow(')',1);
        _priority.AppendRow('+',2);
        _priority.AppendRow('-',2);
        _priority.AppendRow('*',3);
        _priority.AppendRow('/',3);
    };
    void BuildPostfix(){
        std::string operators = "(+-*/)";
         std::string current_num="";
        for(size_t i=0; i<_expression.length();i++){
            if(operators.find(_expression[i])!= std::string::npos){
                if(current_num!=""){
                    _postfix.append(current_num);
                    _postfix.push_back(' ');
                    current_num="";
                }
                if(_priority[_expression[i]].value()==0 || _priority[_expression[i]].value() > _priority[_calcStack.Check()].value() || _calcStack.IsEmpty()){
                    if(_expression[i]!=')')
                        _calcStack.Push(_expression[i]);
                    //std::cout<<_calcStack<<"\n";
                }
                else{
                    while(_priority[_expression[i]].value()<=_priority[_calcStack.Check()].value() && !_calcStack.IsEmpty() ){
                        //_postfix.push_back(_calcStack.Pop());
                        if(_calcStack.Check()=='(')
                            _calcStack.Pop();
                        else
                            _postfix.push_back(_calcStack.Pop());

                        //std::cout<<_calcStack<<"\n";
                    }
                    if(_expression[i]!=')')
                        _calcStack.Push(_expression[i]);
                }
            }
            else
                current_num.push_back(_expression[i]);
        }
        if(current_num!=""){
                    _postfix.append(current_num);
                    _postfix.push_back(' ');
                    current_num="";
                }
        while(!_calcStack.IsEmpty())
            if(_calcStack.Check()!='('&&_calcStack.Check()!=')'){
                _postfix.push_back(_calcStack.Pop());
                //std::cout<<_calcStack<<"\n";
            }
            else{
                _calcStack.Pop();
                //std::cout<< _calcStack<< "\n";
            }
        std::cout<<_postfix<<"\n";
    };



    double Calculate(Table<std::string, double> var_table){
        BuildPostfix();
        Stack<double> st;
        double tmp2=0;
        double tmp1=0;
        double res_tmp=0;
        std::string operators = "+-*/";
        std::string current_num="";
        for(size_t i=0; i<_postfix.length();i++){
            if (operators.find(_postfix[i])== std::string::npos){
                if(_postfix[i]!=' ')
                    current_num.push_back(_postfix[i]);
                else{
                    int var_flag=0;
                    for(size_t i=0;i<current_num.length();i++){
                        if(std::isalpha(current_num[i])){
                            var_flag++;
                            break;
                        }
                    }
                    if(var_flag==0){
                        st.Push(std::stod(current_num));
                        
                    }
                    else{
                        st.Push(var_table[current_num].value());
                        
                    }
                        current_num="";
                }

            }
            else{
                
                tmp1=st.Pop();
                tmp2=st.Pop();
                switch(_postfix[i]){
                    case '+':res_tmp=tmp1+tmp2;break;
                    case '-':res_tmp=tmp2-tmp1;break;
                    case '*':res_tmp=tmp1*tmp2;break;
                    case '/':res_tmp=tmp2/tmp1;break;
                }
                st.Push(res_tmp);
                
                
            }
        }
        double res=st.Pop();
        return res;

    }


};
