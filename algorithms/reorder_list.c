/*
 * =====================================================================================
 *
 *       Filename:  reorder_list.c
 *
 *    Description:  Reorder List
 *                  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 *                  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *                  You must do this in-place without altering the nodes' values.
 *                  For example,
 *                  Given {1,2,3,4}, reorder it to {1,4,2,3}.
 *
 *        Version:  1.0
 *        Created:  07/05/2015 11:38:16 AM
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

static void printSingleList(struct ListNode *head)
{
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

static void reorderSingleList(struct ListNode **head)
{
	struct ListNode *p;
	struct ListNode *q;
	struct ListNode *n;

	if (!head || !*head) {
		return;
	}

	p = *head;
	q = p->next;
	p->next = NULL;
	while (q) {
		n = q->next;
		q->next = p;
		p = q;
		q = n;
	}

	*head = p;
}

void reorderList(struct ListNode *head)
{
	struct ListNode *head2;
	struct ListNode *tail;
	struct ListNode *p;
	struct ListNode *q;
	struct ListNode *n;
	struct ListNode *m;
	int cnt = 0;

	if (!head || !head->next || !head->next->next) {
		return;
	}

	/* Caculate node count. */
	p = head;
	while (p) {
		cnt++;
		p = p->next;
	}

	/* Get the bottom half linked list. */
	cnt = (cnt + 1) / 2;
	p = head;
	while (cnt > 0) {
		tail = p;
		p = p->next;
		cnt--;
	}
	tail->next = NULL;
	head2 = p;
	/* Reorder single linked list. */
	reorderSingleList(&head2);
	// printSingleList(head2);

	/* Merge two single linked list. */
	p = head;
	q = head2;
	while (q) {
		n = p->next;
		m = q->next;
		p->next = q;
		q->next = n;
		p = n;
		q = m;
	}
}

int main(int argc, char *argv[])
{
	struct ListNode *head = NULL;
	struct ListNode *prev = NULL;
	struct ListNode *p;
	struct ListNode *n;
	int max = 8;
	int i;

	for (i = 1; i <= max; i++) {
		p = calloc(1, sizeof(struct ListNode));
		p->val = i;
		if (!prev) {
			prev = p;
			head = p;
		} else {
			prev->next = p;
			prev = p;
		}
	}

	printSingleList(head);
	reorderList(head);
	printSingleList(head);

	/* free list */
	p = head;
	while (p) {
		n = p->next;
		free(p);
		p = n;
	}

	return 0;
}

