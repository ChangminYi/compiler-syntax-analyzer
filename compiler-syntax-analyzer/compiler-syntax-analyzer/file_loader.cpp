#include "file_loader.h"

vector<map<string, string>> LoadParsingTable(string file_name) {
	vector<map<string, string>> table(ROW);
	ifstream table_file(file_name);
	
	if (table_file.is_open()) {
		for (map<string, string> &tmap : table) {
			string temp;
			for(int i = 0; i < COL; ++i){
				table_file >> temp;
				tmap[state[i]] = temp;
			}
		}
	}
	else {
		cerr << "there is no SLR_parsing_table.txt in directory" << '\n';
		exit(-1);
	}
	
	table_file.close();
	return table;
}

vector<Transition> LoadCFG(string file_name) {
	vector<Transition> cfg(CFG_LEN);
	ifstream cfg_file(file_name);
	
	if (cfg_file.is_open()) {
		string temp;
		for (Transition &c : cfg) {
			getline(cfg_file, temp);
			int arrow_idx = temp.find('→');
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