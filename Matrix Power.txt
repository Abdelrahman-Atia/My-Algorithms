#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

const int md = 1e9 + 7;
typedef vector<long long> vl;
typedef vector<vl> matrix;
matrix initial(int n, int m) {
	return matrix(n, vl(m, 0));
}

matrix identity(int n) {
	matrix ret = initial(n, n);
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;
	return ret;

}

matrix multiply(const matrix &x, const matrix &y) {
	matrix ret = initial(x.size(), y[0].size());
	for (int i = 0; i < sz(x); i++) {
		for (int k = 0; k < sz(x[0]); k++) {
			for (int j = 0; j < sz(y[0]); j++) {
				ret[i][j] += (((x[i][k] * y[k][j]) % md) + md) % md;
				ret[i][j] = ((ret[i][j] % md) + md) % md;
			}
		}
	}
	return ret;
}

matrix pow(const matrix &x, long long k) {
	if (k == 0)
		return identity(sz(x));
	if (k & 1)
		return multiply(x, pow(x, k - 1));

	return pow(multiply(x, x), k / 2);
}

long long fib(int n) {
	if (n < 3)
		return 1;
	matrix init = initial(1, 2), t = initial(2, 2);
	t[0][1] = t[1][1] = t[1][0] = 1;
	init[0][0] = init[0][1] = 1;
	matrix moves = pow(t, n - 2);
	matrix ans = multiply(init, moves);
	return ans[0][1];

}
