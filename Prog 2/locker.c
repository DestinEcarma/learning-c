/* Instructions:
	The University of San Carlos has begun rolling out its newest locker
   technology: GraviLockers. These lockers are capable of fitting any amount of
   items, for as long as the total weight of all items does not exceed the
   weight limit of 5 KG. However, during shipping, the lockers' disk drives were
   damaged, and the firmware that made them work was lost. Luckily, the
   documentation for the structures remained intact.

	As students of DCIS, USC needs your help. Write the codes for the
   functions to make the lockers work again. Use the structures defined below.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLOCKERS 10
#define WEIGHTLIMIT 5

typedef struct {
	char studID[9];
	char studName[65];
	char course[5];
} Student;

typedef struct {
	char itemName[33];
	float weight; /* Weight of the item to be stored */
} ItemDets;

typedef struct ItemNode {
	ItemDets item;
	struct ItemNode *nextItem;
} ItemNode, *ItemList;

// typedef struct ItemNode {
// 	ItemDets* items;
// 	int count;
// 	int max;
// };

typedef struct {
	Student owner; /* Details of the student who owns the locker */
	ItemList IL; /* Array list representation of all the items inside a certain
			locker */
	int lockerStat;	 /* 0 if locker is Vacant, 1 if occupied */
	float totWeight; /* Total weight of all items in the locker */
} Locker;

/* Function depositItem(): This function will receive as parameter a Locker, a
student ID, and an item to be stored. The function will insert the item into the
Locker's ItemList, which is sorted by weight. Heavier items are stored at the
end of the locker's ItemList. Before insertion, please make sure that the
student ID passed is the same as the student ID of the locker's owner. Also,
make sure that the weight of all items, including the new item to store, does
not exceed the weight limit. */

void depositItem(Locker *L, char studID[], ItemDets newItem) {
	if (strcmp(L->owner.studID, studID)) {
		return;
	}

	if (L->totWeight + newItem.weight > WEIGHTLIMIT) {
		return;
	}

	ItemNode *newNode = (ItemNode *)malloc(sizeof(ItemNode));

	newNode->item = newItem;
	newNode->nextItem = NULL;

	ItemNode *head = L->IL;

	if (head == NULL) {
		L->IL = newNode;
	} else {
		while (head->nextItem != NULL) {
			if (head->item.weight > newItem.weight) {
				break;
			}

			head = head->nextItem;
		}

		newNode->nextItem = head->nextItem;
		head->nextItem = newNode;
	}

	L->totWeight += newItem.weight;
	L->lockerStat = 1;
}

/* Function getHeavyItems(): This function will receive as parameter a Locker
and a weight threshold/limit. The function will go through all the items in the
passed Locker's ItemList. If any item EXCEEDS the passed threshold/limit, store
that item into a new ItemList using insertFirst, and delete it from the locker's
ItemList. Return the ItemList of deleted items to the calling function. */

ItemList getHeavyItems(Locker *L, float limit) {
	ItemList heavyHead = NULL;
	ItemNode *heavyTail = NULL;

	ItemNode *head = L->IL;
	ItemNode *prev = NULL;

	while (head != NULL) {
		if (head->item.weight > limit) {
			if (prev == NULL) {
				L->IL = head->nextItem;
			} else {
				prev->nextItem = head->nextItem;
			}

			if (heavyHead == NULL) {
				heavyHead = head;
				heavyTail = head;
			} else {
				heavyTail->nextItem = head;
				heavyTail = head;
			}

			head = head->nextItem;
			heavyTail->nextItem = NULL;
		} else {
			prev = head;
			head = head->nextItem;
		}
	}

	return heavyHead;
}

void displayItemList(ItemList L) {
	ItemNode *head = L;

	while (head != NULL) {
		printf("{ %s, %.2f }", head->item.itemName, head->item.weight);
		head = head->nextItem;

		if (head != NULL)
			printf(" -> ");
	}

	printf("\n");
}

int main(void) {
	ItemDets item1 = {"Prog 1 Book", 0.35};
	ItemDets item2 = {"Shoes", 0.87};
	ItemDets item3 = {"Laptop", 2.35};
	ItemDets item4 = {"Keyboard", 1.17};

	Locker myLocker = {{"14101941", "Cris Militante", "BSCS"}, NULL, 1, 0};
	ItemList heavyItems;

	depositItem(&myLocker, "14101941", item4);
	depositItem(&myLocker, "14101941", item2);
	depositItem(&myLocker, "14101941", item3);
	depositItem(&myLocker, "14101941", item1);
	displayItemList(myLocker.IL);

	heavyItems = getHeavyItems(&myLocker, 1.00);
	displayItemList(myLocker.IL);
	displayItemList(heavyItems);
	return 0;
}
