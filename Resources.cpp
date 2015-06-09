/*
	Igor Lopes
	Schedulability Analysis
	June 9th , 2015
	oliv7721@vandals.uidaho.edu
*/
#include <iostream>
#include <fstream>

using namespace std;

class Resource
{
	public: void perfFunction(double a, int t)
	{
		ofstream file;
		file.open("ResultFunction.txt");
		double Ft;
		Ft = 1 - (a * t);
		file << "Performance function result:" << Ft <<endl;
		cout << "Performance function result: " << Ft << endl;
		file.close();
	}

	public: void supplyAnalysis(double a , int t, int pi, int phi)
	{
		ofstream file;
		file.open("ResultAnalysis.txt");
		double theta;
		theta = (pi - phi) - (a/2 * pi - phi * pi - phi);
		int k = t / pi;
		double supply;
	
		if(t % pi == 0)
		{
			supply = k * theta;		
			file << "Supply:" << supply << endl;
			file.close();
		}

		if(t % pi != 0)
		{
			if(t % pi >= pi - phi)
			{
				supply = (k + 1) * theta;
				file << "Supply:" << supply << endl;
				file.close();
			}
			if(t % pi < pi - phi)
			{
				for(int index = 0; index <= t; index ++)
				{
					supply = (k * theta)   +  ( (t % pi) - (a/2 * (t % pi) * (t % pi) ) );
					file << "Supply for time: [" << index << "]" << ":" << supply <<endl;
					cout << "Supply for time: [" << index << "]" << ":" << supply <<endl;
				}
				file.close();
			}
			
		}
	}

};

int main()
{
	Resource r;
	int op;
	double a;
	int t, pi,phi;

    cout << "******************* Resources Simulation *******************" << endl;
    cout << "Enter 1 to calculate the Performance Function" << endl;
    cout << "Enter 2 to calculate the Supply int a time interval" << endl;
    cout << "Enter 3 to exit the program" << endl;
	cin >> op;

		switch (op)
		{
			case 1:
				{
					cout << "Enter the value between 0 and 1 for the constant A:";
					cin >> a;
					while(a < 0 || a > 1)
					{
						cout << "Invalid entry for the constant A ! \nPlease enter a number between 0 and 1:";
						cin >> a;
					}
					cout << "Enter the value for the time:";
					cin >> t;
					r.perfFunction(a,t);
					break;
				}
			case 2:
				{
					cout << "Enter the value between 0 and 1 for the constant A:" << endl;
					cin >> a;
					while(a < 0 || a > 1)
					{
						cout << "Invalid entry for the constant A ! \nPlease enter a number between 0 and 1:";
						cin >> a;
					}
					cout << "Enter the value for the time:";
					cin >> t;
					cout << "Enter the value for Pi:";
					cin >> pi;
					cout << "Enter the value for Phi:";
					cin >> phi;
					r.supplyAnalysis(a,t,pi,phi);
					break;
				}
			case 3:
				{
					exit(0);
				}
			default:
				cout << "Invalid entry !" << endl;
				op = 0;
		}

	system ("PAUSE");
	return 0;
}

