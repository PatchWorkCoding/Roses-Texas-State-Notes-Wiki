@ECHO off
g++ GameShow.cpp -o gameshow.exe
gameshow.exe questions.txt answers.txt 7
pause