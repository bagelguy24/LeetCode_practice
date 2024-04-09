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
    int cycle = 0;
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            std::cout << "head == NULL" << endl;
            return false;
        }
        if (head->next == NULL) {
            std::cout << "head->next == NULL" << endl;
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (slow != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == NULL || fast->next == NULL) {
                break;
            }
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};