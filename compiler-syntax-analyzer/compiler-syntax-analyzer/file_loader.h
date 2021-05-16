#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "cfg.h"

using namespace std;

#ifndef FILE_LOADER
#define FILE_LOADER

#define ROW 85
#define COL 39
#define CFG_LEN 38
#define ERROR 'e'

vector<map<string, string>> LoadParsingTable(string file_name);
vector<Transition> LoadCFG(string file_name);

#endif