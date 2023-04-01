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
	
	int T = 0;
	vector<int> ans(n, 0);
	while(!empty(p)) {
		sort(bb(p), [&](int i, int j) {
			return f[i].first < f[j].first;
		});
		
		bool fl = 0;
		for(int k=0; k+1<size(p); ++k) {
			int i = p[k], j = p[k+1];
			if(f[i].first == f[j].first) {
				ans[i] = ans[j] = T;
				p.erase(begin(p) + k, begin(p) + k + 2);
				fl = 1;
				break;
			}
		}
		if(fl) continue;
		
		if(f[p[0]].second == -1) {
			p.erase(begin(p));
			continue;
		}
		if(f[p.back()].second == +1) {
			p.pop_back();
			continue;
		}
		
		int dt = inf<int>;
		for(int k=0; k+1<size(p); ++k) {
			int i = p[k], j = p[k+1];
			if(f[i].second == +1 && f[j].second == -1) {
				umin(dt, f[j].first - f[i].first);
			}
		}
		
		int add = (dt + 1) / 2;
		for(int i : p) f[i].first += add * f[i].second;
		T += add;
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
