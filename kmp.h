#ifndef KMP_h
#define KMP_h
#include <iostream>
#include <vector>
#include <string>


class KMP {

     private:
          //Vector of strings containing all the sentences from second file 
          std:: vector <std::string> sentenceVector; 
          //Text string which is the entire first file in one string 
          std:: string text;
          //Function to set up pre preprocessing vector 
          void findPrefix(std::string pattern, std::vector <int> &prefixArray);


     public:
          //Constructor to begin function calls and output results 
          KMP(std:: vector<std::string> sentenceVector, std::string text);
          //KMP search function which locates any sentences that match 
          int kmpSearch(std::string text, std::string pattern);


  #endif
 };