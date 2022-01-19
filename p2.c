#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/un.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<errno.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex;
sem_t forks[5];
sem_t ketchup;
pthread_t threads[5];
int number[5];

void* philprocess(void* idx) {
	int id = *((int *) idx);
	while(1) {
		sem_wait(&mutex);
		sem_wait(&forks[id]);
	    sem_wait(&forks[(id + 1) % 5]);
        sem_wait(&ketchup);
		printf("Philosopher %d has used forks %d and %d to have his meal with a saucer of ketchup\n", id , id, (id + 1) % 5);
		sem_post(&mutex);
		sem_post(&forks[(id + 1) % 5]);
	    sem_post(&forks[id]);
        sem_post(&ketchup);
		printf("Philosopher %d: Meal finished\n", id);
		printf("\n");
		sleep(1);
	}
}

int main() {
	
    sem_init(&mutex, 0, 1);
    sem_init(&ketchup, 0, 4);

    for(int i = 0; i < 5; i++) {
        sem_init(&forks[i], 0, 1);
	    number[i] = i;
    }

	for(int i = 0; i < 5; i++) {
		pthread_create(&threads[i], NULL, philprocess, &number[i]);
	}

	for(int i = 0; i < 5; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}


