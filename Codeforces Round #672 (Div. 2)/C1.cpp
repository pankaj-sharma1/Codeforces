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

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;

  ll ans = 0;
  cin >> t; while (t--) {
    ll n, q;
    cin >> n >> q;
    ans = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    if (n == 2) {
      ans = max(a[0], a[1]);
      cout << ans << "\n";
      continue;
    }
    ll cur_sign = 1;
    if (n == 1) {
      cout << a[0] << '\n';
      continue;
    }
    if (a[0] > a[1]) {
      ans += a[0];
      cur_sign *= -1;
    }
    for (int i = 1; i < n - 1; i++)
    {
      if (cur_sign > 0) {
        if ((a[i] > a[i - 1]) and (a[i] > a[i + 1]))
        {

          ans += a[i];
          cur_sign *= -1;
        }
      }
      else {
        if ((a[i] < a[i + 1]) and (a[i] < a[i - 1]))
        {
          cur_sign *= - 1;
          ans -= a[i];
        }
      }
    }
    if (cur_sign == 1)
      ans += a[n - 1];


    cout << ans << "\n";

  }
  return 0;
}
