#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <thread>

using namespace std;




class Process {
    private:
	int id;
	double execution_time;
	bool isAlive;

    public: void setID(int n){
        id = n;
    }

    public: void setExecution(int secs){
        execution_time = secs;
    }

    public: void setStatus(bool st){
        isAlive = st;
    }

    public: bool getStatus(){
        return isAlive;
    }

    public: int getExecution(){
        return execution_time;
    }

    public: int getID(){
        return id;
    }
};

class CPU{
public:
    Process *p;

    CPU(){
        p = new Process; //Leak
    }

    public: void SetProcess(Process process){
        *p = process;
    }

    public: void run(){
            for(int sec= p -> getExecution();sec>= 0 ;sec--){
                Sleep(1000);
                cout << "running" <<sec << endl;
            }
	}

	public: void displayData(){
        cout << "P#" << p -> getID() << " Execution Time Left: " << p -> getExecution() << " Running: " << p -> getStatus() << endl;
	}
};

class LinkedList{
public:
    typedef struct Node{
    Process process;
    Node* next;
    } *ListPtr;

    ListPtr header;
    ListPtr previous;
    int size;

    LinkedList(){
        header = NULL;
        previous = NULL;
        size = 0;
    }
    ~LinkedList(){

    }

    public: void insertProcess(Process p){
        ListPtr new_process = new Node;
        new_process -> process = p;
        new_process -> next = NULL;

        if(header == NULL){
            header = new_process;
            previous = header;
        } else {
            previous -> next = new_process;
            previous = new_process;
        }
        size ++;
    }

    public: Process removeProcess(){
        Process p;
        if(size > 0){
            if(header -> next == NULL){
                p = header -> process;
                header = NULL;
            } else {
                ListPtr new_header = new Node; // Leak
                new_header = header -> next;
                header -> next = NULL;
                header = new_header;
            }
             size --;
             return p;
        }
    }

    public: int getSize(){
        return size;
    }

    public: void showList(){
        ListPtr curr;
        curr = header;

        while(curr != NULL){
            Process p = curr -> process;
            cout << "P#" << p.getID() <<endl;
            curr = curr -> next;

        }

    }
};

class Scheduler{
    private:
    CPU cpu[4];
    int id;
    LinkedList L;
    public:
    Scheduler(){
        id = 0;
        for(int i = 0 ; i < 1000 ; i++){
                Process p;
                int time = rand() % 10 + 1;
                p.setExecution(time);
                p.setID(id);
                id++;
                L.insertProcess(p);
        }
    }

    public: void checkCPU(){

    }

    public: void createProcess(){
        Process p;
        int time = rand() % 10 + 1;
        p.setExecution(time);
        p.setID(id);
        id++;
    }

    public: void displaySimulation(){
        while(true){
            for(int i = 0; i < 4 ; i++){
                cout << "--------------------------------" <<endl;
                cout << "CPU: [" << i << "] : ";
                cpu[i].displayData();
                cout << "--------------------------------" <<endl;
            }
            cout.flush();
            Sleep(1000);
            cout << '\r';
        }
    }
};

int main()
{
    Scheduler S;
    return 0;
}
