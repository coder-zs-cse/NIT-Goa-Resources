#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int mutex = 1;
int full = 0;
int empty = 3;
int item = 0;

void wait(int *mutex){
	*mutex = *mutex - 1;
}
void signal(int *mutex){
	*mutex = *mutex + 1;
}

void producer(){
	wait(&mutex);
	signal(&full);
	wait(&empty);
	
	item++;
	printf("Currently produced item: %d\n",item);

 	signal(&mutex);
}

void consumer(){
	wait(&mutex);
	signal(&empty);
	wait(&full);

	printf("Currently consumed item: %d\n",item);
	item--;

	signal(&mutex);
}

int main(){
	int n;
	printf("1.Producer\n 2.Consumer\n 3.Exit\n");
	
	while(1){
		printf("Your input: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				if((mutex==1) && (empty!=0)) producer();
				else printf("Buffer is full\n");
			break;
			case 2:
				if((mutex==1) && (full!=0)) consumer();
				else printf("Buffer is empty\n");
			break;
			case 3:
				exit(0);
			default:
				printf("Check the menu and choose again\n)");
			}
	}
return 0;
}

											
