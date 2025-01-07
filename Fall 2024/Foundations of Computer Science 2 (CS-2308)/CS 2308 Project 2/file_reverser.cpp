#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

int main() {

    //Tries to open the file used for Input and throws an error if it can't open it
    ifstream inputFile;
    inputFile.open("input.txt");
    if(!inputFile.is_open()) {
	   cout << "Error: could not open \"input.txt\"" << endl;
	   return -1;
    }

    //Tries to open the file used for Output and throws and error if it can't open it
    ofstream outputFile;
    outputFile.open("output_reverse.txt");
    if(!outputFile.is_open()) {
	cout << "Error: could not open \"output_reverse.txt\"" << endl;
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

    //Writes the to the output file character by character from the stack
    while(!fileStack.empty()) {
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
