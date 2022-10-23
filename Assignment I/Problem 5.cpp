#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, num = 1;
	int k;
	cin >> n >> k;
	priority_queue<ll> pq;
	for (int i = 0; n && i < k; ++i) {
		if (n < num)
			break;
		if ((n & num) == num) {
			pq.push(num);
			n -= num;
		}
		num <<= 1;
	}
	if (n)
		cout << "NO";
	else {
		int len = pq.size(), flag = 1;
		for (; len < k; ++len) {
			ll temp = pq.top();
			pq.pop();
			if (temp == 1) {
				flag = 0;
				break;
			}
			pq.push(temp / 2);
			pq.push(temp / 2);
		}
		if (flag) {
			cout << "YES\n";
			for (; !pq.empty();) {
				cout << pq.top() << " ";
				pq.pop();
			}
		}
		else
			cout << "NO";
	}
}