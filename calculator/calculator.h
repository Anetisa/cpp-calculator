#pragma once

#include <string>

using Number = double;

class Calculator{
public:
    Calculator();

    void Set(Number n);
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);

    Number GetNumber() const;
    std::string GetNumberRepr() const;
private:
    Number num_current_ = 0;
};
