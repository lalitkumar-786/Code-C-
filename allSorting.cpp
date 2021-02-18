/* The closer you see, the less you observe.*/
#include<iostream>
using namespace std;

// 5 1 3 2 6
void displayElements(int arr[],int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void selectionSort(int arr[],int n){
	int minIndex,temp;

	for(int curIndex=0;curIndex<n;curIndex++){
		minIndex=curIndex;
		for(int i=curIndex+1;i<n;i++){
			if(arr[i]<arr[minIndex])
				minIndex=i;
		}
		temp=arr[curIndex];
		arr[curIndex]=arr[minIndex];
		arr[minIndex]=temp;

	}
}

int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	selectionSort(arr,n);

	cout<<"Selection sort result --"<<endl;
	displayElements(arr,n);
        return 0;
}

