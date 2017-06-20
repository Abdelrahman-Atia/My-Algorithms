const int NSize = 100;
int cost[NSize][NSize];
int d[NSize];
bool V[NSize];
const int inf = 9999999;
void mstPrim(int start, int n) {
	for (int i = 0; i < n; i++)
		d[i] = inf;
	memset(V, 0, sizeof V);
	d[start] = 0;

	int current = start;
	int minD = inf;
	int nextInd = -1; 
	while (current != -1) {
		V[current] = 1;
		minD = inf;
		nextInd = -1;
		for (int i = 0; i < n; ++i) {
			if (!V[i] && cost[current][i] < d[i]) {
				d[i] = cost[current][i];
			}
			if (!V[i] && d[i] < minD) {
				nextInd = i;
				minD = d[i];
			} 
		}
		current = nextInd;
	}
}
