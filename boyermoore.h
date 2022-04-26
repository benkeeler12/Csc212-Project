#ifndef boyermoore_h
#define boyermoore_h
#include <iostream>
#include <vector>
#include <string>




class BoyerMoore {
     
    private:
     std:: vector <std::string> sentenceVector;
     std:: string text;

     public:
          BoyerMoore(std::vector<std::string> sentenceVector, std::string text);
          int boyerSearch(std::string text, std::string pattern);


  #endif
 };