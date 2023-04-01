#include "testlib.h"
#include <stdio.h>
#include <bits/stdc++.h>
#define endl '\n'
#define ALL(c) begin(c), end(c)
#define fun(T, name, ...) function<T(__VA_ARGS__)> name = [&](__VA_ARGS__)->T

using namespace std;
using ll = long long;

const int LIM = 1e4;

set<int> get_opt(string key) {
	string s = opt<string>(key);
	set<int> ok;
	for(char c : s) ok.insert(c - '0');
	return ok;
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int it = 1;
	
	const int n = opt<int>("n");
	
	auto oks = vector {
		get_opt("a"),
		get_opt("b"),
		get_opt("c")
	};
	
	auto ok = [](int x, auto &&s) {
		return s.count(x%6) != 0;
	};
	
	vector<vector<int>> a(3);
	
	for(int k=0; k<3; ++k) {
		auto &v = a[k];
		int sz = n - rnd.next(0, 10);
		for(int i=0; i<sz; ++i){
			int x;
			do x = rnd.next(1, LIM); while(!ok(x, oks[k]));
			v.push_back(x);
		}
	}
	
	
	
	for(auto &v : a) {
		println(size(v), v);
	}
	
	
	return 0;
}
