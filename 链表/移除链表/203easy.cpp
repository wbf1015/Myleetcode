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
        if(head==nullptr){
            return head;
        }
        while(head->val==val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            if(head==nullptr){
                return head;
            }
        }
        for(ListNode* it=head; it->next!=nullptr; ){
            if(it->next->val==val){
                ListNode* tmp = it->next;
                it->next=it->next->next;
                delete tmp;
                if(it==nullptr) break;
                // 在这里不能把指针移过去，因为一直判断的都是下一个
            }else{
                it = it->next;
            }
        }
        return head;
    }
};