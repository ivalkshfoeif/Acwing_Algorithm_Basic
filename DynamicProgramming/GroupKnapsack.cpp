#include<iostream>
#include<cstdio>
#include<algorithm>


using namespace std;

int const N = 110;

int n, m;
int f[N], v[N], w[N];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		for (int k = 0; k < s; k++) {
			cin >> v[k] >> w[k];
		}
		for (int j = m; j >= 0; j--) {
			for (int k = 0; k < s; k++) {
				if (j - v[k] >= 0) {
					f[j] = max(f[j], f[j - v[k]] + w[k]);
				}

			}
		}


	}
	cout << f[m] << endl;

	return 0;
}
