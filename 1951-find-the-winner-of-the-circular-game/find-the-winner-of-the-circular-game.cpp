class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
        val = x;
        next = nullptr;
            }
        };
    int findTheWinner(int n, int k) {
        if(k==1) return n;
        ListNode* head = new ListNode(1);
        ListNode* curr = head;
        for(int i=2;i<=n;i++){
            ListNode* temp = new ListNode(i);
            curr->next = temp;
            curr = curr->next;
        }
        curr->next = head;
        int  count= n;
        curr = head;
        while(count>0){
            int it = 1;
            ListNode* temp = curr;
            while(it<k){
                curr = temp;
                temp = temp->next;
                it++;
            }
            curr->next = temp->next;
            curr = curr->next;
            count--;
        }
        return curr->val;
    }
};