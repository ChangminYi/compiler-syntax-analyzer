#include "table_loader.h"

vector<unordered_map<string, string>> LoadParsingTable(string file_name) {
	vector<unordered_map<string, string>> table(ROW);
	ifstream table_file(file_name);
	
	if (table_file.is_open()) {
		for (unordered_map<string, string> &tmap : table) {
			string temp;
			for(int i = 0; i < COL; ++i){
				table_file >> temp;
				tmap[symbol[i]] = temp;
			}
		}
	}
	else {
		cerr << "there is no SLR_parsing_table.txt in directory.\n";
		exit(-1);
	}
	
	table_file.close();
	return table;
}