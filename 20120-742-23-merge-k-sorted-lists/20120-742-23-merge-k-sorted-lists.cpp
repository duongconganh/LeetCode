class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return result(lists, 0, n - 1);
    }
    ListNode* result(vector<ListNode*>& lists, int l, int r){
        if(l > r){
            return nullptr;
        }
        if(l == r){
            return lists[l];
        }
        int n = l + (r - l) / 2 ;

        return merge(result(lists, l, n),result(lists, n + 1, r));
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