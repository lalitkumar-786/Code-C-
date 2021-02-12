/* The closer you see, the less you observe */

#include<iostream>
using namespace std;


// Seems like O(n^3) 
void getAllSubarrays_itr(int arr[],int n){
	
	cout<<"Subarrays-"<<endl;
	for(int start=0;start<n;start++){
		for(int end=start;end<n;end++){
			for(int k=start;k<=end;k++)
				cout<<arr[k]<<" ";
			cout<<endl;
		}
	}
}



int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	getAllSubarrays_itr(arr,n);
	return 0;
}
