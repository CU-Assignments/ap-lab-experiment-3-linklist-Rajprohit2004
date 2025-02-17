

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node to simplify the edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (head) {
            // Check if the current node is a duplicate
            if (head->next && head->val == head->next->val) {
                // Skip all duplicate nodes
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // Link the previous node to the next distinct node
                prev->next = head->next;
            } else {
                // No duplicate, move prev pointer
                prev = prev->next;
            }
            // Move the head pointer
            head = head->next;
        }
        
        return dummy->next;
    }
};
