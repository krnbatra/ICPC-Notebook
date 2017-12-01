/* toposort */
const int MAXN = 1e5+5;
bool vis[MAXN];
int n, in_degree[MAXN];
vector<int> adj[MAXN], topo;

void topoSort(){
    for(int u = 1; u <= n; u++)
        for(auto v : adj[u])
            indegree[v]++;
    set<int> S;
    for(int i = 1;i <= n; i++){
        if(in_degree[i] == 0){
            S.insert(i);
            vis[i] = true;
        }
    }
    while(!S.empty()){
        int curr = *(S.begin());
        S.erase(S.begin());
        topo.push_back(curr);
        for(auto v : adj[curr]){
            if(!vis[v]){
                indegree[v]--;
                if(indegree[v] == 0){
                    S.insert(v);    
                    vis[v] = 1;
                }
            }
        }
    }
}
