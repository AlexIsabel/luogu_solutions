// LIS 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100010;
int n, a[MAXN], head[MAXN], cnt;

int search(int l, int r, int x){
	int mid;
	while (l < r){
		mid = (l + r) >> 1;
		if (head[mid] >= x) r = mid;
		else l = mid + 1;
 	}
	return l;
} 

int main()
{
	cin>> n;
	for (int i=1; i<=n; i++) cin>>a[i];
	
	cnt = 0, head[0] = 0;
	for (int i=1; i<=n; i++){	// O (n logn)
		if (a[i] > head[cnt]) {
			head[++cnt] = a[i];
		}else{
		//	head[search(1, cnt, a[i])] = a[i];
			head[lower_bound(head+1, head+cnt+1, a[i]) - head] = a[i];
		}
	}
	cout << cnt << endl;
	return 0;	
} 
