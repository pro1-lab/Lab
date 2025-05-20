// 4. Write a program to insert the elements {61,16,8,27} into singly linked list and delete 8,61,27
// from the list. Display your list after each insertion and deletion.
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int data) {
    struct Node* temp;
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
	*head = newNode; 
	return;
    }				 temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = newNode;
}


void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    
    if (temp != NULL && temp->data == key) {
        *head = temp->next; 
        free(temp); 
        return;
    }

    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) return;

    
    prev->next = temp->next;
    free(temp); 
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

   
    int elements[] = {61, 16, 8, 27};
    int i;
      int keysToDelete[] = {8, 61, 27};
    for (i = 0; i < 4; i++) {
	insertEnd(&head, elements[i]);
	printf("List after inserting %d: ", elements[i]);
	printList(head);
    }

   

    for ( i = 0; i < 3; i++) {
        deleteNode(&head, keysToDelete[i]);
        printf("List after deleting %d: ", keysToDelete[i]);
        printList(head);
    }

    return 0;
}