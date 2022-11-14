#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 #include <sys/wait.h>
 #include <sys/types.h>
int main()
// {
//     int n, status;
//         pid_t child;
//             n = 0;
//                 if (!(child = fork()))
//                     {
//                             n = 1;
//                                     fprintf(stderr, "n = %d\n", n);
//                                             n = 2;
//                                                 }
//                                                     else
//                                                         {
//                                                                 n = 3;
//                                                                         fprintf(stderr, "n = %d\n", n);
//                                                                                 n = 4;
//                                                                                         exit(0);
//                                                                                                 fprintf(stderr, "n =%d\n", n);
//                                                                                                     }
//                                                                                                         waitpid(child, &status, 0);
//                                                                                                             n = 5;
//                                                                                                                 fprintf(stderr, "n = %d\n", n);
//                                                                                                                     return 0;
//                                                                                                                     }
