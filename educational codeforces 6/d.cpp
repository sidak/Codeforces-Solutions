#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a, b)

using namespace std;
typedef long long int ll;

const ll INF = ll(1e18);

int main(){
	int n,m;
	vector<ll> a, b;
	ll sum_a=0, sum_b=0;
	cin>>n;
	for(int i=0; i<n; i++){
		ll x ;
		cin>>x;
		a.pb(x);
		sum_a += x;
	}
	
	cin>>m;
	for(int i=0; i<m; i++){
		ll x ;
		cin>>x;
		b.pb(x);
		sum_b += x;
	}
	
	
	vector< pair<int, int> > ans;
	
	ll minDiff = INF;
	
	if(abs(sum_a-sum_b) < minDiff){
		minDiff = abs(sum_a - sum_b);
		ans.clear();
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			sum_a += b[j] - a[i];
			sum_b += a[i] - b[j];
			if(abs(sum_a-sum_b)< minDiff){
				minDiff = abs(sum_a - sum_b);
				ans.clear();
				ans.pb(mp(i, j));
			}
			sum_a -= b[j] - a[i];
			sum_b -= a[i] - b[j];
		}
	}
	
	map< ll, pair<int, int> > my_map;
	for(int i=0; i<n; i++){
		for(int j = i+1; j<n; j++){
			my_map[2*(a[i] + a[j])] = mp(i,j);
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=i+1; j<m; j++){
			ll val = sum_a - sum_b + 2*(b[i] + b[j]);
			auto it = my_map.lower_bound(val);
			if(it!=my_map.begin()) it--;
			
			for(int k=0; k<2; k++){
				if(it==my_map.end()) break;
				ll other = it->first;
				if(abs(val- other) < minDiff){
					minDiff = abs(val-other);
					ans.clear();
					ans.pb(mp(it->second.first, i));
					ans.pb(mp(it->second.second, j));
				}
				it++;
			}
		}
	}
	
	cout<<minDiff<<endl;
	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i].first+1<<" "<<ans[i].second +1<<endl;
	}
}
