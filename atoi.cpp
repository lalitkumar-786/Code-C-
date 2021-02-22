 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}


/*You are required to complete this method */

// test cases
// 123
// 1024
// -19
// 1000
int atoi(string str)
{
    //Your code here
    if(str.empty())
        return 0;
    int flag=0;
    if(str[0]=='-'){
        str.erase(str.begin());
        flag=1;        
    }
    for(int i=0;i<str.length();i++){
            if(!isdigit(str[i]))
                return -1;
    }
    reverse(str.begin(),str.end());
    int res=0;
    for(int i=0;i<str.length();i++){
            res=int(str[i]-'0')*pow(10,i)+res;
    }
    if(flag)
        res=-res;
     return res;
}
