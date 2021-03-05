//
// Created by balis on 05/02/2021.
//
#include "BrentComponent.h"
bool processRHS(Delta d) {
    return (d.d1.index.first == d.d1.index.second) &&
           (d.d2.index.first == d.d2.index.second) &&
           (d.d3.index.first == d.d3.index.second);
}