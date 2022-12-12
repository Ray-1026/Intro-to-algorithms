#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;
};

inline bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

int find(vector<int>& p, int x) {
	return (p[x] == x) ? (x) : (p[x] = find(p, p[x]));
}

void kruskal(vector<Edge>& edge, vector<int>& p, vector<int>& outpost, int& sum) {
	vector<int> point;
	for (Edge i : edge) {
		int x = find(p, i.u), y = find(p, i.v);
		if (x != y) {
			p[x] = y;
			sum += i.w;
		}
	}
	for (int i = 0; i < outpost.size(); i++) {
		if (!outpost[i])
			point.emplace_back(i);
		else
			outpost[i] = 0;
	}
	for (int i : point) {
		if (find(p, i) != find(p, point[0])) {
			sum = -1;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int v, e, w;
	while (cin >> v >> e >> w) {
		vector<Edge> total, edge1, edge2;
		total.reserve(e);
		vector<int> outpost(v, 0), p(v);
		int sum = 0;
		for (int i = 0; i < e; i++) {
			int u, v, weight;
			cin >> u >> v >> weight;
			total.push_back({ u, v, weight });
		}
		for (int i = 0; i < w; i++) {
			int op;
			cin >> op;
			outpost[op] = 1;
		}
		for (int i = 0; i < v; i++)
			p[i] = i;
		for (Edge i : total) {
			if (outpost[i.u] || outpost[i.v])
				edge2.emplace_back(i);
			else
				edge1.emplace_back(i);
		}
		sort(edge1.begin(), edge1.end(), cmp);
		kruskal(edge1, p, outpost, sum);
		if (sum != -1) {
			sort(edge2.begin(), edge2.end(), cmp);
			kruskal(edge2, p, outpost, sum);
		}
		cout << sum << "\n";
	}
}