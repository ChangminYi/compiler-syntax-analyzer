#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "input_loader.h"

list<Token> getInput(const string input_file_name) {
	list<Token> inp;
	
	ifstream i_file = ifstream(input_file_name);
	if (i_file.is_open()) {
		string temp;
		
		while (!i_file.eof()) {
			vector<string> split_temp;
			istringstream temp_s;
			string strBuf;

			getline(i_file, temp);
			if (!temp.empty()) {
				//문자열 꺾쇠 제거
				if (temp.front() == '<' && temp.back() == '>') {
					temp = temp.substr(1, temp.size() - 2);
					temp_s = istringstream(temp);

					//문자열 공백 제거
					while (getline(temp_s, strBuf, ',')) {
						while (strBuf.front() == ' ') {
							strBuf = strBuf.substr(1);
						}
						while (strBuf.back() == ' ') {
							strBuf = strBuf.substr(0, strBuf.size() - 1);
						}
						split_temp.push_back(strBuf);
					}

					Token toPush;
					if (split_temp.size() == 1) {
						toPush = Token(revConvert(split_temp.front()), "");
					}
					else {
						toPush = Token(revConvert(split_temp.front()), split_temp[1]);
					}

					inp.push_back(toPush);
				}
				else {
					cerr << "input file is corrupted." << '\n';
					exit(-1);
				}
			}
		}
		
		i_file.close();
	}
	else {
		cerr << "there is no input file." << '\n';
		exit(-1);
	}

	return inp;
}
