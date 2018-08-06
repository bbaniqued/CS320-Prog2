#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Tokenizer{
	public:
		vector<string> *tokens;
		int lines;
		int outputCounter;
		Tokenizer();
		~Tokenizer();
		void Tokenize(string input);
		vector<string> GetTokens();
};
