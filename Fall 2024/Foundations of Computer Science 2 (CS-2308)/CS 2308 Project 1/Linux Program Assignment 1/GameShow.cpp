using namespace std;
#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <cstdlib>

bool read_questions(string _questionsFileName);
bool read_answers(string _answersFileName);
void show_questions(string _displayQuestion[], int _previousAnswerIndex);
char player_try(int _questionIndex, int _previousAnswer, bool _showQuestion); 
int play_game();
void sort_score(string playerName);

//This for easy conversion between character to array indexes and back
const char POSSIBLE_ANSWERS[4] = {'A', 'B', 'C', 'D'};

unsigned int seed;
string questions[50][5];
char answers[50];
int numberOfQuestions;
vector<int> usedQuestions;
int currentQuestion = 0;
int previousPoints;
int score;


int main(int argc, char* argv[4]){
    
    if(argc < 4)
    {
        cout << "ERROR: There are too few arguments";
        return -1;
    }
    else if(argc > 4){
        cout << "ERROR: There are too many arguments";
        return -1;
    }
    
    
    
    if(!read_questions(argv[1]))
        return -1;
    if(!read_answers(argv[2]))
        return -1;

    cout << "Please enter your name" << endl;
    cout << ">: ";    
    string playerName;
    cin >> playerName;
    cout << endl << endl;

    seed = atoi(argv[3]);
    srand(seed);

    score = 0;
    previousPoints = 1;
    
    int gameExitCode = 0;
    while (gameExitCode == 0)
    {
        gameExitCode = play_game();
    }

    if(gameExitCode == 1)
    {
        sort_score(playerName);
    }
    
    return 0;
}

/*reads in the questions/responses from file, storing to 2D array of strings*/
bool read_questions(string _questionsFileName){
    ifstream questionInputStream;
    questionInputStream.open(_questionsFileName);

    if(!questionInputStream.is_open())
    {
        cout << "ERROR: could not open " << _questionsFileName << endl;
        questionInputStream.close();
        return false;
    }

    int questionIndex = 0;
    while(!questionInputStream.eof())
    {
        string curline;
        getline(questionInputStream, curline);
        if (curline.size() > 0)
        {
            questions[questionIndex][4] = curline;
            getline(questionInputStream, questions[questionIndex][0]);
            getline(questionInputStream, questions[questionIndex][1]);
            getline(questionInputStream, questions[questionIndex][2]);
            getline(questionInputStream, questions[questionIndex][3]);
            questionIndex++;
        }
    }

    numberOfQuestions = questionIndex;
    questionInputStream.close();
    return true;
}

/*reads in the answers from file, storing to a 1D array of characters*/
bool read_answers(string _answersFileName){
    ifstream answersInputStream;
    answersInputStream.open(_answersFileName);

    if(!answersInputStream.is_open())
    {
        cout << "ERROR: could not open " << _answersFileName << endl;
        answersInputStream.close();
        return false;
    }

    int answerIndex = 0;
    while(!answersInputStream.eof() && answerIndex < 50){
        string curLine;
        getline(answersInputStream, curLine);
        answers[answerIndex] = curLine.at(0);
        answerIndex++;
    }
    
    if(answerIndex != numberOfQuestions)
    {
        if(answerIndex > numberOfQuestions){
            cout << "ERROR: There are too many answers!" << endl;
            cout << "answers: " << answerIndex
                << ", questions: " << numberOfQuestions;
            
            answersInputStream.close();
            return false;
        }
        /*We can skip the comparision because we already know the 
            values aren't equal*/
        else{
            cout << "ERROR: There are too few answers!" << endl;
            cout << "answers: " << answerIndex 
                << ", questions: " << numberOfQuestions;
            
            answersInputStream.close();
            return false; 
        }
    }

    answersInputStream.close();
    return true;
}

/*displays a question and its responses, labeled A-D, optionally hiding a 
specified response for the second try at a question.  Its primary parameter 
is an array of strings that is one single question/response set*/
void show_questions(string _displayQuestion[], int _previousAnswerIndex){
    cout << _displayQuestion[4] << endl;
    for (int i = 0; i < 4; i++)
    {
        if(i != _previousAnswerIndex)
        {
            cout << POSSIBLE_ANSWERS[i] << ": " << 
                _displayQuestion[i] << endl;
        }
    }
    cout << endl;
}

/*handles the overall display of a question, getting the response from player, 
validate response is in range A-D */
char player_try(int _questionIndex, int _previousAnswer, bool _showQuestion){
    if(_showQuestion){
        show_questions(questions[_questionIndex], _previousAnswer);
    }  
    
    cout << ">: ";
    
    string playerInput;
    cin >> playerInput;

    //cout << playerInput.size() << " " << playerInput.at(0) << " " << (int)toupper(playerInput.at(0));
    if(playerInput.size() == 1 && 
        ((int)toupper(playerInput.at(0)) >= 65 && 
        (int)toupper(playerInput.at(0)) <= 68))
        return toupper(playerInput.at(0));
    else
        return '\0';
} 

