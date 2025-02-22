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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        temp->next = head;
        ListNode* first;
        ListNode* last;
        ListNode* newnode;
        ListNode* check;
        int count = 0;
        while(head){
            count++;
            if(count == k){
                newnode = new ListNode(head->val);
                newnode->next = first;
                first = newnode; 
                temp->next = first;
                temp = last;
                count = 0;
            }else if(count == 1){
                newnode = new ListNode(head->val);
                check = head;
                last = newnode;
                first = newnode;
            }else{
                newnode = new ListNode(head->val);
                newnode->next = first;
                first = newnode;
            }

            head = head->next;
        }
        if(count != 0){
            temp -> next = check ;   
        }
        return ans->next;
    }
};