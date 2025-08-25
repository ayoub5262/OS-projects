/* Required includes */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/signal.h>

#include "exam_grading_framework.h"

/* Variables for the two worker threads */
pthread_t worker_a_thread;
pthread_t worker_b_thread;

/* Current status of the two workers */
enum STATUS worker_a_status;
enum STATUS worker_b_status;

/* Semaphores */
sem_t exams;
sem_t list;
sem_t status;
int main (void) {
    /* Initial status of the two workers */
    worker_a_status = other_work;
    worker_b_status = other_work;
	/*
	 * Register signal handler for program termination.
	 * When e.g. CTRL-C is pressed in the shell, the function program_termination is executed.
	 */
	struct sigaction action;
	action.sa_handler = &program_termination;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGINT, &action, NULL) == -1) {
		perror("Could not set signal handler");
		exit(EXIT_FAILURE);
	}
	

	/*
	 * Initialize semaphores.
	 */
    init_semaphores();

	/*
	 * The worker threads are now created.
	 */
	if (pthread_create(&worker_a_thread, NULL, &worker_a, NULL) != 0) {
		perror("Could not create thread for Worker A");
		exit(EXIT_FAILURE);
	}

	if (pthread_create(&worker_b_thread, NULL, &worker_b, NULL) != 0) {
		perror("Could not create thread for Worker B");
		exit(EXIT_FAILURE);
	}

	/* 
	 * The parent process handles deadlock detection.
	 */
	deadlock_detection();

	return 0;
}



/*
 * The function for a worker thread.
 * Here the other work is implemented.
 */
void perform_other_work(char name) {
	static int i = 5;
	int duration;

	/* 
	 * Worker A always works for 8 time units, Worker B for different time units.
	 * This temporal sequence provokes a deadlock.
	 */
	if (name == 'A') {
		printf("Worker %c: My other work takes 8 seconds.\n", name);
		sleep(8);
	} else {
		if (i >= 8) {
			i = 0;
		}
		duration = (8 - i);
		printf("Worker %c: My other work takes %d seconds.\n", name, duration);
		sleep(duration);
		i+=6;
	}
}

/*
 * The function of the parent process.
 * Here deadlock detection and resolution takes place.
 */
void deadlock_detection(void) {
	while (1) {
		sleep(12);
		check_for_deadlocks();
		 
	}
}

/*
 * The function that is executed when the program is terminated (e.g. with
 * CTRL-C in the shell). Here the worker threads are cancelled and
 * the semaphores are cleaned up.
 */
void program_termination(int sig) {
	printf("Program was terminated.\n");
	
	/* Check if threads could be cancelled */
	if (pthread_cancel(worker_a_thread) == -1) {
		perror("Error terminating threads");
		exit(EXIT_FAILURE);
	}
	if (pthread_cancel(worker_b_thread) == -1) {
		perror("Error terminating threads");
		exit(EXIT_FAILURE);
	}

	if (sem_destroy(&exams) == -1) {
		perror("Error removing semaphore exams");
		exit(EXIT_FAILURE);
	}
	if (sem_destroy(&list) == -1) {
		perror("Error removing semaphore list");
		exit(EXIT_FAILURE);
	}

    if (sem_destroy(&status) == -1) {
		perror("Error removing semaphore status");
		exit(EXIT_FAILURE);
	}
	
	exit(sig);
}
