#include <iostream>
#include "file_loader.h"
#include "input_loader.h"
#include "token.h"

using namespace std;

const string parse_table_name = "SLR_parsing_table.txt";
const string cfg_table_name = "ambiguity_fixed_CFG.txt";
const string input_file_name = "test.txt";

int main(/*int argc, char *argv[]*/) {
	//input_file_name = argv[1];

	initRevConvert();

	vector<map<string, string>> parse_table = LoadParsingTable(parse_table_name);
	//vector<Transition> cfg = LoadCFG(cfg_table_name);
	list<Token> temp = getInput(input_file_name);

	for (Token &t : temp) {
		cout << t;
	}

	return 0;
}