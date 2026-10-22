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
    
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l==r){
            return head;
        }
        ListNode* dummy = new ListNode(0,head);
        ListNode* p = dummy;
        for( int i = 1;i<l;i++){
            p=p->next;
        }
        ListNode* c = p->next;
        for(int i = 0;i<r-l;i++){
            ListNode* n = c->next;
            c->next = n->next;
            n->next = p->next;
            p->next = n;
        }
        return dummy->next;
    }
};