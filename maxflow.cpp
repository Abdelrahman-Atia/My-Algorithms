
const int N  = 5e3 + 3;
const int M = 6e4 + 4;



int head[N], work[N], nxt[M], to[M], cap[M], dis[N], que[N];
int edge_cnt , src, snk , back , front , qsz;
//src and snk is different according to the problem

void add_edge(int f, int t, int c) {
  nxt[edge_cnt] = head[f];
  head[f] = edge_cnt;
  to[edge_cnt] = t;
  cap[edge_cnt] = c;
  edge_cnt++;
}

void add_bi_edge(int f, int t, int c) {
  add_edge(f, t, c); 
  add_edge(t, f, c); // 0 if directed edge
}

void init() {
    memset(head, -1, sizeof head);
    edge_cnt = 0;
}

bool bfs() {
    back = front = qsz = 0;
    memset(dis, -1, sizeof dis);
    dis[src] = 0;
    que[qsz++, back++] = src;
    while (qsz) {
        int cur = que[qsz--,front++];
        for (int i = head[cur]; ~i; i = nxt[i]){
                int t = to[i];
                if (!cap[i] || dis[t] != -1)continue;
                dis[t] = dis[cur] + 1;
                if (t == snk)return 1;
                que[qsz++, back++] = t;
        }
    }
    return 0;
}

int dfs(int u, int flow = 1e9 + 3) {
    if(!flow)return flow;
    if (u == snk)return flow;
    for (int &i = work[u]; i != -1; i = nxt[i]){
        int v = to[i];
        if (!cap[i] || dis[u] + 1 != dis[v])continue;
        int f = dfs(v, min(flow, cap[i]));
        if (f){
          cap[i] -= f;
          cap[i ^ 1] += f;
          return f;
        }
    }
    return 0;
}

long long  max_flow(){
    long long ret = 0, flow = 0;
    while (bfs()) {
        memcpy(work, head, sizeof head);
        while ((flow = dfs(src)))ret += flow;
  }
  return ret;
}

