#include<bits/stdc++.h>
using namespace std;
typedef long long           ll;
#define all(x) (x).begin(), (x).end()
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...);
}

ll max(ll a, ll b) {return (a > b ? a : b);}
ll min(ll a, ll b) {return (a < b ? a : b);}
const ll mod =  998244353;
const ll MAXN = 3e5 + 5;
ll fac[MAXN], inverse[MAXN];

ll nCr(ll n, ll k)
{
  if (k < 0 || k > n) {
    return 0;
  }
  ll ans = fac[n];
  ans = (ans * inverse[n - k]) % mod;
  ans = (ans * inverse[k]) % mod;

  return ans;
}
ll power(ll a, ll b)
{
  ll res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }

  return res;
}
ll numberOfWays(vector<pair<ll, ll> > lines,
                ll K, ll N)
{
  sort(all(lines));
  ll total_case = nCr(N, K);
  multiset<ll> m;
  for (ll i = 0; i < N; i++) {

    while (!m.empty()
           && (*m.begin() < lines[i].first)) {
      m.erase(m.begin());
    }
    total_case -= nCr(m.size(), K - 1);
    total_case += mod;
    total_case %= mod;
    m.insert(lines[i].second);
  }

  return total_case;
}
void preCompute()
{
  ll fact = 1;

  fac[0] = 1;
  inverse[0] = 1;

  for (ll i = 1; i < MAXN; i++) {

    fact = (fact * i) % mod;
    fac[i] = fact;
    inverse[i] = power(fac[i], mod - 2);
  }
}
void test_case() {
  ll ans = 0;
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> lines(n);

  for (int i = 0; i < n; i++)
    cin >> lines[i].first >> lines[i].second;
  ans = nCr(n, k) - numberOfWays(lines, k, n);
  ans += mod;
  ans %= mod;
  cout << ans << "\n";
}
int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  preCompute();
  test_case();
  return 0;
}
