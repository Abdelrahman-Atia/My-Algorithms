const int M = 1e5 + 5;
const int N = 4*M;
int s[N] , a[M];
int n;


void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){	//	l + 1 == r
		s[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

void modify(int p,int x,int id = 1,int l = 0,int r = n){
	s[id] += x - a[p];
	if(r - l < 2){	//	l = r - 1 = p
		a[p] = x;
		return ;
	}
	int mid = (l + r)/2;
	if(p < mid)
		modify(p, x, id * 2, l, mid);
	else
		modify(p, x, id * 2 + 1, mid, r);
}

int sum(int x,int y,int id = 1,int l = 0,int r = n){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return sum(x, y, id * 2, l, mid) +
	       sum(x, y, id * 2 + 1, mid, r);
}
