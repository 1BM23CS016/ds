
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *link;
};
typedef struct Node node;

node *start1 = NULL, *start2 = NULL, *newNode, *temp, *curr;


void create(node **start);
void display(node *start);
void reverse(node **start);
void sort(node *start);
void concatenate(node *start1, node *start2);

int main() {
    int choice;
    while (1) {
       
        printf("\n1. Create 1st Linked List \n2. Create 2nd Linked List \n3. display 1st Linked List \n4. display 2nd Linked List \n5. Reverse 1st Linked List \n6. Reverse 2nd Linked List \n7. Sort 1st Linked List \n8. Sort 2nd Linked List\n9. Concatenate Linked Lists\n10. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {  // Input validation for menu choice
            printf("Invalid input! Please enter a valid option.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        switch(choice) {
            case 1: create(&start1); break;
            case 2: create(&start2); break;
            case 3: display(start1); break;
            case 4: display(start2); break;
            case 5: reverse(&start1); break;
            case 6: reverse(&start2); break;
            case 7: sort(start1); break;
            case 8: sort(start2); break;
            case 9: concatenate(start1, start2); break;
            case 10: exit(0); break;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}


void create(node **start) {
    char choice;
    node *newNode;
    do {
        newNode = (node*) malloc(sizeof(node));
        if (!newNode) {
            printf("Memory allocation failed!\n");
            return;
        }
       
        printf("Enter value: ");
        if (scanf("%d", &newNode->data) != 1) {  // Input validation for node data
            printf("Invalid input! Please enter a valid integer.\n");
            free(newNode);  // Free the allocated memory on invalid input
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        newNode->link = NULL;

        if (*start == NULL) {
            *start = newNode;
            curr = newNode;
        } else {
            curr->link = newNode;
            curr = newNode;
        }

        printf("Do you want to add another element (Y/N): ");
        scanf(" %c", &choice); 
    } while(choice == 'y' || choice == 'Y');
}


void display(node *start) {
    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
   
    temp = start;
    printf("Elements in the linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}


void reverse(node **start) {
    node *prev = NULL, *current = *start, *next = NULL;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *start = prev;
    printf("Linked list reversed.\n");
}


void sort(node *start) {
    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    node *i, *j;
    int tempData;
    for (i = start; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                // Swap data
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("Linked list sorted.\n");
}


void concatenate(node *start1, node *start2) {
    if (start1 == NULL && start2 == NULL) {
        printf("Both linked lists are empty.\n");
        return;
    }
   
    if (start1 == NULL) {
        printf("Linked list 1 is empty. Displaying Linked List 2:\n");
        display(start2);
        return;
    }

    if (start2 == NULL) {
        printf("Linked list 2 is empty. Displaying Linked List 1:\n");
        display(start1);
        return;
    }


    temp = start1;
    while (temp->link != NULL) {
        temp = temp->link;
    }

 
    temp->link = start2;
    printf("Linked lists concatenated. Displaying the concatenated list:\n");
    display(start1);
}
