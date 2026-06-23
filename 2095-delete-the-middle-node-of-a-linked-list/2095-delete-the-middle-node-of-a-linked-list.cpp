
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

    if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next->next;
       

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = slow->next->next;
        delete mid;

        return head;
    }
};