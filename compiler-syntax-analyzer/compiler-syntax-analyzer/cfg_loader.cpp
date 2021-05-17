#include "cfg_loader.h"

vector<Transition> LoadCFG(string file_name) {
	vector<Transition> cfg(CFG_LEN);
	ifstream cfg_file(file_name);
	
	if (cfg_file.is_open()) {
		string temp;
		for (Transition &c : cfg) {
			getline(cfg_file, temp);
            int arrow_idx = (int)temp.find('=');
			c.lhs = temp.substr(0, arrow_idx);
			c.rhs = temp.substr(arrow_idx + 1);
		}
	}
	else {
		cerr << "there is no cfg file in directory" << '\n';
		exit(-1);
	}
	
	cfg_file.close();
	return cfg;
}