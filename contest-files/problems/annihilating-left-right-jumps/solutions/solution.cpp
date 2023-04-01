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
#define bb(c) begin(c), end(c)
#define ff(T, name, args...) function<T(args)> name = [&](args)->T
#define jj(v...) v; [](auto&...x){(cin>>...>>x);}(v);
#define ii(v...) int jj(v)
using ll = long long;


void run_case(const size_t ____case) { // rr(____case)
	ii(n)
	
	vector<pair<int,int>> f(n);
	for(int i=0; i<n; ++i) {
		ii(x, d)
		f[i] = {x, d};
	}
	
	vector<int> p(n);
	iota(bb(p), 0);
	sort(bb(p), [&](int i, int j) {
		return f[i].first < f[j].first;
	});
	
	array<vector<int>, 2> st{};
	vector<int> ans(n, 0);
	for(int i : p) {
		auto [x, d] = f[i];
		auto &s = st[x%2];
		if(d < 0) {
			if(!empty(s)) {
				int j = s.back();
				s.pop_back();
				ans[i] = ans[j] = (x - f[j].first) / 2;
			}
		} else {
			s.push_back(i);
		}
	}
	
	for(int t : ans) cout << t << endl;
	
}

int main() {
	if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	size_t tn = 1; //cin>>tn;
	for(size_t t=1; t<=tn; ++t) run_case(t);
	
	return 0;
}
