class MinStack {
public:
    /** initialize your data structure here. */
    struct Node {
        int data;
        int min;
        Node *next;
    };
    
    struct Node* head;
    MinStack() { 
        head=NULL;
    }
    
    void push(int val) {
        struct Node *new_node = new Node();
        if(head==NULL){
             new_node->data=val;
             new_node->min=val;
             new_node->next=NULL;
        }
        else{
             new_node->data=val;
             new_node->min=min(val,head->min);
             new_node->next=head;
        }
        head=new_node;
    }
    
    void pop() {
        head=head->next;
    }
    
    int top() {
        return head->data;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
