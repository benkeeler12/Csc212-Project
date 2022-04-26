#include "naive.h"
#include <iostream> 
#include <string> 
#include <vector>

Naive::Naive(std::vector<std::string> sentenceVector, std::string text){
    this->sentenceVector = sentenceVector;
    this->text = text;
    
    double test = 0; 
    for (int i = 0; i < sentenceVector.size(); i++){
        int total = naiveSearch(text, sentenceVector[i]);
        if (total > 0){
            test++; 
        }
    }
    std:: cout << test << "/" << sentenceVector.size() << " sentences have matched between the documents! " << std:: endl; 
     if(test/sentenceVector.size() >= 0.7){
        std:: cout << "High levels of plagiarism (Greater than or equal to 70 percent of sentences matched)" << std:: endl; 
    }
     if(test/sentenceVector.size() < 0.7 && test/sentenceVector.size() >= 0.3){
        std:: cout << "Moderate levels of plagiarism (Inbetween 30 and 69 percent of sentences matched)" << std:: endl; 
    }
     if(test/sentenceVector.size() < 0.3){
        std:: cout << "Low levels of plagiarism (Less than 30 percent of sentences matched)" << std:: endl; 
    }
}

int Naive::naiveSearch(std::string text, std::string pattern) { 

  int count = 0; 
  //length of text string stored in n
  int n = text.length();
  //length of pattern string stored in m 
  int m = pattern.length(); 
  int i,j;
  //Loop for text
  for (i = 0; i <= n-m; i++) 
  { 
    //Loop for pattern
    for (j = 0; j < m; j++) 
    {
      if (text[i+j]!= pattern[j]) 
        break; 
    }
   //if j==pattern length means pattern found
    if (j == m) {
//      std::cout <<"Pattern found at index "<< i << std::endl; 
      count++;
    }
  }
  
//  std:: cout << "Total number of matches: " << count << std:: endl; 
   return count; 
} 

