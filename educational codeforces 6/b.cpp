#include<bits/stdc++.h>
using namespace std;

int arr[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int addDig(int x){
	if(x==0){
		return arr[x];
	}
	
	int sum =0;
	while(x>0){
		int dig = x%10;
		x/=10;
		sum+= arr[dig]; 
	}
	
	return sum;
}
int main(){
	int a, b;
	cin>>a>>b;
	
	int sum =0;
	for(int i=a; i<=b; i++){
		sum += addDig(i);
	}
	cout<<sum<<endl;
}
