
#define MAXN 507
#define MAXM 130000 // n*(n - 1)/2
typedef vector<int> VI;

const int INF = 1e9; // $infinity$: be careful to make this big enough!!!
int S; // source
int T; // sink
int FN; // number of nodes
int FM; // number of edges (initialize this to 0)
// ra[a]: edges connected to a (NO MATTER WHICH WAY!!!); clear this in the beginning
VI ra[MAXN];
int kend[MAXM], cap[MAXM], cost[MAXM]; // size: TWICE the number of edges

void init() {
	FM = 0;
	for (int i = 0; i < MAXN; ++i) {
		ra[i].clear();
	}
}

// Adds an edge from a to b with capacity c and cost d and returns the number of the new edge
int addedge(int a, int b, int c, int d) {
	int i = 2 * FM;
	kend[i] = b;
	cap[i] = c;
	cost[i] = d;
	ra[a].push_back(i);
	kend[i + 1] = a;
	cap[i + 1] = 0;
	cost[i + 1] = -d;
	ra[b].push_back(i + 1);
	FM++;
	return i;
}

int dst[MAXM], pre[MAXM], pret[MAXM];
bool spfa() {
	for (int i = 0; i < FN; ++i)
		dst[i] = INF;
	dst[S] = 0;
	queue<int> que;
	que.push(S);
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (int t : ra[x]) {
			int y = kend[t], nw = dst[x] + cost[t];
			if (cap[t] > 0 && nw < dst[y]) {
				dst[y] = nw;
				pre[y] = x;
				pret[y] = t;
				que.push(y);
			}
		}
	}
	return dst[T] != INF;
}
// returns the maximum flow and the minimum cost for this flow
pair<vlong, vlong> solve() {
	vlong totw = 0, totf = 0;
	while (spfa()) {
		int minflow = INF;
		for (int x = T; x != S; x = pre[x]) {
			minflow = min(minflow, cap[pret[x]]);
		}
		for (int x = T; x != S; x = pre[x]) {
			cap[pret[x]] -= minflow;
			cap[pret[x] ^ 1] += minflow;
		}
		totf += minflow;
		totw += minflow * dst[T];
	}
	return make_pair(totf, totw);
}
