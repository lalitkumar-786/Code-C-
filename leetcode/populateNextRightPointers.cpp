/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root){
        queue<Node*> q;
        q.push(root);
        
        int count=1;
        int flag=0;
        Node* pre=NULL;
        int startingLevel=1;
        while(!q.empty()){
            Node* temp=q.front();
         
            if(count!=startingLevel)
                pre->next=temp;
            
            q.pop();
            count--;
               
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
            if(count==0){
                temp->next=NULL;
                count=q.size();
                startingLevel=count;
            }
            pre=temp;
        }
    }
    Node* connect(Node* root) {
        if(root==NULL)
           return root;
         bfs(root);
        return root;
    }
};
