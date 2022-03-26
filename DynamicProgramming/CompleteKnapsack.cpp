#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

// https://www.acwing.com/problem/content/3/
// n is the amount of items
int n, m;
int dp[N][N];
int v[N], w[N];
int dp2[N];

//TLE
int solution1() {
    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j <= m; j ++ )
            for(int k = 0; k * v[i] <= j; k ++ )
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
    cout << dp[n][m] << endl;
	return 0;
}

int solution2() {
	for (int i = 1; i <= n; i++) {
		for (int j = v[i]; j <= m; j++) {
			dp2[j] = max(dp2[j], dp2[j - v[i]] + w[i]);
		}
	}
	cout << dp2[m] << endl;


	return 0;
}



int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	solution2();
	return 0;
}