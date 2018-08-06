#include "prog2_1.hpp"
#include "prog2_3.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <stdexcept>

using namespace std;

int main(int argc,char* argv[]) {

	cout << "Assignment #2-4, Brandon Baniqued, brandon.baniqued@gmail.com" << endl;
	ifstream input;
	int line = 1;
	string current;
	Tokenizer* tok = new Tokenizer();
	input.open(argv[1],std::ifstream::in);  
	try {
		while(getline(input,current)) {   
			tok->Tokenize(current);
			line++;
		}
	}
	catch(const std::runtime_error& e) {
		cout << "Error on line " << line << ": " << e.what() << endl;
		return 0;
	}

	line = 1;
	vector<string> output;
	vector<string> pcurrent;
	string errout;
	Parser *parser = new Parser();

	while(tok->outputCounter < tok->tokens->size()) {
		pcurrent = tok->GetTokens();
		if (parser->Parse(&pcurrent)) {
			if(pcurrent.size() == 2) {
				output.push_back(pcurrent.at(0));
			}

			if(pcurrent.size() == 3) {
				output.push_back(pcurrent.at(0) + "," + pcurrent.at(1));
			}
			line++;
		}
		else {
			for(int i = 0; i < pcurrent.size(); i++) {
				errout.append(pcurrent.at(i).c_str());
				if(i+1 < pcurrent.size()) {
					errout.append(" ");
				}
			}
			cout << "Parse error on line " << line << ": " << errout;
			return 0;
		}
	}

	for(int i = 0;i<output.size();i++) {
		cout << output.at(i) << endl;
	}

	return 0;

}