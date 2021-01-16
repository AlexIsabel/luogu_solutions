// 区间合并 
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 110;

int L, n, sum;

struct Segment{
    int l,r;
    bool operator < (const Segment& t) const {
        return l < t.l;
    }
}seg[N];

bool cmp(int a, int b) {return a < b;}

int main()
{
    cin >> L >> n;
    for (int i=1; i<=n; i++) cin >> seg[i].l >> seg[i].r;
    sort(seg+1, seg+n+1);
    int ll = seg[1].l, rr = seg[1].r;
    for (int i=1; i<=n; i++){
        if (seg[i].l <= rr) rr = max(rr, seg[i].r);
        else {
            sum += rr-ll+1;
            ll = seg[i].l, rr=seg[i].r;
        }
    }
    sum += rr - ll +1;
    cout<< L + 1 - sum <<endl;
    return 0;
}
