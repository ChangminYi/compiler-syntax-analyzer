#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define CFG_LEN 39

typedef struct Transition {
    string lhs;
    int rhs_len;
};

vector<Transition> LoadCFG(string file_name);