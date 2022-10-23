#include<bits/stdc++.h>
#define Min(a,b) (a<b)?(a):(b)
using namespace std;
typedef long long int ll;

ll a, b;

ll divide(vector<int>& region, ll head, ll end) {
	if (head == end) {
		int left = lower_bound(region.begin(), region.end(), head) - region.begin(), right = upper_bound(region.begin(), region.end(), head) - region.begin();
		right -= left;
		return (right > 0) ? (right * b) : (a);
	}
	int left = lower_bound(region.begin(), region.end(), head) - region.begin(), right = upper_bound(region.begin(), region.end(), end) - region.begin();
  	ll sum_1 = right - left, mid = (head + end) / 2;
	if (!sum_1)
		return a;
	sum_1 *= b * (end - head + 1);
	ll sum_2 = divide(region, head, mid) + divide(region, mid + 1, end);
	return Min(sum_1, sum_2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k, num;
	vector<int> region;
	cin >> n >> k >> a >> b;
	region.reserve(k);
	for (int i = 0; i < k; ++i) {
		cin >> num;
		region.emplace_back(num - 1);
	}
	sort(region.begin(), region.end());
	cout << divide(region, 0, n - 1) << "\n";
}