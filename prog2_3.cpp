#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "prog2_3.hpp"
#include <cctype>
#include <stdlib.h>
#include <climits>
#include <vector>



using namespace std;

Parser::Parser() {

}

Parser::~Parser() {

}

bool Parser::Parse(vector<string> *input) {	//takes in string vector and checks for predetermined tokens
	if(input->at(0) == "push" || input->at(0) == "save" || input->at(0) == "get") {
		if(input->size() == 3) {
			if(strtol(input->at(1).c_str(),NULL,0) < LONG_MAX && strtol(input->at(1).c_str(),NULL,0) > LONG_MIN) {
				return true;
			}
		}
	}

	if(input->size() == 2) {
		if(input->at(0) == "pop" || input->at(0) == "add" || input->at(0) == "sub" || input->at(0) == "mul" || input->at(0) == "div" || input->at(0) == "mod" || input->at(0) == "skip") {
			return true;
		}
	}
	return false;
}