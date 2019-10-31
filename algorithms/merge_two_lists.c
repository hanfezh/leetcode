/*
 * =====================================================================================
 *
 *       Filename:  merge_two_lists.c
 *
 *    Description:  21. Merge Two Sorted Lists.
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

// Iterative
struct ListNode *
mergeTwoLists1(struct ListNode *l1, struct ListNode *l2)
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

// Recursive
struct ListNode *
mergeTwoLists2(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists2(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists2(l1, l2->next);
        return l2;
    }
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

#define mergeTwoLists mergeTwoLists2

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
