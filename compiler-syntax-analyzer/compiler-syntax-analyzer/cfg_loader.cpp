#include "cfg_loader.h"

vector<Transition> LoadCFG(string file_name) {
	vector<Transition> cfg(CFG_LEN);
	ifstream cfg_file(file_name);
	
	if (cfg_file.is_open()) {
		string temp;
		for (Transition &c : cfg) {
			cfg_file >> temp;
			c.lhs = temp;
			cfg_file >> temp;
			c.rhs_len = stoi(temp);
		}
	}
	else {
		cerr << "there is no cfg file in directory" << '\n';
		exit(-1);
	}
	
	cfg_file.close();
	return cfg;
}