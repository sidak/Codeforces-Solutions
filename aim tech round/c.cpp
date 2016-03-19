
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
	iOS;
	//std::ios::sync_with_stdio(false);  
	// uncomment it or use scanf and printf
	//cout << "Minimum value for long long int(or other datatype): " << std::numeric_limits<long long int>::min() << '\n';
	// instead of min() use max() to get the maximum value in the previous case
	//scanf returns the number of items succesfully converted  or EOF on error
	
	int n,m;
	cin>>n>>m;
	// remove self things
	vector < vector<int> > adj (n, vector<int>(m,0) );
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		adj[x-1][y-1]=1;
		adj[y-1][x-1]=1;
	}
	
	map<int,int> b;
	for(int i=0; i<n; i++){
		int ct =0;
		for(int j=0; j<n; j++){
			if(adj[i][j]==1)ct++;
		}
		if(ct==(n-1)){
			b[i]=1;
		}
	}
	
	set<int> u, v;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(adj[i][j]==1){
				if(b.find(i)==b.end() && b.find(j) == b.end()){
					u.insert(i);
					v.insert(j);
				}
			}
		}
	}
	vector<int> vec;
	auto it=std::set_intersection (u.begin(), u.end(), v.begin(), v.end(), vec.begin());
                                               // 10 20 0  0  0  0  0  0  0  0
	//v.resize(it-v.begin());                      // 10 20
	if(vec.size()>0)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	
	
}

// int(1e6) is equivalent to 10^6
