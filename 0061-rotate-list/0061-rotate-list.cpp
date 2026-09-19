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
    
    ListNode* f(ListNode* head,int t){
        int cnt = 1;
        while(head!=NULL){
            if(cnt==t) return head;
            head=head->next;
            cnt++;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        int len = 1;
        ListNode * tail = head;
        while(tail->next!=NULL){
            
            tail=tail->next;
            len++;
        }
        if(k%len==0){
            return head;
        }
        k=k%len;
        tail->next = head;
        ListNode * nn = f(head,len-k);
        head = nn->next;
        nn->next = NULL;
        return head;
    }
};