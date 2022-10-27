#include<bits/stdc++.h>
#define vi vector<int>
#define Max(a,b) (a>b)?(a):(b)
#define Min(a,b) (a<b)?(a):(b)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cur_min = 0, cur_max = 0, res = 0;
	cin >> n;
	vi sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
		if (sum[i] < 0)
			res = Max(res, abs(cur_max - sum[i]));
		else
			res = Max(res, abs(cur_min - sum[i]));
		cur_min = Min(cur_min, sum[i]);
		cur_max = Max(cur_max, sum[i]);
	}
	cout << res;
}