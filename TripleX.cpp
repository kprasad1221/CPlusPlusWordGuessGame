#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
    //intro message
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room\n"
              << "You need to enter the correct codes to continue...\n" << "\n X_X";

    //declare 3 numbers
}

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product to terminal
    std::cout << std::endl
              << std::endl;
    std::cout << "There are 3 numbers in the code\n\n"
              << "The three numbers add up to: "
              << CodeSum << std::endl
              << "The three numbers multiply to: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check player answer
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win!";
        return true;
    }
    else
    {
        std::cout << "You Lose. Try Again...";
        return false;
    }
}

int main() 
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    const int MaxLevels = 5;

    while(LevelDifficulty <= MaxLevels)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete)
        {
            LevelDifficulty++;
        }
    }
    
    return 0;
}