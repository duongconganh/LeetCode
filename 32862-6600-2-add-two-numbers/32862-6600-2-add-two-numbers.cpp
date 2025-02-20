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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int red = 0;
        ListNode* ptr = new ListNode(0);
        ListNode* ans = ptr;
        int x = 0;
        int y = 0;
        while(1){
            x = (l1 == NULL)?0:(l1 -> val);
            y = (l2 == NULL)?0:(l2 -> val);
            ptr->val = (x + y + red) % 10;
            red = (x + y + red)/10;
            if(l1 != NULL){
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                l2 = l2 -> next;
            }
            ListNode* newnode = new ListNode(0);
            if(red == 0 && l1 == NULL && l2 == NULL){
                break;
            }
            ptr->next = newnode;
            ptr = ptr->next;
        }
        return ans;
    }
};