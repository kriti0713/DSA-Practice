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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *prevGroupEnd = dummy;

        while (true) {
        ListNode* kth = prevGroupEnd;
        for (int i = 0; i < k && kth; ++i) kth = kth->next;
        if (!kth) break; 
        
        ListNode* nextGroupStart = kth->next;
        
       
        ListNode* prev = nextGroupStart;
        ListNode* curr = prevGroupEnd->next;
        for(int i = 0; i < k; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        
        ListNode* temp = prevGroupEnd->next;
        prevGroupEnd->next = kth;
        prevGroupEnd = temp;
    }
    return dummy->next;
        
    }
};