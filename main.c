#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* ThreadFunctionRead(void *arguments)
{

    FILE * file_ptr;
    char c;

    char nameOfFile[50];
    printf("Enter the name of the file to read: \n");
    scanf("%s", nameOfFile);
    file_ptr = fopen(nameOfFile, "r"); // send test.txt

    if(file_ptr == NULL)//Check for file opened or not
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        return (void *) -1; // if file can not opened, terminate
    }


    printf("File opened successfully. Reading file contents character by character.\n");
    int num_chars=0;
    while ((c = fgetc(file_ptr)) != EOF)
    {
        printf("%c",c);
        num_chars++;
    }
    printf("\n*********File contains %d characters.\n", num_chars);

    fclose(file_ptr);

    return 0;
}



void* ThreadFunctionWrite(void *arguments)
{

    // creating file pointer to work with files
    FILE *file_ptr;

    char nameOfFile[50];
    printf("Enter the name of the file to write: \n");
    scanf("%s", nameOfFile);
    file_ptr = fopen(nameOfFile, "w"); // send test.txt

    // exiting program
    if (file_ptr == NULL) {//Check for is file opened
        printf("Error!");
        return (void *) -1; // if file can not opened, terminate

    }

    char wordToWrite[200];
    printf("Enter a word :\n");
    scanf("%s", wordToWrite);

    fprintf(file_ptr, "%s",wordToWrite);
    fclose(file_ptr);
    return 0;
}


void* ThreadFunctionOpen(void *arguments)
{

    FILE *file_ptr;
    char ch;
    char nameOfFile[50];
    printf("Enter the name of the file that you want to open: \n");
    scanf("%s", nameOfFile);
    file_ptr = fopen(nameOfFile, "w+");
}

void* ThreadFunctionClose(void *arguments)
{
    FILE *file_ptr;
    char ch;
    char nameOfFile[50];
    printf("Enter the name of the file that you want to close: \n");
    scanf("%s", nameOfFile);
    file_ptr = fopen(nameOfFile, "w");
    fclose(file_ptr);
}



// 19070001027 Ali Kağan Bertizlioğlu
int main(void) {
    pthread_t thread1,thread2,thread3,thread4;


    while(1){
        printf("*******Menu************\n");
        printf("Press 1 for : Read a file \n");
        printf("Press 2 for : Write to  a file \n");
        printf("Press 3 for : OPen a file \n");
        printf("Press 4 for : Close a file\n");
        printf("Press any button except 1 2 3 4 for exit\n");
        int input;
        scanf("%d", &input);

        if(input == 1){
            pthread_create(&thread1, NULL, ThreadFunctionRead, NULL); //This function reads the all characters from a5 file
            pthread_join(thread1, NULL);

        }else if(input ==2){
            pthread_create(&thread2, NULL, ThreadFunctionWrite, NULL); //This function writes a word to a file****It writes to until space(" ") character. Its important to care that while using it.
            pthread_join(thread2, NULL);

        }else if(input ==3){
            pthread_create(&thread3, NULL, ThreadFunctionOpen, NULL); //This function open's a file( if not exist creates), at the end it closes file.
            pthread_join(thread3, NULL);


        }else if(input ==4){
            pthread_create(&thread4, NULL, ThreadFunctionClose, NULL); //This function close's a file but as you know, file should be opened before closing it. So my function works like that.
            pthread_join(thread4, NULL);

        }else{
            printf("\n Program is turned of succesfully");
            break;
        }


    }




}
