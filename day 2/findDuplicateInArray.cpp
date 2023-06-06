#include<bits/stdc++.h>
using namespace std;
//Method 1(Extra Space)
int findDuplicate(vector<int> &arr, int n){
	map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	int ans=-1;

	for(auto i:mp){
		if((i.second)>1) {
			ans=i.first;
			break;
		}
	}
	return ans;
}
//Method 2(Using constant space)
int findDuplicate(vector<int> &arr, int n){
	int ans=-1;
	for(int i=0;i<arr.size();i++){
		int index=abs(arr[i]);
		if(arr[index]<0) return index;
		arr[index]*=-1;
	}
	return ans;
}
int main(){
    vector<int>arr={1,1,2};
    cout<<findDuplicate(arr,3);
}