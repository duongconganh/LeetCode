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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        int temp = -200;
        int count = 0;

        ListNode* ans = new ListNode(-1);
        ListNode* n;
        ans->next = nullptr;
        ListNode* result = ans;
        while(head){
            if(temp != head->val){
                if(count == 1){
                    n = new ListNode(temp);
                    ans->next = n;
                    ans = ans->next;
                }
                count = 0;
            }

            temp = head->val;
            count ++;
            head = head->next;
        }
        if(count == 1){
            n = new ListNode(temp);
            ans->next = n;
            ans = ans->next;
        }
        return result -> next;
    }
};