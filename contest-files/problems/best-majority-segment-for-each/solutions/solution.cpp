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
	
	map<int, vector<int>> pos;
	for(int i=0; i<n; ++i) {
		ii(x)
		pos[x].push_back(i);
	}
	
	for(auto &[x, p] : pos) {
		int ans = 0;
		auto upd = [&](int i, int j) {
			int len = p[j] - p[i] + 1;
			int cnt = j - i + 1;
			int ex = cnt * 2 - len - 1;
			if(ex < 0) return ;
			umax(ans, min(n, len + ex));
		};
		
		//fix i:
		//(j-i+1)*2 > p[j]-p[i]+1
		//2j - p[j] + 2 > 2i - p[i] + 1
		//2j - p[j] >= 2i - p[i]
		//need max j
		
		//pair(2j-p[j], j) sorted by first
		vector<pair<int, int>> q;
		
		for(int i=size(p); i--; ) {
			int fi = 2*i - p[i];
			if(empty(q) || q.back().first < fi) {
				q.emplace_back(fi, i);
			}
			auto it = partition_point(bb(q), [&](auto &&e) {
				return e.first < fi;
			});
			upd(i, it->second);
		}
		
		cout << x << ' ' << ans << endl;
	}
	
}
 
int main() {
	if(auto f="in.txt"; fopen(f,"r") && freopen(f,"r",stdin));
	cin.tie(0)->sync_with_stdio(0);
	
	size_t tn = 1; //cin>>tn;
	for(size_t t=1; t<=tn; ++t) run_case(t);
	
	return 0;
}
