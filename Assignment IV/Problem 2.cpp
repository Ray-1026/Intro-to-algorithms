#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, step = 0, last = 0, maxpos = 0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; last < n - 1; i++) {
		maxpos = max(maxpos, i + num[i]);
		if (i == last) {
			last = maxpos;
			step++;
		}
	}
	cout << step << "\n";
}