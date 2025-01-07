#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {
   queue<char> fileQueue;

   //Tries to open input.txt and throws an error if it can't be opened
   ifstream inputFile;
   inputFile.open("input.txt");
   if(!inputFile.is_open()) {
      cout << "Error: unable to open \"input.txt\"" << endl;
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

   //Tries to open output_reverse.txt and throws an error if its can't be opened
   ofstream outputFile;
   outputFile.open("output_filter.txt");
   if(!outputFile.is_open()) {
      cout << "Error: unable to open \"output_reverse.txt\"" << endl;
      return -1;
   }

   //Reads the queue character by character, converts the characters to uppercase, and then outputs them to the output file
   while(!fileQueue.empty()) {
      outputFile.put((char)toupper(fileQueue.front()));
      fileQueue.pop();
   }

   //Alerts the user that the program finished successfully
   cout << "File Filtered Successfully!" << endl;

   //Closes all open files
   inputFile.close();
   outputFile.close();
   return 0;
}

