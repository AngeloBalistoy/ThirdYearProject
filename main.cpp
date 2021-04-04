#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include<vector>
#include<bitset>

#include "BrentComponent.h"
//add typedef for indices


int main(int argc, char *argv[]) {
    //Holding all the variables and expressions
    std::vector<Delta> rightHandSide;
    std::vector<BrentExpression> brentComponents;
    std::vector<std::vector<BrentExpression> > leftHandSide;
    std::vector<bool> RHSasBool;
    std::vector<uint16_t> literals;
    std::vector<std::vector<uint16_t> > firstOrder;
    std::vector<T_Variable> t_Variables;
    std::vector<std::vector<T_Variable> > leftHandSideAsTVariables;


    if (argc != 3) {
        std::cout << "Not a valid input." << std::endl;
        return -1;
    }
    //Rename?
    uint16_t numberOfMultiplications = atoi(argv[1]);
    uint16_t matrixSize = atoi(argv[2]);

    //Left Hand Side Deltas
    for (index i = 0; i < matrixSize; i++) {
        for (index j = 0; j < matrixSize; j++) {
            for (index k = 0; k < matrixSize; k++) {
                for (index l = 0; l < matrixSize; l++) {
                    for (index m = 0; m < matrixSize; m++) {
                        for (index n = 0; n < matrixSize; n++) {
                            //Produce every combination of rightHandSide (d(i,j)*d(k,l)*d(m,n))
                            BrentComponentIndex index1 = {n, i};
                            BrentComponentIndex index2 = {j, k};
                            BrentComponentIndex index3 = {l, m};
                            DeltaComponent d1 = {index1};
                            DeltaComponent d2 = {index2};
                            DeltaComponent d3 = {index3};
                            Delta d = {d1, d2, d3};
                            rightHandSide.push_back(d);
                            //RHS alpha beta gammas
                            for (uint16_t productNumber = 0;
                                 productNumber < numberOfMultiplications; productNumber++) {
                                BrentComponentIndex index1 = {i, j};
                                BrentComponentIndex index2 = {k, l};
                                BrentComponentIndex index3 = {m, n};
                                BrentComponent alpha = {productNumber, index1};
                                BrentComponent beta = {productNumber, index2};
                                BrentComponent gamma = {productNumber, index3};
                                BrentExpression b = BrentExpression(alpha, beta, gamma);
                                brentComponents.push_back(b);
                            }
                            leftHandSide.push_back(brentComponents);
                            brentComponents.clear();
                        }
                    }
                }
            }
        }
    }
    /*
    int counter = 0;
    for (int i = 0; i < rightHandSide.size(); i++) {
        Delta delta = rightHandSide.at(i);
        bool processedDelta = processRHS(delta);
        RHSasBool.push_back(processedDelta);
        if (processedDelta) {counter++;}

    }
     */
    //std::cout << "Number of Trues:" << counter << std::endl << "Size of Vector: " << RHSasBool.size() << std::endl;




    //Test output below
/*
    std::cout << "RHS" << std::endl;
    std::cout << "LHS" << std::endl;
    for (int i = 0; i < leftHandSide.size(); i++) {
        for (int j = 0; j < leftHandSide.at(i).size(); j++) {
            std::cout << leftHandSide.at(i).at(j);
            if (j != leftHandSide.at(i).size() - 1) {
                std::cout << " + ";
            }
        }

        std::cout << " = " << rightHandSide.at(i) << std::endl;
    }
*/
    /*
    //There are matrixSize^2 x numberOfMultiplications * 3 number of base variables. store as a
    for(int i = 1; i <= matrixSize*matrixSize*numberOfMultiplications*3; i++) {
        if (literals.size() == 3) {
            firstOrder.push_back(literals);
            literals.clear();
        }
        literals.push_back(i);
    }
    firstOrder.push_back(literals);
    literals.clear();
    std::cout << firstOrder.size() << std::endl;
    */
    for (int i = 0; i < leftHandSide.size(); i++) {
        for (int j = 0; j < leftHandSide.at(i).size(); j++) {
            BrentExpression be = leftHandSide.at(i).at(j);
            S_Variable s = S_Variable(be.alpha, be.beta);
            T_Variable t = T_Variable(s, be.gamma);
            t_Variables.push_back(t);
        }

        leftHandSideAsTVariables.push_back(t_Variables);
        t_Variables.clear();
    }
    std::vector<std::vector<uint16_t> > tVariableLit;
    for(auto x : leftHandSideAsTVariables) {
        for(auto y : x) {
            std::cout << y.literal << " ";
        }
        std::cout << std::endl;
    }





}
