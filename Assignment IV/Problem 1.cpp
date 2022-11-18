#include<bits/stdc++.h>
using namespace std;

inline bool cmp(string a, string b) {
	if (a[0] != b[0])
		return a > b;
	else {
		if (a + b > b + a)
			return 1;
		else
			return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string num, ans = "";
	cin >> n;
	vector<string> pw;
	pw.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> num;
		pw.emplace_back(num);
	}
	sort(pw.begin(), pw.end(), cmp);
	for (string i : pw)
		ans += i;
	cout << ((ans[0] != '0') ? (ans) : ("0"));
}