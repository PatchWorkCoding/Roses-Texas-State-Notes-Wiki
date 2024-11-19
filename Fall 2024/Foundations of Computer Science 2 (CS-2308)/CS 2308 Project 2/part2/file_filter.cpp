#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
   //Checks to see if the user provided the appropriate amount of parameters
   if(argc != 3) {
      cout << "Error: incorrect number of parameters" << endl;
      return -1;
   }

   queue<char> fileQueue;
   //Trys to open the input file given by argv[1] an throws and error if it can't be opened
   ifstream inputFile;
   inputFile.open(argv[1]);
   if(!inputFile.is_open()) {
      cout << "Error: unable to open \"" << argv[1] << "\"" << endl;
      return -1;
   }

   //Reads the file character by character and loads it into the queue
   char fileInputChar;
   while(!inputFile.eof()) {
      fileInputChar = inputFile.get();

      if(fileInputChar > -1) {
         fileQueue.push(fileInputChar);
      }
   }

   //trys to open the output file given by argv[2] and throws an error if its can't be opened
   ofstream outputFile;
   outputFile.open(argv[2]);
   if(!outputFile.is_open()) {
      cout << "Error unable to open \"" << argv[2] << "\"" << endl;
      return -1;
   }

   //Reads the queue character by character, converts the characters to uppercase, and then outputs them to the output file
   while(!fileQueue.empty()) {
      outputFile.put((char)toupper(fileQueue.front()));
      cout << toupper(fileQueue.front()) << " ";
      fileQueue.pop();
   }

   //Alerts the user that the program finished successfully
   cout << "File Filtered Successfully!" << endl;

   //Closes all open files
   inputFile.close();
   outputFile.close();
   return 0;
}

