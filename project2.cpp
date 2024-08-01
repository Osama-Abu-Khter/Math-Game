#include <iostream>
using namespace std;


enum QuestionsLevel{ EasyLevel=1,MedLevel=2,HardLevel=3,Mix=4 };
enum OperationLevel{ Add=1,Sub=2,Mul=3,Div=4,Mixpp=5 };

int RandomNuber(int from,int to)
{
    int number = rand() % (to - from + 1) + from;
    return number;
}
OperationLevel GetRandomOperationType()
{
    int Op = RandomNuber(1, 4);
    return (OperationLevel)Op;
}

short HowMany()
{
    short number = 0;
    do {
        cout << "How Many Questions do want Answer ?  ";
        cin >> number;
    } while (number <1 || number > 10);
    return number;
}

QuestionsLevel ReadQuestionLevel()
{
    short number = 0;
    do {
        cout << " Enter Question Level [1]:Easy , [2]:Med , [3]:Hard , [4]:Mix ? ";
        cin >> number;
    } while (number < 1 || number>4);
    return (QuestionsLevel)number;
}

OperationLevel ReadOparationLevel()
{
    short number = 0;
    do {
        cout << " Enter Oparation Tybe [1]:Add , [2]:Sub , [3]:Mul , [4]:Div , [5]:Mix ? ";
        cin >> number;
    } while (number < 1 || number>5);
    return (OperationLevel) number;
}

struct stQuestion {
    short number1 = 0;
    short number2 = 0;
    QuestionsLevel Question;
    OperationLevel Operation;
    short correctAnswer = 0;
    short UserAnswer = 0;
    bool ResultAnswer = false;
};

struct Quizz {
    stQuestion Questions[100];
    short NumberOfQuestion = 0;
    QuestionsLevel Question;
    OperationLevel Oparation;
    short NumberOfRightAnswer = 0;
    short NumberOfWrongAnswer = 0;
    bool IsPass = false;

};
int CorrectAnswer(int number1, int number2, OperationLevel optybe)
{
   
    switch (optybe)
    {
    case OperationLevel::Add:
        return number1 + number2;

    case OperationLevel::Sub:
        return number1 - number2;
    case OperationLevel::Mul:
        return number1 * number2;
    case OperationLevel::Div:
        return number1 / number2;
    default:
        return number1 + number2;
    }
}


stQuestion GenaratQuestion(QuestionsLevel enquestionlevel, OperationLevel enopeartionelevel)
{
    stQuestion Question;
    if (enquestionlevel == QuestionsLevel::Mix)
    {
        enquestionlevel = (QuestionsLevel)RandomNuber(1, 3);
    }
    if (enopeartionelevel == OperationLevel::Mixpp)
    {
        enopeartionelevel = GetRandomOperationType();
    }
    Question.Operation = enopeartionelevel;
    switch (enquestionlevel)
    {
    case QuestionsLevel::EasyLevel:
        Question.number1 = RandomNuber(1, 10);
        Question.number2 = RandomNuber(1, 10);

        Question.correctAnswer = CorrectAnswer(Question.number1, Question.number2, Question.Operation);
        Question.Question = enquestionlevel;
        return Question;

    case QuestionsLevel::MedLevel:
        Question.number1 = RandomNuber(10, 50);
        Question.number2 = RandomNuber(10, 50);

        Question.correctAnswer = CorrectAnswer(Question.number1, Question.number2, Question.Operation);
        Question.Question = enquestionlevel;
        return Question;

    case QuestionsLevel::HardLevel:
        Question.number1 = RandomNuber(50, 100);
        Question.number2 = RandomNuber(50, 100);

        Question.correctAnswer = CorrectAnswer(Question.number1, Question.number2, Question.Operation);
        Question.Question = enquestionlevel;
        return Question;



    }
    return Question;
}



void GenaratQuizzQuestions(Quizz &stQuizz)
{
    for (short Question = 0; Question <stQuizz.NumberOfQuestion; Question++)
    {
        stQuizz.Questions[Question] = GenaratQuestion(stQuizz.Question, stQuizz.Oparation);
    }
}

