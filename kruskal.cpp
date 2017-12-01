/* kruskal */
const int MAXN = 1e5+5;
int parent[MAXN], n, m;
pair<ll, pair<int, int> > table[MAXN];	// table stores <ll, pair of ints>, weight and in between what n the edge is. 
// table[i] = {weight, {x, y}};
void init(){
	for(int i = 1;i <= n; i++){
		parent[i] = i;
	}
}

int root(int x){
	while(parent[x] != x){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void union1(int x, int y){
	int root_a = root(x);
	int root_b = root(y);
	parent[root_a] = root_b;
}

ll kruskal(){
	ll minCost = 0;
	for(int i = 0;i < m; i++){
		int x = table[i].second.first;
		int y = table[i].second.second;
		ll cost = table[i].first;
		//check if the selected edge makes a cycle or not.
		if(root(x) != root(y)){
			minCost += cost;
			union1(x, y);
		}
	}
	return minCost;
}