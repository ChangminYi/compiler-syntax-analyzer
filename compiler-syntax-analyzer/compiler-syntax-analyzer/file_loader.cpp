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

// vector<pair<string, string>> LoadCFG(string file_name) {
// 	vecotr<pair<string, string>> 
// }