#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int Mod = 1e9 + 7;

inline ll fast_mul(ll a, int b) {
	ll res = 0;
	for (; b; b /= 2, a = (a >= Mod) ? (a - Mod) : (a)) {
		if (b & 1) {
			res += a;
			res = (res >= Mod) ? (res - Mod) : (res);
		}
		a *= 2;
	}
	return res;
}

int main() {
	int n, num;
	ll ans(1);
	vector<int> p;
	scanf("%d", &n);
	p.reserve(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		num = (num < n) ? (num) : (n);
		p.push_back(num);
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < n; ++i)
		ans = fast_mul(ans, p[i] - i);
	printf("%lld\n", ans);
}