#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Flow {
private:
	struct Edge {
		int v, flow, cap, rev;
	};
	int v;
	vector<vector<Edge>> adj, adj_copy;
	vector<int> level;
public:
	Flow(int num) :v(num) {
		adj.resize(v, vector<Edge>());
		level.resize(v);
	};
	void add(int u, int v, int cap) {
		int usize = adj[u].size(), vsize = adj[v].size();
		adj[u].push_back({ v, 0, cap, vsize });
		adj[v].push_back({ u, 0, 0, usize });
	};
	bool bfs(int s, int t, unordered_map<int, int>& comb) {
		for (int i = 0; i < v; i++)
			level[i] = -1;
		level[s] = 0;
		queue<int> q;
		for (Edge e : adj_copy[s]) {
			if (comb[e.v] && level[e.v] < 0 && e.flow < e.cap) {
				level[e.v] = 1;
				q.push(e.v);
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (Edge e : adj_copy[u]) {
				if (level[e.v] < 0 && e.flow < e.cap) {
					level[e.v] = level[u] + 1;
					q.push(e.v);
				}
			}
		}
		return (level[t] < 0) ? (false) : (true);
	};
	int dfs(int u, int flow, int t, vector<int>& start) {
		if (u == t)
			return flow;
		for (; start[u] < adj_copy[u].size(); start[u]++) {
			Edge& e = adj_copy[u][start[u]];
			if (level[e.v] == level[u] + 1 && e.flow < e.cap) {
				int curr = min(flow, e.cap - e.flow), temp = dfs(e.v, curr, t, start);
				if (temp > 0) {
					e.flow += temp;
					adj_copy[e.v][e.rev].flow -= temp;
					return temp;
				}
			}
		}
		return 0;
	};
	int dinic(unordered_map<int, int>& comb) {
		adj_copy = adj;
		int total = 0, flow;
		while (bfs(0, v - 1, comb)) {
			vector<int> start(v + 1, 0);
			while (flow = dfs(0, INT_MAX, v - 1, start))
				total += flow;
		}
		return total;
	};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, c, r;
	while (cin >> n >> m >> c >> r) {
		Flow f(2 + n + m);
		int num, time;
		vector<int> timeslot(n, 0);
		for (int i = 1; i <= n; i++)
			f.add(0, i, c);
		for (int i = 0; i < m; i++) {
			int st;
			cin >> st >> num;
			for (int j = 0; j < num; j++) {
				cin >> time;
				f.add(time + 1, n + st + 1, 1);
			}
			f.add(n + st + 1, n + m + 1, 1);
		}
		for (int i = 0; i < r; i++) {
			unordered_map<int, int> comb;
			cin >> num;
			for (int j = 0; j < num; j++) {
				cin >> time;
				comb[time + 1] = 1;
			}
			int res = f.dinic(comb);
			if (res < m)
				cout << m - res << "\n";
			else
				cout << "0\n";
		}
	}
}