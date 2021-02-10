#include<iostream>
using namespace std;

void printPath(int** sol,int n) {
	cout<<"one of the valid paths: "<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
}

bool isValid(int** arr,int x,int y,int n,int **sol) {
	if(x<n and y<n and x>=0 and y>=0 and arr[x][y]==1 and sol[x][y]==0)
		return true;
	return false;
}


bool getPath(int **arr, int x,int y,int **sol,int n) {
	
	if(x==n-1 and y==n-1) {
		sol[x][y]=1;
		printPath(sol,n);
		return true;
	}
	else {
		if(isValid(arr,x,y,n,sol)){
			sol[x][y]=1;

			getPath(arr,x,y+1,sol,n);
			getPath(arr,x-1,y,sol,n);
			getPath(arr,x+1,y,sol,n);
			getPath(arr,x,y-1,sol,n);

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

		getPath(arr,0,0,sol,n);
	}

	return 0;
}
