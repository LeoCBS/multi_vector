#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_THREADS 100
#define NTHREADS 4
#define VECSIZE 16

void *func_thread(void *id) {
	int my_id = *((int *) id);

	printf("Thread %d criada.\n", my_id);
	return 0;
}

int main(int argc, char **argv) {
	srand(time(NULL))
	pthread_t threads[MAX_THREADS];
	int threads_id[MAX_THREADS];

	for(int i=0; i < MAX_THREADS; i++) {
		threads_id[i] = i;
		pthread_create(&threads[i], NULL, func_thread, (void *) &threads_id[i]);
	}
	
	for(int i=0; i < MAX_THREADS; i++)
		pthread_join(threads[i], NULL);

	return 0;
}
