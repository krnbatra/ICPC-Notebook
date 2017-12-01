/* sparse table */
const int MAXN = 1e5+5;
const int LG = log2(MAXN) + 1;
int sparse_table[LG][MAXN];
int A[MAXN];
int n;

// <O(NlogN), O(1)>
// query O(1) only for idempotent functions, otherwise O(log(n))

void preprocess(){
    // storing index of the minimum element
    for(int i = 0; i < n; i++)
        sparse_table[0][i] = i;
    for(int j = 1; j < LG; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++){
            if(A[sparse_table[j-1][i]] < A[sparse_table[j-1][i + (1 << (j-1))]])
                sparse_table[j][i] = sparse_table[j-1][i];
            else
                sparse_table[j][i] = sparse_table[j-1][i + (1 << (j-1))];
        }
    }
}

int query(int left, int right){
    int range = right - left + 1;
    int k = log2(range);
    return min(A[sparse_table[k][left]], A[sparse_table[k][right - (1 << k) + 1]]);
}
int main(){
    preprocess();
}