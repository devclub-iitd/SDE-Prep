// Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        ListNode*n = head;
        ListNode*m = head->next;
        ListNode*r;
        while(n && m){
            r = m->next;
            m->next = n;
            n = m;
            m = r;
        }
        head->next = nullptr;
        return n;
    }
};
// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        else if(!(head->next))return new ListNode(head->val);
        ListNode*ans = reverseList(head->next);
        ListNode*n = ans;
        while(n->next)n=n->next;
        n->next = new ListNode(head->val);
        return ans;
    }
};