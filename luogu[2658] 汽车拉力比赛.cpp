#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#define id(i,j) n*(i-1)+j
using namespace std;

const int N = 505;

int h[N][N], a[N*N], n, m, num, f[N*N];
int l, r, mid;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int find(int u) {
	return (f[u] == u) ? u : f[u] = find(f[u]);
}

void add(int x1, int x2){
	f[find(x1)] = find(x2);
}


bool check(int d){
	for (int i=1; i<=m; i++) for (int j=1; j<=n; j++) 
		f[id(i,j)] = id(i,j);
	
	int nx, ny; 
	for (int i=1; i<=m; i++) for(int j=1; j<=n; j++)
	for (int k=0; k<4; k++){
		nx = i+dx[k], ny = j+dy[k];
		if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
		if (abs(h[i][j] - h[nx][ny]) > d) continue;
		add(id(i,j), id(nx,ny));
	}
	
	for (int i=1; i<num; i++) 
		if (find(a[i]) != find(a[i+1])) return false;
	// »·Ê½¼ì²é 
	return true;
}

int main()
{
	scanf("%d %d", &m, &n);
	
	for (int i=1; i<=m; i++) 
		for (int j=1; j<=n; j++){
			scanf("%d", &h[i][j]); 
			r = max(r, h[i][j]);
		}
			
	
	int p;		
	for (int i=1; i<=m; i++) 
		for (int j=1; j<=n; j++){
			scanf("%d", &p);
			if (p) a[++num] = id(i,j);
		}
	
	l = 0;
	while (l < r){
		mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l << endl;
	
	return 0;
}
 
