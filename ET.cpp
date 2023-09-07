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
const int maxN = 1e5 + 5;
int n, m, deg[maxN], par[maxN];
vector<pair<int, int>> adj[maxN];
bool visited[maxN];
void make_set()
{
    for (int i = 1; i <= n; ++i) par[i] = i;
}
int find_set(int v)
{
    return v != par[v] ? par[v] = find_set(par[v]) : v;
}
void Union(int u, int v)
{
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    par[u] = v;
}
list<int> find_Euler(int u)
{
    list<int> res;
    res.push_back(u);
    while (!adj[u].empty()) {
        auto [v, id] = adj[u].back();
        adj[u].pop_back();
        if (visited[id]) continue;
        visited[id] = true;
        u = v;
        res.push_back(u);
    }
    for (auto it = ++res.begin(); it != res.end(); it++) {
        list<int> tmp = find_Euler((*it));
        tmp.pop_back();
        res.splice(it, tmp);
    }
    return res;
}
void findPath()
{
    int st = 1, deg_odd = 0;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() & 1) ++deg_odd;
    }
    if (deg_odd != 0) {
        cout << "NO\n";
        return;
    }
    list<int> path = find_Euler(1);
    cout << "YES\n";
    for (auto it = path.begin(); it != path.end(); it++) cout << (*it) - 1 << ' ';
}
signed main() {
    #define TASK "ET"
        if (fopen(TASK ".inp", "r")) {
            freopen(TASK ".inp", "r", stdin);
            freopen(TASK ".out", "w", stdout);
        }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    make_set();
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++u;
        ++v;
        Union(u, v);
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        deg[u]++;
        deg[v]++;
    }
    int cur = find_set(1);
    for (int i = 2; i <= n; ++i) {
        if (find_set(i) != cur) {
            cout << "NO\n";
            return 0;
        }
    }
    findPath();
    return 0;
}




