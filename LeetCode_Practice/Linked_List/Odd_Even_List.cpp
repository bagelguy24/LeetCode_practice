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
    int count = 1;
    bool even = false;
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *tmp = head;
        ListNode *curr = tmp;
        ListNode *prev = curr;
        ListNode *ooo = prev;
        
        while (tmp->next != nullptr) {
            tmp = tmp->next;
            count++;
        }
        
        while (curr->next != nullptr && count > 0) {
            if (even) {
                tmp->next = new ListNode(curr->val);
                tmp = tmp->next;
                curr = curr->next;
                prev->next = prev->next->next;
                prev = prev->next;
                even = false;
            }
            else {
                curr = curr->next;
                even = true;
            }
            count--;
        }
        
        return ooo;
    }
};