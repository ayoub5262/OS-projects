#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>    
#include <sys/wait.h>   

int main() {
    while (1) {  // Infinite loop to continuously display the menu
        printf("Menu:\n1. ls -a\n2. cat fish.txt\n3. exit\n");  // Display menu
        printf("Please select an option: ");
        int choice;
        scanf("%d", &choice);  // Read user selection
        while (getchar() != '\n');  // Clear input buffer

        if (choice == 3) {  // If the user chooses "exit"
            printf("Program terminated.\n");
            exit(0);  // Exit program
        }
        pid_t pid = fork();  // Create new process

        if (pid < 0) {  // Error handling for fork()
            perror("Error in fork");
            exit(1);
        }
        if (pid == 0) {  // In child process
            // Execute the corresponding program based on user selection
            if (choice == 1) 
                execlp("ls", "ls", "-a", NULL);
                
             else if (choice == 2) 
                execlp("cat", "cat", "fish.txt", NULL);
            
            perror("Error in execlp");  // Error handling for execlp()
            exit(1);
        } else {  // In parent process
            int status;
            waitpid(pid, &status, 0);  // Wait for child process to terminate
            // Output PID and exit status of child process
            printf("\nChild process with PID %d terminated with status %d\n", pid, WEXITSTATUS(status));
        }
    }
    return 0;
}
