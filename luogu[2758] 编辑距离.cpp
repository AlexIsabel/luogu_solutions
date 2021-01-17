#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 2020;

char a[N], b[N];
int dp[N][N], lena, lenb;

int main()
{
	scanf("%s %s", a, b);
	lena = strlen(a), lenb = strlen(b);
	// dp[i][i] a��ǰ i ��Ԫ�� �� b��ǰ j ��Ԫ�أ������±���㿪ʼ 
	for (int i=1; i<=lena; i++) dp[i][0] = i;
	for (int j=1; j<=lenb; j++) dp[0][j] = j;
	
	for (int i=1; i<=lena; i++)
	for (int j=1; j<=lenb; j++) {
		if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
		else {
			dp[i][j] = min( min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1] ) + 1;
		}
	} 
	
	cout << dp[lena][lenb] << endl; 
		
	return 0;	
} 