/*the core function for controlling the game play.  Picks questions, checks 
correctness of player response, offers second chance, determines and 
applies scoring.  (NOTE:  This function does a lot – it will not be unusual 
to see this on at twice the recommended size for a function.) */
int play_game(){

    if (usedQuestions.size() >= 6)
    {
        return 1;
    }

    int previousAnswerIndex = 0;
    bool foundUseableIndex = false;
    int questionIndex = -1;
    while (!foundUseableIndex)
    {
        foundUseableIndex = true;
        questionIndex = rand();
        questionIndex %= numberOfQuestions; // Replace with Random Code
        
        for (int i = 0; i < usedQuestions.size(); i++)
        {
            if(questionIndex == usedQuestions.at(i))
            {
                foundUseableIndex = false;
                break;
            }
        }
        
    }
    usedQuestions.push_back(questionIndex);
    
    char playerInput = player_try(questionIndex, -1, true);
    
    //If the player put in an incorrect input prompt them until it is correct
    while (playerInput == '\0'){
        cout << endl << "Error: Invalid Input, please enter an input A-D" << endl;
        playerInput = player_try(questionIndex, -1, false);
    }

    //Check to see if the player input the correct answer. 
    //If so Exit the function early
    if (answers[questionIndex] == playerInput)
    {
        previousPoints *= 10;
        score += previousPoints;
        cout << "Correct! you scored: " << previousPoints << endl << endl;
        return 0;
    }

    //Else Log the previous answer and ask if the player would like to continue
    cout << "Incorrect! would you like to try again? [Y/N]" << endl;
    
    //Converts playerInput into an int ranging 
    //between 0-3 so we can use it to index into the questions array
    previousAnswerIndex = (int)(playerInput) - 65;

    //Continuously prompt the player until we get a valid input
    while (playerInput != 'Y')
    {
        cout << ">: ";
        string skipInput;
        getline(cin, skipInput);
        
        if(skipInput.size() == 1)
        {
            if(toupper(skipInput.at(0)) == 'Y'){
                playerInput = 'Y';
                continue;
            }

            //If the player skips the question exit early
            else if (toupper(skipInput.at(0)) == 'N')
            {
                cout << "Question Skipped!" << endl << endl;
                return 0;
            }

            else{
                cout << "Error: Invalid input, please enter \"Y\" or \"N\"" << endl;
            }
        }
        else{
            cout << "Error: Invalid input, please enter \"Y\" or \"N\"" << endl;
        }
    }
    
    playerInput = player_try(questionIndex, previousAnswerIndex, true);
    
    //If the player inputs an incorrect input prompt them until it is correct
    while (playerInput == '\0'){
        cout << endl << "Error: Invalid Input, please enter an input A-D" << endl;
        playerInput = player_try(questionIndex, previousAnswerIndex, false);
    }

    //Check to see if the player input the correct answer. 
    //If so Exit the function early
    if (answers[questionIndex] == playerInput)
    {
        previousPoints *= 5;
        score += previousPoints;
        cout << "Correct! you scored: " << previousPoints << endl;
        return 0;
    }
    else {
        cout << "Incorrect! you have lost the game... Thank you for playing" << endl;
        return -1;
    }

    return 0;
}

/*read in historical records of previous players (including current player as 
well). Sort the scores and names accordingly, display the player’s name 
and score who has the highest score, and the rank of the currently player 
based on his/her score. */
void sort_score(string playerName){
    
    ofstream fout;
    fout.open("summary.txt", ios::app);

    fout << playerName << "\t" << score << endl;
    fout.close();

    ifstream fin;
    fin.open("summary.txt");
    
    int numberOfLines = 0;
    vector<string> names;
    vector<int> scores;
    
    //string fileContents = "";
    while (!fin.eof())
    {
        //fileContents += curLine;
        string curName; 
        fin >> curName;
        if (curName == "")
            continue;    
        names.push_back(curName);
        
        int curScore;
        fin >> curScore;
        scores.push_back((curScore));
        
        numberOfLines++;
    }
    
    cout << endl;
    bool isSorted = false;
    while (!isSorted){
        
        isSorted = true;
        for (int i = 0; i < numberOfLines - 1; i++)
        {
            if(scores.at(i) < scores.at(i + 1)){
                int swapValue = scores.at(i);
                scores.at(i) = scores.at(i + 1);
                scores.at(i + 1) = swapValue;
                isSorted = false;

                string swapNameValue = names.at(i);
                names.at(i) = names.at(i + 1);
                names.at(i + 1) = swapNameValue;
            }
        }
        
    }   

    int linesToDisplay = 3;
    if (numberOfLines < 3)
        linesToDisplay = numberOfLines;

    for (int i = 0; i < linesToDisplay; i++)
    {
        cout << names.at(i) << "\t" << scores.at(i) << endl;
    }
    
    fin.close();
}