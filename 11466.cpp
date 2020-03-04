#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tam 9999998
ll mp[tam];
vector<ll> primes;
void fun()
{
	for (ll i = 2; i < tam; i++)
	{
		if(!mp[i])
		{
			primes.push_back(i);
			mp[i] = i;
		}
		for(ll j = 0; j < (int)primes.size() && primes[j] <= mp[i] && i*primes[j] < tam; j++)
		{
			mp[i*primes[j]]= primes[j];
		}
	}
}


int main()
{	
	fun();
	//~ freopen("in", "r", stdin);
	//~ freopen("out", "w", stdout);
	ll n;
	set<ll> ans;
	while(scanf("%Ld", &n), n)
	{		
		
		ll aux = abs(n);	
		bool flag = 0;
		for (int i = 0; i < primes.size() && aux > 1 ; i++)
		{
			while(aux%primes[i] == 0)
			{
				flag = 1;
				aux = (ll)(aux/primes[i]);					
			}
			if(flag){ans.insert(primes[i]); flag = 0;}
		}
		if(aux != n && aux > 1 ) cout << aux;
		else if(ans.size() > 1)
		{
			set<ll>::iterator it;
			it = ans.end();
			it--;
			cout << *it;
		}
		else printf("-1");	
		ans.clear();
		puts("");
	} 
	
}
      



