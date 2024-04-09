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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *tmp = head;
        while (tmp != nullptr) {
            tmp = tmp->next;
            count++;
        }
        tmp = head;
        if (count > 2) {
            if (n == count) {
                tmp = tmp->next;
            }
            else {
                for (int i = 0; i < count-n; i++) {
                    if (i == count-n-1) {
                        tmp->next = tmp->next->next;
                    }
                    else if (n == 1 && i == count-n-1) {
                        tmp = nullptr;
                    }
                    else {
                        tmp = tmp->next;
                    }
                }
                tmp = head;
            }
        }
        else if (count == 2) {
            if (n == 2) {
                tmp = tmp->next;
            }
            else {
                tmp->next = nullptr;
            }
        }
        else {
            tmp = nullptr;
        }
        return tmp;
    }
};