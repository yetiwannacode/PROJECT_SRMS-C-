#include <stdio.h>
#include <stdlib.h>
#include "student_ops.h"
int main()
{
    int Option;
    loadFromFile();

    do{
        printf("\n---STUDENT RECORD MANAGEMENT SYSTEM---\n");
        printf("1. Add Student in the records:\n");
        printf("2. View Students in the record:\n");
        printf("3. Search for a Student in the records:\n");
        printf("4. Edit Student details:\n");
        printf("5. Delete Student from the records:\n");
        printf("6. Save your file and exit:\n");
        printf("Enter your desirable action by the number\n");
        scanf("%d", &Option);
        getchar();

        switch(Option)
        {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: editStudent(); break;
            case 5: deleteStudent(); break;
            case 6: saveToFile();
                    freeStudents();
                    printf("Exiting the file...\n");
                    break;
            default: printf("Please choose a number from the above 6 only.\n");
        }
    }
    while(Option != 6);

    return 0;
}