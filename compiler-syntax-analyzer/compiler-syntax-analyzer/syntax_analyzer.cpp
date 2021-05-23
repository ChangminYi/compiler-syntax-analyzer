#include <iostream>
#include <stack>
#include <cctype>
#include "cfg_loader.h"
#include "table_loader.h"
#include "input_loader.h"
#include "token.h"

using namespace std;

const string parse_table_name = "SLR_parsing_table.txt";
const string cfg_table_name = "cfg.txt";

int main(int argc, char *argv[]) {
	string input_file_name = argv[1];
	if (argc != 2) {
		cerr << "Not acceptible parameters.\n";
		exit(-1);
	}

	initRevConvert();
	vector<unordered_map<string, string>> parse_table = LoadParsingTable(parse_table_name);
	vector<Transition> cfg = LoadCFG(cfg_table_name);
	list<Token> token_input = getInput(input_file_name);

	int line_cnt = 1;
	stack<int> state_stack;
	state_stack.push(0);
	string next_symbol = tokenToTerminal(token_input.front());

	while(!state_stack.empty()){
		string act = parse_table[state_stack.top()][next_symbol];
		Transition transition;
		int new_state = 0;

		if (isdigit(act.front())) {
			new_state = stoi(act);
			state_stack.push(new_state);
			next_symbol = tokenToTerminal(token_input.front());
		}
		else {
			switch (act.front()) {
			case 's':
				line_cnt++;
				token_input.pop_front();
				next_symbol = tokenToTerminal(token_input.front());
				new_state = stoi(act.substr(1));
				state_stack.push(new_state);
				break;
			case 'r':
				transition = cfg[stoi(act.substr(1))];
				next_symbol = transition.lhs;
				for (int i = 0; i < transition.rhs_len; ++i) {
					state_stack.pop();
				}
				break;
			case 'e':
				cerr << "Rejected: " << token_input.front() << " ( line: " << line_cnt << " ) is invalid.\n";
				exit(-1);
				break;
			case 'a':
				cout << "Accepted\n";
				while (!state_stack.empty()) { state_stack.pop(); }
				break;
			default:
				cerr << "?????\n";
				exit(-1);
			}
		}
	}

	return 0;
}