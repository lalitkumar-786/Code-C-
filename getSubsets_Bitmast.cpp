/* The closer you see, the less you observe.*/
#include<iostream>
#include<math.h>
using namespace std;

void getSubsets(char *s,int n){
	int total=(1<<n)-1;
	for(int i=0;i<=total;i++){
		for(int j=0;j<n;j++){
			if(i & (1<<j))
				cout<<s[j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	char* s;
	cin>>s;
	getSubsets(s,strlen(s));

    return 0;
}

