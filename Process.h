#include <iostream>
#include <string> 
using namespace std;
class Process {
private:

int id;
double execution_time;
bool isAlive;
string text;

	public: void setText(){
		text = "wertyuisfiajkfbjhsafahsfvahfbahvAUIHSASFASFBAUIFBASFBASFAUF2302854528524085495829ISDNFSDHFUISDFJSBFSOB240845U2045U0845U2095U2HDSOJFSNDJFBSFBSDIYFGASYUFVSDHFVSDGVFUSDVFSVFKHSFBKSVFKHSVFHSVFSDIEDKRYEWURISDOPFKNDSBYSVBN987654R";
	}
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
