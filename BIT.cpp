//Code : (1-based)

int fen[MAX_N];
void update(int p,int val){
	for(int i = p;i <= n;i += i & -i)
		fen[i] += val;
}
int sum(int p){
	int ans = 0;
	for(int i = p;i;i -= i & -i)
		ans += fen[i];
	return ans;
}
