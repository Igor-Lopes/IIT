#include <iostream>
#include <stdlib.h>

#include "Process.h"

using namespace std;

typedef struct Node{
  Process process;
  Node* next;
} *ListPtr;



class LinkedList{
public:

ListPtr header;
ListPtr previous;
int size;

	public: LinkedList(){
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
			p = header -> process;
			ListPtr new_header = new Node; // Leak
			new_header = header -> next;
			//header -> next = NULL; //Leak
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
