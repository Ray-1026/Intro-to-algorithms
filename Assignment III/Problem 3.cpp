#include<bits/stdc++.h>
#define vi vector<int>
#define Min(a,b) (a<b)?(a):(b)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, e;
	cin >> n;
	vi lv(n + 2, 0);
	for (int i = 0; i < n; i++) {
		cin >> e;
		lv[i + 2] = e + (Min(lv[i], lv[i + 1]));
	}
	cout << (Min(lv.back(), lv[n]));
}