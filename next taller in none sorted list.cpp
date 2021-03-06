vector<int> _Taller(vector<int> H) {
	vector<int> ans;
	stack<int> st;
	for (int i = 0; i < sz(H); ++i) {
		while (!st.empty() && H[st.top()] <= H[i])
			st.pop();
		st.push(i);
	}
	for (int i = 0; i < sz(H); ++i) {
		while (!st.empty() && H[st.top()] <= H[i])
			st.pop();
		ans.push_back(st.empty() ? -1 : st.top());
		st.push(i);
	}
	return ans;
}

vector<vector<int> > Taller(int N, vector<int> H) {
	vector<int> x = _Taller(H);
	reverse(H.begin(), H.end());
	vector<int> y = _Taller(H);
	reverse(y.begin(), y.end());
	vector<vector<int> > ans(N);
	for (int i = 0; i < N; ++i) {
		ans[i].push_back(x[i] == -1 ? -1 : x[i] + 1);
		ans[i].push_back(y[i] == -1 ? -1 : N - y[i]);
	}
	return ans;
}
