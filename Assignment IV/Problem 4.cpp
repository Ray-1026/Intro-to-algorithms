#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

inline bool cmp(pii& a, pii& b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, start, end, last = 0;
	cin >> n;
	vector<pii> t;
	t.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		if(end>start)
			t.push_back({ start, end });
	}
	sort(t.begin(), t.end(), cmp);
	for (pii i : t) {
		if (i.first >= last) {
			cout << i.first << " " << i.second << "\n";
			last = i.second;
		}
	}
}