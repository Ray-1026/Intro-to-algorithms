#include<bits/stdc++.h>
using namespace std;
const int MAX = 2147483647;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int l, r, s;
	while (cin >> l >> r >> s) {
		vector<vector<pair<int, int>>> road(l, vector<pair<int, int>>());
		vector<int> dose(l), shelter, d(l, MAX), visit(l);
		shelter.reserve(s);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		int start, ans = MAX;
		for (int i = 0; i < l; i++)
			cin >> dose[i];
		for (int i = 0; i < r; i++) {
			int loc1, loc2, rad;
			cin >> loc1 >> loc2 >> rad;
			road[loc1].push_back({ loc2, rad });
			road[loc2].push_back({ loc1, rad });
		}
		for (int i = 0; i < s; i++) {
			int s;
			cin >> s;
			shelter.emplace_back(s);
		}
		cin >> start;
		d[start] = 0;
		pq.push({ 0, start });
		for (int i = 0; i < l; i++) {
			int a = -1;
			while (!pq.empty() && visit[a = pq.top().second])
				pq.pop();
			if (a == -1)
				break;
			visit[a] = 1;
			for (auto& it : road[a]) {
				if (!visit[it.first] && d[a] + it.second + dose[it.first] < d[it.first]) {
					d[it.first] = d[a] + it.second + dose[it.first];
					pq.push({ d[it.first], it.first });
				}
			}
		}
		for (int i : shelter)
			ans = min(ans, d[i]);
		cout << ((ans != MAX) ? (ans + dose[start]) : (-1)) << "\n";
	}
}