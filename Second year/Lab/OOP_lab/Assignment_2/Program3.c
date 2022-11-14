/* 
 * C Program to Reverse the Contents of a File and Print it
 */
#include <stdio.h>
#include <errno.h>
 
long count_characters(FILE *p){
    fseek(p,-1L,SEEK_END);
    return 1 + ftell(p);
}
 
void main(int argc, char * argv[])
{
    int i;
    long cnt;
    char ch, ch1;
    FILE *fp1, *fp2;
 
    if (fp1 = fopen("text.txt", "r"))    
    {
        printf("The FILE has been opened...\n");
        fp2 = fopen("reversed_text.txt", "w");
        cnt = count_characters(fp1); // to count the total number of characters inside the source file
        fseek(fp1, -1L, 2);     // makes the pointer fp1 to point at the last character of the file
        printf("Number of characters to be copied %d\n", ftell(fp1));
        //-1L means -1 in long datatype
        while (cnt)
        {
            ch = fgetc(fp1);
            fputc(ch, fp2);
            fseek(fp1, -2L, 1);     // shifts the pointer to the previous character
            cnt--;
        }
        printf("\n**File copied successfully in reverse order**\n");
    }
    else
    {
        perror("Error occured\n");
    }
    fclose(fp1);
    fclose(fp2);
}
// count the total number of characters in the file that *f points to
// long count_characters(FILE *f) 
// {
//     fseek(f, -1L, 2);
//     long last_pos = ftell(f); // returns the position of the last element of the file
//     last_pos++;
//     return last_pos;
// }