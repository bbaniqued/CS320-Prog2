#include <stdlib.h>
#include <vector>
#include <string>

class Parser {

    public:

        Parser();
        ~Parser();
        bool Parse(std::vector<std::string> *input);
} ;
