#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    // Initialize the user's guess
    int userGuess = 0;

    // Start the game loop
    while (userGuess != secretNumber) {
        // Ask the user for their guess
        std::cout << "Guess the number between 1 and 100: ";
        std::cin >> userGuess;

        // Provide feedback on the user's guess
        if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number " << secretNumber << "!" << std::endl;
        }
    }

    return 0;
}
