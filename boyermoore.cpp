#include <iostream>
#include <string>
#include <vector>
#include "boyermoore.h"

BoyerMoore::BoyerMoore(std::vector<std::string> sentenceVector, std::string text){
    this->sentenceVector = sentenceVector;
    this->text = text;
     double test = 0;
    for (int i = 0; i < sentenceVector.size(); i++){
        int total = boyerSearch(text, sentenceVector[i]);
        if (total > 0){
            test++;
        }
    }
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

int BoyerMoore::boyerSearch(std::string text, std::string pattern){
    int count = 0;
    int p = pattern.size();
    int t = text.size();
    int badchar[256];

    std::fill(badchar, badchar + 256, -1);
    for (int i = 0; i < t; i++){
        badchar[(int) text[i]] = i;
    }

    int s = 0;
    while(s <= (t - p)){
            int pointer = p - 1;
            while(pointer >= 0 && pattern[pointer] == text[s + pointer]){
                pointer--;
            }
            if (pointer < 0){
                count++;
		if (s + pointer < t){
		    s += std::max(1, pointer - badchar[text[s + pointer]] 
);
                }
                s++;

            }
            else{
                //
                s += std::max(1, pointer - badchar[text[s + pointer]] );

            }
    }
    return count;
}

