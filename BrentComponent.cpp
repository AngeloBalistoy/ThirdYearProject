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

void recurseTranslate(std::vector<std::vector<uint16_t> > firstOrder) {
    std::size_t const halfSize = firstOrder.size() / 2;
    std::vector<std::vector<uint16_t> >leftHalf(firstOrder.begin(), firstOrder.begin() + halfSize);
    std::vector<std::vector<uint16_t> > rightHalf(firstOrder.begin() + halfSize, firstOrder.end());
    if (leftHalf.size() == 1 || leftHalf.size() == 2) {
        std::cout << "LHS base case reached!" << std::endl;
        //do some processing
        if (leftHalf.size() == 1) {
            //answer is just returning this pair
        }
        return
    }
    else {
        recurseTranslate(leftHalf);
    }
    if (rightHalf.size() == 1 || rightHalf.size() == 2) {
        std::cout << "RHS base case reached!" << std::endl;
        //do some processing
    }



}

std::vector<uint16_t> twoPairCase(std::vector<uint16_t> a, std::vector<uint16_t>b) {
    std::vector<uint16_t> firstClause = {b.at(1),-b.at(0),- a.at(1),-a.at(2)}
}