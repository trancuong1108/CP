#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define NAME "Bai"
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r)
{
    return l + (abs(1ll * rd() * rd()) % (r - l + 1));
}
ll RAND(ll l, ll r)
{
    return l + ((ll) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll) rand()) % (r - l + 1);
}
const int maxN= 1e5 + 2;
int par[maxN];
int find(int v)
{
    return v != par[v] ? par[v] = find(par[v]) : v;
}
char a[1005][1005];
pair<int, int> p[100];
int mark[1005][1005];
ll f[maxN];
string s[maxN];
void init()
{
    for (int i = 0; i < maxN; ++i) par[i] = i;
}
void MakeTest()
{
    ofstream cout (NAME".INP");
    srand(time(0));
    int n = Rand(70, 100), m = Rand(50, 100), q = 1;
    cout << n << ' ' << m << ' ' << q << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = char(Rand('A', 'Z'));
        }
    }
    int k = Rand(1, 5);
    for (int i = 1; i <= k; ++i) {
        int u = Rand(1, n);
        int v = Rand(1, m);
        a[u][v] = '*';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    for (int i = 1; i <= q; ++i) {
        int u = Rand(1, n);
        int v = Rand(1, m);
        cout << u << ' ' << v << '\n';
    }
}
int main()
{
    int N = 1e5;
    for (int i = 1; i <= 1; i++) {
        MakeTest();
//        system(NAME".exe < "NAME".INP > "NAME".OUT");
//        system(NAME"_trau.exe < "NAME".INP > "NAME".ANS");
//        if (system("fc "NAME".OUT "NAME".ANS") != 0) {
//            cerr << "Test " << i << ": " << "WRONG!\n";
//            return 0;
//        }
//        cerr << "Test " << i << ": " << "CORRECT!\n";
    }
    return 0;
}
