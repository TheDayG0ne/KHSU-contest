#include<bits/stdc++.h>
using namespace std;
template<class T, T Q=2> constexpr T inf = numeric_limits<T>::max() / Q - 1;
template<class T,class S=T>inline bool umin(T&m,S&&x){return x<m?m=x,1:0;}
template<class T,class S=T>inline bool umax(T&m,S&&x){return m<x?m=x,1:0;}
auto operator<<(ostream&o,auto&&v)->enable_if_t<!is_constructible_v<string,decltype(v)>,decltype(o<<*end(v))>{int f=0,u=&o!=&cerr;o<<"["+u;for(auto&&x:v)(f++?o<<", "+u:o)<<x;return o<<"]"+u;}
auto operator<<(ostream&o,auto&&t)->decltype(o<<get<0>(t)){int f=0,u=&o!=&cerr;o<<"<"+u;apply([&](auto&...x){(((f++?o<<", "+u:o)<<x),...);},t);return o<<">"+u;}
#ifdef BIZON
	#define rr(v...) [](auto&&...x){ cerr << boolalpha << "\e[1;38;5;68m" << #v << " "; int _=0; ((cerr<<"\e[0;38;5;61m"<<",="[!_++]<<"\e[0m "<<x),...)<<endl; }(v);
#else
	#define rr(...) ;
	#define endl '\n'
#endif
#define p2(c) begin(c), end(c)
#define f1(T, name, args...) function<T(args)> name = [&](args)->T
#define p1(v...) v; [](auto&...x){(cin>>...>>x);}(v);
#define pt1(v...) int p1(v)
using ll = long long;


void run_case(const size_t ____case) { // rr(____case)
	pt1(n)
	vector<int> a(n);
	for(auto &it : a) cin >> it;
	vector<int> b(n);
	for(auto &it : b) cin >> it;
	
	vector<pair<int,int>> nx(n+1);
	for(int i=0; i<n; ++i) {
		nx[a[i]] = {b[i], i};
	}
	
	vector<int> out1, u(n+1);
	int cn = 0;
	for(int i=1; i<=n; ++i) if(!u[i]) {
	    ++cn;
		vector<int> cur;
		for(int x=i; ;) {
			u[x] = 1;
			cur.push_back(nx[x].second);
			x = nx[x].first;
			if(u[x]) break;
		}
		for(int k=0; k<size(cur); k+=2) out1.push_back(cur[k] + 1);
	}
	cerr << "cycs: " << cn << endl;
	
	cout << size(out1) << endl;
	cout << out1 << endl;
	
}

int main() {
	if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	size_t tn = 1; //cin>>tn;
	for(size_t t=1; t<=tn; ++t) run_case(t);
	
	return 0;
}
