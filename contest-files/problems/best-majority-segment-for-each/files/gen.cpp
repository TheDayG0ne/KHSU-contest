#include "testlib.h"
#include <stdio.h>
#include <bits/stdc++.h>
#define endl '\n'
#define ALL(c) begin(c), end(c)
#define fun(T, name, ...) function<T(__VA_ARGS__)> name = [&](__VA_ARGS__)->T

using namespace std;
using ll = long long;

const int A = 1e9;

vector<int> gg(int n) {
	deque<int> v = {rnd.next(1, A)};
	while(size(v)*2+1 <= n) {
		int x = rnd.next(1, A);
		int s = size(v) + 1;
		for(int i=0; i<s/2; ++i) {
			v.push_back(x);
			v.push_front(x);
		}
	}
	return {ALL(v)};
}

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int it = 1;
	
	const int n = opt<int>("n");
	string str = opt<string>("t");
	
	vector<int> a;
	
	if(str == "rand") {
		int d = opt<int>("d");
		vector<int> nums = rnd.distinct(d, 1, A);
		for(int i=0; i<n; ++i) a.push_back(rnd.any(nums));
	} else
	if(str == "rand2") {
		while(size(a) < n) {
			int rem = n - size(a);
			int cnt = rnd.next(1, rem);
			int x = rnd.next(1, A);
			while(cnt--) a.push_back(x);
		}
		shuffle(ALL(a));
	} else
	if(str == "dx") {
		int f = A / 2;
		for(int i=0; i<n; ++i) {
			a.push_back(f);
			f += rnd.next(-1, 1);
		}
	} else
	if(str == "spec1") {
		while(size(a) != n) {
			auto v = gg(n - size(a));
			a.insert(end(a), ALL(v));
		}
	}
	
	cout << size(a) << endl;
	println(a);
	
	
	return 0;
}
