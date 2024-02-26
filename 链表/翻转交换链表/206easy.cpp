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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* origin_next = head->next;
        for(ListNode*it=head; ;){
            ListNode* for2 = origin_next->next;
            if(it==head) it->next=nullptr;
            origin_next->next = it;
            it = origin_next;
            origin_next = for2;

            if(for2==nullptr){
                head=it;
                return head;
            }
        }
        return nullptr;
    }
};