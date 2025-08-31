#ifndef LIST_QUESTIONS_H
#define LIST_QUESTIONS_H

#include "LinkedList.h"
#include <stdbool.h>
/*
 * Problem: Determine if a linked list has a cycle
 *
 * Description:
 * Given the head of a linked list, determine if the list contains a cycle. A cycle occurs if a node can be
 * reached again by continuously following the `next` pointer. Internally, 'pos' is used to denote the index
 * of the node that the tail's next pointer is connected to, indicating a cycle. Note that 'pos' is not
 * accessible or passed as a parameter; it's only used for problem understanding and explanation.
 *
 * Task:
 * Implement a function to check if the given linked list has a cycle. The function should return 'true' if a
 * cycle is present and 'false' otherwise.
 *
 * Prototype:
 * bool hasCycle(struct Node *head);
 */

static bool hasCycle(struct Node *head)
{
	struct Node *slow = head;	//define slow (1 move per iteration) and fast (2 moves per iteration) nodes
	struct Node *fast = head;
	while (fast != NULL && fast->next != NULL) {	//moves the nodes at their respective speeds and returns true if they are at same position
		slow = slow->next;         					
		fast = fast->next->next;   

		if (slow == fast) {          
			return true;
		}
	}
	return false;	// No cycle (NULL detected at end of list)
}

/*
 * Problem: Merge Two Sorted Lists
 *
 * Description:
 * You are given the heads of two sorted linked lists, list1 and list2. Your task is to merge these two
 * lists into one single sorted list. The merged list should be constructed by splicing together the nodes
 * of the first two lists without creating new nodes, but by rearranging the nodes from the given lists.
 *
 * Task:
 * Implement a function that merges two sorted linked lists and returns the head of the newly merged sorted
 * linked list.
 *
 * Prototype:
 * struct Node* mergeTwoLists(struct Node* list1, struct Node* list2);
 *
 * Note:
 * Both list1 and list2 are sorted in non-decreasing order.
 */

static struct Node* mergeLists(struct Node* list1, struct Node* list2)
{
	if(list1 == NULL) {		//checks if list1 is empty, if so return list2
		return list2;
	}
	if (list2 == NULL) {	//checks if list2 is empty, if so return list1
		return list1;
	}

	struct Node *head = NULL;	//create head and tail dummy nodes to more easily manage merged list		
	struct Node *tail = NULL;	

	if (list1->data <= list2->data) {		//if else defines first node of merged list
		head = tail = list1;
		list1 = list1->next;
	} else {
		head = tail = list2;
		list2 = list2->next;
	}
	while (list1 != NULL && list2 != NULL) {	/*while loop traverses both lists to decide which
												 node is next in merged list*/
		if (list1->data <= list2->data) {
			tail->next = list1;
			tail = list1;
			list1 = list1->next;
		} else {
			tail->next = list2;
			tail = list2;
			list2 = list2->next;
		}
	}
	if (list1 != NULL) {		//if one list becomes empty, append the rest of the other list to merged list
		tail->next = list1;
	} else {
		tail->next = list2;
	}
	return head;
}

#endif
