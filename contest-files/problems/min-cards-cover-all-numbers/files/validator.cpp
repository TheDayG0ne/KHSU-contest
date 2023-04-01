#include "testlib.h"
#include <bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using ll = long long;
using namespace std;


bool is_perm(vector<int> v) {
	sort(begin(v), end(v));
	for(int i=0; i<size(v); ++i) if(v[i] != i+1) return false;
	return true;
}

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
	
	
	int n = inf.readInt(1, 1e5, "n");
	inf.readEoln();
	
	auto a = inf.readInts(n, 1, n, "a");
	inf.readEoln();
	auto b = inf.readInts(n, 1, n, "b");
	inf.readEoln();
	
	ensuref(is_perm(a), "a is not permutation");
	ensuref(is_perm(b), "b is not permutation");
	
	
	inf.readEof();
	
	
    return 0;
}
