/* ***************************************************************
 * Program Name : SPOJ
 * Date:  5,16,2016
 * Author: Mahmoud Ismail
 *Copyright: Your copyright notice
 ***************************************** *******************/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
long long tree[4194304];
long long lazy[4194304];
void update(long long n,long long s,long long e,long long i,long long j,long long val)
{
	if(lazy[n])
	{
		tree[n]+=(e-s+1)*lazy[n];
		if(s!=e)
		{

			lazy[n*2]+=lazy[n];
			lazy[n*2+1]+=lazy[n];

		}
		lazy[n]=0;
	}
	if(s>e||i>e||j<s)return;

	if(s>=i&&e<=j)
	{
		tree[n]+=(e-s+1)*val;
		if(s!=e)
		{
			lazy[n*2]+=val;
			lazy[n*2+1]+=val;
		}

	return;
	}

	update(n*2,s,(s+e)/2,i,j,val);
	update(n*2+1,(s+e)/2+1,e,i,j,val);
	tree[n]=tree[n*2]+tree[n*2+1];

}
long long quary(long long n, long long s, long long e, long long i, long long j) {

	if(lazy[n])
	{
		tree[n]+=(e-s+1)*lazy[n];
		if(s!=e)
		{
			lazy[n*2]+=lazy[n];
			lazy[n*2+1]+=lazy[n];

		}


		lazy[n]=0;

	}

	if (j < s || i > e)
		return 0;
	if (s >= i && e <= j)
	{
		return tree[n];
	}
		int mid = (s + e) / 2;
	if (j <= mid) {
		return quary(n * 2, s, mid, i, j);
	}
	if (i > mid) {
		return quary(n * 2 + 1, mid + 1, e, i, j);
	}
	return quary(n * 2, s, mid, i, j)+quary(n * 2 + 1, mid + 1, e, i, j);



}

int main() {

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
	memset(tree,0,sizeof tree);
		memset(lazy,0,sizeof lazy);
		long long n, q;
		scanf("%lld%lld", &n, &q);
		vector<int> arr(n);


		while (q--) {
		
			long long a,b,c;
			scanf("%lld",&a);
			if(a)
			{
				scanf("%lld%lld",&b,&c);


				printf("%lld\n",quary(1,0,n-1,b-1,c-1));

			}
			else
			{
				scanf("%lld%lld%lld",&a,&b,&c);

				update(1,0,n-1,a-1,b-1,c);

			}


		}
	}
	return 0;
}


