#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "LinkedList.h"

using namespace std;

	Process createProcess(int ID){
		Process p;
		int time = rand() % 5 + 1;
		p.setExecution(time);
		p.setID(ID);
		p.setText();
		return p;

	}

class Test{

	public:
	LinkedList L;
	int pid;
	Test(){

	pid = 0;
	}
	public: void addWorkload(){
		for(int i = 0 ; i < 1000; i++){
			Process p = createProcess(pid);
			L.insertProcess(p);
			pid++;
			
		}
		cout << "WorkLoad Added" <<endl;
	}
	
};

void *cpuCore1(void* arg){
	Test t; 

	int pid = 0;
	t.addWorkload();
	

	//Process *p = (Process*) arg;
	while(true){
		Process k = t.L.removeProcess();
		if(t.L.getSize() < 10){
			t.addWorkload();
		}
		for(int sec= k.getExecution();sec>= 0 ;sec--){
			usleep(1000000);
			//cout << "Running Thread ID: " << k.getID()<< " Total: " <<k.getExecution() << "Left: " << sec << endl;
			
			}
}
}
	
	//pthread_exit(NULL);	
//cout << "Threads Exited"<<endl;
	
int main()
{
	Process p = createProcess(0);
	pthread_t threads [10];
	int rc;
 	for(int i = 0; i < 10; i++){
		rc = pthread_create(&threads[i],0,cpuCore1,(void*) &p);


		if(rc){
			cout << "Error "<<endl;
			exit(-1);
		}		
	}

pthread_exit(NULL);


return 0;
}
