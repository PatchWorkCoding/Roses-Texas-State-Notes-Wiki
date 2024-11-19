#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

int main(int argc, char* argv[3]) {
    //Checks to see if the user used the right number of parameters
    if(argc != 3) {
	cout << "Error: you entered the wrong number of parameters" << endl;
    	return -1;
    }

    //Tries to open the file used for Input and throws an error if it can't open it
    ifstream inputFile;
    inputFile.open(argv[1]);
    if(!inputFile.is_open()) {
	cout << "Error: could not open " << argv[1] << endl;
	return -1;
    }

    //Tries to open the  file used for Oupt and throws and error if it can't open it
    ofstream outputFile;
    outputFile.open(argv[2]);
    if(!outputFile.is_open()) {
	cout << "Error: could not open " << argv[2] << endl;
	return -1;
    }

    stack<char> fileStack;

    //Reads in the input file character by character into the stack
    char fileInputChar;
    while(!inputFile.eof()) {
	fileInputChar = inputFile.get();

        if(fileInputChar > -1) {
	   fileStack.push(fileInputChar);
        }
    }

    //Writes the to the output file charcter by character from the stack
    while(!fileStack.empty()) {
	//cout << fileStack.top();
	outputFile.put(fileStack.top());
	fileStack.pop();
    }

    //closes the input and output files
    outputFile.close();
    inputFile.close();

    //Alerts the user that the file reverse completed successfully
    cout << "Reversed Successfully" << endl;

    return 0;
}
