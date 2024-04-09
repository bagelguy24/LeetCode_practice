/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *listA = headA;
        ListNode *listB = headB;
        ListNode *ints = nullptr;
		
        while (listA != nullptr) {
            if (listB == nullptr) {
                listA = listA->next;
                listB = headB;
            }
            else if (listA->val != listB->val) {
                listB = listB->next;
            }
            else {
                ints = listA;

                while (&ints->val == &listB->val) {
                    if (ints->next == nullptr && listB->next == nullptr) {
                        return listA;
                    }
                    ints = ints->next;
                    listB = listB->next;
                }
                listA = listA->next;
            }
        }
        return nullptr;
    }
};