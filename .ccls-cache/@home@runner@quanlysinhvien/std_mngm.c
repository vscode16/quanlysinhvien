#include <stdio.h>
#include <string.h>

// Create structs
struct FullName {
    char firstName[20];
    char lastName[10];
};

typedef struct Student {
    int id;
    struct FullName name;
    double score;
} student;

// Declare functions
student enterStd(void);
void displayStd(student *, unsigned int);
void arrangeList(student *, unsigned int);
void findStudent(student *, unsigned int);
void exportFile(student *, unsigned int);

// Implement in main() function
int main(void) {
    student listOfStd[50];
    unsigned int numOfStd, i, option = 7, countStd = 0;
    do {
        switch (option) {
            case 0:
                option = 0;
                break;
            
            case 1:
                printf("How many students: ");
                scanf("%u", &numOfStd);
                getchar();
                for (i = countStd; i < countStd + numOfStd; i++) {
                    printf("Information of student %u\n", i + 1);
                    listOfStd[i] = enterStd();
                    printf("\n");
                }
                countStd = countStd + numOfStd;
                option = 7;
                break;
            case 2:
                displayStd(listOfStd, countStd);
                printf("Press 7 to return menu ");
                scanf("%u", &option); getchar();
                break;
            case 3:
                arrangeList(listOfStd, countStd);
                displayStd(listOfStd, countStd);
                printf("Press 7 to return menu ");
                scanf("%u", &option); getchar();
                break;
            case 4:
                findStudent(listOfStd, countStd);
                printf("Press 7 to return menu ");
                scanf("%u", &option); getchar();
                break;
            case 5:
                exportFile(listOfStd, countStd);
                printf("Press 7 to return menu ");
                scanf("%u", &option); getchar();
                break;
            case 7:
                printf("======== Student Management Program ========\n");
                printf("|| 1. Add student\n");
                printf("|| 2. Display the list of students\n");
                printf("|| 3. Arrange list of students\n");
                printf("|| 4. Find the student by name\n");
                printf("|| 5. Export information of students to file\n");
                printf("|| 0. Exit the program\n");
                printf("Your option: ");
                scanf("%u", &option); getchar();
                break;
        }
    } while (option);
    return 0;
}

// Write functions
student enterStd(void) {
    student std;
    printf("Enter the ID of student: ");
    scanf("%d", &std.id);
    getchar();
    printf("Enter the first name: ");
    scanf("%[^\n]%*c", std.name.firstName);
    printf("Enter the last name: ");
    scanf("%[^\n]%*c", std.name.lastName);
    printf("Enter the score of student: ");
    scanf("%lf", &std.score);
    getchar();
    return std;
}

void displayStd(student *listOfStd, unsigned int numOfStd) {
    int i;
    printf("+----+---------------------+-----------+-------+\n");
    printf("| ID |     first name      | last name | score |\n");
    printf("+----+---------------------+-----------+-------+\n");
    for (i = 0; i < numOfStd; i++) {
        printf("| %-2d | %-20s| %-10s| %-5.2lf |\n",
        listOfStd[i].id, listOfStd[i].name.firstName, listOfStd[i].name.lastName, listOfStd[i].score);
    }
    printf("+----+---------------------+-----------+-------+\n");
}

void arrangeList(student *listOfStd, unsigned int numOfStd) {
    unsigned short int i, j, select;
    student flag;
    printf("Sort by:\n1. Name\n2. Score\nYour select: ");
    scanf("%hu", &select);
    getchar();
    if (select == 1) {
        for (i = 0; i < numOfStd - 1; i++) {
            for (j = i + 1; j < numOfStd; j++) {
                if (strcmp(listOfStd[i].name.lastName, listOfStd[j].name.lastName) > 0) {
                    flag = listOfStd[i];
                    listOfStd[i] = listOfStd[j];
                    listOfStd[j] = flag;
                }
            }
        }
    } else if (select == 2) {
        for (i = 0; i < numOfStd - 1; i++) {
            for (j = i + 1; j < numOfStd; j++) {
                if (listOfStd[i].score < listOfStd[j].score) {
                    flag = listOfStd[i];
                    listOfStd[i] = listOfStd[j];
                    listOfStd[j] = flag;
                }
            }
        }
    }
}

void findStudent(student *listOfStd, unsigned int numOfStd) {
    char fName[10];
    unsigned int i, count = 0;
    printf("Enter the name of student want to find: ");
    scanf("%[^\n]%*c", fName);
    for (i = 0; i < numOfStd; i++) {
        if (strcmp(fName, listOfStd[i].name.lastName) == 0) {
            printf("| %-2d | %-20s| %-10s| %-5.2lf |\n",
            listOfStd[i].id, listOfStd[i].name.firstName, listOfStd[i].name.lastName, listOfStd[i].score);
            count++;
        }
    }
    if (count == 0) printf("Not find the student\n");
}

void exportFile(student *listOfStd, unsigned int numOfStd) {
    unsigned int i;
    FILE *fOut;
    fOut = fopen("student.txt", "a");
    for (i = 0; i < numOfStd; i++) {
        fprintf(fOut, "| %-2d | %-20s| %-10s| %-5.2lf |\n",
        listOfStd[i].id, listOfStd[i].name.firstName, listOfStd[i].name.lastName, listOfStd[i].score);
    }
    fclose(fOut);
}