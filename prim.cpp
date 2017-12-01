/* Prim */
const int MAXN = 1e4+5;
bool vis[MAXN];
int n, m;
vector<pair<ll, int> > adj[MAXN];   // for every vertex store all the edge weight and the adjacent vertex to it
// adj[x].pb({weight, y});
ll prim(int x){
    // start prim from xth vertex
    multiset<pair<int, int> > S;
    ll minCost = 0;
    S.insert({0, x});
    while(!S.empty()){
        pair<int, int> p = *(S.begin());
        S.erase(S.begin());
        x = p.second;
        if(vis[x])
            continue;
        minCost += p.first;
        vis[x] = true;
        for(int i = 0; i < adj[x].size(); i++){
            int y = adj[x][i].second;
            if(!vis[y])
                S.insert(adj[x][i]);
        }
    }
    return minCost;
}