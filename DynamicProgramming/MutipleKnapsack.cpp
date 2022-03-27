#include<iostream>
#include<algorithm>
#include <cstring>

const int N = 110;

int n, m;
int f[N][N];
int v[N], w[N], s[N];
int f2[N];

using namespace std;

int solution1(){

    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j <= m; j ++ )
            for(int k = 0; k * v[i] <= j && k <= s[i]; k ++ )
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
    cout << f[n][m] << endl;
	return 0;
}

int solution2(){

	for (int i = 1; i <= n; i++){
		for (int j = m; j >= 0; j--){
			for (int k = 0; k <= s[i] && j - k * v[i] >= 0; k++){
				f2[j] = max(f2[j], f2[j - k * v[i]] + k * w[i]);
			}
		}
	}

	cout << f2[m] << endl;

	return 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> v[i] >> w[i] >> s[i];
	}

	solution2();
	

	return 0;
}