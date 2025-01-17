#include <iostream>
#include <ctime>
#include "myheaders.h"

using namespace std;

int main() {
	
	int		choice, sz;
	long	data1[MAXSIZE], data2[MAXSIZE];
	double  begin_time, end_time, cpu_time_used;
	string  ifilename, ofilename;

	while (1) {

		printmenu();
		cin >> choice;
		switch (choice) {

			case 1: //Reads an input file of integers
					ifilename = "lab5_input.txt";
					sz = readfile(ifilename, data1, data2);
			
					if (sz < 0)	 {
						 cerr << endl << "No input file found." <<endl;
						 return 0;
					}
					else cout<<endl<<"File size is: "<< sz << endl;
			
					break;

			case 2: //Bubblesort
					
					begin_time = clock(); 
			
					bubbleSort(data1,sz);
			
					end_time = clock();
					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "BubbleSort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_bubbleout.txt";
					writefile(data1, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;

			case 3: //Mergesort

					begin_time = clock();
					mergesort(data2,0,sz-1);
			
					end_time = clock();

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "MergeSort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_mergeout.txt";
					writefile(data2, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quiting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;
			
			case 4: // Exit Program

					cout << endl << "Program quit." << endl << endl;

					return 0;

			default: // Error in selection

					cout << endl << "Incorrect selection, try again from the menu below." << endl;
		}
	}	
	return 0;
}

