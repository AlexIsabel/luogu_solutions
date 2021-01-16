#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;

int ans, n, a[N], b[N], c[N], map[N], f[N];
int dp[1001][1001];

int find(int x, int l, int r){
	while (l < r){
		int mid = (l+r) >> 1;
		if (f[mid] < x) l = mid + 1;
		else r = mid;
	}
	return l;
}

int getLis(int* p){
	int res = 0;
	for(int i=1; i<=n; i++){
		if (p[i] > f[res]) f[++res] = p[i];
		else {
			f[find(p[i], 1, res)] = p[i];
		}
	}
	return res;
}


int main()
{
	cin >> n;
	for (int i=1; i<=n; i++){			
		cin >> a[i];
		map[a[i]] = i;
	} 
	for (int i=1; i<=n; i++) {
		cin >> b[i]; 
		c[i] = map[b[i]]; 	// 相当 hash 后的序列  
	}
	if (n > 1e3){
		ans = getLis(c); 
	} else {
		for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]), dp[i][j] = (a[i] == b[j]) ? max(dp[i][j], dp[i-1][j-1]+1) : dp[i][j];
		ans = dp[n][n];
	}
	cout << ans << endl;
	return 0;	
} 
