signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // int T; cin >> T; while(T --) solve();

    int n, m; cin >> n >> m;
    int S, T; cin >> S >> T;

    int inf = 1e9;
    vector<int> dis1(n + 1, inf), dis2(n + 1, inf);
    vector<vector<int>> g(n + 1);

    for(int i = 1; i <= m; i ++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    dis1[S] = 0, q.push(S);

    while(!q.empty()){
        auto t = q.front(); q.pop();

        for(auto v : g[t]){
            if(dis1[v] > dis1[t] + 1){
                dis1[v] = dis1[t] + 1;
                q.push(v);
            }
        }
    }

    dis2[T] = 0, q.push(T);
    while(!q.empty()){
        auto t = q.front(); q.pop();

        for(auto v : g[t]){
            if(dis2[v] > dis2[t] + 1){
                dis2[v] = dis2[t] + 1;
                q.push(v);
            }
        }
    }

    int target = dis1[T], ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            if(min(dis1[i] + dis2[j], dis1[j] + dis2[i]) + 1 >= target) 
                ans ++;
        }
    }
    cout << ans - m << endl;

    return 0;
}
