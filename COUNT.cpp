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
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    subtask2();
    return 0;
}



