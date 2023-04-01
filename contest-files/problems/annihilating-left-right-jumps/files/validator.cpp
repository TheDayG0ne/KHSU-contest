#include "testlib.h"
#include <bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using ll = long long;
using namespace std;

const int A = 1e9;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
	
	int n = inf.readInt(1, 1e5, "n");
	inf.readEoln();
	
	set<int> ux;
	for(int i=0; i<n; ++i) {
		int x = inf.readInt(1, A, "xi");
		inf.readSpace();
		int d = inf.readInt(-1, 1, "di");
		inf.readEoln();
		
		ensuref(d == 1 || d == -1, "d can be +1 or -1 only");
		ensuref(ux.count(x) == 0, "x must uniqie");
		ux.insert(x);
	}
	
	inf.readEof();
	
	
    return 0;
}
