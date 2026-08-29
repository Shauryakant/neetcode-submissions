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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* t=dummy;
        queue<ListNode*>s1;
        queue<ListNode*>s2;
        ListNode* temp=l1;
        while(temp) {
            s1.push(temp);
            temp=temp->next;
        }
        temp=l2;
        while(temp) {
            s2.push(temp);
            temp=temp->next;
        }
        int carry=0;
        while(!s1.empty()||!s2.empty()||carry) {
            int a=0;
            int b=0;
            if(!s1.empty()) {
                a=s1.front()->val;
                s1.pop();
            }
            if(!s2.empty()) {
                b=s2.front()->val;
                s2.pop();
            }
            int num=a+b+carry;
            if(num>=10) carry=1;
            else carry=0;
            ListNode* node=new ListNode(num%10);
            t->next=node;
            t=t->next;  
        }
        // if(carry==1) {
        //     ListNode* node=new ListNode(1);
        //     node->next=dummy->next;
        //     dummy->next=node; 
        // }
        return dummy->next;
    }
};
