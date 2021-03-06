
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
	
	int n, a,b, t;
	cin>>n>>a>>b>>t;

	string str ;
	cin>>str;

	string left;
	left.pb(str[0]);
	for(int i=(n-1); i>=1; i--){
		left.pb(str[i]);
	}

	string right = str;

	vector<int> leftTime, rightTime;

	int origTime = 1;
	if(str[0]=='w'){
		origTime += b;
	}

	if(origTime>t){
		cout<<0<<endl;
		return 0;
	}

	leftTime.pb(origTime);
	for(int i=1; i<n; i++){
		int tm = leftTime[i-1];
		tm+= a+1;
		if(left[i]=='w'){
			tm += b;
		}
		leftTime.pb(tm);
	}
	/*cout<<"left times are "<<endl;
	for(int i=0; i<leftTime.size(); i++){
		cout<<leftTime[i]<<" "<<endl;
	}
	cout<<"right times are "<<endl;
	*/
	
	rightTime.pb(origTime);
	for(int i=1; i<n; i++){
		int tm = rightTime[i-1];
		tm+= a+1;
		if(right[i]=='w'){
			tm += b;
		}
		rightTime.pb(tm);
	}
	/*
	for(int i=0; i<rightTime.size(); i++){
		cout<<rightTime[i]<<" "<<endl;
	}
	*/
	//cout<<"left and turn back\n";
	// go left and then reiterate again in right direction
	int ans = 0;
	for(int i = 0; i<n; i++){
		//cout<<"i is "<<i<<endl; 
		if(leftTime[i] > t){
			break;
		}
		
		ans = max(ans, i +1);
		//cout<<"ans is "<<ans<<endl;

		int timeLeft = t - leftTime[i] - i*a;
		int first = 1;
		int last = n-i-1;
		int idx = -1;

		while(first<=last){
			int mid = (first + last)/2;
			if((rightTime[mid]-rightTime[0]) <= timeLeft){
				first = mid +1;
				idx = mid;
			}
			else{
				last = mid-1;
			}
		}
		if(idx!=-1){
			//cout<<"idx is "<<idx<<endl;
			ans = max(ans, idx + i +1);
			//cout<<"ans is "<<ans<<endl;
			
		}
	}

	//cout<<"right and turn back\n";
	// go right and then reiterate again in left direction
	for(int i = 0; i<n; i++){
		//cout<<"i is "<<i<<endl;
		if(rightTime[i] > t){
			break;
		}
		
		ans = max(ans, i +1);
		//cout<<"ans is "<<ans<<endl;

		int timeLeft = t - rightTime[i] - i*a;
		int first = 1;
		int last = n-i-1;
		int idx = -1;

		while(first<=last){
			int mid = (first + last)/2;
			if((leftTime[mid]-leftTime[0]) <= timeLeft){
				first = mid +1;
				idx = mid;
			}
			else{
				last = mid-1;
			}
		}
		if(idx!=-1){
			//cout<<"idx is "<<idx<<endl;
			ans = max(ans, idx + i +1);
			//cout<<"ans is "<<ans<<endl;
		}
	}


	cout<<ans<<endl;

}

// int(1e6) is equivalent to 10^6
