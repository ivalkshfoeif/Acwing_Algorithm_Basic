#include<iostream>
#include<vector>

using namespace std;


/*

abc[d]efg

0 ~ (abc - 1) * 0 ~ 999 = (abc - 1) * 1000

abc 
	1. num[i] < x, 0 = 0
	2. nums[i] = x, 0 - efg = efg + 1
	3. nums[i] > x 0 - 999 = 10^3


if x == 0
it will not on num[0]
it will become 1 ~ (abc - 1)

*/

int getNum(vector<int> num, int l, int r){
	int res = 0;
	for (int i = l; i >= r; i--) res = res * 10 + num[i];
	return res;

}

int power10(int x){
	int res = 1;
	while(x --) res *= 10;
	return res;

}


int count(int n, int x){

	if (!n) return 0;

	vector<int> num;

	while(n)
	{
		num.push_back(n % 10);
		n /= 10;
	}
	n = num.size();

	int res = 0;
	for (int i = n - 1 - !x; i >= 0; i --)
	{
		if (i < n - 1)
		{
			res += getNum(num, n - 1, i + 1) * power10(i);
			if (!x) res -= power10(i);
		}

		if (num[i] == x) res += getNum(num, i - 1, 0) + 1;
		else if (num[i] > x) res += power10(i);
	}

	return res;
}

int main()
{
	int a, b;
	while(cin >> a >> b, a){
		if (a > b) swap(a, b);

		for (int i = 0; i <= 9; i++){
			cout << count(b, i) - count(a - 1, i) << ' ';
		}
		cout << endl;

	}




	return 0;
}