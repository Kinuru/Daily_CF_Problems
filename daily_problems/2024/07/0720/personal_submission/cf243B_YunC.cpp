signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // int T; cin >> T; while(T --) solve();
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }

    ll ans = 100, ok = 0;
    // if n > 10 || m > 10: case1 (bf)
    auto case1 = [&]() -> void {
        ll res = 100;        
        if(n > 10){
            for(int i = 1; i <= n; i ++){
                ll sum = 0;
                for(int r = 1; r <= n; r ++){
                    if(r == i) continue;
                    ll cnt = 0;
                    for(int c = 1; c <= m; c ++){
                        if(a[r][c] == a[i][c]) cnt ++;
                    }
                    sum += min(m - cnt, cnt);
                    if(sum > k) break;
                }
                if(sum <= k) res = min(res, sum);
            }
        }else{
            for(int i = 1; i <= m; i ++){
                ll sum = 0;
                for(int c = 1; c <= m; c ++){
                    if(c == i) continue;
                    ll cnt = 0;
                    for(int r = 1; r <= n; r ++){
                        if(a[r][c] == a[r][i]) cnt ++;
                    }
                    sum += min(n - cnt, cnt);
                    if(sum > k) break;
                }
                if(sum <= k) res = min(res, sum);
            }
        }
        if(res <= k) ans = res, ok = 1;
    };
    if(n > 10 || m > 10){
        case1();
    }
    // n <= 10 && m <= 10 : case2 (dp)
    auto case2 = [&]() -> void {
        ll up = (1ll << m) - 1;
        vector<int> dp(up + 1, 100);

        int start = 0;
        for(int i = 1; i <= m; i ++){
            if(a[1][i] == 1) start += 1ll << (i - 1);
        }
        for(int i = 0; i <= up; i ++){
            int cnt = 0;
            for(int p = 0; p < m; p ++){
                if( ((i >> p) & 1) == ((start >> p) & 1) ) cnt ++;
            }
            dp[i] = min(dp[i], min(cnt, m - cnt));
        }
        for(int s = 0; s < up; s ++){
            ll res = dp[s];

            for(int i = 2; i <= n; i ++){
                ll cur = 0, cnt = 0;
                for(int j = 1; j <= m; j ++){
                    if(a[i][j]) cur += 1ll << (j - 1);
                }
                for(int p = 0; p < m; p ++){
                    if( ((s >> p) & 1) == ((cur >> p) & 1) ) cnt ++;
                }
                res += min(cnt, m - cnt);
                if(res > k) break;
            }
            if(res <= k){
                ans = min(ans, res);
                ok  = 1;
            }
        }
    };
    if(n <= 10 && m <= 10){
        case2();
    }

    cout << (ok ? ans : -1) << endl;

    return 0;
}
