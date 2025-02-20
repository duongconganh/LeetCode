/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* First = head ;
        ListNode* Second = head->next ;
        while(First != Second){
            if(Second->next == NULL || Second->next->next == NULL){
                return false;
            }
            First = First -> next;
            Second = Second->next->next;

        }
        return true;
    }
};