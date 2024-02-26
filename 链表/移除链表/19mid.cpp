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
        ListNode* dummyhead = new ListNode(-1, head);

        int count = 0;
        ListNode* slownode = dummyhead;
        ListNode* fastnode = nullptr;
        
        for(ListNode* it=dummyhead; ;it=it->next){
            if(count++==n){
                fastnode=it;
                break;
            }
        }

        while(fastnode->next!=nullptr){
            fastnode = fastnode->next;
            slownode = slownode->next;
        }
        ListNode* tmp = slownode->next;
        slownode->next = slownode->next->next;
        delete tmp;
        return dummyhead->next;
    }
};