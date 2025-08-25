#ifndef EXAM_GRADING_FRAMEWORK_H
#define EXAM_GRADING_FRAMEWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

/* Variables for the two worker threads */
extern pthread_t worker_a_thread;
extern pthread_t worker_b_thread;

/* Possible status values of a worker */
enum STATUS {
	other_work,
	fetch_exams, 
	fetch_list, 
	grading};

/* Current status of the two workers */
extern enum STATUS worker_a_status;
extern enum STATUS worker_b_status;

/* Semaphores */
extern sem_t exams;
extern sem_t list;
extern sem_t status;

/* Function declarations */
void init_semaphores(void);
void *worker_a(void *);
void *worker_b(void *);
void perform_other_work(char);
void check_for_deadlocks(void);
void deadlock_detection(void);
void program_termination(int sig);




#endif
