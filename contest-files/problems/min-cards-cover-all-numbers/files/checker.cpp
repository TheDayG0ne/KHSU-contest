#include "testlib.h"
#include <bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;

auto readResult(auto &in, const int n) {
    int m = in.readInt(1, n, "m");
    auto v = in.readInts(m, 1, n, "v");
    return v;
}

bool check(const vector<int> &a, const vector<int> &b, const vector<int> &v) {
    int n = size(a);
    
    set<int> u;
    for(int i : v) {
        u.insert(a[i-1]);
        u.insert(b[i-1]);
    }
    
    return size(u) == n;
}

int main(int argc, char* argv[]){
    setName("checker");
    registerTestlibCmd(argc, argv);
	
    int n = inf.readInt();
    auto a = inf.readInts(n);
    auto b = inf.readInts(n);
    
    auto result = readResult(ouf, n);
    auto answer = readResult(ans, n);
    
    quitif(!check(a, b, result), _wa, "not all numbers covered");
    
    quitif(size(result) > size(answer), _wa, "result is not minimal");
    quitif(size(result) < size(answer), _fail, "result is minimal O_o");
    
    quitf(_ok, "OK");

    return 0;
}
