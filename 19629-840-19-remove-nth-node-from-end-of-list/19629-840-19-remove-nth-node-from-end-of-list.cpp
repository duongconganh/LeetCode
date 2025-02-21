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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        ListNode* ans = new ListNode(0);
        ans -> next = head;
        ListNode* temp = ans;
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        int step = 0;

        while(1){
            if(step >= count - n){
                ans->next = ans->next->next;
                break;
            }
            ans = ans->next;
            step++;
        }

        return temp->next;
        
    }
};