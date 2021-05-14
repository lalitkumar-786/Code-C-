class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0;
        int end=letters.size()-1;
        int l=letters.size();
        char res;
        
        //check index out of bound
        if(int(letters[end])<int(target))
            return letters[0];
        
        while(start<=end){
            int mid=(start+(end-start)/2);
            
            if(int(letters[mid])>int(target)){
                res=letters[mid];
                end=mid-1;
            }
            else if(int(letters[mid])<int(target)) 
                start=mid+1;
            else{
                if(int(letters[(mid+1)%l])==int(letters[mid]))
                    start=mid+1;
                else 
                    return letters[(mid+1)%l];
            }          
        }
        
        return res;
    }
};
