#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, anum = 0, bnum = 0, sum = 0;
	priority_queue<int, vector<int>, greater<int>> pqa, pqb;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			bnum++;
			sum += b;
			pqa.push(a - b);
		}
		else {
			anum++;
			sum += a;
			pqb.push(b - a);
		}
	}
	int temp = abs(anum - bnum) / 2;
	if (anum > bnum) {
		for (int i = 0; i < temp; i++) {
			sum += pqb.top();
			pqb.pop();
		}
	}
	else if (bnum > anum) {
		for (int i = 0; i < temp; i++) {
			sum += pqa.top();
			pqa.pop();
		}
	}
	cout << sum << "\n";
}