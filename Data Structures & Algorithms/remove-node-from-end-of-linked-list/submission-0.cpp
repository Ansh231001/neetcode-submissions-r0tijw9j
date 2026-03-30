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

//reverse -> remove -> reverse -> return

ListNode* reverse(ListNode* head){
    if(!head)
        return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* temp = head;

        while(temp)
        {
            ListNode* curr = temp;
            temp = temp->next;
            curr->next = prev;
            prev = curr;
        }

        return prev;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);

        if(n == 1){
            ListNode* newHead = head->next;
            delete head;
            return reverse(newHead);
        }

        ListNode* temp = head;
        for(int i = 1; i < n - 1; i++){
            temp = temp->next;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return reverse(head);
    }
};
