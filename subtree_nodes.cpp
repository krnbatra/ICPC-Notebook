/* subtree nodes */
int n, a, b;
vector<int> adj[MAX];
vector<int> discovery;
int start[MAX], end[MAX];
static int tim = 0;

void dfs(int s, int p){
	discovery.pb(s);
	tim++;
	start[s] = tim;

	forc(adj[s], it){
		if(*it != p)
			dfs(*it, s);
	}
	end[s] = tim;
}

int main(int argc, char const *argv[])
{
  discovery.pb(-1);
  dfs(1, -1); 
  return 0;
} 