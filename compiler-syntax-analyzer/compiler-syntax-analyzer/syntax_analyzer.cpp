#include <iostream>
#include <stack>
#include "cfg_loader.h"
#include "table_loader.h"
#include "input_loader.h"
#include "token.h"

using namespace std;

const string parse_table_name = "SLR_parsing_table.txt";
const string cfg_table_name = "cfg.txt";
const string input_file_name = "test.txt";

int main(/*int argc, char *argv[]*/) {
	//input_file_name = argv[1];

	initRevConvert();

	vector<unordered_map<string, string>> parse_table = LoadParsingTable(parse_table_name);
	vector<Transition> cfg = LoadCFG(cfg_table_name);
	list<Token> token_input = getInput(input_file_name);

	stack<int> state_stack;
	state_stack.push(0);
	string next_symbol;
	next_symbol = tokenToTerminal(token_input.front());
	token_input.pop_front();

	while(!token_input.empty() && !state_stack.empty()){
		string act = parse_table[state_stack.top()][next_symbol];

		if (act[0] == 's') {
			next_symbol = tokenToTerminal(token_input.front());
			token_input.pop_front();
			int new_state = stoi(act.substr(1));
			state_stack.push(new_state);
		}
		else if (act[0] == 'r') {
			Transition transition = cfg[stoi(act.substr(1))];
			next_symbol = transition.lhs;
			for(int i = 0; i < transition.rhs_len; ++i){
				state_stack.pop();
			}
		}
		else if (act[0] == 'e') {
			cerr << "Rejected\n"; // why? where?
			exit(-1);
		}
		else if (act == "acc") {
			cout << "Accepted\n";
		}
		else {
			int new_state = stoi(act);
			state_stack.push(new_state);
		}
	}

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