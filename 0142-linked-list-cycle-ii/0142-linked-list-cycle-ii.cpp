/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode *FlyodDetectionLoop(ListNode* head){
  if(head==NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            

            if(fast == slow){
                return slow;
            }
        }
        return NULL;
 }

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
       ListNode *intersection = FlyodDetectionLoop(head);
       if(FlyodDetectionLoop(head) == NULL){
           return NULL;
       }
       ListNode *slow = head;

       while(slow != intersection){
           slow = slow->next;
           intersection = intersection->next;
       }
       return slow;

        
    }
};