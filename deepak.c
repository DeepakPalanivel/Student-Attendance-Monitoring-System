#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for attendance record
typedef struct Attendance {
    int studentID;
    char date[15];
    char status[10]; // Present / Absent
    struct Attendance *next;
} Attendance;

Attendance *head = NULL;

// Add attendance record
void addRecord(int id, char date[], char status[]) {
    Attendance *newNode = (Attendance*)malloc(sizeof(Attendance));
    newNode->studentID = id;
    strcpy(newNode->date, date);
    strcpy(newNode->status, status);
    newNode->next = head;
    head = newNode;
    printf("Record added successfully!\n");
}

// Delete incorrect entry
void deleteRecord(int id, char date[]) {
    Attendance *temp = head, *prev = NULL;
    while (temp != NULL) {
        if (temp->studentID == id && strcmp(temp->date, date) == 0) {
            if (prev == NULL) head = temp->next;
            else prev->next = temp->next;
            free(temp);
            printf("Record deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Record not found!\n");
}

// Search attendance by student ID and date
void searchRecord(int id, char date[]) {
    Attendance *temp = head;
    while (temp != NULL) {
        if (temp->studentID == id && strcmp(temp->date, date) == 0) {
            printf("Found: ID=%d, Date=%s, Status=%s\n", temp->studentID, temp->date, temp->status);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found!\n");
}

// Display attendance list for a date
void displayByDate(char date[]) {
    Attendance *temp = head;
    printf("Attendance on %s:\n", date);
    while (temp != NULL) {
        if (strcmp(temp->date, date) == 0) {
            printf("ID: %d, Status: %s\n", temp->studentID, temp->status);
        }
        temp = temp->next;
    }
}

// Reverse display (recursion)
void reverseDisplay(Attendance *node) {
    if (node == NULL) return;
    reverseDisplay(node->next);
    printf("ID: %d, Date: %s, Status: %s\n", node->studentID, node->date, node->status);
}

// Clone list (for admin reviews)
Attendance* cloneList(Attendance *src) {
    if (src == NULL) return NULL;
    Attendance *newNode = (Attendance*)malloc(sizeof(Attendance));
    newNode->studentID = src->studentID;
    strcpy(newNode->date, src->date);
    strcpy(newNode->status, src->status);
    newNode->next = cloneList(src->next);
    return newNode;
}

// Main menu
int main() {
    int choice, id;
    char date[15], status[10];
    Attendance *adminCopy = NULL;

    while (1) {
        printf("\n--- Student Attendance Monitoring ---\n");
        printf("1. Add Record\n2. Delete Record\n3. Search Record\n4. Display by Date\n5. Reverse Display\n6. Clone List for Admin\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID, Date (dd-mm-yyyy), Status (Present/Absent): ");
                scanf("%d %s %s", &id, date, status);
                addRecord(id, date, status);
                break;
            case 2:
                printf("Enter ID and Date to delete: ");
                scanf("%d %s", &id, date);
                deleteRecord(id, date);
                break;
            case 3:
                printf("Enter ID and Date to search: ");
                scanf("%d %s", &id, date);
                searchRecord(id, date);
                break;
            case 4:
                printf("Enter Date: ");
                scanf("%s", date);
                displayByDate(date);
                break;
            case 5:
                printf("Attendance in reverse:\n");
                reverseDisplay(head);
                break;
            case 6:
                adminCopy = cloneList(head);
                printf("List cloned for admin review!\n");
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}