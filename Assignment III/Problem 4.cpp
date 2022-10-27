#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, len, res = 1;
	cin >> n;
	vi fw, dis;
	fw.reserve(n);
	dis.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> len;
		fw.emplace_back(len);
	}
	dis.emplace_back(fw[0]);
	for (int i = 1; i < n; i++) {
		if (fw[i] > dis.back())
			dis.emplace_back(fw[i]);
		else {
			int pos = lower_bound(dis.begin(), dis.end(), fw[i]) - dis.begin();
			dis[pos] = fw[i];
		}
	}
	cout << dis.size();
}