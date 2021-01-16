#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 10010;

struct Segment{
	int l, r, len;
	void init(int a, int b){
		this->l = a, this->r = a+b-1, this->len = b;
	}
	bool operator < (const Segment& t) const {
		return (l < t.l) ? true : false;	 
	}

}seg[N];

int L, n, ans;
int f[N];

void dfs(int lastId, int lastEnd, int cost){
	if (lastEnd >= seg[n].l) {
		ans = max(ans, L-cost);
		return;
	} 

	for (int i=lastId+1; i<=n; i++) {
		if (seg[i].l > lastEnd) {
			for (int j=i; seg[j].l == seg[i].l; j++) {
				dfs(j, seg[j].r, cost + seg[j].len); 
			}
			break;
		}
	}
}

int main()
{
	cin >> L >> n;
	int st, len;
	for (int i=1; i<=n; i++){
		cin >> st >> len;
		seg[i].init(st, len);
	}
	sort(seg+1, seg+n+1);
	 
//	dfs(0, 0, 0);
	
	int t = n;
	for (int i=L; i; i--){
		if (seg[t].l != i) f[i] = f[i+1] + 1;
		else {
			int j;
			for (j=t; seg[j].l == seg[t].l; j--) {
				f[i] = max(f[seg[j].r + 1], f[i]);
			}
			t = j;
		} 
	}
	ans = f[1];
	
	cout << ans << endl;
	
	return 0;
}
