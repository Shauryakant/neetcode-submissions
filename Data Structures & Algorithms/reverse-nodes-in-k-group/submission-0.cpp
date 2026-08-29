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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* travel=head;
        stack<ListNode*>st;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(travel) {
            int r=k;
            ListNode* parthead=travel;
            while(travel && r-- ){
                st.push(travel);
                travel=travel->next;
            }
            if(travel==nullptr&&r>0) {
                temp->next=parthead;
                break;
            }
            while(!st.empty()) {
                temp->next=st.top();
                temp=temp->next;
                st.pop();
                temp->next=nullptr;
            }
        }
        return dummy->next;
    }
};
