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
        ListNode* sm = new ListNode(0);
        ListNode* lg = new ListNode(0);
        ListNode* cs = sm;
        ListNode* cl = lg;
        while(head!=NULL){
            if(head->val < x){
                cs->next = head;
                head=head->next;
                cs = cs->next;
                cs->next = NULL;
            }
            else{
                cl->next = head;
                head=head->next;
                cl = cl->next;
                cl->next = NULL;
            }
            
        }
        cs->next = lg->next;
        return sm->next;

    }
};