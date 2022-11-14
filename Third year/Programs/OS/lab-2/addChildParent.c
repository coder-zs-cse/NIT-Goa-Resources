#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
void main(){
	int n = 5;
	int array[n];
	int pid = fork();
	if(pid==0){
		for(int i=0;i<n;i++){
			scanf("%d",&array[i]);
		}
		
	
	}
	else{
		sleep(10);
		int sum=0;
		
		for(int i=0;i<n;i++){
			printf("%d ",array[i]);
			sum+=array[i];
		}
		printf("The sum is %d",sum);
	}
	
	printf("Program successfully completed\n");
	sleep(15);
}

