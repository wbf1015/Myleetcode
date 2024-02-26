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
    ListNode *detectCycle(ListNode *head) {
        // 空链表或者只有一个节点的非环链表
        if(head==nullptr||head->next==nullptr){
            return nullptr;
        }

        ListNode* slowpoint = head;
        ListNode* fastpoint = head;
        while(true){
            slowpoint = slowpoint->next;
            fastpoint = fastpoint->next;
            // 快指针走出去了，说明没有环路
            if(fastpoint==nullptr){
                return nullptr;
            }
            fastpoint = fastpoint->next;
            // 快指针走出去了，说明没有环路
            if(fastpoint==nullptr){
                return nullptr;
            }
            if(slowpoint==fastpoint){
                break;
            }
        }
        ListNode* point1 = head;
        ListNode* point2 = slowpoint;
        while(point1!=point2){
            point1=point1->next;
            point2=point2->next;
        }
        return point1;
    }
};