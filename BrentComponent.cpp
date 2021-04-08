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
    std::cout << "ODD:" << std::endl;

    for (auto num : oddCombinations) {
        for (auto elem : num) {
            std::cout << elem << ",";
        }
        std::cout << std::endl;
    }
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
    for (auto num : evenCombinations) {
        for (auto elem : num) {
            std::cout << elem << ",";
        }
        std::cout << std::endl;
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


