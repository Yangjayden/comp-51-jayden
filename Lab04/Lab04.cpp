#include <iostream>
using namespace std;

// Hint: This function should generate a random number between 1 and 6.
// Use rand() % 6 to get a number between 0-5 and then add 1 to shift it to 1-6.
// Example: return (rand() % 6) + 1;
int rollDie(){
    return (rand() % 6) + 1;
}
// Hint: This function should roll 'numberOfDice' times and return the total sum.
// Steps:
// 1. Initialize a variable 'total' to 0.
// 2. Use a for loop to roll the dice 'numberOfDice' times.
// 3. Each time, call rollDie() to get a random number and add it to 'total'.
// 4. Print each roll to show the player what was rolled.
// 5. Return the 'total' after the loop.
int rollMultipleDice(int numberOfDice){
    int total = 0;
    for (int i = 0; i < numberOfDice; i++) {
        int roll = rollDie();
        cout << "Rolling 2 dice: " << endl;
        total += roll;
    }
    return total;
}

// Hint: This function plays one round of the game and returns the result.
// Steps:
// 1. Call rollMultipleDice(2) to get the player’s total.
// 2. Call rollMultipleDice(2) to get the computer’s total.
// 3. Compare the totals:
//    - If player > computer, return 1 (win)
//    - If player == computer, return 0 (draw)
//    - Otherwise, return -1 (loss)
// 4. The main function will use this result to update scores.
int playRound(){
    int playerTotal = rollMultipleDice (2);
    cout << "Your total: " << playerTotal << endl;

    int computerTotal = rollMultipleDice(2);
    cout << "Computer's total: " << computerTotal << endl;

    if (playerTotal > computerTotal) {
        return 1;
    }
    else if (playerTotal == computerTotal) {
        return 0;
    }
    else {
        return -1;
    }
}

// Hint: This function allows the player to spend points for bonuses.
// Steps:
// 1. Display the shop menu with options and costs.
// 2. Read the player’s choice.
// 3. Use an if-else or switch statement to handle choices:
//    - Option 1: If player has enough points (>=5), deduct 5 points and add +5 points as a bonus.
//    - Option 2: If player has enough points (>=10), deduct 10 points and add +15 points as a bonus.
//    - Option 3: Exit the shop without changes.
//    - Invalid input: Show an error and exit.
// 4. Return the updated score to the main function.
int shop(int currentScore){
    int playerChoice;
    cout << "Shop" << endl;
    cout << "1. Add +5 points (Cost: 5 points)" << endl;
    cout << "2. Add +15 points (Cost: 10 Points)" << endl;
    cout << "3. Exit Shop" << endl;
    cout << "Enter your choice: " << endl;
    cin >> playerChoice;

    if (playerChoice == 1 && currentScore >= 5) {
        currentScore -= 5;
        currentScore += 5;
        cout << "Not enough points." << endl;
    }
    else if (playerChoice == 2 && currentScore >=10) {
        currentScore -= 10;
        currentScore += 15;
        cout << "Purchased +15 points!" << endl;
    }
    else if (playerChoice == 3) {
        cout << "Exiting Shop" << endl;
    }
    else {
        cout << "Invalid input. Exiting shop." << endl;
    }
    return currentScore;
}
// Hint: This function shows the final game results after the player is done.
// Steps:
// 1. Print the total number of rounds played.
// 2. Print how many rounds the player won, drew, and lost.
// 3. Display the final score.
// No return value is needed since it's just displaying information.
void displayStatistics(int totalRounds, int wins, int draws, int losses, int finalScore){
    cout << "Game Over!" << endl;
    cout << "Rounds Played: " << totalRounds << endl;
    cout << "Wins: " << wins << " | Draws: " << draws << " | Losses: " << losses << endl;
    cout << "Final Score: " << finalScore << endl;
    cout << "Thanks for playing!" <<endl;
}
int main() {
    cout << "Welcome to the Dice Battle Game!" << endl;
   // 1. Initialize variables:
    //    - score: to track player’s points
    //    - rounds: to track how many rounds have been played
    //    - wins, draws, losses: to track the game outcomes
    int score = 0;
    int rounds = 0;
    int wins = 0, draws = 0, losses = 0;

    // 2. Use srand(time(0)) to seed the random number generator for different results each time.
    srand(time(0));

    // 3. Use a while loop to keep the game running while the user wants to play:
    //    a. Increment the round counter.
    //    b. Ask the player if they want to visit the shop.
    //       - If yes, call the shop function and update the score.
    //    c. Call playRound() to play one round of dice.
    //       - Based on the returned result, update score, wins, draws, or losses.
    //    d. Display the current score.
    //    e. Ask the player if they want to play another round.
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y'){
        rounds++;
        
        cout << "Round " << rounds << endl;
        cout << "Do you want to visit the shop before playing? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            score = shop(score);
        }
    }

    int result = playRound();
    if (result == 1) {
        score += 20;
        wins ++;
        cout << "You win this round! (+20 points)" <<endl;
    }
    else if (result == 0) {
        score += 10;
        draws ++;
        cout << "You tied this round! (+10 points)" <<endl;
    }
    else {
        score -= 0;
        losses ++;
        cout << "You lose this round! (+0 points)" <<endl;
    }
    cout << "Current Score: " << score << endl;

    // 4. After the loop ends, call displayStatistics() to show final game results.
    cout << "Do you want to play another round? (y/n): ";
    cin >> playAgain;

    while (playAgain == 'y' || playAgain == 'Y');
    displayStatistics(rounds, wins, draws, losses, score);

    return 0;

}
