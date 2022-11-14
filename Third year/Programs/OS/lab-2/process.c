#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void main(){
	int pid;
	pid = fork();
	if(pid==0){
		printf("Child process %d\n",getpid());
		printf("Parent process %d\n",getppid());
		sleep(5);
		printf("Exiting the if condition\n");
	}
	else{
		sleep(10);
		printf("Exiting the else condition\n");
	}
	printf("Outside the conditional statements\n");
	
}
