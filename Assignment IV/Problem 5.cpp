#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll k;
	cin >> n;
	set<ll> s;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
	}
	vector<ll> price(s.begin(), s.end());
	cin >> k;
	ll total = (1LL + k) * k / 2LL;
	for (auto it : price) {
		if (it == 0 || it > k)
			continue;
		k++;
		total += (k - it);
	}
	cout << total;
}