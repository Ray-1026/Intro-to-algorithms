#include<bits/stdc++.h>
#define NOT_GREATER_THAN(a, b) (a<=b)?(1):(0)
#define MAX(a, b) (a>b)?(1):(0)
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, l, r, num, res = 0;
	vector<ll> v;
	cin >> n >> l >> r;
	v.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());
	ll right = n - 1, left = n - 1;
	for (int i = 0; i < n - 1; ++i) {
		left = (left > i) ? (left) : (i + 1);
		while (right > i && MAX(v[i] * v[right], r))
			right--;
		if (right <= i)
			break;
		while (left > i && NOT_GREATER_THAN(l, v[i] * v[left]))
			left--;
		res += (left >= i) ? (right - left) : (0);
	}
	cout << res << "\n";
}