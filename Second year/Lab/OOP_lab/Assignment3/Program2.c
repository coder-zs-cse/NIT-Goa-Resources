#include<stdio.h>
#include<stdlib.h>
#define take(n) int n;scanf("%d",&n)
void writefile(char *file_name){
   FILE* file = fopen(file_name, "r"); 
    if(file == NULL) 
    {
        printf("Error! File not found at %s\n", file_name);
        exit(-1); 
    }
    char ch; 
    do{
        ch = fgetc(file);
        printf("%c", ch);
    }while(ch != EOF);  
}
int main(int argc, char *argv[]){
   if(argc==1) {
      printf("No files inputted\n");
   }
   else{
      for(int i=1;i<argc;i++){
         writefile(argv[i]);
      }
   }
return 0;
}