/* BS Fenwick */
const int MAXN = 1e5+5;

int BIT[MAXN];
int bitmask = 1 << 10;

// refer TopCoder tutorial
int find(int cumFre){
	// finds some index of corresponding cum freq
	int idx = 0;
	while(bitmask != 0 && idx < MAXN){
		int tIdx = idx + bitmask;
		if(cumFre == BIT[tIdx])
			return tIdx;
		else if(cumFre > BIT[tIdx]){
			idx = tIdx;
			cumFre -= BIT[tIdx];
		}
		bitmask >>= 1;
	}
	if(cumFre != 0)
		return -1;
	return idx;
}
// finds greatest index of corresponding cum freq
int findG(int cumFre){
	int idx = 0;
	while(bitmask != 0 && idx < MAXN){
		int tIdx = idx + bitmask;
		if(cumFre >= BIT[tIdx]){
			idx = tIdx;
			cumFre -= BIT[tIdx];
		}
		bitmask >>= 1;
	}
	if(cumFre != 0)
		return -1;
	return idx;
}