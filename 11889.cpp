#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int mp[10000100];
vector<int> primes;
void fun()
{
	for (ll i = 2; i < 10000010; i++)
	{
		if(!mp[i])
		{
			primes.push_back((int)i);
			mp[(int)i] = (int)i;
		}
		for(ll j = 0; j < (int)primes.size() && primes[j] <= mp[i] && i*primes[j] < 10000010; j++)
		{
			mp[(int)(i*primes[j])]= primes[(int)j];
		}
	}
}


int main()
{	
	fun();
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t, a,c;
	map <int,int> fat_a;
	map <int, int> fat_c;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &c);
		if(c%a != 0) puts("NO SOLUTION");
		else
		{
			
			int ca = c;
			while(ca != 1)
			{
				fat_c[mp[ca]]++;
				ca = ca/mp[ca];
			}
			int ans = 1;
			while(a != 1)
			{
				//~ cout << mp[a] << endl;
				if(fat_c.find(mp[a]) == fat_c.end()) // nao existe
				{				
					ans *= mp[a];
					a = a/mp[a];
				}
				else
				{			
					fat_a[mp[a]]++;
					a = a/mp[a];
				}
				
			}
			
				
				
			map <int,int>::iterator it;
			for (it = fat_c.begin(); it != fat_c.end(); it++)
			{
				if(fat_a.find(it->first) != fat_a.end())
				{
					if(it->second > fat_a[it->first])
						ans *= pow(it->first, it->second);
				}
				else
					ans *= pow(it->first, it->second);
					
			}
			cout << ans << endl;
			
			
		}
		fat_a.clear();
		fat_c.clear();
	}
	
}
      



