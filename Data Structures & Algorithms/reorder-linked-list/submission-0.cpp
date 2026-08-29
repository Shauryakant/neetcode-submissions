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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }
        stack<ListNode*>st;
        ListNode* temp=slow->next;
        slow->next=nullptr;
        while(temp!=nullptr) {
            st.push(temp);
            temp=temp->next;
        }
        temp=head;
        while(!st.empty()) {
            ListNode* top=st.top();
            st.pop();
            top->next=temp->next;
            temp->next=top;
            temp=top->next;
        }



    }
};
