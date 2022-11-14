// What is the output of the following program?
int main()
{
char arr[] = {1, 2, 3};
char *p = arr;
if(&arr[0] == &arr)
printf("Same");
else
printf("Not same");
getchar();
return 0;
}