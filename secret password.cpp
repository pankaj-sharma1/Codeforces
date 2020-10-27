#include<bits/stdc++.h>
using namespace std;
typedef long long           ll;
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

ll max(ll a, ll b) {return (a > b ? a : b);}
ll min(ll a, ll b) {return (a < b ? a : b);}

int n, edges;
vector<vector<int>> graph;
vector<int> vis;
void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void init() {
    graph = vector<vector<int>>(n + 30);
    vis = vector<int>(n + 30, 0);
}
void dfs(int x) {
    vis[x] = 1;
    for (auto i : graph[x]) {
        if (!vis[i]) dfs(i);
    }
}
void solve_test() {
    cin >> n;
    init();
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (char c : s) {
            addEdge(i, c - 'a' + n);
            cnt[c - 'a' + n]++;
        }
    }
    ll ans = 0;
    for (int i = n; i < n + 26; i++) {
        if (cnt[i] == 0) continue;
        if (vis[i] == 0) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << "\n";
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    solve_test();
    return 0;
}
