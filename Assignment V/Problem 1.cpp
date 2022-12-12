#include<bits/stdc++.h>
using namespace std;

int dfs(vector<string>& site, int posx, int posy) {
	int len = site.size(), res = 0;
	vector<pair<int, int>> pos;
	pos.push_back({ posx, posy });
	site[posx][posy] = '^';
	while (!pos.empty()) {
		int x = pos.back().first, y = pos.back().second;
		pos.pop_back();
		res++;
		if (0 < x && site[x - 1][y] == '_') {
			site[x - 1][y] = '^';
			pos.push_back({ x - 1, y });
		}
		if (0 < y && site[x][y - 1] == '_') {
			site[x][y - 1] = '^';
			pos.push_back({ x, y - 1 });
		}
		if (x + 1 < len && site[x + 1][y] == '_') {
			site[x + 1][y] = '^';
			pos.push_back({ x + 1, y });
		}
		if (y + 1 < len && site[x][y + 1] == '_') {
			site[x][y + 1] = '^';
			pos.push_back({ x, y + 1 });
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (; n; n--) {
		int l, r;
		cin >> l >> r;
		int top = l / 2 - r, bottom = min(l / 2 + r, l - 1), largest = 0;
		vector<string> site(l);
		for (int i = 0; i < l; i++)
			cin >> site[i];
		for (int i = top; i <= bottom; i++) {
			for (int j = top; j <= bottom; j++) {
				if (site[i][j] == '_')
					largest = max(largest, dfs(site, i, j));
			}
		}
		cout << largest << "\n";
	}
}