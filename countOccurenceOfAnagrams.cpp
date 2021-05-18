#include<iostream>
#include<map>
using namespace std;

// To store frequency 
map<char,int> freq;

// To calcualte all freq of word
void storeFreq(string word){
    for(auto it:word)
        freq[it]++;
}

// To display freq of word
void display(map<char,int> f){
    cout<<"Freq is "<<endl;
    for(auto it:f)
        cout<<it.first<<" and value is "<<it.second<<endl;
    
}

// To compare actual freq and the temp freq for sliding window
bool checkMaps(map<char,int> freq,map<char,int> tempFreq){
  
    if(freq==tempFreq)
        return true;
    else
        return false;
    
}

int countAnagrams(string text, string word){

    storeFreq(word);

    int i=0,j=0;
    int l=text.length();
    int numOfChrs=word.length();
    map<char,int> tempFreq;
    int ans=0;

    while(j<l){
       
        if(freq.find(text[j])!=freq.end())
            tempFreq[text[j]]++;
     
        if(j-i+1==numOfChrs){
            if(checkMaps(freq,tempFreq))
                    ans++;
          
            if(freq.find(text[j])!=freq.end())
                tempFreq[text[i]]--;

            i++;
        }
        j++;
    }

    return ans;

}

int main()
{
    string text = "aabaabaa";
    string word = "aaba";
     
    cout << countAnagrams(text, word)<<endl;
     
    return 0;
}
