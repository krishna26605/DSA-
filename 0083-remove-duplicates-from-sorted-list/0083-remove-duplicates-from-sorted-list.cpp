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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==nullptr || head->next==nullptr) return head;

        ListNode*t1=head;
        ListNode*t2=head->next;
        

        while(t2!=nullptr){
            if(t1->val==t2->val){
                ListNode*nextnode=t2->next;
                t1->next=t1->next->next;
                delete(t2);
                t2=nextnode;
            }
            else{
                t1=t1->next;
                t2=t2->next;
            }
        }

        return head;
    }
};