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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list1 == NULL)
        {
			return list2;
		}
		
		if(list2 == NULL)
        {
			return list1;
		} 

        ListNode * ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }

        ListNode* ans = ptr;
        ListNode* cur = ans;
        while(list1 && list2){

            if(list1->val < list2->val){
                ans->next = list1;
                list1 = list1->next;
            }else{
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }
        if(list1 == NULL){
            ans->next = list2;
        }else{
            ans->next = list1;
        }
        return cur;
    }
};