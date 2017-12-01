/* fft normal */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

#define pb     push_back
#define mp     make_pair
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
const ll INF =  0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
// const int MAX = 1e5+5;

//2^ceil(log2(x)) where x = Maximum size of Polynomial
const int MAX = 131100;

//Complex class: Quite faster than in-built C++ library as it uses only functions required 
template<typename T> class cmplx {
private:
	T x, y;
public:
	cmplx () : x(0.0), y(0.0) {}
	cmplx (T a) : x(a), y(0.0) {}
	cmplx (T a, T b) : x(a), y(b) {}
	T get_real() { return this->x; }
	T get_img() { return this->y; }
	cmplx conj() { return cmplx(this->x, -(this->y)); }
	cmplx operator = (const cmplx& a) { this->x = a.x; this->y = a.y; return *this; }
	cmplx operator + (const cmplx& b) { return cmplx(this->x + b.x, this->y + b.y); }
	cmplx operator - (const cmplx& b) { return cmplx(this->x - b.x, this->y - b.y); }
	cmplx operator * (const T& num) { return cmplx(this->x * num, this->y * num); }
	cmplx operator / (const T& num) { return cmplx(this->x / num, this->y / num); }
	cmplx operator * (const cmplx& b) { 
		return cmplx(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y); 
	}
	cmplx operator / (const cmplx& b) {
		cmplx temp(b.x, -b.y); cmplx n = (*this) * temp;
		return n / (b.x * b.x + b.y * b.y);
	}
};

//T = int/long long as per polynomial coefficients
//S = double/long double as per precision required
template<typename T, typename S> struct FFT {
	S PI;
	int n, L, *rev, last;
	cmplx<S> ONE, ZERO;
	cmplx<S> *omega_powers;

	FFT() {
		PI = acos(-1.0);
		ONE = cmplx<S>(1.0, 0.0);
		ZERO = cmplx<S>(0.0, 0.0);
		last = -1;
		int req = 1 << (32 - __builtin_clz(MAX));
		rev = new int[req];
		omega_powers = new cmplx<S>[req];
	}

	~FFT() {
		delete rev;
		delete omega_powers;
	}

	void ReverseBits() {
		if (n != last) {
			for (int i = 1, j = 0; i < n; ++i) {
				int bit = n >> 1;
				for (; j >= bit; bit >>= 1) j -= bit;
				j += bit;
				rev[i] = j;
			}
		}
	}
 
	void DFT(vector<cmplx<S> > &A, bool inverse = false) {
		for(int i = 0; i < n; ++i) 
			if (rev[i] > i) swap(A[i], A[rev[i]]);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s, half = m / 2;
			cmplx<S> wm(cosl(2.0 * PI / m), sinl(2.0 * PI / m));
			if (inverse) wm = ONE / wm;
			omega_powers[0] = ONE;
			for(int k = 1; k < half; ++k) {
				omega_powers[k] = omega_powers[k-1] * wm;
			}
			for (int k = 0; k < n; k += m) {
				for (int j = 0; j < half; j++) {
					cmplx<S> t = omega_powers[j] * A[k + j + half];
					cmplx<S> u = A[k + j];
					A[k + j] = u + t;
					A[k + j + half] = u - t;
				}
			}
		}
		if (inverse) {
			for (int i = 0; i < n; i++) A[i] = A[i] / n;
		}
	}
 
	// c[k] = sum_{i=0}^k a[i] b[k-i]
	vector<T> multiply(const vector<T> &a, const vector<T> &b) {
		L = 0;
		int sa = a.size(), sb = b.size(), sc = sa + sb - 1;
		while ((1 << L) < sc) L++; 
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S> > aa(n, ZERO), bb(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		for (int i = 0; i < sb; ++i) bb[i] = cmplx<S>(b[i], 0);
		DFT(aa, false); DFT(bb, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * bb[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = cc[i].get_real() + 0.5;
		return ans;
	}

	// c[k] = sum_{i=0}^k a[i] a[k-i], saves one FFT call
	vector<T> multiply(const vector<T> &a) {
		L = 0;
		int sa = a.size(), sc = sa + sa - 1;
		while ((1 << L) < sc) L++; 
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S> > aa(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		DFT(aa, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * aa[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = cc[i].get_real() + 0.5;
		return ans;
	}
};

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  
  #ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  #endif

  FFT<int, double > f;
  vector<int> a, b, c;
  c = f.multiply(a, b);
  return 0;
}  


