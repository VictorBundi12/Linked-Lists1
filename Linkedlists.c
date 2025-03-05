#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};
struct Node* head;

void insert( int digit) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = digit;
    ptr->next = NULL;
    
    if (head == NULL) {
        head = ptr;
        return;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = ptr;
}

void search(int digit){
    Struct Node* current = head;
    bool status=false;
    while(current!=NULL){
        if(current->data == digit){
            status=true;
        }
        current = current->next;
    }
    if(status){
        printf("Number found");
    }else{
        printf("Number not found");
    }
}

void traverse() {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void delete(int digit) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    
    if (current != NULL && current->data == digit) {
        *head = current->next;
        free(current);
        return;
    }
    
    while (current != NULL && current->data != digit) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Element not found!\n");
        return;
    }
    
    prev->next = current->next;
    free(current);
}

int main() {
    struct Node* head = NULL;
    int choice, value;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Traverse List\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf( &value);
                search(value);
                   
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                delete(value);
                printf("Updated List:\n");
                traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
