#include <iostream>
#include <cstdlib>
using namespace std;
enum Choices
{
    stone = 1, paper = 2, scissors = 3
};
int AskUserAboutRound()
{
    int round;
    do
    {
        cout << "=> How Many Rounds 1 To 10 ? " << endl;
        cout << "=> ";
        cin >> round;

    } while (round <= 0);
    return round;
}
int RandomNumber(int from,int to)
{
    int Random = rand() % (to - from + 1) + from;
    return Random;
}
string Choice(int Choice)
{
    switch (Choice)
    {
    case Choices::stone:
        return "Stone";
        break;
    case Choices::paper:
        return "Paper";
        break;
    case Choices::scissors:
        return "Scissors";
        break;
    default:
        return "Not Found";
    }

}
int Cases(int PlayerChoice, int Computer)
{
    if ((PlayerChoice == 1 && Computer == 1) || (PlayerChoice == 2 && Computer == 2) || (PlayerChoice == 3 && Computer == 3))
    {
        return 0;
    }
    else if (PlayerChoice == 1 && Computer == 3 || PlayerChoice == 2 && Computer == 1 || PlayerChoice == 3 && Computer == 2)
    {
        return 1;
    }
    else if (Computer == 1 && PlayerChoice == 3 || PlayerChoice == 1 && Computer == 2 || PlayerChoice == 2 && Computer == 3)
    {
        return 2;
    }

}
string RoundWinner(int PlayerChoice, int Computer)
{
    if (Cases(PlayerChoice, Computer) == 0)
    {
        system("color 6f");
        return "No Winner";
       
    }
    else if (Cases(PlayerChoice, Computer) == 1)
    {
        system("color 2f");
        return "Player1";
    }
    else
    {
        cout << "\a";
        system("color 4f");
        return "Computer";
    }
}
void SeeResults(int PlayerChoice,int &NumberOfPlayer1,int &NumberOfComputer,int &NumberOfDraw)
{
    
    int Computer = RandomNumber(1, 3);
    cout << "Player1 Choice : " << Choice(PlayerChoice) << endl;
    cout << "Computer Choice : " << Choice(Computer) << endl;
    cout << "Round Winner : [" << RoundWinner(PlayerChoice, Computer) << "]" << endl;
    cout << "__________________________________________" << endl;
    if (RoundWinner(PlayerChoice,Computer)=="Player1")
    {
        NumberOfPlayer1++;
    }
    if (RoundWinner(PlayerChoice, Computer) == "Computer")
    {
        NumberOfComputer++;
    }
    if (RoundWinner(PlayerChoice, Computer) == "No Winner")
    {
        NumberOfDraw++;
    }


}
string GameOVer(int Round,int c,int f,int b,string g)
{
    string YesOrNo;
    cout << "\n";
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                    _______________________________________________________" << endl;
    cout << endl;
    cout << "                                                  ++ G A M E  O V E R ++                   " << endl;
    cout << endl;
    cout << "                                    _______________________________________________________" << endl;
    cout << endl;
    cout << "                                    _____________     [GamE   reEsULts]     _______________" << endl;
    cout << endl;
    cout << "                                    Game Rounds : " << Round << endl;
    cout << "                                    Player1 Won Times : " <<c<< endl;
    cout << "                                    Computer Won Times : " <<f<< endl;
    cout << "                                    Draw Times : " << b << endl;
    cout << "                                    Final Winner : " << g << endl;
    cout << endl;
    cout << "                                    _______________________________________________________" << endl;
    cout << endl;
    cout << "                                    Do You Want To Play Again ? [Y/N] ?" << endl;
    cout << "                                    ";
    cin >> YesOrNo;
    cout << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    return YesOrNo;
}
string FinalWinner(int NumberOfPlayer1, int NumberOfComputer, int NumberOfDraw)
{
    //|| (NumberOfComputer > NumberOfDraw)
    if ((NumberOfComputer > NumberOfPlayer1) )
    {
        return "Computer";
    }
    //|| (NumberOfPlayer1 > NumberOfDraw)
    else if ((NumberOfPlayer1 > NumberOfComputer))
    {
        return "Player1";
    }
    else if (NumberOfComputer==NumberOfPlayer1)
    {
        return "No Winner";
    }
  

}
void StartRounds()
{

    int NumberOfPlayer1;
    int NumberOfComputer;
    int NumberOfDraw;
    int Player1Choice;
    string EndGame;
   
    do
    { 
        system("cls");
        system("color 0f");
        NumberOfPlayer1 = 0;
         NumberOfComputer = 0;
        NumberOfDraw = 0;
        int Round = AskUserAboutRound();
        for (int R = 1; R <= Round; R++)
        {
            cout << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Round [" << R << "] Begins :" << endl;
            cout << "\n";
            cout << "Your Choice: (1)\"Stone\"  (2)\"Paper\"  (3)\"Scissors\" ?" << endl;
            cout << "\n";
            cout << "=> ";
            cin >> Player1Choice;
            cout << endl;
            cout << "______________ Round [" << R << "] _________________" << endl;
            cout << endl;
            SeeResults(Player1Choice, NumberOfPlayer1, NumberOfComputer, NumberOfDraw);
        }
        string Item = FinalWinner(NumberOfPlayer1, NumberOfComputer, NumberOfDraw);
        EndGame = GameOVer(Round, NumberOfPlayer1, NumberOfComputer, NumberOfDraw, Item);
        
    } while (EndGame == "Y" || EndGame == "y");
    
    
}
int main()
{
    srand((unsigned)time(NULL));
    StartRounds();
}
