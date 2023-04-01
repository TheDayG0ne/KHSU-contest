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
	
	const int t = opt<int>("t"); //type of ans
	
	int M{}, D{}, A{}, B{};
	
	auto gen = [&] { return rnd.next(1, LIM); };
	auto divs = [&](int n) {
		set<int> d;
		for(int i=1; i*i <= n; ++i) if(n %i == 0) {
			d.insert(i);
			if(i*i < n) d.insert(n / i);
		}
		d.erase(n);
		return vector<int>(begin(d), end(d));
	};
	
	if(t == 0) { 
		//a == b
		A = B = gen();
	} else
	if(t == 1) {
		//a == 0
		A = 0;
		B = gen();
	} else
	if(t == 2) {
		//b == 0
		A = gen();
		B = 0;
	} else
	if(t == 3) {
		//a % b == 0
		for(;;) {
			A = gen();
			if(auto d = divs(A); !empty(d) &&  size(d) > 5) {
				B = rnd.any(d);
				break;
			}
		}
	} else
	if(t == 4) {
		//b % a == 0
		for(;;) {
			B = gen();
			if(auto d = divs(B); !empty(d) &&  size(d) > 5) {
				A = rnd.any(d);
				break;
			}
		}
	} else {
		//else
		do {
			A = gen();
			B = gen();
		} while(A % B == 0 ||  B % A == 0);
	}
	
	const int cmp = opt<int>("cmp"); //M cmp D
	
	for(;;) {
		M = gen();
		D = cmp ? gen() : M;
		if(M == D && cmp == 0) break;
		if(M < D && cmp < 0) break;
		if(M > D && cmp > 0) break;
	}
	
	println(M, D);
	println(A, B);
	
	return 0;
}
