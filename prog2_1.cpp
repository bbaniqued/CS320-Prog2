#include "prog2_1.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <cctype>
#include <stdexcept>

using namespace std;

Tokenizer::Tokenizer() {
	Tokenizer::tokens = new vector<string>();
	int lines = 0;
	int outputCounter = 0;
}

void Tokenizer::Tokenize(string input) {  
	stringstream oss(input);
	while(!oss.eof())
	{
		string s;
		oss >> s;
		char *isNotNum;
		long numcheck;
		if(!(s == "push" || s == "pop" || s == "add" || s == "sub" || s == "mul" || s == "div" || s == "mod" || s == "skip" || s == "save" || s == "get")) {
				numcheck = strtol(s.c_str(),&isNotNum,0);  
				if(*isNotNum) {
						throw std::runtime_error( "Unexpected token: " + s );
					}
		}
		this->tokens->push_back(s);
	}
	this->tokens->push_back("\n");
	lines++;
}

Tokenizer::~Tokenizer() {   
	delete &lines;
	delete &outputCounter;
}

vector<string> Tokenizer::GetTokens() {  
	vector<string> output;
	if(outputCounter < this->tokens->size()) {
		while((outputCounter < this->tokens->size()) && (this->tokens->at(outputCounter) != "\n")) {
			output.push_back(this->tokens->at(outputCounter));
			outputCounter += 1;
		}
		outputCounter+= 1;
		output.push_back("\n");
		return output;
	}
	throw std::runtime_error( "No tokens" );
}
