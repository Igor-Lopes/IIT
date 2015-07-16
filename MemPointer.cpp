public: Process removeProcess(){
	Process p;
	if(size > 0){

		if(header -> next == NULL){
			p = header -> process;
			header = NULL;
		} else {
			p = header -> process;
			ListPtr new_header = new Node;  Leak
			new_header = header -> next;
			//header -> next = NULL; Leak
			header = new_header;
			
		}
	size --;
	return p;
	}
