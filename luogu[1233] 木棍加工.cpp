#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 5010;

struct Stick{
	int l, w;
}s[N];

bool cmp(Stick a, Stick b){	return a.l > b.l; }

int n, dp[N], cnt, l , r, mid;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d %d", &s[i].l, &s[i].w);
	
	sort(s+1, s+n+1, cmp);
	
	// 不上升子序列的划分 等于 最长不下降子序列的长度 
	cnt = 0;
	for(int i=1; i<=n; i++){
		if (s[i].w > dp[cnt]) dp[++cnt] = s[i].w;
		else{
			l = 1, r = cnt;
			// 找到第一个大于他的数字 
			while (l < r){
				mid = (l+r) >> 1;
				if (dp[mid] >= s[i].w) r = mid;
				else l = mid+1;
			}
			dp[l] = s[i].w;
		}
	}	
	printf("%d\n", cnt);
	return 0;
 } 
