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
	ListNode* dummy = new ListNode();
	ListNode* temp = dummy;
	ListNode *itr1 = list1, *itr2 = list2;
	while(itr1 != NULL && itr2!=NULL) {
		if(itr1->val < itr2->val) {
			temp->next = itr1;
			itr1 = itr1->next;
		} 
		else {
			temp->next = itr2;
			itr2 = itr2->next;
		}
		temp = temp->next;
	}
	if(itr1 != NULL) temp->next = itr1;
	else temp->next = itr2;
	ListNode* sortedList = dummy->next;
	delete dummy;
	return sortedList;
}
};
