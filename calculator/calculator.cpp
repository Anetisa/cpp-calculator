#include "calculator.h"
#include <string>
#include <iostream>
#include <cmath>

bool ReadNumber(Number& result){
    std::cin >> result;
    if(std::cin.fail()){
        std::cerr << "Error: Numeric operand expected" << std::endl; 
        return false;
    }
    return true;
}

bool RunCalculatorCycle(){
    Number num_buf;
    Number num1;
    bool save_fl = false;
    if(ReadNumber(num1)){
        while(true){
            std::string str;
            Number num2;
            
            std::cin >> str;
            if(str == "+"){
                if(!ReadNumber(num2)){
                    return false;
                }
                num1 += num2;
            } else if(str == "-"){
                if(!ReadNumber(num2)){
                     return false;
                }
                num1 -= num2;
            } else if(str == "/"){
                if(!ReadNumber(num2)){
                     return false;
                }
                num1 /= num2;
            } else if(str == "*"){
                if(!ReadNumber(num2)){
                    return false;
                }
                num1 *= num2;
            } else if(str == "**"){
                if(!ReadNumber(num2)){
                     return false;
                }
                num1 = std::pow(num1, num2);
            } else if(str == "="){
                std::cout << num1 << std::endl;
            } else if(str == ":"){
                if(!ReadNumber(num2)){
                     return false;
                }
                num1 = num2;
            } else if(str == "c"){
                num1 = 0;
            } else if(str == "q"){
                return true;
            } else if(str == "s"){
                num_buf = num1;
                save_fl = true;
            } else if(str == "l"){
                if(!save_fl){
                    std::cerr << "Error: Memory is empty" << std::endl;
                    return false;
                }
                num1 = num_buf;
            } else {
                std::cerr << "Error: Unknown token " << str << std::endl;
                return false;
            }
        }
    } else{
        return false;
    }
    return true;
}
