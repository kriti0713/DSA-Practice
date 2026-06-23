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
        int l1 = 0;
        int l2 = 0;
        ListNode* t = headA;
        while(t != nullptr) {
            l1++;
            t = t->next;
        }
        ListNode* t2 = headB;
        while(t2 != nullptr){
            l2++;
            t2 = t2->next;
        }

        if(l1>l2){
            for(int i=0; i<l1-l2; i++) headA = headA->next;
        } else{
            for(int i = 0; i<l2-l1; i++) headB = headB->next;
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
        // if(headA== nullptr || headB == nullptr) return nullptr;
        // ListNode* a = headA;
        // ListNode* b = headB;
        // while(a!=b){
        //    if(a == nullptr){
        //     a = headB;
        //    }
        //    else{
        //     a = a->next;
        //    }

        //    if(b== nullptr){
        //     b = headA;
        //    }
        //    else{
        //     b = b->next;
        //    }

        // }
    
        
    }
};