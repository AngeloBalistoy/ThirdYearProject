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
    for (index i = 1; i <= matrixSize; i++) {
        for (index j = 1; j <= matrixSize; j++) {
            for (index k = 1; k <= matrixSize; k++) {
                for (index l = 1; l <= matrixSize; l++) {
                    for (index m = 1; m <= matrixSize; m++) {
                        for (index n = 1; n <= matrixSize; n++) {
                            //Produce every combination of rightHandSide (d(i,j)*d(k,l)*d(m,n))
                            BrentComponentIndex index1 = {j, k};
                            BrentComponentIndex index2 = {i, m};
                            BrentComponentIndex index3 = {l, n};
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
                                BrentComponent alpha(productNumber, index1);
                                BrentComponent beta(productNumber, index2);
                                BrentComponent gamma(productNumber, index3);
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
            T_Variable t = T_Variable(be.alpha,be.beta,be.gamma);
            t_Variables.push_back(t);
        }

        leftHandSideAsTVariables.push_back(t_Variables);
        t_Variables.clear();
    }

    std::vector<std::vector<bool>> oddCombinations{};


    std::ofstream outputFileEven("negative.txt");
    std::ofstream outputFileOdd("negative2.txt");
    createOddNumberOfCombinations(outputFileOdd, numberOfMultiplications);
    createEvenNumberOfCombinations(outputFileEven, numberOfMultiplications);


    std::cout << "Opening Files now" << std::endl;
    std::ifstream evenFile;
    std::ifstream oddFile;
    evenFile.open("negative.txt");
    oddFile.open("negative2.txt");
    std::string s;
    std::vector<std::vector<bool> > even = {};
    std::vector<std::vector<bool> > odd = {};
    if (evenFile.is_open()) {
        while (std::getline(evenFile, s)) {
            std::vector<bool> clause = {};
            for (auto value : s) {
                if (value == '0') {
                    clause.push_back(0);
                } else if (value == '1') {
                    clause.push_back(1);
                }
            }
            even.push_back(clause);

        }
    }
    std::cout << "Opening Odd Files now" << std::endl;
    if (oddFile.is_open()) {
        while (std::getline(oddFile, s)) {
            std::vector<bool> clause = {};
            for (auto value : s) {
                if (value == '0') {
                    clause.push_back(0);
                } else if (value == '1') {
                    clause.push_back(1);
                }
            }
            odd.push_back(clause);

        }
    }

    std::vector<int> literalLine = {};
    std::vector<std::vector<int> > literalLineHolder = {};

    for (auto x : leftHandSideAsTVariables) {
        for (auto y : x) {
            literalLine.push_back(y.literal);
        }
        literalLineHolder.push_back(literalLine);
        literalLine.clear();

    }
    std::cout << "Constructing Output now" << std::endl << literalLineHolder.size() << std::endl;

    std::ofstream outputFile("C:\\cygwin\\bin\\input.in");
    outputFile << "p cnf " << literalLineHolder.size() * literalLineHolder.at(0).size() * 4 << " "
               << even.size() * literalLineHolder.size() +
                  4 * leftHandSideAsTVariables.size() * leftHandSideAsTVariables.at(0).size() << std::endl;
    for (int i = 0; i < literalLineHolder.size(); i++) {
        bool equationIsOdd = processRHS(rightHandSide.at(i));
        std::vector<int> currentClauseLine = literalLineHolder.at(i);
        if (equationIsOdd) {
            for (auto oddLine : odd) {
                for (int i = 0; i < currentClauseLine.size(); i++) {
                    int literalToPush = oddLine.at(i) ? -currentClauseLine.at(i) : currentClauseLine.at(i);
                    outputFile << literalToPush << " ";
                }
                outputFile << "0" << std::endl;
            }
        } else {
            for (auto evenLine : even) {
                for (int i = 0; i < currentClauseLine.size(); i++) {
                    int literalToPush = evenLine.at(i) ? -currentClauseLine.at(i) : currentClauseLine.at(i);
                    outputFile << literalToPush << " ";
                }
                outputFile << "0" << std::endl;
            }
        }


    }

    for (int i = 0; i < leftHandSideAsTVariables.size(); i++) {
        for (int j = 0; j < leftHandSideAsTVariables.at(i).size(); j++) {
            T_Variable t = leftHandSideAsTVariables.at(i).at(j);
            literal tLiteral = t.literal;
            literal alphaLit = t.A.literal;
            literal betaLit = t.B.literal;
            literal gammaLit = t.G.literal;

            outputFile << -alphaLit << " " << -betaLit << " " << -gammaLit << " " << tLiteral << " 0" << std::endl;
            outputFile << -tLiteral << " " << alphaLit << " 0" << std::endl;
            outputFile << -tLiteral << " " << betaLit << " 0" << std::endl;
            outputFile << -tLiteral << " " << gammaLit << " 0" << std::endl;


        }
    }


}
