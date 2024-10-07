#include <stdio.h>
#include <stdlib.h>

// Node structure definition: Each node stores an integer (data) and a pointer to the next node.
typedef struct Node {
    int data;           // Data stored in the node
    struct Node *next;  // Pointer to the next node in the list
} Node;

// Function prototypes
void addFront(Node **head, int data);
void addEnd(Node **head, int data);
void displayList(Node *head);
void insertAtPosition(Node **head, int data, int position);
void removeNode(Node **head, int data);
int findSmallest(Node *head, int data);
int findLargest(Node *head, int data);
void findCenter(Node **head, Node **center, float *median);
void findCenterOnly(Node **head, Node **center);

int main() {
    Node *head = NULL;  // Initialize the linked list head as NULL (empty list)
    Node *center = NULL;
    int choice, data, position;  // Variables to store user inputs
    int isEnabled = 1;  // Flag for controlling the menu loop
    float median = 0;

    while (isEnabled) {
        // Displaying a menu of options for the user
        printf("\nLinked List choices:\n");
        printf("1. Add Front\n");
        printf("2. Add End\n");
        printf("3. Insert at position\n");
        printf("4. Remove node\n");
        printf("5. Display List\n");
        printf("6. Find smallest node\n");
        printf("7. Find largest node\n");
        printf("8. Find the center of the node\n");
        printf("9. Find the center node only\n");
        printf("10. Exit\n");
        scanf("%d", &choice);  // Get the user's choice

        switch (choice) {
            case 1:  // Add a node at the front of the list
                printf("\nEnter data to add at front: ");
                scanf("%d", &data);
                addFront(&head, data);
                break;

            case 2:  // Add a node at the end of the list
                printf("\nEnter data to add at end: ");
                scanf("%d", &data);
                addEnd(&head, data);
                break;  // Ensure proper exit from the case

            case 3:  // Insert a node at a specific position in the list
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 4:  // Remove a node with a specific data value
                printf("\nEnter data of node to remove: ");
                scanf("%d", &data);
                removeNode(&head, data);
                break;

            case 5:  // Display the entire linked list
                printf("\n");
                displayList(head);
                break;

            case 6:  // Exit the program
                int getSmallest = findSmallest(head, data);
                printf("\nThe smallest node is %d\n", getSmallest);
                break;

            case 7:  // Exit the program
                int getLargest = findLargest(head, data);
                printf("\nThe largest node is %d\n", getLargest);
                break;

            case 8:
            findCenter(&head, &center, &median);

            if(center != NULL){
                if((int)median == center -> data){
                    printf("\nThe center node is %d\n", center -> data);
                }else{
                    printf("\nThe center node median is %.2f\n", median);
                }
            }else{
                printf("\nThe linked list is empty..\n");
            }  
            break;

            case 9:  // Exit the program
            findCenterOnly(&head, &center);

            if(center != NULL){
                printf("\nThe only center node is %d\n", center -> data);
            }else{
                printf("\nThe linked list is empty..\n");
            }
            break;

            case 10:  // Exit the program
                isEnabled = 0;  // Set flag to 0 to exit the loop
                printf("\nExiting..\nGoodbye!\n");
                break;

            default:  // Handle invalid user input
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}

void addFront(Node **head, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = *head;
    *head = newNode;
}

void addEnd(Node **head, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = newNode;
}

int findSmallest(Node *head, int data){
    if(head == NULL){
        printf("\nThe linked list is empty..");
        return 0;
    }
    int smallest = head -> data;
    Node *current = head -> next;

    while(current != NULL){
        if(current -> data < smallest){
            smallest = current -> data;
        }
        current = current -> next;
    }

    return smallest;
}

int findLargest(Node *head, int data){
    if(head == NULL){
        printf("\nThe linked list is empty..");
        return 0;
    }

    int largest = head -> data;
    Node *current = head -> next;

    while(current != NULL){
        if(current -> data > largest){
            largest = current -> data;
        }
        current = current -> next;
    }

    return largest;
}

void findCenter(Node **head, Node **center, float *median){
    if(*head == NULL){
        *center = NULL;
        *median = 0;
        return;
    }

    Node *slow = *head;
    Node *fast = *head;
    Node *prevSlow = NULL;

    while(fast != NULL && fast -> next != NULL){
        prevSlow = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    *center = slow;

    if(fast == NULL){
        *median = (prevSlow -> data + slow -> data) / 2.0;
    }else{
        *median = slow -> data;
    }
}

void findCenterOnly(Node **head, Node **center){
    if(*head == NULL){
        *center = NULL;
        return;
    }

    Node *slow = *head;
    Node *fast = *head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    *center = slow;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(Node **head, int data, int position) {
    Node *newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for the new node
    newNode->data = data;  // Set the data of the new node

    if (position == 1) {  // If inserting at the first position
        newNode->next = *head;  // Point new node's next to current head
        *head = newNode;  // Make the new node the head
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {  // Traverse to the (position-1)th node
        temp = temp->next;
    }

    if (temp == NULL) {  // If the position is out of bounds
        printf("Position out of bounds\n");
        free(newNode);  // Free the memory allocated for the new node
        return;
    }

    newNode->next = temp->next;  // Link the new node with the node currently at the position
    temp->next = newNode;  // Link the (position-1)th node to the new node
}

// Function to remove a node with a specific data value
void removeNode(Node **head, int data) {
    Node *temp = *head, *prev = NULL;  // Pointers for traversing the list

    // If the node to be removed is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Move the head pointer to the next node
        free(temp);  // Free the old head node
        return;
    }

    // Traverse the list to find the node to remove
    while (temp != NULL && temp->data != data) {
        prev = temp;  // Store the previous node
        temp = temp->next;  // Move to the next node
    }

    if (temp == NULL) {  // If the node with the given data is not found
        printf("Node with data %d not found\n", data);
        return;
    }

    prev->next = temp->next;  // Link the previous node to the next node (bypass the node to be deleted)
    free(temp);  // Free the memory of the node to be removed
}

// Function to display the linked list
void displayList(Node *head) {
    if (head == NULL) {  // If the list is empty
        printf("List is empty\n");
        return;
    }

    Node *temp = head;  // Start from the head of the list
    while (temp != NULL) {  // Traverse the list
        printf("%d -> ", temp->data);  // Print the data of the current node
        temp = temp->next;  // Move to the next node
    }
    printf("NULL\n");  // End of the list
}
