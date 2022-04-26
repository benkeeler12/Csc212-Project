#ifndef naive_h
#define naive_h
#include <iostream>
#include <vector>
#include <string>




class Naive {

     private:
     std:: vector <std::string> sentenceVector;
     std:: string text;

     public:
          Naive(std::vector<std::string> sentenceVector, std::string text);
          int naiveSearch(std::string text, std::string pattern);


  #endif
 };