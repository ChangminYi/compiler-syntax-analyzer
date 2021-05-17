#include <iostream>
#include "cfg_loader.h"
#include "table_loader.h"
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
	vector<Transition> cfg = LoadCFG(cfg_table_name);
	list<Token> token_input = getInput(input_file_name);


	/* flow
	stack<int> stk;
	int current = 0;
	stk.push(current);
	Token toSee = token_input.front();
	token_input.pop_front();
	while(!list.empty() && !stack.empty()){
		if(parse_table[current][token_to_terminal(toSee)] == accepted){
			cout << "Accepted.\n";
			break;
		}
		else if(parse_table[current][token_to_terminal(toSee)] == shift){
			current = parse_table[token_to_terminal(toSee)].shiftState;
			stk.push(current);
			toSee = token_input.front();
			token_input.pop_front();
		}
		else if(parse_table[current][token_to_terminal(toSee)] == reduce){
			reduce(parse_table[current].reduce_value);
			for(sizeof(reduce_value)){
				stk.pop();
			}
			current = parse_table[nonterminal_to_cfg()];
			stk.push(current);
		}
		else{
			cerr << "Invalid Syntax: ~~~\n";
			exit(-1);
		}
	}
	*/

	return 0;
}