/* lca */
const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;

int n;
vector<int> adj[MAXN];
int level[MAXN], par[MAXN][LG];

void dfs(int u, int parent = -1){
	par[u][0] = parent;
	if(parent + 1)
		level[u] = level[parent] + 1;
	for(int i = 1; i < LG; i++){
		if(par[u][i-1] != -1)
			par[u][i] = par[par[u][i-1]][i-1];
    }
	for(auto v : adj[u]){
		if(v == parent)	continue;
		dfs(v, u);
	}
}

int lca(int u, int v){
	if(level[u] < level[v])	swap(u, v);
	int log = log2(level[u]);
	for(int i = log; i >= 0; i--)
		if(level[u]-level[v] >= (1 << i))
			u = par[u][i];
	if(u == v)
		return u;
	for(int i = log; i >= 0; i--){
		if(par[u][i] != -1 && par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int kth(int n, int k){
	int log = log2(level[n]);
	for(int i = 0; i <= log; i++){
		if(k & (1 << i))
			n = par[n][i];
	}
	return n;
}