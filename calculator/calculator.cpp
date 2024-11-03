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
    Number num_left;
    bool save_fl = false;
    if(ReadNumber(num_left)){
        while(true){
            std::string str;
            Number num_right;
            
            std::cin >> str;
            if(str == "+"){
                if(!ReadNumber(num_right)){
                    return false;
                }
                num_left += num_right;
            } else if(str == "-"){
                if(!ReadNumber(num_right)){
                     return false;
                }
                num_left -= num_right;
            } else if(str == "/"){
                if(!ReadNumber(num_right)){
                     return false;
                }
                num_left /= num_right;
            } else if(str == "*"){
                if(!ReadNumber(num_right)){
                    return false;
                }
                num_left *= num_right;
            } else if(str == "**"){
                if(!ReadNumber(num_right)){
                     return false;
                }
                num_left = std::pow(num_left, num_right);
            } else if(str == "="){
                std::cout << num_left << std::endl;
            } else if(str == ":"){
                if(!ReadNumber(num_right)){
                     return false;
                }
                num_left = num_right;
            } else if(str == "c"){
                num_left = 0;
            } else if(str == "q"){
                return true;
            } else if(str == "s"){
                num_buf = num_left;
                save_fl = true;
            } else if(str == "l"){
                if(!save_fl){
                    std::cerr << "Error: Memory is empty" << std::endl;
                    return false;
                }
                num_left = num_buf;
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
