#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int P = 1e6+7;

int n, m, a[105], f[105][105];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]); 
	
	f[0][0] = 1;
	for (int i=1; i<=n; i++){
		for (int j=0; j<=m; j++){
			for (int k=0; k<=a[i]; k++){
				if (k > j) break;
 				f[i][j] = (f[i][j] + f[i-1][j-k]) % P;
			}
		}
	}
	
	printf("%d\n", f[n][m]); 
	
	return 0;
} 
