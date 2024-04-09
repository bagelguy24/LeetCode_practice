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
    
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *prev = curr;
        
        if (curr == nullptr) {
            return nullptr;
        }
        if (curr->next != nullptr) {
            while (curr->next->next != nullptr) {
                if (curr->next->val == val) {
                    curr->next = curr->next->next;
                }
                else {
                    curr = curr->next;
                }
            }
            if (curr->next->next == nullptr && curr->next->val == val) {
                curr->next = nullptr;
            }
        }
        if (prev->val == val) {
            prev = prev->next;
        }
        
        return prev;
    }
};