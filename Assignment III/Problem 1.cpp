#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int m[2000001] = { 0 };
vi post, in, trans;
int ocur = 0;

inline int read() {
	int res = 0;
	char c = getchar();
	while (c < '0' && c>'9')
		c = getchar();
	while (c >= '0' && c <= '9') {
		res = (res << 1) + (res << 3) + c - '0';
		c = getchar();
	}
	return res;
}

int build(int in_begin, int in_end, int post_begin, int post_end) {
	int val = trans[post[post_end] - 1], i = m[post[post_end]] - in_begin;
	if (i) {
		int left = build(in_begin, in_begin + i - 1, post_begin, post_begin + i - 1);
		(val < left) ? (ocur++) : (ocur);
	}
	if (in_begin + i < in_end) {
		int right = build(in_begin + i + 1, in_end, post_begin + i, post_end - 1);
		(val < right) ? (ocur++) : (ocur);
	}
	return val;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n;
	n = read();
	trans.resize(n, 0);
	in.resize(n, 0);
	post.resize(n, 0);
	for (int i = 0; i < n; i++)
		trans[i] = read();
	for (int i = 0; i < n; i++) {
		in[i] = read();
		m[in[i]] = i;
	}
	for (int i = 0; i < n; i++)
		post[i] = read();
	n--;
	int r = build(0, n, 0, n);
	printf("%d", ocur);
}