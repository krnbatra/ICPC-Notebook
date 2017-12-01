/* articulation_points */
const int MAXN = 1e4+5;
vector<int> adj[MAXN];
bool vis[MAXN], AP[MAXN];
int n, m, currTime;
int disc[MAXN];
int low[MAXN];  // low[i] is the minimum of visited currTime of all vertices which are reachable from i.
vector<pair<int, int> > bridges;

void init(){
    currTime = 0;
    for(int i = 1;i <= n; i++){adj[i].clear();vis[i]=false;AP[i]=false;disc[i]=0;low[i]=INT_MAX;}
}

// dfs(1, -1)
void dfs(int u, int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime+1;  //since till now i have not explored the children of u all i know is the lowest numbered vertex which can be reached from u is u itself.
    int child = 0;
    for(auto v : adj[u]){
        if(v == parent)     continue;
        if(!vis[v]){
            child = child+1;
            currTime++;
            dfs(v, u);
            //check if subtree rooted at v has a connection to one of the ancestors of u.
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){
                if(u < v)
                    bridges.push_back({u, v});
                else
                    bridges.push_back({v, u});
            }
            if(parent == -1 && child > 1)
                AP[u] = true;
            
            if(parent != -1 && low[v] >= disc[u])
                AP[u] = true;
        }else{
            // back edge.
            low[u] = min(low[u], disc[v]);
        }
    }
}