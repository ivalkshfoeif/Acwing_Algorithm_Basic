#include<iostream>


using namespace std;

const int N = 1010, mod = 1e9 + 7;

int f1[N], f2[N][N];
int n;

int solution1() {
	//cout << 0 << endl
	f1[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			//f[i][j] = max(f[i][j], f[i - 1][j] + f[i - 1][j - i] + f[i - 1][j - 2 * i] + f[i][j - 3 * i] + ...)
			//f[i][j - i] = max(f[i][j - i], f[i - 1][j - i])
			//f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - i])
			f1[j] = (f1[j] + f1[j - i]) % mod;
		}
	}
	cout << f1[n] << endl;
	return 0;


}

int solution2() {
	f2[1][1] = 1;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= i; j ++){
			// the min element is 1 vs the min element is larger than 1
			f2[i][j] = (f2[i - j][j] + f2[i - 1][j - 1]) % mod;
		}
	}
	int res = 0;
	for (int i = 1; i <= n ; i++){
		res = (res + f2[n][i]) % mod;
	}
	cout << res <<endl;
	return 0;
}

int main() {
	cin >> n;
	solution2();
	return 0;
}
