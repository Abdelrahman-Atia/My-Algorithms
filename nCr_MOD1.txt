#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

#define ABS(x) ((x) < 0 ? -(x) : (x))

vlong gcd(vlong a, vlong b) {
	a = ABS(a), b = ABS(b);
	while (b) {
		a = a % b;
		swap(a, b);
	}

	return a;
}



vlong power(vlong a, vlong p) {
	vlong res = 1, x = a;
	while (p) {
		if (p & 1)
			res = (res * x);
		x = (x * x);
		p >>= 1;
	}
	return res;
}

vlong powerMOD(vlong a, vlong p, vlong m) {
	vlong res = 1 % m, x = a % m;
	while (p) {
		if (p & 1)
			res = (res * x) % m;
		x = (x * x) % m;
		p >>= 1;
	}
	return res;
}
vlong ext_gcd(vlong A, vlong B, vlong *X, vlong *Y) {
	vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
	x2 = 1;
	y2 = 0;
	x1 = 0;
	y1 = 1;
	for (r2 = A, r1 = B; r1 != 0;
			r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
		q = r2 / r1;
		r = r2 % r1;
		x = x2 - (q * x1);
		y = y2 - (q * y1);
	}

	*X = x2, *Y = y2;
	return r2;
}

vlong modInv(vlong a, vlong m) {
	vlong x, y;
	ext_gcd(a, m, &x, &y);
	if (x < 0)
		x += m;
	return x;
}

const int MAX = 1e5 + 5;
vlong mod = 1e9 + 7;

vlong fact[MAX], inv[MAX];
void precal() {
	fact[0] = 1;
	inv[0] = modInv(1, mod);
	for (vlong i = 1; i < MAX; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = modInv(fact[i], mod);
	}
}

vlong nCr(int n, int r) {
	return fact[n] * inv[n - r] % mod * inv[r] % mod;
}

int main() {

//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	//freopen("out.in", "w", stdout);
//#endif
	precal();
	int t;
	cin >> t;
	while (t--) {
		int n, m, c, r;
		cin >> n >> m >> r >> c;
		vlong ans = nCr(n + m - 2, n - 1)
				- nCr(r + c - 2, r - 1) * nCr(n + m - r - c, n - r);
		while (ans < 0)
			ans += mod;
		ans %= mod;
		cout << ans << endl;
	}

	return 0;
}
