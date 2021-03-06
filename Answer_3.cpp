#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
#define sz(a) ((int)a.size())
#define cl clear()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))
#define PI 3.1415926535897932384626433832795
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
//#define inf 1000000007
const ll inf=100000000000007LL;
#define N 20010
const ll mod=1000000007LL;
int a[N],b[N/2];
pii p[N/2];
int solve(int x,int y)
{
	int i,l,k=0,r,m;
	for(i=x;i<=y;i++)
	{
		l=0,r=k-1;
		while(l<=r)
		{
			m=(l+r)>>1;
			if(a[b[m]]>=a[i])r=m-1;
			else l=m+1;
		}
		b[r+1]=i;
		if(r+1>=k)k++;
	}
	return k;
}
int main()
{
    int i,j,T,ca=0,k,n,m=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]),p[i].x=a[i],p[i].y=i;
		for(i=n;i<n+n-1;i++)a[i]=a[i-n];
		sort(p,p+n);
		int ans=0;
		for(i=0;i<=50&&i<n;i++)
		{
			ans=max(ans,solve(p[i].y,p[i].y+n-1));
		}
		printf("%d\n",ans);
	}
    return 0;
} 
