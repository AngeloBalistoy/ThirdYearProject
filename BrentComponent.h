//
// Created by balis on 05/02/2021.
//
#include <stdint.h>
#include <ostream>
#include <vector>
#include <math.h>
#include<unordered_map>
#ifndef DISSERTATION_BRENTCOMPONENT_H
#define DISSERTATION_BRENTCOMPONENT_H
typedef uint16_t  index;
typedef uint16_t  literal;

//Functions and structs




struct BrentComponentIndex {
    uint16_t first;
    uint16_t second;
    friend std::ostream &operator<<( std::ostream &output, BrentComponentIndex i) {
        output << "(" << i.first << "," << i.second << ")"
               << " ";
        return output;
    }

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
    BrentExpression(const BrentComponent& alpha,const BrentComponent& beta,const BrentComponent& gamma);
    BrentComponent alpha;
    BrentComponent beta;
    BrentComponent gamma;
    literal literal;
    friend std::ostream &operator<<( std::ostream &output, BrentExpression B) {
        output << "(" << B.alpha.productNumber << ")" << "(" << B.alpha.index.first << "," << B.alpha.index.second << ")"
               << "(" << B.beta.index.first << "," << B.beta.index.second << ")"
               << "(" << B.gamma.index.first << "," << B.gamma.index.second << ")";
        return output;
    }
    static uint16_t counter;
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
struct S_Variable {
    uint16_t productNumber;
    BrentComponentIndex index1;
    BrentComponentIndex index2;
    S_Variable(BrentComponent a, BrentComponent b);

};

struct T_Variable {
    uint16_t productNumber;
    BrentComponentIndex index1;
    BrentComponentIndex index2;
    BrentComponentIndex index3;
    literal literal;
    T_Variable(S_Variable s, BrentComponent c);
    friend std::ostream &operator<<( std::ostream &output, T_Variable B) {
        output << "(" << B.productNumber << ")" << B.index1 << B.index2 << B.index3 << std::endl;
        return output;
    }
private:
    static uint16_t counter;
};
bool processRHS(Delta);

void recurseTranslate(std::vector<std::vector<uint16_t> > firstOrder);



#endif //DISSERTATION_BRENTCOMPONENT_H
