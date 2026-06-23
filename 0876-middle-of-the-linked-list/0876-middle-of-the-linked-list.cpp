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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid1 = head;
        ListNode* mid2 = head;

        while(mid2 != nullptr && mid2->next != nullptr){
            mid1 = mid1->next;
            mid2 = mid2->next->next;
        }

        return mid1;
    }
};