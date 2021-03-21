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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *oddList=head,*evenList=head->next;
        ListNode *evenStart=head->next;
        
        while(evenList and evenList->next){
            oddList->next=evenList->next;
            oddList=oddList->next;
            
            evenList->next=oddList->next;
            evenList=evenList->next;
        }
        oddList->next=evenStart;
        return head;
    }
};
