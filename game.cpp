#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You're a secret agent breaking into a level " << Difficulty << " secure server room...\n";
    std::cout << "You need to enter the correct codes to continue...\n\n";
}

void PrintHints(int CodeSum, int CodeProduct)
{
    std::cout << std::endl;
    std::cout << "+ There are three numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n\n";
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);

    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintHints(CodeSum, CodeProduct);

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nNice work! You entered the correct code!\n\n";
        return true;
    }
    else
    {
        std::cout << "\nYou died, better luck next time!\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // reate new random sequeunce based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            // increase level difficulty
            ++LevelDifficulty;
        }
        std::cout << "\n\nNice work, you have successfully navigated the secure facilty!";
    }
    return 0;
}