#include <iostream>
#include <ctime>

void PrintGameIntroduction()
{
    std::cout << R"(                    `. ___
                    __,' __`.                _..----....____
        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'
  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'
,'________________                          \`-._`-','
 `._              ```````````------...___   '-.._'-:
    ```--.._      ,.                     ````--...__\-.
            `.--. `-`                       ____    |  |`
              `. `.                       ,'`````.  ;  ;`
                `._`.        __________   `.      \'__/`
                   `-:._____/______/___/____`.     \  `
                               |       `._    `.    \
                               `._________`-.   `.   `.___
                                             SSt  `------'`)";
    std::cout << "\nHello, Captain!\n";
    std::cout << "You need to pilot the spaceship across the asteroid belt ahead!\n";
    std::cout << "Enter the correct vectors on each axis according to the AI's assistance.\n\n\n";

}

void PrintLevelIntroduction(int Difficulty)
{

    std::cout << "Here comes wave number " << Difficulty;

}

bool PlayGame(int Difficulty)
{
   
   PrintLevelIntroduction(Difficulty);
   
    //variables declaration
    const int VectorX = rand() % Difficulty + Difficulty;
    const int VectorY = rand() % Difficulty + Difficulty;
    const int VectorZ = rand() % Difficulty + Difficulty;



    int VectorSum = VectorX + VectorY + VectorZ;
    int VectorMul = VectorX * VectorY * VectorZ;

    std::cout << std::endl;
    std::cout << ">>The sum of the three vectors is " << VectorSum << std::endl;
    std::cout << ">>The product of the three vectors is " << VectorMul << std::endl;

    //Store Player Input
    int InputX, InputY, InputZ;

    std::cin >> InputX >> InputY >> InputZ;
    
    int InputSum = InputX + InputY + InputZ;
    int InputMul = InputX * InputY * InputZ;

    std::cout << std::endl << "You Entered " << InputX << InputY << InputZ << std::endl;
    std::cout << "-The sum of your input is " << InputSum << std::endl;
    std::cout << "-The product of your input is " << InputMul << std::endl;

    //Checking the Result
    std::cout << std::endl;    
    if(InputSum == VectorSum && InputMul == VectorMul)
    {

        std::cout << "Amazing Captain!!!\n\n\n";
        return true;

    }
    else
    {

        std::cout << "That was a huge hit!! Lets try this again.\n\n\n";
        return false;
    }
}

int main()
{

    srand(time(NULL));

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    PrintGameIntroduction();

    while(LevelDifficulty <= MaxDifficulty) //loop the game until all levels are complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        

    }

    std::cout << "\nWOOOOHOOOO!!!! Mars here we come!!!\n\n";

    return 0;
}