class Solution {
public:
    ListNode*ans;
    int a,b,c,d,e;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ans = new ListNode;
        ans->val = 0;
        a = 0;b = 0;c = 0;
        ListNode*temp = headA;
        while(temp){
            a^=(temp->val);
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            b^=(temp->val);
            temp=temp->next;
        }
        c = !(a^b);
        d = a^c;
        e = 0;
        temp = headA;
        cout<<d;
        while(temp){
            e = temp->val;
            temp = temp->next;
            if(e==d)return temp;
        }
        return ans;
    }
};
