#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 

bool isNumber(std::string x);

int main(void) 
{
    std::string a;
    int result, expression_old_size;
    std::vector<std::string> expression;
    while(std::cin.peek() != '\n')
    {
        std::cin >> a;
        expression.push_back(a);
    }
    while(expression.size() > expression_old_size)
    {
        expression_old_size = expression.size();
        for(int i = 0; i < expression.size()-2; i++)
        {   
            if(isNumber(expression[i+1]) && isNumber(expression[i+2]))
            {
                if(expression[i] == "+")
                    result = stoi(expression[i+1])+stoi(expression[i+2]);   
                else if(expression[i] == "-")
                    result = stoi(expression[i+1])-stoi(expression[i+2]);   
                else if(expression[i] == "*")
                    result = stoi(expression[i+1])*stoi(expression[i+2]);   
                expression.erase((expression.begin()+i));
                expression.erase((expression.begin()+i));
                expression.erase((expression.begin()+i));
                expression.emplace(expression.begin()+i,std::to_string(result));
                i += 3;
            }
        }
    }
    for(int i = 0; i < expression.size(); i++)
        std::cout << expression[i] << " ";
    std::cout << std::endl;
    return 0;
}

bool isNumber(std::string x)
{
    if(x.find_first_not_of("0123456789") == std::string::npos)
        return true;
    else
        return false;
}
