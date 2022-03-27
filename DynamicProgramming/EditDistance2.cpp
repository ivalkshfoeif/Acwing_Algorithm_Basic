#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010, M = 15;
char str[N][M];
int f[M][M];

int edit_distance(char a[], char b[]){
	int la = strlen(a + 1), lb = strlen(b + 1);
	for (int i = 1; i <= la; i++) f[i][0] = i;
	for (int i = 1; i <= lb; i++) f[0][i] = i;

	for (int i = 1; i <= la; i++){
		for (int j = 1; j <= lb; j++){
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
		}
	}

	// cout << f[la][lb] << endl;

	return f[la][lb];


}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		scanf("%s", str[i] + 1);
	}

	for (int i = 0; i < m; i++){
		char s[M];
		int target;
		scanf("%s%d", s + 1, &target);

		int res = 0;

		for (int i = 0; i < n; i++){
			if (edit_distance(str[i], s) <= target){
				res++;
			}
			
		}

		cout << res << endl;

		

		
	}
	return 0;
}