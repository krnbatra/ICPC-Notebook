/* 2D sparse table */
const int MAXN = 1e3+5;
const int MAXM = 1e3+5;
const int LGN = log2(MAXN) + 1;
const int LGM = log2(MAXM) + 1;

int n, m;
int matrix[MAXN][MAXM];
int sparse_table[LGN][MAXN][LGM][MAXM];

// sparse_table[jr][ir][jc][ic]
void preprocess(){
	for(int ir = 0; ir < n; ir++){
		for(int ic = 0; ic < m; ic++)
			sparse_table[0][ir][0][ic] = matrix[ir][ic];

		for(int jc = 1; jc < LGM; jc++)
			for(int ic = 0; ic + (1 << jc) - 1 < m; ic++)
				sparse_table[0][ir][jc][ic] = min(sparse_table[0][ir][jc-1][ic], sparse_table[0][ir][jc-1][ic + (1 << (jc-1))]);
	}

	for(int jr = 1; jr < LGN; jr++)
		for(int ir = 0; ir + (1 << jr) - 1 < n; ir++)
			for(int jc = 0; jc < LGM; jc++)
				for(int ic = 0; ic + (1 << jc) - 1 < m; ic++)
					sparse_table[jr][ir][jc][ic] = min(sparse_table[jr-1][ir][jc][ic], sparse_table[jr-1][ir + (1 << (jr-1))][jc][ic]);	
}

int query(int x1, int y1, int x2, int y2){
	int lenx = x2-x1+1;
	int kx = log2(lenx);
	int leny = y2-y1+1;
	int ky = log2(leny);
	int minn1 = min(sparse_table[kx][x1][ky][y1], sparse_table[kx][x1][ky][y2-(1 << ky)+1]);
	int minn2 = min(sparse_table[kx][x2-(1 << kx)+1][ky][y1], sparse_table[kx][x2-(1 << kx)+1][ky][y2-(1 << ky)+1]);
	return min(minn1, minn2);
}