#include "testlib.h"
#include <bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using ll = long long;
using namespace std;

const int A = 1e9;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
	
	
	inf.readInt(1, A, "M");
	inf.readSpace();
	inf.readInt(1, A, "D");
	inf.readEoln();
	
	inf.readInt(0, A, "A");
	inf.readSpace();
	inf.readInt(0, A, "B");
	inf.readEoln();
		
	
	inf.readEof();
	
	
    return 0;
}
