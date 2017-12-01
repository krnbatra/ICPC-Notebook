/* PU_RQ */
const int MAXN = 1e3+5;
int BIT[MAXN], arr[MAXN];

void update(int idx, int val){
    while(idx <= MAXN){
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}