
#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define ppb pop_back
#define mp(x,y) make_pair((x),(y))
//#define sd(n) scanf("%d" , &n);
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define maX(a,b)   ( (a) > (b) ? (a) : (b))
#define miN(a,b)   ( (a) < (b) ? (a) : (b))
#define bitcount   __builtin_popcount
#define mset(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forit(it, s) for(typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it) 
#define F first
#define S second
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define LEN(X) strlen(X)
#define iOS ios_base::sync_with_stdio(false)
const double pi = acos(-1.0);

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<long long> vl;
typedef pair<long long,long long> pll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs;
typedef long double ld;
typedef  long long ll;
typedef unsigned long long ull;
string NumberToString ( ll Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}


ll StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a 
{                               //character array as argument
	stringstream ss(Text);
	ll result;
	return ss >> result ? result : 0;
}

void solve(){
	
}
#ifdef DEBUGIT
  #define DEBUG(X) cerr << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << X << endl
#else
  #define DEBUG(X) (void)0
#endif

int main(){
	ll n,k;
	cin>>n>>k;
	vector<ll> bt;
	for(ll i=0; i<n; i++){
		ll x;
		cin>>x;
		bt.pb(x);
		
	}
	vector<ll> idx;
	map<ll, ll> mp;
	for(ll i=0; i<k; i++){
		ll x;
		cin>>x;
		idx.pb(x-1);
		mp[x-1]=1;
	}
	ll ans = bt[0]*bt[n-1];
	for(ll i=0; i<=(n-2); i++){
		ans += (bt[i]*bt[i+1]);
	}
	//cout<<" ans before is "<<ans<<endl;
	
	vector<ll> capsum;
	ll bval = 0;
	for(ll i=k-1; i>=1; i--){
		bval += bt[idx[i]];
		capsum.pb(bval);
	}
	
	for(ll i=0; i<(k-1); i++){
		ll other_cap = capsum[k-2-i];
		if(mp.find(idx[i]+1)!=mp.end()){
			other_cap-=bt[idx[i]+1];
		}
		if(idx[i]==0 && mp.find(n-1)!=mp.end()){
			other_cap-=bt[n-1];
		}
		ans+= bt[idx[i]]*other_cap;
	}
		/*
		for(ll j=i+1; j<k; j++){
			if( ((idx[i]+1)==idx[j]) || (idx[i]==0 && idx[j]==(n-1)) || (idx[j]==0 && idx[i]==(n-1)) ) continue;
			ans+= (bt[idx[i]]*bt[idx[j]]);
			//cout<<"idx i is "<<idx[i]<<" and idx j is "<<idx[j]<<endl;
		}
	}
	*/
	
	ll all_except_cap = 0;
	for(ll i=0; i<n; i++){
		if(mp.find(i)==mp.end()){
			all_except_cap += bt[i];
		}
	}
	
	for(ll i=0; i<k; i++){
		ll val = all_except_cap;
		if((idx[i]+1)<n && mp.find(idx[i]+1)==mp.end()){
			val -= bt[idx[i]+1];
		}
		if((idx[i]-1)>=0 && mp.find(idx[i]-1)==mp.end()){
			val -= bt[idx[i]-1];
		}
		if(idx[i]==0 && mp.find(n-1)==mp.end()){
			val -= bt[n-1];
		}
		if(idx[i]==(n-1) && mp.find(0)==mp.end()){
			val -= bt[0];
		}
		ans+= bt[idx[i]]*val;
		
		/*
		for(ll j=0; j<n; j++){
			if((idx[i]!=j) && mp.find(j)==mp.end()){
				if( ((idx[i]+1)==j) || ((idx[i]-1)==j) || (idx[i]==0 && j==(n-1)) || (j==0 && idx[i]==(n-1)) ) continue;
				ans += (bt[idx[i]]*bt[j]);
				//cout<<"idx i is "<<idx[i]<<" and idx j is "<<j<<endl;
			}
			
		}
		*/
	}
	cout<<ans<<endl;
}
