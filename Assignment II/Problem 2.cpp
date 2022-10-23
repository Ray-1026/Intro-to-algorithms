#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, num;
	cin >> n >> k;
	vector<int> count(20001, 0);
	for (; n > 0; --n) {
		cin >> num;
		count[num + 10000]++;
	}
	priority_queue<pi> pq;
	for (int i = 0; i < 20001; ++i)
		pq.push({ count[i], i - 10000 });
	for (; k > 1; --k)
		pq.pop();
	cout << pq.top().second << "\n";
}