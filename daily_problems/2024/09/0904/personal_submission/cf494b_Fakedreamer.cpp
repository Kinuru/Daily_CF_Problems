#include<bits/stdc++.h>
#define L(i, l, r) for(int i = l; i <= r; i ++)
#define R(i, l, r) for(int i = l; i >= r; i --)
#define ll long long
#define fi first
#define se second
#define vi vector <int>
#define vl vector <long long> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
using namespace std;
const ll mod = 1e9 + 7;
vector <int> Zfunc(string S){
    int n = S.size() - 1;
    vector <int> z(n + 1, 0);
    
    z[1] = n;
    int l, r = 0;
    for(int i = 2; i <= n; i ++){
        if(i <= r) z[i] = min(r - i + 1, z[i - l + 1]);
        while(S[1 + z[i]] == S[i + z[i]]) z[i] ++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // int Case; cin >> Case; while(Case --) solve();
    string s, t; cin >> s >> t;
    string S = " " + t + "?" + s;

    s = " " + s, t = " " + t;
    vector <int> z = Zfunc(S);

    int n = sz(s) - 1, m = sz(t) - 1;
    vector <int> pre(n + 1, 0);
    vector <ll>  dp (n + 1, 0), sum(n + 1, 0);
    vector <ll>  ts (n + 1, 0);

    for(int i = 1; i <= n; i ++){
        if(z[i + m + 1] == m){
            pre[i + m - 1] = i + m - 1;
        }
    }

    for(int i = 1; i <= n; i ++){
        if(!pre[i]) pre[i] = pre[i - 1];
        // cout << pre[i] << " \n"[i == n];
    }

    for(int i = 1; i <= n; i ++){
        if(!pre[i]) continue;
        int L = pre[i] - m + 1;
        ts[i]  = ts[i - 1] + sum[i - 1], ts[i] %= mod;
        dp[i] += L + ts[L];

        sum[i] = sum[i - 1] + dp[i], sum[i] %= mod;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++){
        ans += dp[i]; ans %= mod;
        // cout << dp[i] << " \n"[i == n];
    }

    cout << ans << endl;

    return 0;
}
