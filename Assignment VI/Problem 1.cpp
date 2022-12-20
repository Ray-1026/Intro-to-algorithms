#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void floyd_warshall(vector<vector<int>>& adj, int total) {
	int max_connect = -1;
	for (int i = 1; i < total; i++) {
		for (int j = 1; j < total; j++) {
			for (int k = 1; k < total; k++) {
				if (adj[j][i] + adj[i][k] < adj[j][k])
					adj[j][k] = adj[j][i] + adj[i][k];
			}
		}
	}
	for (int i = 1; i < total; i++) {
		for (int j = i + 1; j < total; j++)
			max_connect = max(max_connect, adj[i][j]);
	}
	cout << ((max_connect != 1e9) ? (max_connect) : (-1)) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n) {
		int total = 1;
		vector<vector<int>> adj(505, vector<int>(505, 1e9));
		unordered_map<string, int> name;
		for (int i = 0; i < n; i++) {
			string n1, n2;
			cin >> n1 >> n2;
			if (!name[n1])
				name[n1] = total++;
			if (!name[n2])
				name[n2] = total++;
			adj[name[n1]][name[n2]] = 1;
			adj[name[n2]][name[n1]] = 1;
		}
		for (int i = 1; i < total; i++)
			adj[i][i] = 0;
		floyd_warshall(adj, total);
	}
}
