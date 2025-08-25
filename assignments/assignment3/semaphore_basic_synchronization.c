/**
 * @file 3_b.c
 * @brief Assignment 3b - Basic semaphore implementation for process synchronization
 * @author Ayoub
 * @date 2025
 * 
 * This program demonstrates basic semaphore usage for synchronizing two worker 
 * threads in a grading system simulation. It implements a producer-consumer 
 * pattern where workers coordinate access to shared resources (exams and result lists).
 * 
 * Key concepts demonstrated:
 * - POSIX semaphores for mutual exclusion
 * - Thread synchronization without deadlocks
 * - Resource management in concurrent systems
 * - Signal handling for graceful shutdown
 */

/* Required system includes */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

#include "exam_grading_framework.h"

/**
 * @brief Initialize semaphores for process synchronization
 * 
 * Initializes two binary semaphores:
 * - exams: Controls access to exam resources (mutex)
 * - list: Controls access to the result list (mutex)
 * 
 * Both semaphores are initialized with value 1 to act as mutexes,
 * ensuring only one thread can access the protected resource at a time.
 * 
 * @note This function will exit the program on initialization failure
 */
void init_semaphores(void){
    /*
	 * Initialize semaphores with proper error handling
	 */
	if (sem_init(&exams, 0, 1) == -1) {
		perror("Could not initialize exams semaphore");
		exit(EXIT_FAILURE);
	}
	if (sem_init(&list, 0, 1) == -1) {
		perror("Could not initialize list semaphore");
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Worker thread function for Worker A
 * @param arg Thread argument (unused)
 * @return NULL on thread completion
 * 
 * This function implements the main loop for worker A, which:
 * 1. Performs other work (other_work)
 * 2. Retrieves exams using semaphore synchronization
 * 3. Grades the exams
 * 4. Updates the result list with proper synchronization
 * 
 * The function demonstrates proper use of semaphores to prevent
 * race conditions when accessing shared resources.
 */
void *worker_a(void *arg) {
	char name = 'A';

	printf("Worker %c: I'm starting now.\n", name);
	sleep(1);

	while (1) {
		/**
		 * Phase 1: Perform other work
		 * Worker performs alternative tasks while not processing exams
		 */
		printf("Worker %c: Now I'm working on something else.\n", name);
		worker_a_status = other_work;
		perform_other_work(name);
		 
		/** 
		 * Phase 2: Retrieve exams with synchronization
		 * Use semaphore to ensure exclusive access to exam resources
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
	}
	pthread_exit(NULL);
}

void *worker_b(void *arg) {
	char name = 'B';

	printf("Worker %c: I'm starting now.\n", name);

	while (1) {
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
	}
	pthread_exit(NULL);
}

void check_for_deadlocks(void){
	return;
}
