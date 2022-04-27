# Csc212-Final-Project
# String Search Algorithms- Plagiarism Checker 
# Authors: Ben Keeler, David Nitschke, Thomas Holmes 
This project is an implementation of three string search algorithms. The naive method, Knuth-Morris-Pratt, and Boyer-Moore. The program takes in two command line arguments which will both be text files. It breaks up the second text file into sentences and the user picks what algorithm they would like to use to see how many sentences from the second file match with the first file. Based on how many match, it will output either: "High levels of plagiarism (Greater than or equal to 80 percent of sentences matched)", or "Moderate levels of plagiarism (In between 40 and 79 percent of sentences matched)", or "Low levels of plagiarism (Less than 40 percent of sentences matched)". The algorithms were constructed in their own separate classes which end up getting called throughout the program. It also includes a word search feature that allows the user to search for a word in both of the files to see if it is present. 
# Dependencies
In order to compile and execute this code you must include all .cpp files and two text files for the command line arguments. 
(You can use the two .txt files provided to see an example where all the sentences match)
