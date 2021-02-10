#include<iostream>
using namespace std;

bool isValid(int** arr,int x,int y,int n) {
	if(x<n and y<n and arr[x][y]==1)
		return true;
	return false;
}


bool getPath(int **arr, int x,int y,int **sol,int n) {
	
	if(x==n-1 and y==n-1) {
		sol[x][y]=1;
		return true;
	}
	else {
		if(isValid(arr,x,y,n)){
			sol[x][y]=1;

			if(getPath(arr,x+1,y,sol,n))
				return true;
			if(getPath(arr,x,y+1,sol,n))
				return true;
			sol[x][y]=0;
		}
	}
	return false;
}
int main() {
	
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int** arr=new int*[n];
		for(int i=0;i<n;i++){
			arr[i]=new int[n];
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		}

		int **sol= new int*[n];
		for(int i=0;i<n;i++){
			sol[i]=new int[n];
			for(int j=0;j<n;j++)
				sol[i][j]=0;
		}

		if(getPath(arr,0,0,sol,n))
			cout<<"POSSIBLE"<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
		// cout<<"The rat can follow "<<endl;
		// for(int i=0;i<n;i++) {
		// 	for(int j=0;j<n;j++)
		// 		cout<<sol[i][j]<<" ";
		// 	cout<<endl;	
		// }
	}

	return 0;
}
