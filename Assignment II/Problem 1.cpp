#include<iostream>
using namespace std;

int main() {
	int n, input, count[501] = { 0 };
	scanf("%d", &n);
	for (int i = 0, sum = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &input);
			sum += input;
		}
		count[sum]++;
		sum = 0;
	}
	for (int i = 500; i >= 0; --i) {
		for (; count[i] > 0; --count[i])
			printf("%d\n", i);
	}
}