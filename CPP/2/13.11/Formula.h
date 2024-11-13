class Formula
{
private:
    string _expression;
    Stack<string> _calcStack;// стэк для подсчетов
    string _postfix;
    bool CheckBrackets();
    bool CheckFormula();
    void EnterVariableValues();//ввод значения переменных в выражении
public:
    Formula(string exp);
    string BuildPostfix();
    double Calculate();
    ~Formula();
};
