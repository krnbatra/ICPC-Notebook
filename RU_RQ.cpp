/* RU_RQ */
const int MAXN = 1e3+5;
int BIT[2][MAXN];
 
void update(int bit, int idx, int val){
    while(idx <= 500000){
        BIT[bit][idx] += val;
        idx += idx&-idx;
    }
}
 
void udpateRange(int l, int r, int val){
    update(0, l, val);
    update(0, r+1, -val);
    update(1, l, val*(l-1));
    update(1, r+1, -val*r);
}
 
int queryTree(int bit, int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[bit][idx];
        idx -= idx&-idx;
    }
    return sum;
}
 
int query(int idx){
    return idx*queryTree(0, idx) - queryTree(1, idx);
}
 
int queryRange(int l, int r){
    return query(r)-query(l-1);
}