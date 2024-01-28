#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game
{
public:
    Game(int maxN);
    ~Game();
    void play();
private:
    void printGameResult();
    int maxNumber;
    int playerQuess;
    int randomNumber;
    int numOfGuesses;
};

Game::Game(int maxN)
{
    maxNumber = maxN;
    playerQuess = 0;
    numOfGuesses = 0;
    srand(std::time(0));
    cout<<"GAME CONSTRUCTOR: object initialized with "<< maxN<<" as a maximum value"<<endl;
}

Game::~Game()
{
    cout<<"GAME DESTRUCTOR: object cleared from stack memory"<<endl;
}

void Game::play()
{
    bool stayInLoop = true;
    short randomNumber = (rand()%maxNumber)+1;  //random number between 1-maxNumber
    numOfGuesses = 0;

    while(stayInLoop)
    {
        cout<<"Give your guess between 1-"<<maxNumber<<endl;
        cin>>playerQuess;
        if(playerQuess == randomNumber)
        {
            cout<<"Your quess is right = "<<playerQuess<<endl;
            stayInLoop = false;
        }
        else if(playerQuess<randomNumber)
        {
            cout<<"Your guess is too small"<<endl;
        }
        else
        {
            cout<<"Your guess is too big"<<endl;
        }

        numOfGuesses++;
    }
    printGameResult();
}

void Game::printGameResult()
{
    cout<<"You quessed the right answer = "<<playerQuess<<" with "<<numOfGuesses<<" quesses"<<endl;
}

int main()
{
    Game gameObject(10);
    gameObject.play();
    return 0;
}
