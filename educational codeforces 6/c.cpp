#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector<int> arr;
	for(int i =0; i<n; i++){
		int x;
		scanf("%d", &x);
		arr.push_back(x);
	}
	
	vector< pair<int, int> > ans;
	int k =0;
	unordered_map<int, bool> hmap;
	int st = 1;
	for(int i=1; i<=n; i++){
		if(hmap.find(arr[i-1])!=hmap.end()){
			int l = st;
			int r = i;
			k++;
			st = r+1;
			ans.push_back(make_pair(l,r));
			hmap.clear();
		}
		else{
			hmap[arr[i-1]] = true;
		}
	}
	
	
	if(k==0) printf("-1\n");
	else{
		if(st<=n){
			ans[ans.size()-1].second = n;
		}
	
		printf("%d\n", k);
		for(int i=0; i<ans.size(); i++){
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	
}
