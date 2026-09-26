class Solution {
public:
    ListNode* kth(ListNode* temp, int k) {
        k -= 1;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {

            ListNode* kthNode = kth(temp, k);

            // Less than k nodes remaining
            if (kthNode == NULL) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;

            // Cut current group
            kthNode->next = NULL;

            // Reverse current group
            reverseList(temp);

            // First group
            if (temp == head) {
                head = kthNode;
            }
            else {
                prevLast->next = kthNode;
            }

            // temp is now the last node of reversed group
            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};