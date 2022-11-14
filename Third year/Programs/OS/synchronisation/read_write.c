#include<stdio.h>
#include<stdlib.h>

int wrt = 1;
int mutex = 1;
int readerCount = 0;
int count=1;

void wait(int *value){
	*value = *value - 1;
}
void signal(int *value){
	*value = *value + 1;
}

void writer(){
	wait(&wrt);
	count++;
	printf("Writer has modified the value of count to %d\n",count);
}
void stopWriter(){
	printf("Writer has stopped writing\n");
	signal(&wrt);
}
void reader(){
	wait(&mutex);
	readerCount++;
	if(readerCount==1){
		wait(&wrt);
	}
	signal(&mutex);

	printf("Reader %d has read the value of count as %d\n",readerCount,count);
}
void stopReader(){
	wait(&mutex);
	readerCount--;
	if(readerCount==0){
		signal(&wrt);
	}
	signal(&mutex);
}


int main(){
	
	int n;
	printf("1.Read the file\n2.Write the file\n3.Stop reader\n4.Stop writing\n5.Exit\n");
	while(1){
	scanf("%d",&n);
	switch(n){
		
		case 1:
			if(wrt==1 || readerCount!=0) reader();
			else printf("Writing in process\n");
		break;
		case 2:
			if(wrt==1 && readerCount==0) writer();
			else if(wrt==0 && readerCount==0) printf("Writing in process\n");
			else printf("Reading in process\n");
		break;
		case 3:
			if(readerCount>0) stopReader();	
			else printf("No reading in process\n");
		break;
		case 4:
			if(wrt==0 && readerCount==0) stopWriter();
			else printf("No writing in process\n");
		break;
		case 5:
			exit(0);
		break;
		default:
			printf("Check the menu and try again\n");
	}}

	return 0;
}

