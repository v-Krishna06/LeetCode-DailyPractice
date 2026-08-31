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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> node;
        int n = 1;
        ListNode *curr = head->next;
        ListNode *prev = head;
        while(curr->next ){
            n++;
            if((prev->val > curr->val) && (curr->val < curr->next->val)){
                node.push_back(n);
            }
            else if ((prev->val < curr->val) && (curr->val > curr->next->val)){
                node.push_back(n);
            }
            prev=curr;
            curr=curr->next;
        }
        
        if(node.size()>1){
            int mx = node[node.size()-1]-node[0];
            int mn = INT_MAX;
            cout<<node.size();
            for(int i=1;i<node.size();i++){
                mn = min(mn,node[i]-node[i-1]);
                
            }
            return {mn,mx};
        }
        return {-1,-1};
        

    }
};