class Solution {
public:
    
    //poplulate all phone numbers in map 
    // 2--> abc
    // 3--> def ...
    void defMap(map<int,vector<char>> &mymap){ 
      
        int count;
        int j=97;
        for (int i=2;i<=9;i++){
            if(i==7 || i==9)
                count=-1;
            else
                count=0;
        
            while(true){
                mymap[i].push_back(char(j));
                count++;
                j++;
                if(count==3)
                    break;
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map<int,vector<char>> mymap;
        vector<string> res;
        
        //construct the map 
        defMap(mymap);
        
        int l=digits.length();
        if(l==0)
            return res;
        
        // List is kind of doubly link list. 
        list<string> mylist;
        mylist.push_back("");
        
        for(int i=0;i<l;i++){
            
            //digits="23"--> convert string '2' to int 2 and likewise
            int d=int(digits[i]-'0');
            int list_size= mylist.size();
            
            for(int j=0;j<list_size;j++){
                    string s=mylist.front();
                    mylist.pop_front();
                    
                    for(auto chr:mymap[d]){
                        string temp;
                        
                        //Convert char to string and concatenate it with existing list string
                        temp=s;
                        temp.push_back(chr);
                        mylist.push_back(temp);
                    }        
            }            
        }
        
        //copy list to the vector and return it
        vector<string> res1(mylist.begin(),mylist.end());
        
        return res1;
    }
};
