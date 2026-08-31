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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpoints;
        int count = 1;
        ListNode* curr1 = head;
        int prev = curr1->val;
        curr1= curr1->next;
        
        while(curr1->next){
            if(curr1->val > prev && curr1->val > curr1->next->val){
                criticalpoints.push_back(count);
            }
            if(curr1->val < prev && curr1->val < curr1->next->val){
                criticalpoints.push_back(count);
            }
            count ++;
            prev = curr1->val;
            curr1 = curr1->next;
        }
        for(auto&it : criticalpoints) cout << it << " ";
        // criticalpoints is already sorted.
        
        if(!criticalpoints.size() || criticalpoints.size()==1) return {-1,-1};
        int mini = INT_MAX;
        int n = criticalpoints.size();
        for(int i=1 ; i<n ; i++){
            if(criticalpoints[i]-criticalpoints[i-1] < mini) mini = criticalpoints[i]-criticalpoints[i-1];
        }
        return {mini , criticalpoints[n-1] - criticalpoints[0]};
    
    }
};