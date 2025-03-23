#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// insted of this #include "myheaders.h" we can use

#define MAX_USERS 10
#define MAX_FILES 10
#define NAME_LEN 20
// in a single line #define MAX_USERS 10, MAX_FILES 10, NAME_LEN 20 check it out once 

// Structure for File
typedef struct {
    char name[NAME_LEN];
} File;

// Structure for User Directory
typedef struct {
    char name[NAME_LEN];
    int fileCount;
    File files[MAX_FILES];
} UserDirectory;

UserDirectory users[MAX_USERS];
int userCount = 0;

// Function to create a user directory
void createUserDirectory() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user directories reached!\n");
        return;
    }

    printf("Enter User Name: ");
    scanf("%s", users[userCount].name);
    users[userCount].fileCount = 0;
    userCount++;

    printf("User Directory Created Successfully!\n");
}

// Function to add a file to a user directory
void addFile() {
    char userName[NAME_LEN], fileName[NAME_LEN];
    printf("Enter User Name: ");
    scanf("%s", userName);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            if (users[i].fileCount >= MAX_FILES) {
                printf("File limit reached for this user!\n");
                return;
            }

            printf("Enter File Name: ");
            scanf("%s", fileName);
            strcpy(users[i].files[users[i].fileCount].name, fileName);
            users[i].fileCount++;

            printf("File Added Successfully!\n");
            return;
        }
    }
    printf("User Not Found!\n");
}

// Function to list files in a user directory
void listFiles() {
    char userName[NAME_LEN];
    printf("Enter User Name: ");
    scanf("%s", userName);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            printf("Files in User Directory '%s':\n", userName);
            if (users[i].fileCount == 0) {
                printf("No files available.\n");
                return;
            }

            for (int j = 0; j < users[i].fileCount; j++) {
                printf("- %s\n", users[i].files[j].name);
            }
            return;
        }
    }
    printf("User Not Found!\n");
}

// Function to delete a file from a user directory
void deleteFile() {
    char userName[NAME_LEN], fileName[NAME_LEN];
    printf("Enter User Name: ");
    scanf("%s", userName);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            printf("Enter File Name to Delete: ");
            scanf("%s", fileName);

            for (int j = 0; j < users[i].fileCount; j++) {
                if (strcmp(users[i].files[j].name, fileName) == 0) {
                    // Shift files to fill the gap
                    for (int k = j; k < users[i].fileCount - 1; k++) {
                        strcpy(users[i].files[k].name, users[i].files[k + 1].name);
                    }
                    users[i].fileCount--;

                    printf("File Deleted Successfully!\n");
                    return;
                }
            }
            printf("File Not Found!\n");
            return;
        }
    }
    printf("User Not Found!\n");
}

// Function to delete a user directory
void deleteUserDirectory() {
    char userName[NAME_LEN];
    printf("Enter User Name: ");
    scanf("%s", userName);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            // Shift users to fill the gap
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;

            printf("User Directory Deleted Successfully!\n");
            return;
        }
    }
    printf("User Not Found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n---- Two-Level Directory System ----\n");
        printf("1. Create User Directory\n");
        printf("2. Add File\n");
        printf("3. List Files\n");
        printf("4. Delete File\n");
        printf("5. Delete User Directory\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createUserDirectory(); break;
            case 2: addFile(); break;
            case 3: listFiles(); break;
            case 4: deleteFile(); break;
            case 5: deleteUserDirectory(); break;
            case 6: exit(0);
            default: printf("Invalid Choice! Try Again.\n");
        }
    }
    
    return 0;
}
