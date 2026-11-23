
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[50];
    char department[50];
    float cgpa;
};

void textMenu();
void binaryMenu();

void createText();
void readText();
void updateText();
void deleteText();

void createBinary();
void readBinary();
void updateBinary();
void deleteBinary();

int main()
{
    int choice;

    do
    {
        printf("                         STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("                       ====================================\n");

        printf("1. Text File Operations\n");
        printf("2. Binary File Operations\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                textMenu();
                break;

            case 2:
                binaryMenu();
                break;

            case 3:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while(choice != 3);

    return 0;
}


// TEXT FILE
void textMenu()
{
    int choice;

    do
    {
        printf("\n========== TEXT FILE MENU ==========\n");
        printf("1. Create Student\n");
        printf("2. Read Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Back to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createText();
                break;

            case 2:
                readText();
                break;

            case 3:
                updateText();
                break;

            case 4:
                deleteText();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);
}


void createText()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt", "a");

    if(fp == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);

    printf("Enter Student Name: ");
    scanf("%49s", s.name);

    printf("Enter Department: ");
    scanf("%49s", s.department);

    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);

    fprintf(fp, "%d %s %s %.2f\n",
            s.id, s.name, s.department, s.cgpa);

    fclose(fp);

    printf("\nStudent Created Successfully!\n");
}



void readText()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo Student Record Found!\n");
        return;
    }

    printf("\n======= TEXT STUDENT RECORDS =======\n");

    while(fscanf(fp, "%d %49s %49s %f",
                 &s.id, s.name,
                 s.department, &s.cgpa) == 4)
    {
        printf("\nID: %d", s.id);
        printf("\nName: %s", s.name);
        printf("\nDepartment: %s", s.department);
        printf("\nCGPA: %.2f\n", s.cgpa);
    }

    fclose(fp);
}



void updateText()
{
    FILE *fp, *temp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.txt", "r");

    if(fp == NULL)
    {
        printf("\nFile Not Found!\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    if(temp == NULL)
    {
        fclose(fp);
        printf("\nTemporary File Error!\n");
        return;
    }

    printf("\nEnter Student ID to Update: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %49s %49s %f",
                 &s.id, s.name,
                 s.department, &s.cgpa) == 4)
    {
        if(s.id == id)
        {
            found = 1;

            printf("Enter New Name: ");
            scanf("%49s", s.name);

            printf("Enter New Department: ");
            scanf("%49s", s.department);

            printf("Enter New CGPA: ");
            scanf("%f", &s.cgpa);
        }

        fprintf(temp, "%d %s %s %.2f\n",
                s.id, s.name, s.department, s.cgpa);
    }

    fclose(fp);
    fclose(temp);

    if(found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");

        printf("\nRecord Updated Successfully!\n");
    }
    else
    {
        remove("temp.txt");
        printf("\nStudent ID Not Found!\n");
    }
}



void deleteText()
{
    FILE *fp, *temp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.txt", "r");

    if(fp == NULL)
    {
        printf("\nFile Not Found!\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    if(temp == NULL)
    {
        fclose(fp);
        printf("\nTemporary File Error!\n");
        return;
    }

    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %49s %49s %f",
                 &s.id, s.name,
                 s.department, &s.cgpa) == 4)
    {
        if(s.id == id)
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "%d %s %s %.2f\n",
                    s.id, s.name, s.department, s.cgpa);
        }
    }

    fclose(fp);
    fclose(temp);

    if(found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");

        printf("\nRecord Deleted Successfully!\n");
    }
    else
    {
        remove("temp.txt");
        printf("\nStudent ID Not Found!\n");
    }
}


// BINARY FILE MENU

void binaryMenu()
{
    int choice;

    do
    {
        printf("\n========== BINARY FILE MENU ==========\n");
        printf("1. Create Student\n");
        printf("2. Read Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Back to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createBinary();
                break;

            case 2:
                readBinary();
                break;

            case 3:
                updateBinary();
                break;

            case 4:
                deleteBinary();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);
}


void createBinary()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "ab");

    if(fp == NULL)
    {
        printf("File Cannot Be Opened!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);

    printf("Enter Student Name: ");
    scanf("%49s", s.name);

    printf("Enter Department: ");
    scanf("%49s", s.department);

    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("\nBinary Record Created Successfully!\n");
}



void readBinary()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo Binary Records Found!\n");
        return;
    }

    printf("\n======= BINARY STUDENT RECORDS =======\n");

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("\nID: %d", s.id);
        printf("\nName: %s", s.name);
        printf("\nDepartment: %s", s.department);
        printf("\nCGPA: %.2f\n", s.cgpa);
    }

    fclose(fp);
}



void updateBinary()
{
    FILE *fp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.dat", "rb+");

    if(fp == NULL)
    {
        printf("\nFile Not Found!\n");
        return;
    }

    printf("\nEnter Student ID to Update: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.id == id)
        {
            found = 1;

            printf("Enter New Name: ");
            scanf("%49s", s.name);

            printf("Enter New Department: ");
            scanf("%49s", s.department);

            printf("Enter New CGPA: ");
            scanf("%f", &s.cgpa);

            fseek(fp, -(long)sizeof(s), SEEK_CUR);

            fwrite(&s, sizeof(s), 1, fp);

            break;
        }
    }

    fclose(fp);

    if(found)
        printf("\nRecord Updated Successfully!\n");
    else
        printf("\nStudent ID Not Found!\n");
}



void deleteBinary()
{
    FILE *fp, *temp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("\nFile Not Found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");

    if(temp == NULL)
    {
        fclose(fp);
        printf("\nTemporary File Error!\n");
        return;
    }

    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if(found)
    {
        remove("students.dat");
        rename("temp.dat", "students.dat");

        printf("\nRecord Deleted Successfully!\n");
    }
    else
    {
        remove("temp.dat");
        printf("\nStudent ID Not Found!\n");
    }
}

