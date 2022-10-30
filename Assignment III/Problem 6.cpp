#include<bits/stdc++.h>
#define vi vector<long long int>
using namespace std;
const int mod = 1e8 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	vi grid(n, 1);
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++)
			grid[j] = (grid[j] + grid[j - 1]) % mod;
	}
	cout << grid.back();
}