// Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    int user_guess;
    int rand_num;
    int attempt;
    string replay; 
 
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I will choose a number between 1 - 100." << endl;
    cout << "You have 5 guesses to choose the correct number." << endl;

bool guessedCorrectly = false;
rand_num = rand() % 100 + 1;

    for (int attempt = 1; attempt <= 5; attempt = attempt + 1) {
        cout << "Attempt #" << attempt << ": Guess a number between 1-100: ";
        cin >> user_guess;
    
    if (user_guess > rand_num) {
        cout << "Too high!" << endl;
    }
    else if (user_guess < rand_num) {
        cout << "Too low!" << endl;
    }
    else  {
        cout << "Congratulations! You guessed the number." << endl;
        guessedCorrectly = true;
        break;
    }
}
    if (!guessedCorrectly){
        cout << "Unfortunately you couldn't guess the number within 5 tries. You lose!" << endl;
    }
        cout << "Would you like to play again? (yes or no): ";
        cin >> replay;

    // Restarted the game
    while (replay == "Yes" || replay == "yes") {
   for (int attempt = 1; attempt <= 5; attempt = attempt + 1) {
        cout << "Attempt #" << attempt << ": Guess a number between 1-100: ";
        cin >> user_guess;
    
    if (user_guess > rand_num) {
        cout << "Too high!" << endl;
    }
    else if (user_guess < rand_num) {
        cout << "Too low!" << endl;
    }
    else  {
        cout << "Congratulations! You guessed the number." << endl;
        guessedCorrectly = true;
        break;
    }
}
    if (!guessedCorrectly){
        cout << "Unfortunately you couldn't guess the number within 5 tries. You lose!" << endl;
    }
        cout << "Would you like to play again? (yes or no): ";
        cin >> replay;

    cout << "Thanks for playing." << endl;
    return 0;
}
}