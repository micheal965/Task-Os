#include <stdio.h>
#include <stdlib.h>

void list_files( char* directory) {
    char Command[]="ls -la ";
    strcat(Command,directory);
    system(Command);
}

void change_permissions( char* file_path,  char* permissions) {
    char Command[100];
    snprintf(Command, sizeof(Command), "chmod %s %s", permissions, file_path);
    system(Command);
}

void create_file(char* file_path) {
    char Command[100];
    snprintf(Command, sizeof(Command), "touch %s", file_path);
    system(Command);
}

void delete_file(char* file_path) {
    char Command[100];
    snprintf(Command, sizeof(Command), "rm %s", file_path);
    system(Command);
}

void create_directory( char* directory_path) {
    char Command[100];
    snprintf(Command, sizeof(Command), "mkdir %s", directory_path);
    system(Command);
}

void delete_directory( char* directory_path) {
    char Command[100];
    snprintf(Command, sizeof(Command), "rm -r %s", directory_path);
    system(Command);
}

void create_symbolic_link(char* source_path,  char* link_path) {
    char Command[100];
    snprintf(Command, sizeof(Command), "ln -s %s %s", source_path, link_path);
    system(Command);
}
int main() {
char c;
printf("Press: A to list files/directories\n");
printf("Press: B to change permission of files\n");
printf("Press: C to make/delete files/directories\n");
printf("Press: D to create symbolic link files\n");
scanf("%c",&c);
switch (toupper(c)){
case 'A':{
     char directory[50];
     printf("Enter path to files/directories:");
     scanf("%s",directory);
     list_files(directory);
    break;
}
case 'B':{
     char file_to_change[50] ;
     char new_permissions[10];
     printf("Enter path of file to change permission:");
     scanf("%s",file_to_change);
     printf("Enter new permission:");
     scanf("%s",new_permissions);
    change_permissions(file_to_change, new_permissions);
    break;
}
case 'C':{
printf("Press A: to make directory:\n");
printf("Press B: to delete directory:\n");
printf("Press c: to make file:\n");
printf("Press D: to delete file:\n");
char c2;
scanf(" %c",&c2);
switch (toupper(c2)){
    case 'A':{
    char directory_to_create[50];
    printf("Enter path to make directory:");
    scanf("%s",directory_to_create);
    create_directory(directory_to_create);
    break;
    }
    case 'B':{
    char directory_to_delete[50];
    printf("Enter path of directory to delete:");
    scanf("%s",directory_to_delete);
    delete_directory(directory_to_delete);
    break;
    }
    case 'C':{
    char file_to_create[50];
    printf("Enter path to make file :");
    scanf("%s",file_to_create);
    create_file(file_to_create);
    break;
    }
    case 'D':{
     char file_to_delete[50];
    printf("Enter path of file to delete:");
    scanf("%s",file_to_delete);
    delete_file(file_to_delete);
    break;
    }
}
break;
}
case 'D':{
     char source_file[50];
     char symbolic_link[50];
     printf("Enter source_file:");
     scanf("%s",source_file);
     printf("Enter symbolic_link:");
     scanf("%s",symbolic_link);
    create_symbolic_link(source_file, symbolic_link);
break;
}
default:{
printf("invalid option");
break;
}
}
}
