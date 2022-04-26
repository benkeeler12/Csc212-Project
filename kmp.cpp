#include "kmp.h"
#include <iostream>
#include <string>
#include <vector>




//Constructor to set the two variables and initiate function calls

KMP::KMP(std:: vector<std::string> sentenceVector, std::string text){
    this->sentenceVector = sentenceVector;
    this->text = text;
    double test = 0; 
    // For loop to check every sentence against the first file using kmp function
    for (int i = 0; i < sentenceVector.size(); i++){
        int total = kmpSearch(text, sentenceVector[i]);
        if (total > 0){
            test++; 
        }
    }
    
    // plagiarism detection code 
    std:: cout << test << "/" << sentenceVector.size() << " sentences have matched between the documents! " << std:: endl; 
    if(test/sentenceVector.size() >= 0.8){
        std:: cout << "High levels of plagiarism (Greater than or equal to 80 percent of sentences matched)" << std:: endl; 
    }
    if(test/sentenceVector.size() < 0.8 && test/sentenceVector.size() >= 0.4){
        std:: cout << "Moderate levels of plagiarism (Inbetween 40 and 79 percent of sentences matched)" << std:: endl; 
    }
    if(test/sentenceVector.size() < 0.4){
        std:: cout << "Low levels of plagiarism (Less than 40 percent of sentences matched)" << std:: endl; 
    }

}

// Function used to set the longest prefix suffix vector
void KMP::findPrefix(std::string pattern, std::vector <int> &prefixVector){
    // Declare first iterator
    int j = 0;
    //First spot in prefix vector is always zero
    prefixVector[0] = 0;

    //for loop to traverse through pattern to store the length of the longest proper prefix that is also a suffix in the pattern.
    //the length gets stored in the vector

    for (int i = 1; i < pattern.length(); i++){

        if (pattern[i] == pattern[j]){
            j++;
            prefixVector[i] = j;
        }
        else if (j != 0){

                j = prefixVector[j-1];
                i--;
        }
            else{
                prefixVector[i] = 0;
           }
     }
}




// Function used to compare the two strings and locate any instances of the pattern in the text
int KMP::kmpSearch(std::string text, std::string pattern){
    //Set prefix vector
    std::vector <int> prefixVector(pattern.length());
    //Call function to fill the vector with the right values
    findPrefix(pattern, prefixVector);
    // Declare counter to keep track of how many patterns are found in the string
    int count = 0;
    //Declare i and j to make the comparisons between the pattern and the main string
    int i = 0;
    int j = 0;

    while(i < text.length()){
        if (pattern[j] == text[i]){  //If there is a match, continue.
            i++;
            j++;
        }
        if (j == pattern.length()){
     // std::cout << "Pattern found at index: " << i - pattern.length() << ' ' << std:: endl;
     //if j is equal to the pattern's length then we have a match and increment the counter of total matches.
            count++;
            j = prefixVector[j-1];
        }

        else if(i < text.length() && pattern[j] != text[i]){    // If there is a mismatch set j equal to prefixVector to see if skips are possible

            if(j == 0){        // if j becomes zero, increment i
                i++;
            }
            else{
                j = prefixVector[j-1];
            }
        }

    }
     return count; 



}