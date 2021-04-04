//
// Created by balis on 05/02/2021.
//
#include <iostream>
#include "BrentComponent.h"

bool processRHS(Delta d) {
    return (d.d1.index.first == d.d1.index.second) &&
           (d.d2.index.first == d.d2.index.second) &&
           (d.d3.index.first == d.d3.index.second);
}


S_Variable::S_Variable(BrentComponent a, BrentComponent b) {
    this->productNumber = a.productNumber;
    this->index1 = a.index;
    this->index2 = b.index;
}
uint16_t T_Variable::counter = 0;
T_Variable::T_Variable(S_Variable s, BrentComponent c) : literal(++counter){
    this->productNumber = s.productNumber;
    this->index1 = s.index1;
    this->index2 = s.index2;
    this->index3 = c.index;

}

void XOR_Encoding(std::vector<T_Variable> t) {
    size_t size = t.size();

}
uint16_t BrentExpression::counter = 0;
BrentExpression::BrentExpression(const BrentComponent &alpha, const BrentComponent &beta, const BrentComponent &gamma) :
        literal(++counter), alpha(alpha), beta(beta), gamma(gamma) {};



