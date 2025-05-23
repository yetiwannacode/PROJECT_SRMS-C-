#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_ops.h"

typedef struct Student{
    int roll;
    char name[50];
    float marks;
    struct Student* next;
}Student;

Student* head= NULL;
Student* createStudent(int roll, const char* name, float marks)
{
    Student* new_student= (Student*) malloc(sizeof(Student));
    new_student->roll= roll;
    strcpy(new_student->name, name);
    new_student->marks= marks;
    new_student->next= NULL;
    return new_student;
}

void addStudent()
{
    int roll;
    char name[50];
    float marks;
    printf("Enter the roll number: ");
    scanf("%d", &roll);
    getchar();
    printf("Enter the name of the student: ");
    scanf("%49[^\n]", name);
    printf("Enter the marks: ");
    scanf("%f", &marks);
    Student* new_student= createStudent(roll, name, marks);
    new_student->next= head;
    head= new_student;
}

void viewStudents()
{
    Student* temp= head;
    if (temp == NULL)
    {
        printf("No records found");
        return;
    }
    printf("\n--- Student records ---\n");
    while(temp != NULL)
    {
        printf("Roll no: %d, Name: %s, Marks: %.2f \n", temp->roll, temp->name, temp->marks);
        temp= temp->next;
    }
}

void searchStudent()
{
    int roll;
    printf("Enter the roll number you want to search: ");
    scanf("%d", &roll);
    Student* temp= head;
    while(temp != NULL)
    {
        if(temp->roll == roll)
        {
            printf("Match found: Roll No. %d, Name: %s, Marks: %.2f\n", temp->roll, temp->name, temp->marks);
            return;
        }
        temp= temp->next;
    }
    printf("No student with this roll number exists.\n");
}

void editStudent()
{
    int roll;
    printf("Enter the roll number of student you want to edit details of: ");
    scanf("%d", &roll);
    getchar();
    Student* temp= head;
    while(temp != NULL)
    {
        if(temp->roll == roll)
        {
            printf("Editing student details: %s (Roll no. %d)\n", temp->name, temp->roll);
            printf("Enter the new name(keep blank if unchanged): ");
            char name[50];
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            if(strlen(name)>0)
            {
                strcpy(temp->name,name);
            }
            printf("enter the marks of the student(or -1 to keep unchanged): ");
            float marks;
            scanf("%f", &marks);
            if(marks>=0.0)
            {
                temp->marks= marks;
            }
            printf("the details are updated\n");
            return;
        }
        temp= temp->next;
    }
    printf("Student not found in database\n");
}

void deleteStudent()
{
    int roll;
    printf("Enter the roll number you want to delete: ");
    scanf("%d", &roll);
    getchar();
    Student* temp= head;
    Student* prev= NULL;
    while(temp != NULL)
    {
        if(temp->roll == roll)
        {
            if(prev!= NULL)
            {
                prev->next= temp->next;
            }
            else
            {
                head= temp->next;
            }
            free(temp);
            printf("Student is deleted from the record.\n");
            return;
        }
        prev= temp;
        temp= temp->next;
    }
    printf("Student not found in database.\n");
}

void saveToFile()
{
    FILE *fp= fopen("data.txt", "w");
    Student* temp= head;
    while(temp != NULL)
    {
        fprintf(fp,"%d,%s,%.2f\n", temp->roll, temp->name, temp->marks);
        temp= temp->next;
    }
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        return;
    }
    int roll;
    char name[50];
    float marks;
    int line = 0;

    while (1) {
        int result = fscanf(fp, "%d,%49[^,],%f\n", &roll, name, &marks);
        if (result == 3) {
            Student* new_student = createStudent(roll, name, marks);
            new_student->next = head;
            head = new_student;
        }
    fclose(fp);
}
}
void freeStudents()
{
    Student* temp;
    while(head != NULL)
    {
        temp= head;
        head= head->next;
        free(temp);
    }
}
