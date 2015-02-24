/*
 * =====================================================================================
 *
 *       Filename:  merge_two_lists.c
 *
 *    Description:  Merge Two Sorted Lists.
 *
 *        Version:  1.0
 *        Created:  2015/02/24 21时49分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhu Xianfeng <xianfeng.zhu@gmail.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *
mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode head;
	struct ListNode *ptr = &head;

	while (l1 || l2) {
		if (l1 && l2) {
			if (l1->val < l2->val) {
				ptr->next = l1;
				l1 = l1->next;
			} else {
				ptr->next = l2;
				l2 = l2->next;
			}
		} else if (l1) {
			ptr->next = l1;
			l1 = l1->next;
		} else {
			ptr->next = l2;
			l2 = l2->next;
		}
		ptr = ptr->next;
	}

	return head.next;
}

void 
generateList(struct ListNode **head, int *arr, int n)
{
	struct ListNode *ptr = NULL;
	struct ListNode *tmp;
	int i;

	for (i = 0; i < n; i++) {
		tmp = calloc(1, sizeof(struct ListNode));
		tmp->val = arr[i];
		if (!ptr) {
			ptr = tmp;
		} else {
			ptr->next = tmp;
			ptr = tmp;
		}
		if (!*head) {
			*head = tmp;
		}
	}
}

void printList(struct ListNode *head)
{
	struct ListNode *ptr = head;

	printf("List: ");
	while (ptr) {
		printf("%d ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	struct ListNode *l1 = NULL;
	struct ListNode *l2 = NULL;
	struct ListNode *l3 = NULL;
	int arr1[] = {1, 3, 5};
	int arr2[] = {2, 4, 6};

	generateList(&l1, arr1, 3);
	generateList(&l2, arr2, 3);
	printList(l1);
	printList(l2);

	l3 = mergeTwoLists(l1, l2);
	printList(l3);

	return 0;
}
