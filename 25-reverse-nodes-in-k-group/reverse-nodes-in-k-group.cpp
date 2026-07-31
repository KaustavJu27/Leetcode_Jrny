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
        ListNode* curr = head;
        int count = 0;
        
        // First, check if there are at least k nodes left
        while (count < k && curr != nullptr) {
            curr = curr->next;
            count++;
        }
        
        // If we have k nodes, then we proceed with reversal
        if (count == k) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* next = nullptr;
            
            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // Recursively reverse the remaining list
            head->next = reverseKGroup(curr, k);
            
            // Return the new head of the reversed portion
            return prev;
        }
        
        // If fewer than k nodes remaining, return head without reversal
        return head;
    }
};