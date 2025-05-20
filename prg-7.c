// 7. Write a program to insert the elements {61,16,8,27} into ordered singly linked list and delete
// 8,61,27 from the list. Display your list after each insertion and deletion.
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


void insertOrdered(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
	struct Node* current;

    
    if (*head == NULL || (*head)->data >= data) {
	newNode->next = *head;
	*head = newNode;
	return;
    }

  
     current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

   
    newNode->next = current->next;
    current->next = newNode;
}


void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;


    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }


    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

 
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp); // Free memory
}


void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    
    int elements[] = {61, 16, 8, 27};
	int keysToDelete[] = {8, 61, 27};

     int i;
    for ( i = 0; i < 4; i++) {
	insertOrdered(&head, elements[i]);
	printf("After inserting %d: ", elements[i]);
	printList(head);
    }

   



    for ( i = 0; i < 3; i++) {
        deleteNode(&head, keysToDelete[i]);
        printf("After deleting %d: ", keysToDelete[i]);
        printList(head);
    }

    return 0;
}