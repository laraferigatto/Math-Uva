#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{	
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	int r, n, k = 1, i;
	while(scanf("%d%d", &r, &n), r && n)
	{		
		ll ans = n;
		if(r<=n) printf("Case %d: 0",k);
		else
		{
			for (i = 1; i <= 26; i++)
			{
				ans += (n*i);
				if(ans >= r)
				{
					printf("Case %d: %d",k, i);
					break;
				}
				else ans = n;			
			}
			if(i > 26) printf("Case %d: impossible", k);
		}
		puts("");
		k++;
		
	} 
	
}
      



