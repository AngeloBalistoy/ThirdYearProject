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
/*

S_Variable::S_Variable(BrentComponent& a, BrentComponent& b) : literal(++counter){
    this->alpha = a;
    this->beta = b;
}
 */
uint16_t ContainsLiteral::counter = 0;

T_Variable::T_Variable(BrentComponent& A,BrentComponent& B, BrentComponent& G) : literal(++counter){
    this->A = A;
    this->B = B;
    this->G = G;

}

void XOR_Encoding(std::vector<T_Variable> t) {
    size_t size = t.size();

}
BrentComponent::BrentComponent(uint16_t& productNumber, BrentComponentIndex& index) : literal(++counter),productNumber(productNumber),index(index) {

};
BrentExpression::BrentExpression(const BrentComponent &alpha, const BrentComponent &beta, const BrentComponent &gamma) :
 alpha(alpha), beta(beta), gamma(gamma) {};

void createOddNumberOfCombinations(std::ostream& outputFileOdd,uint16_t numberOfMultiplications) {
    uint16_t oddStart = numberOfMultiplications%2 == 0 ? 1 : 0;
    std::vector<std::vector<bool>> oddCombinations{};
    std::vector<bool> clause(numberOfMultiplications);
    //Generate odd clauses
    for (oddStart; oddStart <= clause.size(); oddStart += 2) {
        for (int value = 0; value < clause.size(); value++) {
            clause.at(value) = 1;
        }
        for (int j = 0; j < oddStart; j++) {
            clause.at(j) = 0;
        }
        oddCombinations.push_back(clause);
    }
    //display

    //output to a file
    for (auto i : oddCombinations) {
        do {
            for (auto j : i) {
                outputFileOdd << j << " ";
            }
            outputFileOdd << std::endl;
        } while (std::next_permutation(i.begin(), i.end()));
    }
}

void createEvenNumberOfCombinations(std::ostream& outputFileEven,uint16_t numberOfMultiplications) {
    std::vector<bool> clause(numberOfMultiplications);
    std::vector<std::vector<bool>> evenCombinations{};
    uint16_t evenStart = numberOfMultiplications%2 == 0 ? 0 : 1;

    for (evenStart; evenStart <= clause.size(); evenStart += 2) {
        for (int value = 0; value < clause.size(); value++) {
            clause.at(value) = 1;
        }
        for (int j = 0; j < evenStart; j++) {
            clause.at(j) = 0;
        }
        evenCombinations.push_back(clause);
    }

    for (auto i : evenCombinations) {
        do {
            for (auto j : i) {
                outputFileEven << j << " ";
            }
            outputFileEven << std::endl;
        } while (std::next_permutation(i.begin(), i.end()));
    }



}



BrentComponent::BrentComponent() {

}


T_VariableHolder::T_VariableHolder() : literal(++counter) {}
