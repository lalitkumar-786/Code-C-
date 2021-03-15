typedef pair<int,int> pi;
class Solution {
public:
     
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> mymap;
        for(auto i:nums){
            mymap[i]++;
        }
        
        priority_queue<pi,vector<pi>,less<pi>> maxHeap;
        
        for(auto it:mymap){
            maxHeap.push({it.second,it.first});
        }
        
        while(k--){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
