#include<iostream>

using namespace std;

const int N = 1000010;


int f[N], num[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	f[0] = -1e9;
	int len = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] > f[len]) {
			f[len + 1] = num[i];
			len++;
		} else {
			int lo = 0, hi = len;
			while (lo < hi) {
				int mid = lo + hi + 1 >> 1;
				if (f[mid] < num[i]) {
					lo = mid;
				} else {
					hi = mid - 1;
				}
			}
			f[lo + 1] = num[i];
		}
	}
	cout << len << endl;
	return 0;
}