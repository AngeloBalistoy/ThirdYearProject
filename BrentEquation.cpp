
#include<string>
#include<iostream>
static std::string brentEquationComponent(int i,int j, int k, int l, int m, int n, int T) {
  const std::string coefficients = "ABC";
  std::string component = "";
  for(int coefficientCounter = 0; coefficientCounter < coefficients.length(); coefficientCounter++) {
    component += coefficients[coefficientCounter];
    component += std::to_string(T);
    if (coefficientCounter == 0) {
      component += std::to_string(i) + std::to_string(j);
    }
    else if (coefficientCounter == 1) {
      component += std::to_string(k) + std::to_string(l);
    }
    else {
      component += std::to_string(m) + std::to_string(n);
    }
  }
  return component;

}


static std::string brentEquation(int iterations, int matrixSize) {
  std::string output = "";
  for(int i=1; i <= matrixSize; i++) {
    for(int j=1; j <= matrixSize; j++) {
      for(int k=1; k <= matrixSize; k++) {
        for(int l=1; l <= matrixSize; l++) {
          for(int m=1; m <= matrixSize; m++) {
            for(int n=1; n <= matrixSize; n++) {
              for(int T = 1; T <= iterations; T++) {
                output += brentEquationComponent(i,j,k,l,m,n,T);
                output += "\n";
              }
            }
          }
        }
      }
    }

  }
  return output;
}

