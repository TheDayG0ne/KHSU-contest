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
	const string tp = opt<string>("t"); //type of ans
	
	vector<int> a(n);
	if(tp == "rand") {
		int d = opt<int>("d");
		if(d == 0) {
			iota(ALL(a), 0);
			shuffle(ALL(a));
		} else {
			auto part = rnd.partition(d, n, 1);
			vector<int> s = rnd.perm(n);
			int i = 0;
			for(int sz : part) {
				for(int k=0; k<sz; ++k) {
					int v = s[i + k];
					int t = s[i + (k+1)%sz];
					a[v] = t;
				}
				i += sz;
			}
		}
	}
	
	vector<int> p = rnd.perm(n, 1);
	for(int &x : a) x = p[x];
	
	println(n);
	println(a);
	println(p);
	
	
	return 0;
}
