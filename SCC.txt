#include <bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define sz(c) int(c.size())
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define vlong long long

vector<vector<int> > SCCs /* The components itself*/;
#define comps SCCs
vector<int> compIndex /* for each node, what is the index of the component this node inside*/
, ind, lowLink;
stack<int> st;
vector<bool> inst;
vector<vector<int> > adj /*The intial graph*/;
int idx = 0;
void init(int n) {
	adj.resize(n);
	idx = 0;
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
}
void tarjanSCC(int i) {
	lowLink[i] = ind[i] = idx++;
	st.push(i);
	inst[i] = true;
	for (int j = 0; j < sz(adj[i]); j++) {
		int k = adj[i][j];
		if (ind[k] == -1) {
			tarjanSCC(k);
			lowLink[i] = min(lowLink[i], lowLink[k]);
		} else if (inst[k]) {
			lowLink[i] = min(lowLink[i], lowLink[k]);
		}
	}
	if (lowLink[i] == ind[i]) {
		vector<int> comp;
		int n = -1;
		while (n != i) {
			n = st.top();
			st.pop();
			comp.push_back(n);
			inst[n] = 0;
			compIndex[n] = sz(comps);
		}
		comps.push_back(comp);
	}
}
void SCC() {
	comps.clear();
	compIndex.resize(sz(adj));
	ind.clear();
	ind.resize(sz(adj), -1);
	lowLink.resize(sz(adj));
	inst.resize(sz(adj));
	idx = 0; //must be intialized by zero;
	for (int i = 0; i < sz(adj); i++)
		if (ind[i] == -1)
			tarjanSCC(i);
}
vector<vector<int> > cmpAdj /*The new graph between components*/;
void computeNewGraph() {
	cmpAdj.resize(sz(comps));
	for (int i = 0; i < sz(adj); i++) {
		for (int j = 0; j < sz(adj[i]); j++) {
			int k = adj[i][j];
			if (compIndex[k] != compIndex[i]) {
				cmpAdj[compIndex[i]].push_back(compIndex[k]);
			}
		}
	}
}
