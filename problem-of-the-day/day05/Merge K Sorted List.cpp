
class Solution {
public:
    ListNode* mergetwo(ListNode* h1, ListNode* h2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while(h1 && h2) 
        {
            if(h1->val < h2->val)
            {
                ptr->next = h1;
                h1 = h1->next;
            }
            else
            {
                ptr->next = h2;
                h2 = h2->next;
            }
            ptr = ptr->next;
        }

        // to check if any list is remaining, then adding the rest of the remaining list to dummy list whih is our answer
        if(h1!=NULL) ptr->next = h1; 
        if(h2!=NULL) ptr->next = h2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* temp = lists[0];
        if(lists.size()>1)
        {
            for(int i=1;i<lists.size();i++)
            {
                temp = mergetwo(temp,lists[i]);
            }
        }
        return temp;
    }
};