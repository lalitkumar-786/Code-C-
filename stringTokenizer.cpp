/* The closer you see , the less you observe */

#include<bits/stdc++.h>
using namespace std;
#define boost std::ios::sync_with_stdio(false);
#define LL long long int
#define MOD 1000000007
#define MIN INT_MIN
#define MAX INT_MAX
#define mp make_pair
LL gcd(LL a,LL b)
{
	if(a==0)
	    return b;
	return gcd(b%a,a);
}

void printTokenizeChar(char *c) {
	char *ptr;
	cout<<"----- Conveted string into char and then tokenized it...---"<<endl;
	//split char by whitespaces
	ptr=strtok(c," ");
	while(ptr!=NULL) {
		cout<<ptr<<endl;
		ptr=strtok(NULL," ");
	}
}

int main()
{
	boost;
	int t;
	// Note the strtok expect a char* so you can't tokenize a string using strtok directly.
//	string s="Yes !! This script is there as I coded and pushed it to Git..";
	string s;
	getline(cin,s);
	// Using char*
	//Converted string into char
	char *sentence;
	sentence=&s[0];
	//cout<<sentence<<endl;
	printTokenizeChar(sentence);

	return 0;
}

