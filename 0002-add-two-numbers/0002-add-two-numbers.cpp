/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode res = null;  // Head of the result linked list
        ListNode prev = null; // Tracks the last node added (to link next nodes)
        
        int sum = 0;   // Stores digit sum at each step
        int carry = 0; // Stores carry to be added to next digit

        // Traverse both lists until both are exhausted
        while (l1 != null || l2 != null) {

            // Add carry + current digit of l1 (0 if l1 is exhausted)
            //                + current digit of l2 (0 if l2 is exhausted)
            sum = carry 
                + (l1 != null ? l1.val : 0) 
                + (l2 != null ? l2.val : 0);

            carry = sum / 10; // Extract carry for next iteration (e.g. 15/10 = 1)
            sum = sum % 10;   // Extract current digit  (e.g. 15%10 = 5)

            // Create a new node with the current digit
            ListNode temp = new ListNode(sum);

            if (res == null) {
                // First node → becomes the head of result list
                res = temp;
            } else {
                // Link new node to the previous node
                prev.next = temp;
            }

            // Move prev pointer to the current node
            prev = temp;

            // Advance both pointers if not exhausted
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }

        // If carry remains after both lists are exhausted (e.g. 99 + 1 = 100)
        // Add a new node with the carry value
        if (carry != 0) {
            prev.next = new ListNode(carry);
        }

        // Return the head of the result linked list
        return res;
    }
}


// ### Dry Run Example
// ```
// l1 = [2 → 4 → 3]  (represents 342)
// l2 = [5 → 6 → 4]  (represents 465)

// Step 1: 2 + 5 = 7,  carry = 0  → node(7)
// Step 2: 4 + 6 = 10, carry = 1  → node(0)
// Step 3: 3 + 4 + 1 = 8, carry = 0 → node(8)

// Result = [7 → 0 → 8]  (represents 807) ✅
