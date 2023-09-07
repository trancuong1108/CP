#include<bits/stdc++.h>
#define ll long long
#define TASK "COUNT"
#define bit(mask, i) ((mask >> i) & 1)
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 5e4;
int n, m, a[maxN], par[maxN], sz[maxN];
bool mark[maxN];
int pos[maxN];
void make_set()
{
    for (int i = 1; i < maxN; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
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
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}
void subtask1()
{
    make_set();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((a[i] & a[j]) == 0) Union(i, j);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int u = find_set(i);
        if (!mark[u]) {
            ++cnt;
            mark[u] = true;
        }
    }
    cout << cnt;
}
void subtask2()
{
    make_set();
    for (int i = 1; i <= n; ++i) pos[a[i]] = i;
    for (int mask = 0; mask < (1 << m); ++mask) {
        for (int submask = mask; submask; submask = (submask - 1) & mask) {
            int cur = (mask ^ submask);
            int i = pos[submask];
            int j = pos[cur];
            if (j == 0 || i == 0) continue;
            Union(i, j);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int u = find_set(i);
        if (!mark[u]) {
            ++cnt;
            mark[u] = true;
        }
    }
    cout << cnt;
}
void dfs(int u)
{
    if (mark[u]) return;
    mark[u] = true;
    for (int i = 0; i < m; ++i) {
        if (bit(u, i) && !mark[u ^ (1 << i)]) dfs(u ^ (1 << i));
    }
    if (pos[u]) dfs(((1 << m) - 1) ^ u);
}
void subtask3()
{
    for (int i = 1; i <= n; ++i) pos[a[i]] = i;
    int res = 0;
    int mask = (1 << m) - 1;
    for (int i = 1; i <= n; ++i) {
        if (!mark[a[i]]) {
            ++res;
            dfs(mask ^ a[i]);
        }
    }
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("COUNT.INP", "r", stdin);
    freopen("COUNT.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n <= 1000 && m <= 20) subtask1();
    else if (m <= 15) subtask2();
    else subtask3();
    return 0;
}



