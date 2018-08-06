#include "prog2_1.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char*argv[])
{
	cout << "Assignment #2-2, Brandon Baniqued, brandon.baniqued@gmail.com" << endl;
	ifstream input;
	int line = 1;
	string current;
	Tokenizer* tokenizer = new Tokenizer();
	input.open(argv[1],std::ifstream::in);

	try {
		while(getline(input,current)) {
			tokenizer->Tokenize(current);
			line++;
		}
	}
	catch(const std::runtime_error& e) {
		cout << "Error on line " << line << ": " << e.what() << endl;
		return 0;
	}

	vector<string> output;
	vector<string> occur;
	string formatter;
	int currentLine = 1;

	while(currentLine < line) {
		occur = tokenizer->GetTokens();
		formatter.append(occur.at(0));
		for(int i = 1; i < occur.size() - 1; i++) {
			formatter.append("," + occur.at(i));
		}
		output.push_back(formatter);
		formatter = "";
		currentLine++;
	}

	for(int i = 0;i<output.size();i++) {
		cout << output.at(i) << endl;
	}

	return 1;

}