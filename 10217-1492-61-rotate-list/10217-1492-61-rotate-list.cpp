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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr ||head ->next == nullptr){
            return head;
        }
        ListNode* ptr = head;
        ListNode* first = head;
        ListNode* ans = new ListNode(1);
        ans->next = head;
        ListNode* last = head;
        int count = 0;
        while(head){
            if(head->next == nullptr){
                last = head;
            }
            head = head->next;
            count++;
        }
        k = k % count;
        if(k == 0){
            return ans->next;
        }
        int step = 0;
        while(1){
          step++;
          if(step == count - k){
            ans->next = ptr->next;
            last->next = first;
            ptr->next = nullptr;
            break;
          }
          ptr = ptr->next;
        }
        cout<<count;
        return ans->next;
    }
};