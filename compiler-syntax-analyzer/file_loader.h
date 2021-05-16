#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#ifndef FILE_LOADER
#define FILE_LOADER

#define ROW 85
#define COL 39
#define ERROR 'e'

vector<vector<string>> getTransitionTable();

#endif