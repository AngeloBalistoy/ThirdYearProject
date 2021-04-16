//
// Created by balis on 05/02/2021.
//
#include <cstdint>
#include <ostream>
#include <vector>
#include <cmath>
#include <fstream>
#include<algorithm>
#include<unordered_map>
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include<vector>
#include<bitset>
#ifndef DISSERTATION_BRENTCOMPONENT_H
#define DISSERTATION_BRENTCOMPONENT_H
typedef uint16_t  index;
typedef int16_t literal;

//Functions and structs


struct ContainsLiteral{
    static uint16_t counter;
};

struct BrentComponentIndex {
    uint16_t first;
    uint16_t second;
    friend std::ostream &operator<<( std::ostream &output, BrentComponentIndex& i) {
        output << "(" << i.first << "," << i.second << ")"
               << " ";
        return output;
    }

};


//*alpha*.*beta*.*gamma*
struct BrentComponent : ContainsLiteral{
    uint16_t productNumber;
    BrentComponentIndex index;
    literal literal;
    BrentComponent(uint16_t& productNumber, BrentComponentIndex& index);
    friend std::ostream &operator<<( std::ostream &output, BrentComponent& bc) {
        output << "(" << bc.productNumber << ")" << bc.index.first <<"," <<bc.index.second << std::endl;
        return output;
    }
    BrentComponent();
};
// *alpha.beta.gamma*
struct BrentExpression{
    BrentExpression(const BrentComponent& alpha,const BrentComponent& beta,const BrentComponent& gamma);
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
/*
struct S_Variable : ContainsLiteral{
    BrentComponent alpha;
    BrentComponent beta;
    literal literal;
    S_Variable(BrentComponent& a, BrentComponent& b);
    S_Variable();

};
*/



struct T_Variable : ContainsLiteral{
    BrentComponent A;
    BrentComponent B;
    BrentComponent G;
    literal literal;
    T_Variable(BrentComponent& A,BrentComponent& B, BrentComponent& G);


};

struct T_VariableHolder : ContainsLiteral {
    std::vector<T_Variable> holder = {};
    literal literal;
    T_VariableHolder();
};
bool processRHS(Delta);



void createOddNumberOfCombinations(std::ostream& outputFileOdd,uint16_t numberOfMultiplications);
void createEvenNumberOfCombinations(std::ostream& outputFileEven,uint16_t numberOfMultiplications);

#endif //DISSERTATION_BRENTCOMPONENT_H
