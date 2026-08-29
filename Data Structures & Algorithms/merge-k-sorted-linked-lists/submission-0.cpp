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

class compare {
    public:
    bool operator() (ListNode* a,ListNode* b) {
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minheap;
        for(int i=0;i<lists.size();i++) {
            minheap.push(lists[i]);
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(!minheap.empty()) {
            ListNode* minimum=minheap.top();
            minheap.pop();
            temp->next=minimum;
            temp=temp->next;
            if(minimum->next) minheap.push(minimum->next);
        }
        return dummy->next;
    }
};
