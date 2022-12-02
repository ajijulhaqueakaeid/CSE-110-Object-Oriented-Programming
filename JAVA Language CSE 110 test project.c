#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000


void readFile();
void deletefile();
int menu();
void createevent()
{
    FILE *fPtr;
    char filePath[100];

    char dataToAppend[BUFFER_SIZE];



    printf("Enter Event file : ");
    scanf("%s", filePath);


    fPtr = fopen(filePath, "a");



    if (fPtr == NULL)
    {

        printf("\nUnable to open '%s' file.\n", filePath);
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }



    printf("\nEnter Events: ");
    fflush(stdin);
    fgets(dataToAppend, BUFFER_SIZE, stdin);


    fputs(dataToAppend, fPtr);





    printf("\nSuccessfully Saved data to file. \n");
    printf("Changed file contents:\n\n");




    fclose(fPtr);
}

int main()
{
    while(1)
    {
        int menuid=menu();
        char a =0;
        scanf("%c",&a);
        if(menuid==1)
        {
            createevent();
        }
        else if(menuid==2)
        {
            readFile();

        }
        else if(menuid==3)
        {

            deletefile();
        }
    }



    return 0;
}

int menu()
{
    printf("1.Add Event \n");
    printf("2.Show Event \n");
    printf("3.Delete Event \n");
    int menuid=0;
    scanf("%d",&menuid);
    return menuid;

}

void readFile()
{
    char ch, file_name[25];
   FILE *fp;

   printf("Enter Event File you wish to see\n");
   gets(file_name);

   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   printf("The contents of %s file are:\n", file_name);

   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
}

void deletefile()
{

    int status;
      char file_name[25];

      printf("Enter name of Event file you wish to delete\n");
      gets(file_name);

      status = remove(file_name);

      if (status == 0)
        printf("%s file deleted successfully.\n", file_name);
      else
      {
        printf("Unable to delete the file\n");
        perror("Following error occurred");
      }
}
