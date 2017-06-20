const int N = 6e6;
int trie[N][3];
int cnt[N];
int nodeCnt;

int addNode(){
  memset(trie[nodeCnt],-1,sizeof trie[nodeCnt]);
  return nodeCnt++;
}


void ins(int val){
    int cur=0;
    for(int i = 30;i >= 0 ; i--){
        int j = bool((1<<i) & val);
        int &nxt=trie[cur][j];
        if(nxt==-1)nxt=addNode();
        cur=nxt;
        cnt[cur]++;
    }
}

void del(int val){
    int cur = 0;
    for(int i = 30;i >= 0 ; i--){
        int j = bool((1<<i) & val);
        cur = trie[cur][j];
        cnt[cur]--;
    }
}

int query(int val){
    int ret , cur;
    ret = cur = 0;
    for(int i = 30;i >= 0 ; i--){
        int j = bool(!((1<<i) & val));
        if(trie[cur][j] != -1 && cnt[trie[cur][j]]){
    //        cout<<j<<' '<<i<<' '<<trie[cur][j]<<endl;
            ret |= (1<<i);
            cur = trie[cur][j];
        }else{
            cur = trie[cur][!j];
        }
    }
    //cout<<endl;

    return ret;
}
