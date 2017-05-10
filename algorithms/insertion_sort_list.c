/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort_list.c
 *
 *    Description:  Insertion Sort List.
 *
 *        Version:  1.0
 *        Created:  2015/02/25 20时20分13秒
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
insertionSortList(struct ListNode *head)
{
	struct ListNode *iter = head;
	struct ListNode *start;
	struct ListNode *end;
	int val;

	if (!head) {
		return NULL;
	}

	while (iter->next) {
		start = head;
		end = iter->next;
		while (start != end) {
			if (start->val > end->val) {
				val = start->val;
				start->val = end->val;
				end->val = val;
			}
			start = start->next;
		}
		iter = iter->next;
	}

	return head;
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
	struct ListNode *head = NULL;
	int arr[] = {5, 2, 3, 8, 1};

	generateList(&head, arr, 5);
	printList(head);

	head = insertionSortList(head);
	printList(head);

	return 0;
}
