// 10. Write a program to demonstrate working of stack using linked list.
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

 
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top; 
    *top = newNode;  
    printf("Pushed %d onto the stack.\n", data);
}

 
int pop(struct Node** top) {
  struct Node* temp;
  int poppedValue;
    if (*top == NULL) {
	printf("Stack is empty! Cannot pop.\n");
	return -1;  
    }

     temp = *top;  
     poppedValue = temp->data;  
    *top = (*top)->next; 
    free(temp);  
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue; 
}

 
void display(struct Node* top) {
    struct Node* temp;
    if (top == NULL) {
	printf("Stack is empty.\n");
	return;
    }

    printf("Stack elements: ");					 temp = top; 
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL; 

    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    display(stack); 
    
    pop(&stack);  
    display(stack); 
    
    pop(&stack);  
    display(stack);  
    pop(&stack); 
    display(stack);  
    pop(&stack);  

    return 0;
}