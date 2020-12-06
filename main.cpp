#include<string>
#include<iostream>
#include "BrentEquation.cpp"
int main() {
  std::string s = brentEquation(23,3);
  std::cout << s;
  return 0;
}