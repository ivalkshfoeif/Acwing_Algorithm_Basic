#include<iostream>
#include<algorithm>
#include<cstring>


using namespace std;

const int N = 100010;

int num[N], f[N];

int main(){
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	for (int i = 0; i < n; i++){
		f[i] = 1;
		for (int j = 0; j < i; j++){
			if (num[i] > num[j]) f[i] = max(f[i], f[j] + 1);
		}
		res = max(res, f[i]);
	}
	cout << res << endl;
	return 0;
}