
#include <bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define ppb pop_back
#define mp(x,y) make_pair((x),(y))
//#define sd(n) scanf("%d" , &n);
#define sz(v) ll((v).size())
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define maX(a,b)   ( (a) > (b) ? (a) : (b))
#define miN(a,b)   ( (a) < (b) ? (a) : (b))
#define bitcount   __builtin_popcount
#define mset(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2ll(c) (c-'0')
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forit(it, s) for(typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it) 
#define F first
#define S second
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) ll (X); scanf("%d", &X)
#define DRII(X, Y) ll X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) ll X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define LEN(X) strlen(X)
#define iOS ios_base::sync_with_stdio(false)
const double pi = acos(-1.0);

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
	iOS;
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and prllf
	//cout << "Minimum value for long long ll(or other datatype): " << std::numeric_limits<long long ll>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	
	ll n;
	map<ll, ll> same_x, same_y;
	map<pair<ll, ll>, ll> same_xy;
	cin>>n;
	for(ll i=0; i<n; i++){
		ll x,y;
		cin>>x>>y;
		same_x[x]++;
		same_y[y]++;
		same_xy[make_pair(x,y)]++;

	}

	ll ans =0;

	for(auto it = same_x.begin(); it!=same_x.end(); it++){
		if(it->second >1){
			ans += (it->second * (it->second -1))/2;
		}
	}

	for(auto it = same_y.begin(); it!=same_y.end(); it++){
		if(it->second >1){
			ans += (it->second * (it->second -1))/2;
		}
	}
	
	for(auto it = same_xy.begin(); it!=same_xy.end(); it++){
		if(it->second >1){
			ans -= (it->second * (it->second -1))/2;
		}
	}
	
	cout<<ans<<endl;	
}

// ll(1e6) is equivalent to 10^6
