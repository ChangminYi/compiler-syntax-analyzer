#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "input_loader.h"

void ltrim(string &origin, char del) {
	uint32_t startpoint = origin.find_first_not_of(del);
	origin.erase(0, startpoint);
}

void rtrim(string &origin, char del) {
	uint32_t endpoint = origin.find_last_not_of(del);
	origin.erase(endpoint + 1, origin.size() - endpoint + 1);
}

void trim(string &origin, char del_left, char del_right) {
	rtrim(origin, del_right);
	ltrim(origin, del_left);
}

void trim(string &origin, char del) {
	trim(origin, del, del);
}

list<Token> getInput(const string input_file_name) {
	list<Token> res;
	
	ifstream i_file = ifstream(input_file_name);
	if (i_file.is_open()) {
		string temp, strBuf;
		
		while (!i_file.eof()) {
			vector<string> split_temp;
			istringstream temp_s;

			getline(i_file, temp);
			if (!temp.empty()) {
				//형식 체크
				if (temp.front() == '<' && temp.back() == '>') {
					//문자열 꺾쇠 제거
					trim(temp, '<', '>');
					temp_s = istringstream(temp);

					//문자열 공백 제거 및 토큰 분류
					while (getline(temp_s, strBuf, ',')) {
						trim(strBuf, ' ');
						split_temp.push_back(strBuf);
					}

					Token toPush;
					if (split_temp.size() == 1) {
						toPush = Token(revConvert(split_temp.front()));
					}
					else {
						toPush = Token(revConvert(split_temp.front()), split_temp[1]);
					}

					res.push_back(toPush);
				}
				else {
					cerr << "input file is corrupted.\n";
					exit(-1);
				}
			}
		}
		
		i_file.close();
	}
	else {
		cerr << "there is no input file.\n";
		exit(-1);
	}

	return res;
}
