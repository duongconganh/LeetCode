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
        ListNode* ptr = head;
        ListNode* small = new ListNode(-300);
        ListNode* ans =  small;
        ListNode* big = new ListNode(-300);
        ListNode* big1 =  big;
        ListNode* temp;
        int y;
        while(head){
            y = head->val;
            temp = new ListNode(y);
            if(y < x){
                small->next = temp;
                small = small->next;
            }else{
                big->next = temp;
                big = big->next;
            }
            head= head->next;
        }
        small->next = big1->next;
        return ans->next;
    }
};