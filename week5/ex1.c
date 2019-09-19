#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *tread_print(){
    pthread_t threadid=pthread_self();
	printf("Hello, I'm thread %02x \n", threadid);
    pthread_exit(NULL);
}

int main(){
	int N=5;
	pthread_t thread_id;
	for (int i=0; i<5; i++){
		printf("Thread %d is created \n", i);
		pthread_create(&thread_id, NULL, tread_print, NULL);
		sleep(1);
	};
	return 0;
}