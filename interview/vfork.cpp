#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
static bool g_count = true;
int status;
int pid;

void handler(int sig, siginfo_t *info, void *context)
{
	cout <<"parent sig handler\n";
	cout <<"child PID: "<<pid<<endl;
	int status = kill(pid,0);
	cout <<"kill 0 API status:" <<status;
	int ret = wait(&status); // never put child in infinite loop as wait is blocked inside sig handler

	if(WIFEXITED(status))
		cout<<"child process exited normally\n";
	g_count = false;
}

int main()
{
	struct sigaction sig_act;
	memset(&sig_act, 0, sizeof(sig_act));
	sig_act.sa_sigaction = handler;
	sig_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &sig_act, NULL) < 0) {
		perror ("sigaction");
		return 1;
	}

	pid = vfork();
	if(pid == 0) {
		//cout <<"child process born and died ;D \n";
		cout <<"child process ;D \n";
		execl("./test",NULL); //refer test.cpp
	}
	else if(pid == -1) {
		cout <<"Error in child process creation\n";
	}
	else {
		cout << "parent process, child Pid: "<<pid<<endl;
		while(g_count) {
			sleep(10);
		}
	}

	return 0;
}
