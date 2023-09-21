class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>&lists) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            {
                minheap.push({lists[i]->val,i});
            }
        }
        if(minheap.empty())
        {
            return NULL;
        }
        ListNode* node=new ListNode();
        ListNode* head=node;//store the head of ans
        while(1)
        {
            pair<int,int>x=minheap.top();
            minheap.pop();
            node->val=x.first;
            if(lists[x.second]->next!=NULL)//check if end of list not reached
            {
                lists[x.second]=lists[x.second]->next;//traverse list further
                minheap.push({lists[x.second]->val,x.second});//push value of current pointer at this list
            }
            if(!minheap.empty())//still elements exist to insert in list
            {
                node->next=new ListNode();
                node=node->next;
            }
            else
            {
                break;
            }
        }
        return head;
    }
};