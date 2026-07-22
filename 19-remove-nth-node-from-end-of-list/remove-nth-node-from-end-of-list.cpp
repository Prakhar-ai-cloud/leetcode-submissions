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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            size++;
        }
        if(size == n) return head->next;
        if(size == 1) return nullptr;
        int count = 0;
        ListNode* temp = head;
        while(count < size - n - 1){
            count++;
            temp = temp -> next;
        }
        ListNode* tem = temp->next;
        temp->next = tem->next;
        return head;

    }
};