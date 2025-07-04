#include "calculator.h"

#include <cassert>
#include <cmath>

Calculator::Calculator()
    : num_current_(0.0)
{
}

void Calculator::Set(Number n){
    num_current_ = n;
}

void Calculator::Add(Number n){
    num_current_ += n;
}

void Calculator::Sub(Number n){
    num_current_ -= n;
}

void Calculator::Div(Number n){
    //if (n != 0.0)
    num_current_ /= n;
}

void Calculator::Mul(Number n){
    num_current_ *= n;
}

void Calculator::Pow(Number n){
    num_current_ = std::pow(num_current_, n);
}

Number Calculator::GetNumber() const{
    return num_current_;
}

std::string Calculator::GetNumberRepr() const{
    return std::to_string(num_current_);
}
