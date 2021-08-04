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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left=NULL, *right=NULL, *preLeft=NULL, *preRight=NULL, *leftHead=NULL, *rightHead=NULL;

        ListNode *cur=head;

        while(cur!=NULL){
            if(cur->val>=x){
                //right
                ListNode *new_node = new ListNode(cur->val);
                if(preRight){
                    preRight->next=new_node;
                    preRight=new_node;
                }
                else{
                    rightHead=new_node;
                    preRight=rightHead;
                }
            }
            else{
                //left
                ListNode *new_node = new ListNode(cur->val);

                if(preLeft){
                    preLeft->next=new_node;
                    preLeft=new_node;
                }
                else{
                    leftHead=new_node;
                    preLeft=leftHead;
                }
            }
            cur=cur->next;
        }

        if(leftHead){
            preLeft->next=rightHead;
            return leftHead;
        }
        else
            return rightHead;

    }
};
