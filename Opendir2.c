/*The Following code is a User-defined code for the functions 
opendir(),closedir(),readdir()*/
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main()
{
    char dirp[100];
    printf("Enter the directory name :");
    scanf("%s",&dirp);
    DIR *dir=opendir(dirp);/*Declares pointer dir of type DIR,which represent a directory stream*/
    if(dir){
        struct dirent *entry;//pointer to the type struct dirent and entry pinter to the directory
        printf("\n\nDirectory Contents\n");
        while((entry=readdir(dir))!=NULL){
            printf("%s\n",entry->d_name);//entry->d_name prints the names of entries in the directory
        }
        closedir(dir);//close the directory reffered by dir
    }
    return 0;
}