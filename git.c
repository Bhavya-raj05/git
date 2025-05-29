#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached.\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &students[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);  // Read string with spaces
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nMarks: %.2f\n",
               students[i].id, students[i].name, students[i].marks);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}

