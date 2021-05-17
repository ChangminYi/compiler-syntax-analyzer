#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define CFG_LEN 38

typedef struct Transition {
    string lhs, rhs;
};

vector<Transition> LoadCFG(string file_name);