string getfinalresult(bool ispa)
{
    if (ispa)
        return "Pass :)";
    else
        return "Fail :(";
}

string questionslevelll(QuestionsLevel questionlevell)

{
    string arr2[4] = { " Easy","Med","Hard","Mix" };
    return arr2[questionlevell - 1];
     
}
string stmboloperation(OperationLevel ontybe)
{
    switch (ontybe)
    {
    case OperationLevel::Add:
        return "+";
    case OperationLevel::Sub:
        return "-";
    case OperationLevel::Mul:
        return "*";
    case OperationLevel::Div:
        return "/";
    default:
        return "Mix";
    }
}

void printquizzresult(Quizz stquizz)
{
    cout << endl;
    cout << "______________________________\n\n";
    cout << " Final Result is " << getfinalresult(stquizz.IsPass) << endl;
    cout << "______________________________\n\n";

    cout << "Number of Questions : " << stquizz.NumberOfQuestion << endl;
    cout << " Question Level     : " << questionslevelll(stquizz.Question) << endl;
    cout << " Operation Level      : " << stmboloperation(stquizz.Oparation) << endl;
    cout << " Number of Right Answer : " << stquizz.NumberOfRightAnswer << endl;
    cout << " Number of Wrong Answer : " << stquizz.NumberOfWrongAnswer << endl;
    cout << "______________________________\n\n";

}





int useranswer()
{
    int number;
    cin >> number;
    return number;
}

void setscreencolor(bool rihgt)
{
    if (rihgt)
        system("color 2F");
    else
    {
        system("color 4F");
            cout << "\a";
    }
}
void correctquestionsanswer(Quizz& stquizz, short questionnumber)
{
    if (stquizz.Questions[questionnumber].UserAnswer != stquizz.Questions[questionnumber].correctAnswer)
    {
        stquizz.Questions[questionnumber].ResultAnswer = false;
        stquizz.NumberOfWrongAnswer++;

        cout << " Wrong Answer :(" << endl;
        cout << " Right Answer : ";
        cout << stquizz.Questions[questionnumber].correctAnswer << endl;


    }
    else
    {
        stquizz.Questions[questionnumber].ResultAnswer = true;
        stquizz.NumberOfRightAnswer++;
        cout << " Right Answer :) " << endl;

    }
    cout << endl;
    setscreencolor(stquizz.Questions[questionnumber].ResultAnswer);
}

void PrintQuestions( Quizz &stQuizz, short Questionnumber)
{
    cout << endl;
    cout << " Question [" << Questionnumber + 1 << "/" << stQuizz.NumberOfQuestion << "]" << endl;
    cout << stQuizz.Questions[Questionnumber].number1 << endl;
    cout << stQuizz.Questions[Questionnumber].number2 << endl;
    cout << stmboloperation(stQuizz.Questions[Questionnumber].Operation);
    cout << endl << "_____________" << endl;
}

void AskandcoorectAnswer(Quizz &stquizz)
{
    for (short questionnumber = 0; questionnumber < stquizz.NumberOfQuestion; questionnumber++)
    {
        PrintQuestions(stquizz, questionnumber);

        stquizz.Questions[questionnumber].UserAnswer = useranswer();

        correctquestionsanswer(stquizz, questionnumber);
    }
    stquizz.IsPass = (stquizz.NumberOfRightAnswer >= stquizz.NumberOfWrongAnswer);

}



void  PlayMathGame()
{
    Quizz stQuizz;
    stQuizz.NumberOfQuestion = HowMany();
    stQuizz.Question = ReadQuestionLevel();
    stQuizz.Oparation = ReadOparationLevel();

    GenaratQuizzQuestions(stQuizz);

    AskandcoorectAnswer(stQuizz);
   
    printquizzresult(stQuizz);


}

void restartscreen()
{
    system("cls");
    system("color 0F");
}

void startmath()
{
   char charecter = 'Y';
    do
    {
        restartscreen();
        PlayMathGame();

       cout << endl << "Do you want to play again? Y/N? ";          
       cin >> charecter;
    } while (charecter == 'y' || charecter == 'Y');
}

int main()
{
    
    srand((unsigned)time(NULL));
    startmath();

}
