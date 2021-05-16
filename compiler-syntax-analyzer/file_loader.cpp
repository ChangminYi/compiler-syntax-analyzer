#include "file_loader.h"

vector<vector<int>> LoadTransitionTable() {
	vector<vector<int>> table(ROW, vector<int>(COL));
	ifstream table_file("SLR_parsing_table.txt");
	
	if (table_file.is_open()) {
		for (vector<int> &i : table) {
			for (int &j : i) {
				table_file >> j;
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

vecto