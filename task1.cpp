#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number Game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
            continue;
        }

        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts." << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}