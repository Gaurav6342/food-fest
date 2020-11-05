#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
using namespace std;
ll n,ar[3005],dp[3005][3005][2];
ll func(ll,ll,ll);
int main()
{
	cin>>n;
	rep(i,0,n)
	{
		cin>>ar[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<func(0,n-1,0);
}
ll func(ll l,ll r,ll t)
{
	if(l>=r)
		return 0;
	if(dp[l][r][t]!=-1)
		return dp[l][r][t];
	ll ans;
	if(t==0)
	{
		ans=max({func(l,r-1,0),func(l+1,r,0),func(l+1,r-1,1)+(ar[l]*ar[r])});
	}	
	else
	{
		ans=max(func(l+1,r-1,1)+ar[l]*ar[r],0ll);
	}
	return dp[l][r][t]=ans;
}
