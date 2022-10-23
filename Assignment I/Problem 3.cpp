#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

inline int solution(vector<int>& nums, int t) {
	int len = nums.size() - 1, res = 0;
	for (int i = 0; i < len - 2; ++i) {
		if (i && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < len - 1; ++j) {
			if (j != i + 1 && nums[j] == nums[j - 1])
				continue;
			ll temp = nums[i] + nums[j];
			int low = j + 1, high = len;
			for (; low < high;) {
				if (temp + nums[low] + nums[high] > t)
					high--;
				else if (temp + nums[low] + nums[high] < t)
					low++;
				else {
					res++;
					do{
						low++;
						high--;
					} while (low < high && nums[low] == nums[low - 1] && nums[high] == nums[high + 1]);
				}
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t, num, ans;
	vector<int> w;
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		w.emplace_back(num);
	}
	sort(w.begin(), w.end());
	ans = solution(w, t);
	if (ans)
		cout << ans << "\n";
	else
		cout << "FeiDooDoo_Zuo_Wei_Men\n";
}