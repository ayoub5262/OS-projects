/*
 * Template for the additional task (corresponds to the template for task part c).
 * This template should be modified for the additional task.
 */

/* Necessary includes */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

#include "exam_grading_framework.h"

void init_semaphores(void){
	/**
	 * ! ! ! ADAPT THIS FUNCTION ! ! !
	 */
	/*
	 * Initialize semaphores.
	 */
	if (sem_init(&exams, 0, 1) == -1) {
		perror("Could not initialize exams semaphore");
		exit(EXIT_FAILURE);
	}
	if (sem_init(&list, 0, 1) == -1) {
		perror("Could not initialize list semaphore");
		exit(EXIT_FAILURE);
	}
	/* End of area to be modified in this function */
}


/*
 * The function of both threads (worker_a and worker_b).
 */
void *worker_a(void *arg) {
	char name = 'A';

	printf("Worker %c: I'm starting now.\n", name);
	sleep(1);

	while (1) {
		/**
		 * ! ! ! ADAPT THIS FUNCTION FROM HERE ! ! !
		 */
		/**
		 * The worker performs other work.
		 */
		printf("Worker %c: Now I'm working on something else.\n", name);
		worker_a_status = other_work;
		perform_other_work(name);
		 
		/* 
		 * Fetch exams.
		 */
		printf("Worker %c: I'm getting the exams now.\n", name);
		worker_a_status = fetch_exams;
		if(sem_wait(&exams) == -1) {
			perror("Error reserving the exams");
			exit(EXIT_FAILURE);
		}
		sleep(4);
		printf("Worker %c: I have the exams.\n", name);

		/* 
		 * Fetch list.
		 */
		printf("Worker %c: I'm getting the list now.\n", name);
		worker_a_status = fetch_list;
		if(sem_wait(&list) == -1) {
			perror("Error reserving the list");
			exit(EXIT_FAILURE);
		}
		sleep(3);
		printf("Worker %c: I have the list.\n", name);
		
		/* 
		 * Grade.
		 */
		printf("Worker %c: I'm grading now.\n", name);
		worker_a_status = grading;
		sleep(5);
		
		/* 
		 * Return list.
		 */
		printf("Worker %c: Now I'm returning the list.\n", name);
		if (sem_post(&list) == -1) {
			perror("Could not release list semaphore");
			exit(EXIT_FAILURE);
		}
		
		/* 
		 * Return exams.
		 */
		 printf("Worker %c: Now I'm returning the exams.\n", name);
		if (sem_post(&exams) == -1) {
			perror("Could not release exams semaphore");
			exit(EXIT_FAILURE);
		}
	/* End of area to be modified in this function */
	}
	pthread_exit(NULL);
}

void *worker_b(void *arg) {
	char name = 'B';

	printf("Worker %c: I'm starting now.\n", name);

	while (1) {
		/**
		 * ! ! ! ADAPT THIS FUNCTION FROM HERE ! ! !
		 */
		/**
		 * The worker performs other work.
		 */
		printf("Worker %c: Now I'm working on something else.\n", name);
		worker_b_status = other_work;
		perform_other_work(name);
		
		/* 
		 * Fetch list.
		 */
		printf("Worker %c: I'm getting the list now.\n", name);
		worker_b_status = fetch_list;
		if(sem_wait(&list) == -1) {
			perror("Error reserving the list");
			exit(EXIT_FAILURE);
		}
		sleep(3);
		printf("Worker %c: I have the list.\n", name);
		
		/* 
		 * Fetch exams.
		 */
		printf("Worker %c: I'm getting the exams now.\n", name);
		worker_b_status = fetch_exams;
		if(sem_wait(&exams) == -1) {
			perror("Error reserving the exams");
			exit(EXIT_FAILURE);
		}
		sleep(4);
		printf("Worker %c: I have the exams.\n", name);
		
		/* 
		 * Grade.
		 */
		printf("Worker %c: I'm grading now.\n", name);
		worker_b_status = grading;
		sleep(5);
		
		/* 
		 * Return exams.
		 */
		 printf("Worker %c: Now I'm returning the exams.\n", name);
		if (sem_post(&exams) == -1) {
			perror("Could not release exams semaphore");
			exit(EXIT_FAILURE);
		} 
		
		/* 
		 * Return list.
		 */
		printf("Worker %c: Now I'm returning the list.\n", name);
		if (sem_post(&list) == -1) {
			perror("Could not release list semaphore");
			exit(EXIT_FAILURE);
		}
		 
		/* End of area to be modified in this function */
	}
	pthread_exit(NULL);
}


/*
 * The function of the parent process.
 * Here deadlock detection and resolution takes place.
 */
void check_for_deadlocks(void) { 
	/* These two variables might be useful for you: */
	enum STATUS current_status_a;
	enum STATUS current_status_b;
		
	/**
	 * ! ! ! INSERT YOUR CODE HERE ! ! !
	 */
	// Initialize mutex to synchronize access to shared resources 
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	// Lock mutex before accessing status variables
    pthread_mutex_lock(&mutex);
    current_status_a = worker_a_status;
    current_status_b = worker_b_status;
	// Release mutex after access
    pthread_mutex_unlock(&mutex);

    // Check for possible deadlock
    if ((current_status_a == fetch_exams && current_status_b == fetch_list) ||
	    (current_status_a == fetch_list && current_status_b == fetch_exams)){
		printf("Deadlock detected. Deadlock resolution is being performed.\n");
		// Choose one worker for each deadlock 
		static int i = 0;
		if(i % 2 == 0) {
		// Forces worker A to release its resources
        if (current_status_a == fetch_exams)
            sem_post(&exams);
        else if (current_status_a == fetch_list)
            sem_post(&list);
		printf("Worker A has released a resource.\n");
		} else {
        // Forces worker B to release its resources
        if (current_status_b == fetch_exams)
            sem_post(&exams);
        else if (current_status_b == fetch_list)
            sem_post(&list);
        printf("Worker B has released a resource.\n");
		}
		i++;
		}
	/* End of area to be modified in this function */
	return;
}
