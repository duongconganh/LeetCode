#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow -> next;
        slow -> next = nullptr;

        return merge(sortList(head),sortList(fast));
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* node = new ListNode(0);
        ListNode* ans = node;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                node -> next = l1;
                node = l1;
                l1 = l1 -> next;
            }else{
                node -> next = l2;
                node = l2;
                l2 = l2 -> next;
                }
        }
        if(!l1){
            node -> next = l2;
            return ans -> next;
        }
        node -> next = l1;
        return ans -> next;           
    

    }

};