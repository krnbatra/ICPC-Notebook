/* edmond karp */
const int MAXN = 1e3+5;
vector<int> adj[MAXN];
int residual[MAXN][MAXN], from[MAXN], n;
bool vis[MAXN];

int find_path(int src, int dest){
    memset(vis, false, sizeof vis);
    memset(from, -1, sizeof from);
    queue<int> Q;
    Q.push(src);
    vis[src] = true;
    bool done = false;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(auto v : adj[u]){
            if(!vis[v] && residual[u][v] > 0){
                Q.push(v);
                vis[v] = true;
                from[v] = u;
                if(v == dest){
                    done = true;
                    break;
                }
            }
        }
        if(done)    break;
    }
    // find min from path
    int current = dest, path_capacity = INT_MAX;
    while(from[current] != -1){
        int parent = from[current];
        path_capacity = min(path_capacity, residual[parent][current]);
        current = parent;
    }
    // update residual
    current = dest;
    while(from[current] != -1){
        int parent = from[current];
        residual[parent][current] -= path_capacity;
        residual[current][parent] += path_capacity;
        current = parent;
    }
    if(path_capacity == INT_MAX)
        return 0;
    return path_capacity;
}

int max_flow(){
    int res = 0;
    while(1){
        int path_capacity = find_path(1, n);
        if(path_capacity == 0)
            break;
        res += path_capacity;
    }
    return res;
}