Assignment #1, Brandon Baniqued
Brandon.baniqued@gmail.com
Introductory C++ program
This assignment is designed to familiarize you with C++ programming, tokenizers and parsers.
Contents
6 sub-assignments in total.
* prog2_1.cpp:
Tokenizer class with four public methods. A constructor, destructor, a void function named Tokenize that takes a single string argument, and a vector<string> function named GetTokens. Only valid tokens include push, pop, add, sub, mul, div, mod, skip, save, get, and any valid integer.
* prog2_1.hpp:
A header file that contains the constructor, destructor, Tokenize, and GetTokens.
* prog2_2.cpp:
Driver program that takes a single command line argument which will be the name of a file. The program will Tokenize each line of the file. It will tokenize all the input before an outputting. If any line causes a Tokenization error, an error message will occur and stop processing the file. 
* prog2_3.cpp: 
Parser class will have three public function. A constructor, destructor, and a Boolean function Parse which will take a single<vector> argument. The parse function will validate the input and return true if valid, false otherwise. 
* prog2_3.hpp:
A header file that contains the constructor, destructor, and Boolean function Parse.
* prog2_4.cpp:
A driver that tokenizes all the input lines and then parses all of the input lines. All the input is tokenized before any parsing. Tokenization print error is the same as in prog2_2. If a parsing error occurs, the program will print an error and will stop executing. If all input is valid, it will be printed line by line with commas separating tokens.


