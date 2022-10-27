#include<bits/stdc++.h>
#define vi vector<int>
#define Min(a,b) (a<b)?(a):(b)
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n;
	vi coins(n), dp(100001, 1e9);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	for (int i : coins) {
		for (int j = i; j < dp.size(); j++)
			dp[j] = Min(dp[j], (dp[j - i] + 1));
	}
	cin >> q;
	for (; q > 0; q--) {
		ll amount, num;
		cin >> amount;
		for (int i = 0; i < n; i++) {
			cin >> num;
			amount -= num * coins[i];
		}
		amount *= -1;
		cout << dp[amount] << "\n";
	}
}