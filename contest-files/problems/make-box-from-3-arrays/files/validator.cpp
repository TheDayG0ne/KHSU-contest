#include "testlib.h"
#include <bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using ll = long long;
using namespace std;

const int A = 1e9;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
	
	
	for(int k=0; k<3; ++k) {
		int n = inf.readInt(1, 3e4, "n");
		inf.readSpace();
		inf.readInts(n, 1, 1e4, "ai");
		inf.readEoln();
	}
		
	
	inf.readEof();
	
	
    return 0;
}
