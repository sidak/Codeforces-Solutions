
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
typedef queue<pair<long long,long long> > qpll;

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
	iOS;
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	
	ll n, b;
	//scanf("%lld %lld", &n, &b);
	cin>>n>>b;
	vpll reqs;
	qpll save;
	queue<ll> indices;
	for(ll i=0; i<n; i++){
		ll t, d;
		//scanf("%lld %lld", &t, &d);
		cin>>t>>d;
		reqs.pb(mp(t,d));
	}
	vector<ll> ans(n,0);
	ll tm =0;
	ll inq = 0;
	// it is guaranteed that t_i < t_i-1 (storing a single element may turn out to be sufficient) 
	// we will need one more queue in which the req are stored until capacity  
	// otherwise reject them if capacity exceeded
	// when the new entries in reqs have start time later than the time of ending of the current running query
	// then get an element from the queue, insert the incoming one (we can always insert the first req after the current query's completion)
	// update prev req start time and end time 
	ll idx = 0;

	while(!save.empty() || idx<n ){

		if(save.empty() && idx<n){
			save.push(reqs[idx]);
			tm = reqs[idx].F;
			indices.push(idx);
			inq ++;
			idx++;
		}

		pll svreq = save.front();
		tm += svreq.S;
		ans[indices.front()] = tm;
		indices.pop();
		save.pop();
		inq --;

		while(idx<n && reqs[idx].F<tm){
			if(inq<b){
				save.push(reqs[idx]);
				indices.push(idx);
				inq++;
			}
			else{
				ans[idx] = -1;
			}
			idx++;
		}

	}

	for(int i=0; i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;


}

// int(1e6) is equivalent to 10^6
