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

    ListNode*findnthnode(ListNode*head,int k){
        ListNode*temp=head;
        while(temp!=nullptr){
            k--;
            if(k==0) break;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr || k==0) return head;
        
        ListNode*tail=head;
        int len=1;
        while(tail->next!=nullptr){
            len++;
            tail=tail->next;
        }

        if(k%len==0) return head;
        k=k%len;

        tail->next=head;

        ListNode*newlastNode=findnthnode(head,len-k);

        head=newlastNode->next;

        newlastNode->next=nullptr;


        return head;

    }


};