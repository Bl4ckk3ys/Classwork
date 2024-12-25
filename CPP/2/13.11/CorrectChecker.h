#pragma once
#include "Stack.h"
#include "Table.h"
#include "Formula.h"
#include <optional>
#include <vector>
#include <string>
#include <cstdlib>

class CorrectChecker
{
private:
    Stack<int> _brackets;
    Table<int, int> _bracketsTable;
    Table<std::string, double> _varTable;
    bool _state = false;

public:
    CorrectChecker(): _bracketsTable("(", ")", 20), _brackets(), _varTable("var", "val"){
    }
    /// @brief проверяет валидность скобок
    /// @param s 
    /// @return  
    bool CheckBrackets(const std::string s){
        int fl = 0;
        std::vector<int> error;
        for (size_t i = 0; i < s.size(); i++){
            if (s[i] == '(')
                _brackets.Push(i);
            if (s[i] == ')'){
                try{
                    _bracketsTable.AppendRow(_brackets.Pop(), i);
                }
                catch (const char *error_message){
                    _bracketsTable.AppendRow(std::nullopt, i);
                    error.push_back(i);
                    fl++;
                }
            }
        }
        while (!_brackets.IsEmpty()){
            _bracketsTable.AppendRow(_brackets.Pop(), std::nullopt);
        }
        std::cout << _bracketsTable << "\n";
        if (!error.empty()) 
            std::cout << "Error in brackets. ";
        for (size_t i = 0; i < error.size(); i++)   
            std::cout << error[i] << " ";
        std::cout << "\n";
        if (fl == 0) 
            return _brackets.IsEmpty();
        else return false;
    }

    void FillVariable(const std::string &s){
        std::string var;
        std::string operators = "(+-*/)";
        double val;
        std::string val_check;
        for (size_t i = 0; i < s.length(); i++){
            if (operators.find(s[i]) == std::string::npos){
                if (var != "")  var.push_back(s[i]);
                else{
                    if (std::isalpha(s[i]))
                        var.push_back(s[i]);
                }
            }
            else{
                if (var != "sin" && var != ""){
                    if (_varTable[var] != std::string::npos)
                        var = "";
                    else{
                        std::cout << var << " = ";
                        std::cin >> val_check;
                        if (val_check == "no"){
                            _varTable.AppendRow(var, std::nullopt);
                            var = "";
                        }
                        else{
                            val = std::stod(val_check);
                            _varTable.AppendRow(var, val);
                            var = "";
                        }
                    }
                }
                else
                    var = "";
            }
        }
        if (var != ""){
            std::cout << var << " = ";
            std::cin >> val_check;
            if (val_check == "no"){
                _varTable.AppendRow(var, std::nullopt);
                var = "";
            }
            else{
                val = std::stod(val_check);
                _varTable.AppendRow(var, val);
                var = "";
            }
        }
    }

    bool CheckVariable(){
        for (size_t i = 0; i < _varTable.GetCount(); i++){
            if (_varTable.GetCol1()[i] == std::nullopt)
                return false;
            if (_varTable.GetCol2()[i] == std::nullopt || (_varTable.GetCol2()[i] > 96 && _varTable.GetCol2()[i] < 123))
                return false;
        }
        return true;
    }

    const Table<std::string, double>& GetVarTable() const{
        return _varTable;
    }

    bool CheckFormula(const std::string &s){
        if (!CheckBrackets(s)){
            _state = false;
            return false;
        }
        if (!CheckVariable()){
            _state = false;
            return false;
        }
        else{
            for (size_t i = 0; i < _bracketsTable.GetCount(); i++){
                if (_bracketsTable.GetCol2()[i].value() - _bracketsTable.GetCol1()[i].value() <= 3){
                    _state = false;
                    return false;
                }
            }
            std::string operators = "+-*/";
            for (size_t i = 1; i < s.length(); ++i){
                if (operators.find(s[i]) != std::string::npos && operators.find(s[i - 1]) != std::string::npos){
                    _state = false;
                    return false;
                }
            }
        }
        return true;
    }
    bool GetState(){
        return _state;
    }

    void AppendVarTable(std::string s, double d){
        _varTable.AppendRow(s, d);
    }


};
