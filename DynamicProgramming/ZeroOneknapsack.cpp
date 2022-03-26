#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

// https://www.acwing.com/problem/content/2/
// n is the amount of items
int n, capacity;
int dp[N][N];
int volume[N], weight[N];
int dp2[N];

int solution1() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= capacity; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - volume[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - volume[i]] + weight[i]);
		}
	}
	int res = 0;
	for (int i = 0; i <= capacity; i++) res = max(res, dp[n][i]);
	cout << res << endl;
	return 0;
}

int solution2() {
	for (int i = 1; i <= n; i++) {
		for (int j = capacity; j >= volume[i]; j--) {
			dp2[j] = max(dp2[j], dp2[j - volume[i]] + weight[i]);
		}
	}
	cout << dp2[capacity] << endl;


	return 0;
}



int main() {
	cin >> n >> capacity;
	for (int i = 1; i <= n; i++) cin >> volume[i] >> weight[i];
	solution2();
	return 0;
}

