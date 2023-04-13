/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private: 
    void insert(Node* &head,Node* &tail,int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insert(clonehead,clonetail,temp->val);
            temp = temp->next;
        }
            //clone node 
        Node* originalnode = head;
            Node* clonenode = clonehead;
            while(originalnode!=NULL && clonenode!=NULL){
                Node* next = originalnode->next;
                originalnode->next = clonenode;
                originalnode = next;
                   next = clonenode->next;
                clonenode->next = originalnode;
                clonenode = next;
            }
            
            temp = head;
            while(temp!=NULL){
                if(temp->next!=NULL){
                    temp->next->random = temp->random
                        ?temp->random->next:NULL;
                }
                temp = temp->next->next;
            }
              originalnode = head;
             clonenode = clonehead;
            while(originalnode!=NULL && clonenode!=NULL){
                originalnode->next = clonenode->next;
                originalnode = originalnode->next;
                  if(originalnode!=NULL){
                clonenode->next = originalnode->next;
                  }
                clonenode = clonenode->next;
                
                  
            }
            
        
        return clonehead;
        
    }
};