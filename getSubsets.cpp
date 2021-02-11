#include<iostream>
#include<vector>
using namespace std;

void displaySubsets(vector<vector<int>> v){
	for(int i=0;i<v.size();i++){
		for(auto it=v[i].begin();it!=v[i].end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

vector<vector<int>> getSubsets_itr(int n,vector<vector<int>> &v) {
	if(n>0){
		v.push_back({});
		v.push_back({1});
	}

	for(int num=2;num<=n;num++){
		int l=v.size();
		for(int i=0;i<l;i++){
		//	cout<<"Adding partitions... for "<<i<<endl;
			vector<int> r=v[i];
			r.push_back(num);
			v.push_back(r);
		}
	}
	return v;
}

vector<vector<int>> getSubsets_rec(int n,vector<vector<int>> &v){
	if(n==1){
		v.push_back({});
		v.push_back({1});
		return v;
	}
	else {
		getSubsets_rec(n-1,v);
		int l=v.size();
		for(int i=0;i<l;i++){
		//	cout<<"Adding partitions... for "<<i<<endl;
			vector<int> r=v[i];
			r.push_back(n);
			v.push_back(r);
		}
	}
	return v;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> v;
	//v=getSubsets_rec(n,v);
	//displaySubsets(v);
	v.clear();
	v=getSubsets_itr(n,v);
	displaySubsets(v);
	return 0;
}
