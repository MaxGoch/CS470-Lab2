#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	pid_t pid;
	int status;
	const int numberofChildren = 10;
	//Array of commands
	char *commands[][3]={
		{"ls","-l",NULL}, //Command to list directory contents
		{"echo","Hello Max Gochenour",NULL}, //Command to print to
		{"date",NULL,NULL}, //command to print date
		{"pwd",NULL,NULL}, //Command to print the current working dir
		{"whoami",NULL,NULL}, //Command to print the current user
		{"uptime",NULL,NULL}, //Command to show how long the system has been running
		{"df","-h",NULL}, //command to display disk space usage
		{"free","-m",NULL}, //command to display memory usage in megabytes
		{"ps","aux",NULL}, //command to list running process
		{"cat","/etc/os-release",NULL} //command to display OS info
	};
	printf("Parent process PID: %d\n",getpid());
	for (int i = 0; i < numberofChildren; i++){
		pid = fork();
		if (pid < 0){
			perror("Fork Failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0){
			printf("Child process PID: %d - Executing commands: %s\n", getpid(), commands[i][0]);
			execvp(commands[i][0], commands[i]);
			perror("Exec Failed");
			exit(EXIT_FAILURE);
		}	
	}

	//Parent
	printf("Print out history: —------\n");
	while((pid=wait(&status))>0){
		printf("Child process with PID %d finished\n", pid);
	}
	return EXIT_SUCCESS;
}


