#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "kmp.h"
#include "boyermoore.h"
#include "naive.h"


// Function to read a text file and return a single string of the elements
std::string ReadFile(std::string file_name);
// Function to initiate the classess and the plagiarism check between the two documents
void writeText(std::vector <std::string> sentenceVector, std::string answer);
// Function for the word search in the text documents
int searchVect(std::vector<std::string> wordVector, std::string word);




int main(int argc, char** argv){

// Set up command line arguments
    std::string fname = argv[1];
    std::string fname2 = argv[2];
    std::string answer = ReadFile(fname);
    std::string sentence = ReadFile(fname2);

    //BREAK UP SECOND FILE INTO SENTENCES AND STORES THEM INTO VECTOR 
    char seperator = '.';
    std::vector <std::string> sentenceVector;
    std::stringstream streamData(sentence);
    std::string val;
    while(std::getline(streamData, val, seperator)){
        sentenceVector.push_back(val);
    }

    // BREAKS UP THE SECOND FILE INTO WORDS AND STORES THEM INTO VECTOR TO CHECK IF THE WORD IS PRESENT IN THE FILE
    char space = ' ';
    std::vector<std::string> wordVector;
    std::stringstream data(sentence);
    std::string word;
    while(std::getline(data, word, space)){
        wordVector.push_back(word);
    }

    // BREAKS UP THE FIRST FILE INTO WORDS AND STORES THEM INTO VECTOR TO CHECK IF THE WORD IS PRESENT IN THE FILE
    char spaceTwo = ' ';
    std::vector<std::string> wordVectorTwo;
    std::stringstream dataTwo(answer);
    std::string secondWord;
    while(std::getline(dataTwo, secondWord, spaceTwo)){
        wordVectorTwo.push_back(secondWord);
    }

    // WORD SEARCH CODE 
    std::string searchWord;
    std::cout << "What word would you like to search for (From the second file): " << std:: endl;
    std::cin >> searchWord;
    int checkForword = searchVect(wordVector, searchWord);
    if(checkForword > 0) {
        std:: cout << "The word was found!" << std:: endl;
    }
    else {
        std:: cout << "The word was not found." << std:: endl;
    }

    std:: cout << "Would you like to search for a word from the first file? " << std:: endl;
    int answerThree;
    std:: cout << "1. YES" << std:: endl;
    std:: cout << "2. NO" << std:: endl;
    std:: cin >> answerThree;
    if(answerThree == 1){
        std:: string wordThree;
        std:: cout << "What word would you like to search for: " << std:: endl;
        std:: cin >> wordThree;
        int checkForwordTwo = searchVect(wordVectorTwo, wordThree);
        if(checkForwordTwo > 0) {
        std:: cout << "The word was found!" << std:: endl;
    }
    else {
        std:: cout << "The word was not found." << std:: endl;
    }

    }

    //  INITIATE PLAGIARISM PROGRAM
     writeText(sentenceVector, answer);
}


std::string ReadFile(std::string file_name){
    // Create the input filestream - opens the file & prepares it for reading
   std::ifstream input_file(file_name);

   // Returns the text file into one string
   return std::string(std::istreambuf_iterator<char>(input_file), std::istreambuf_iterator<char>());

}


void writeText(std::vector<std::string> sentenceVector, std::string answer){
    bool running = true;
    int ans, num;

    while(running){
        std::cout << "STRING SEARCH ALGORITHMS" << std:: endl;

        std::cout << "1. Naive" << std:: endl;
        std::cout << "2. Knuth-Morris-Pratt" << std:: endl;
        std::cout << "3. Boyer-Moore"<< std:: endl;

        std::cout << "Enter a number to use the corresponding algorithm (For the plagiarism check): ";
        std::cin >> num;


        if (num == 1){
            Naive basic = Naive(sentenceVector, answer);
            std::cout << "Continue?" << std::endl;
            std::cout << "1. YES" << std::endl;
            std::cout << "2. NO" << std::endl;
            std::cin >> ans;
            if (ans == 2){
                   running = false;
            }
        }

        else if (num == 2){
            KMP check = KMP(sentenceVector, answer);
            std::cout << "Continue?" << std::endl;
            std::cout << "1. YES" << std::endl;
            std::cout << "2. NO" << std::endl;
            std::cin >> ans;
            if (ans == 2){
                running = false;
            }
        }


        else if (num == 3){
            BoyerMoore moore = BoyerMoore(sentenceVector, answer);
            std::cout << "Continue?" << std::endl;
            std::cout << "1. YES" << std::endl;
            std::cout << "2. NO" << std::endl;
            std::cin >> ans;
            if (ans == 2){
                running = false;
            }
        }
        else{
                std::cout << "Invalid number, please try again." << std::endl;
            }

    }
}



int searchVect(std::vector<std::string> wordVector, std::string word){

    int isPresent = 0;

    for (int i = 0; i < wordVector.size(); i++){

        if (word == wordVector[i]){
            isPresent++;

        }
    }
    return isPresent;
}



