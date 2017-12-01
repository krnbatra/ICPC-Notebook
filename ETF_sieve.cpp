/* ETF Sieve */
const int MAXN = (int)1e6+5;
ll phi[MAXN+1];

void ETF_sieve(){
	for(int i = 1; i <= MAXN; i++)
		phi[i] = i;
	
	for(int i = 2; i <= MAXN; i++){
		if(phi[i] == i){
			for(int j = i; j <= MAXN; j += i){
				phi[j] /= i;
				phi[j] *= (i-1);
			}
		}
	}
}
