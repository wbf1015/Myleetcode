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
        int lenA = 0; ListNode* ita = headA;
        int lenB = 0; ListNode* itb = headB;
        while(ita!=nullptr){
            ita=ita->next;
            lenA++;
        }
        while(itb!=nullptr){
            itb=itb->next;
            lenB++;
        }

        ita = headA; itb = headB;
        int gap = max(lenA,lenB) - min(lenA, lenB);
        
        if(lenA>lenB){
            for(int i=1;i<=gap;i++){
                ita = ita->next;
            }
        }
        if(lenB>lenA){
            for(int i=1;i<=gap;i++){
                itb = itb->next;
            }
        }

        while(ita!=nullptr&&itb!=nullptr){
            if(ita==itb){
                return ita;
            }
            ita = ita->next;
            itb = itb->next;
        }
        return nullptr;
    }
};