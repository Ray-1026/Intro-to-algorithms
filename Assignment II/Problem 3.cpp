#include<bits/stdc++.h>
#define Min(a,b) (a<b)?(a):(b)
#define Abs(a) (a<0)?(a*(-1)):(a)
using namespace std;
typedef long long int ll;

ll divide(vector<int>& v, int front, int end) {
	if (end - front < 3)
		return 0;
	int mid = (end + front) / 2;
	vector<int>	left(v.begin() + front, v.begin() + mid + 1), right(v.begin() + mid + 1, v.begin() + end + 1);
	nth_element(left.begin(), left.begin() + left.size() / 2, left.end());
	nth_element(right.begin(), right.begin() + right.size() / 2, right.end());
	int left_med = left[left.size() / 2], right_med = right[right.size() / 2];
	ll cost_1 = 0, cost_2 = 0;
	for (int i = front; i <= mid; ++i)
		cost_1 += Abs((left_med - v[i]));
	for (int i = mid + 1; i <= end; ++i)
		cost_2 += Abs((right_med - v[i]));
	cost_1 += divide(v, mid + 1, end);
	cost_2 += divide(v, front, mid);
	return Min(cost_1, cost_2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, num;
	vector<int> arr;
	cin >> n;
	arr.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> num;
		arr.emplace_back(num);
	}
	cout << divide(arr, 0, n - 1) << "\n";
}