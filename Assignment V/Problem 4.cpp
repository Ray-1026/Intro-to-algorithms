#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;
};

inline bool cmp1(Edge a, Edge b) {
	return a.w > b.w;
}

inline bool cmp2(Edge a, Edge b) {
	return a.w < b.w;
}

int find(vector<int>& p, int x) {
	return (p[x] == x) ? (x) : (p[x] = find(p, p[x]));
}

bool check(vector<int>& p) {
	for (int i = 0; i < p.size(); i++) {
		if (find(p, i) != find(p, p[0]))
			return 0;
	}
	return 1;
}

int kruskal(vector<Edge>& edge, vector<int>& p, int v) {
	int sum = 0;
	for (Edge i : edge) {
		int x = find(p, i.u), y = find(p, i.v);
		if (x != y) {
			p[x] = y;
			sum += i.w;
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int v, e, w;
	while (cin >> v >> e >> w) {
		vector<int> p(v), rumor(v, 0);
		vector<Edge> total, group;
		total.reserve(e);
		for (int i = 0; i < e; i++) {
			int u, v, weight;
			cin >> u >> v >> weight;
			total.push_back({ u, v, weight });
		}
		for (int i = 0; i < w; i++) {
			int op;
			cin >> op;
			rumor[op] = 1;
		}
		for (int i = 0; i < v; i++)
			p[i] = i;
		sort(total.begin(), total.end(), cmp1);
		int cost1 = kruskal(total, p, v);
		if (check(p)) {
			int cost2 = 0;
			for (int i = 0; i < v; i++)
				p[i] = i;
			for (Edge i : total) {
				if (rumor[i.u] || rumor[i.v]) {
					int x = find(p, i.u), y = find(p, i.v);
					cost2 += i.w;
					if (x != y)
						p[x] = y;
				}
				else
					group.emplace_back(i);
			}
			sort(group.begin(), group.end(), cmp2);
			cost2 += kruskal(group, p, v);
			if (check(p))
				cout << cost1 - cost2 << "\n";
			else
				cout << "no\n";
		}
		else
			cout << "no\n";
	}
}