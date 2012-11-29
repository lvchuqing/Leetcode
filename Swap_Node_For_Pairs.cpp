/*Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/

public class Solution {
	public:
	    ListNode *swapPairs(ListNode *head) {
	        if(head == NULL) return NULL;
	        ListNode * second = head->next;
	        if(second == NULL) return head;
	        
	        ListNode * rest = swapPairs(second->next);
	        //swap head with second;
	        head->next = rest,
	        second->next = head;
	        return second;   
	    }
	    
	    
};
