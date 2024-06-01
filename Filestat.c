#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<time.h>
int main(){
    char filename[50];
    struct stat fileStat;

    printf("Enter file name :");
    scanf("%s",filename);
    if(stat(filename,&fileStat)==-1){
        perror("Error");
        return 1;
    }
    printf("Information of file %s",filename);
    printf("\n------------------------------\n");
    printf("File Size : %s\n",fileStat.st_size);
    printf("Number of Links :%s\n",fileStat.st_nlink);
    printf("File inode :\t\t%ld\n",fileStat.st_ino);


    printf("File Permission:\t\n");
    printf((S_ISDIR(fileStat.st_mode))?"d":"-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");

    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf("The file %s a symbolic link\n", (S_ISBLK(fileStat.st_mode)) ? "is" : "is not");
    printf("Last access time :%s",(&fileStat.st_atime));
    printf("Status change time :%s",(&fileStat.st_ctime));
    printf("Last modification time :%s",(&fileStat.st_mtime));
    return 0;
}