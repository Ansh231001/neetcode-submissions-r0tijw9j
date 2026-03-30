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

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *head3 = new ListNode();
        ListNode *head4 = new ListNode();
        head4->next=head3;
        
        while(head1 != NULL and head2 != NULL){
            if(head1->val >= head2->val){
                head3->next = head2;
                head2 = head2->next;
                
            } else {
                head3->next = head1;
                head1 = head1->next;
            }
            head3 = head3->next;
        }
        
        while(head1 != NULL){
            head3->next = head1;
            head1 = head1->next;
            head3 = head3->next;
        }

        while(head2 != NULL){
            head3->next = head2;
            head2 = head2->next;
            head3 = head3->next;
        }
        
        return head4->next->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        if(lists[0] == nullptr)
            return lists[0];

        ListNode* head = lists[0];

        for(int i = 1; i < lists.size(); i++){
            head = merge(head, lists[i]);
        }

        return head;
    }
};
