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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* swap1 = head;
        ListNode* swap2 = swap1->next;
        ListNode* n = swap2->next;

        while(swap2!=nullptr){
            swap2->next=swap1;
            swap1->next=n;
            if(swap1==head){
                head=swap2;
                pre=swap1;
            }else{
                pre->next=swap2;
                pre = swap1;
            }

            swap1=n;

            if(n==nullptr){
                return head;
            }
            swap2=n->next;
            
            if(swap2==nullptr){
                return head;
            }
            n = swap2->next;
            

        }
        return head;
    }
};