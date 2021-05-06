/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        ListNode *cur;
        cur=head;
        vector<int> v;
        int arr[100005]={0};
        int i=0;
        while(cur!=NULL){
            arr[i++]=cur->val;
            cur=cur->next;
        }
        
        sort(arr,arr+i);
        cur=head;
        i=0;
        while(cur!=NULL){
            cur->val=arr[i++];
            cur=cur->next;
        }
        return head;   
    }
};
