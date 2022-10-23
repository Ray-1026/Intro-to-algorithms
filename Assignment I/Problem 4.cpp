#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	vector<int> v;
	priority_queue<int> pq;
	cin >> n;
	for (; n > 0; --n) {
		cin >> x;
		switch (x) {
		case 1:
			int num;
			cin >> num;
			v.emplace_back(num);
			break;
		case 2:
			for (auto it : v)
				pq.push(it);
			v.clear();
			break;
		case 3:
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				if (v.empty())
					cout << "Oh Oh\n";
				else {
					cout << v.front() << "\n";
					v.erase(v.begin());
				}
			}
			break;
		}
	}
}