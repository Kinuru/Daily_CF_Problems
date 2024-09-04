#include<bits/stdc++.h>
#define L(i, l, r) for(int i = l; i <= r; i ++)
#define R(i, l, r) for(int i = l; i >= r; i --)
#define fi first
#define se second
#define ll long long
#define ld long double
#define vi vector <int>
#define vl vector <long long> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll n, m, k; cin >> n >> m >> k;
    ll s = (n - 1) + (m - 1);

    if(k > s){
        cout << -1 << endl;
        return 0;
    }
    if(n > m) swap(n, m);

    ll l = max(0ll, k + 1 - m);
    ll r = min(k, n - 1);

    ll ans = 0;
    ans = (n / (l + 1)) * (m / (k - l + 1));
    ans = max(ans, (n / (r + 1)) * (m / (k - r + 1)));

    cout << ans << endl;

    return 0;
}
