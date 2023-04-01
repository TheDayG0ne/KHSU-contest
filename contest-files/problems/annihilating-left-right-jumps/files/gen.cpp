#include "testlib.h"
#include <stdio.h>
#include <bits/stdc++.h>
#define endl '\n'
#define ALL(c) begin(c), end(c)
#define fun(T, name, ...) function<T(__VA_ARGS__)> name = [&](__VA_ARGS__)->T

using namespace std;
using ll = long long;

const int LIM = 1e9;


int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int it = 1;
	
	const int n = opt<int>("n");
	const string str = opt<string>("t");
	
	
	vector<pair<int,int>> f(n);
	vector<int> xs = rnd.distinct(n, 1, LIM);
	
	if(str == "rand") {
		int i = 0;
		for(auto &[x, d] : f) {
			x = xs[i++];
			do d = rnd.next(-1, 1); while(d == 0);
		}
	} else
	if(str == "spec1") {
		sort(ALL(xs));
		for(int i=0; i<n; ++i) {
			f[i].first = xs[i];
			f[i].second = i%2 ? -1 : +1;
		}
	} else
	if(str == "spec2") {
		sort(ALL(xs));
		for(int i=0; i<n; ++i) {
			f[i].first = xs[i];
			f[i].second = i < n/2 ? +1 : -1;
		}
	}
	
	shuffle(ALL(f));
	
	println(n);
	for(auto [x, d] : f) println(x, d);
	
	
	return 0;
}
