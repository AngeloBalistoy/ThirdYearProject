//
// Created by balis on 05/02/2021.
//
#include <stdint.h>
#include <ostream>
#ifndef DISSERTATION_BRENTCOMPONENT_H
#define DISSERTATION_BRENTCOMPONENT_H
//Functions



struct BrentComponentIndex {
    uint16_t first;
    uint16_t second;

};


//*alpha*.*beta*.*gamma*
struct BrentComponent {
    uint16_t productNumber;
    BrentComponentIndex index;
    friend std::ostream &operator<<( std::ostream &output, BrentComponent bc) {
        output << "(" << bc.productNumber << ")" << bc.index.first <<"," <<bc.index.second << std::endl;
        return output;
    }
};
// *alpha.beta.gamma*
struct BrentExpression {
    BrentComponent alpha;
    BrentComponent beta;
    BrentComponent gamma;
    friend std::ostream &operator<<( std::ostream &output, BrentExpression B) {
        output << "(" << B.alpha.productNumber << ")" << "(" << B.alpha.index.first << "," << B.alpha.index.second << ")"
               << "(" << B.beta.index.first << "," << B.beta.index.second << ")"
               << "(" << B.gamma.index.first << "," << B.gamma.index.second << ")";
        return output;
    }
};
struct DeltaComponent {
    BrentComponentIndex index;
};

struct Delta {
    DeltaComponent d1;
    DeltaComponent d2;
    DeltaComponent d3;
    friend std::ostream &operator<<( std::ostream &output, Delta d) {
        output << "(" << d.d1.index.first << "," << d.d1.index.second << ")"
               << "(" << d.d2.index.first << "," << d.d2.index.second << ")"
               << "(" << d.d3.index.first << "," << d.d3.index.second << ")"<< std::endl;
        return output;
    }

};
bool processRHS(Delta);

#endif //DISSERTATION_BRENTCOMPONENT_H
