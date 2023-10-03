#include<bits/stdc++.h>
#define ll long long
#define bit(mask, i) ((mask >> i) & 1)
using namespace std;
template<typename T>
void __print(T &x) {cerr << x;}
template<typename T>
void __print(vector<T> &V) {cerr << "{"; for (int i = 0; i < V.size() - 1; ++i) {cerr << V[i] << ", ";} cerr << V.back(); cerr << "}";}
template<typename T>
void _print(T t) {__print(t);}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "\e[91m" << "[In "<<__func__<<"() : line " <<__LINE__<<" ] : [" << #x << "] = ["; _print(x); cerr << "]\e[39m" << endl;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 5;

signed main() {
    #define TASK ""
        if (fopen(TASK ".inp", "r")) {
            freopen(TASK ".inp", "r", stdin);
            freopen(TASK ".out", "w", stdout);
        }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    return 0;
}



