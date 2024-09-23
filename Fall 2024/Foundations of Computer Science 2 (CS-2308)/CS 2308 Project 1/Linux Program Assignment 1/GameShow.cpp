using namespace std;
#include<iostream>
#include<string>
#include <fstream>

bool read_questions(string _questionsFileName);
bool read_answers(string _answersFileName);
void show_questions(string _displayQuestion[], int _previousAnswerIndex);
char player_try(int _questionIndex, int _previousAnswer, bool _showQuestion); 
void play_game();
void sort_score();

//This for easy conversion between character to array indexes and back
const char POSSIBLE_ANSWERS[4] = {'A', 'B', 'C', 'D'};

int seed;
string questions[50][5];
string answers[50];
int numberOfQuestions;

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
    
    seed = atoi(argv[1]);
    if(!read_questions(argv[2]))
        return -1;
    if(!read_answers(argv[3]))
        return -1;
    
    show_questions(questions[0], 2);
    for (int i = 0; i < numberOfQuestions; i++)
    {
        show_questions(questions[i], -1);
        /*
        cout << "Question #" << i << endl;
        cout << questions[i][4] << endl;
        cout << questions[i][0] << endl;
        cout << questions[i][1] << endl;
        cout << questions[i][2] << endl;
        cout << questions[i][3] << endl;
        cout << "correct answers is: " << answers[i] << endl << endl;
        */
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
            /*We story the question text in the last index so that the
            indicies for answers match with the indicies in 
            "POSSIBLE_ANSWERS"*/
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
        answers[answerIndex] = curLine;
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
    
    char playerInput;
    cin >> playerInput;

    bool foundValidResponse = false;
    for (int i = 0; i < 4; i++)
    {
        if(toupper(playerInput) == POSSIBLE_ANSWERS[i])
        {
            foundValidResponse = true;
            break;
        }
    }
    
    if(foundValidResponse)
    {
        return playerInput;
    }
    else {
        return '\0';
    }
} 

/*the core function for controlling the game play.  Picks questions, checks 
correctness of player response, offers second chance, determines and 
applies scoring.  (NOTE:  This function does a lot – it will not be unusual 
to see this on at twice the recommended size for a function.) */
void play_game(){
    int questionIndex = 0; // Replace with Random Code
    char playerInput = player_try(questionIndex, -1, true);
    //If the player put in an incorrect input prompt them until it is correct
    while (playerInput != '\0'){
        cout << "Error: Invalid Input please enter an input A-D" << endl;
        playerInput = player_try(questionIndex, -1, true);
    }
    
}

/*read in historical records of previous players (including current player as 
well). Sort the scores and names accordingly, display the player’s name 
and score who has the highest score, and the rank of the currently player 
based on his/her score. */
void sort_score(){

}