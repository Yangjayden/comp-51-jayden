#include "Player.h"
// g++ -std=c++20 mainn.cpp Player.cpp -o testtt
void HUD();
void Versus();
void GameHUD();
void Moving();
void CreateDB();
void LevelUp();

int DefensiveBack_xp = 0;
int DefensiveBack_rating = 0;
int DefensiveBack_stars = 0;
int DefensiveBack_defend = 0;

string DefensiveBack_Name[] = {"Channing", "Chase", "Arian", "Ronin", "Teigan", "Terrance" };
int currentDefensiveBack_Names = 6;
string currentDefensiveBack_ = " ";

int counter = 0;

Player player;

int main() {
    srand(std::time(nullptr));  // Seed the random number generator
    player.playerCreation();
    
    HUD();
    Moving();

    cin.ignore();

    return 0;

}

void HUD() { 
    sleep(1);
    system("clear");
    cout << "Name: " << player.name << "\nRating: " << player.current_rating << "\nAttribute: " << player.attribute 
        << "\nNumber: " << player.number << "\nStars: " << player.current_stars <<  "\nRating to Stars: " << player.rate_to_stars << endl;
    Moving();
}

void GameHUD() {
    sleep(1);
    system("clear");
    cout << "Name: " << player.name << "       |       DB Name: " << currentDefensiveBack_ << "\nRating: " << player.totalRating << "       |       DB Rating: " <<
        DefensiveBack_rating << "\nStars: " << player.stars << "          |       DB Stars: " << DefensiveBack_stars << endl;
}

void Versus() {
    GameHUD();

    int yardsToGo = (player.stars <= 2) ? 20 : 40;
    int maxDowns = (player.stars <= 2) ? 4 : 8;
    int currentDown = 1;
    int totalYards = 0;
    int dbStamina = 100;

    cout << "\nYou need " << yardsToGo << " yards in " << maxDowns << " downs to win.\n";

    while (currentDown <= maxDowns) {
        cout << "\n--- Down " << currentDown << " ---\n";
        cout << "Stamina: " << player.stamina << " | DB Stamina: " << dbStamina << "\n";
        cout << "1. Run (1-5 yds)\n2. Pass (5-10 yds)\n3. Deep Pass (10-15 yds)\nChoose your move: ";
        
        int choice;
        cin >> choice;

        int yards = 0;
        if (choice == 1)
            yards = rand() % 5 + 1;
        else if (choice == 2)
            yards = rand() % 6 + 5;
        else if (choice == 3)
            yards = rand() % 6 + 10;
        else {
            cout << "Invalid play. Try again.\n";
            continue;
        }

        // Stamina drain
        player.totalStamina -= 5;
        if (player.totalStamina < 0) player.totalStamina = 0;

        // DB stamina drains with more WR gain
        dbStamina -= yards;
        if (dbStamina < 0) dbStamina = 0;

        // Success probability: based on WR rating + stamina vs DB rating + stamina
        int wrEffective = player.totalRating + player.totalStamina;
        int dbEffective = DefensiveBack_rating + dbStamina;
        int chance = wrEffective - dbEffective + 50;  // normalized around 50%
        if (chance > 95) chance = 95;
        if (chance < 5) chance = 5;

        int roll = rand() % 100;
        if (roll < chance) {
            cout << "You gain " << yards << " yards!\n";
            totalYards += yards;
        } else {
            cout << currentDefensiveBack_ << " locks you up! 0 yards.\n";
        }

        cout << "Total Yards: " << totalYards << " / " << yardsToGo << "\n";

        if (totalYards >= yardsToGo) {
    cout << "\nTouchdown! You beat " << currentDefensiveBack_ << "!\n";
    int xpGained = DefensiveBack_stars * 10;
    player.xp += xpGained;
    int ratingGain = xpGained / 2;
    player.totalRating += ratingGain;
    if (player.totalRating > 99) player.totalRating = 99;
    cout << "+XP: " << xpGained << " | +Rating: " << ratingGain << "\n";
    LevelUp();  // Make sure LevelUp() is called after XP gain
    HUD();
    return;
}

        currentDown++;
    }

    // Failed to score
    cout << "\nTurnover on downs!\n";
    int penalty = DefensiveBack_stars * 8;
    player.totalRating -= penalty;
    if (player.totalRating < 0) player.totalRating = 0;
    cout << "-Rating: " << penalty << " | Current Rating: " << player.totalRating << "\n";
    HUD();
}
 
void Moving() { 

     int choice;

    cout << "\n\n";
    cout << "1. Travel North\n";
    cout << "2. Ice Bath & Massage Gun (Rest to restore stamina)\n";
    cout << "3. Travel South\n";
    cout << "\nChoice: ";
    cin >> choice;

    if (choice == 1 || choice == 3) {
        string direction = (choice == 1) ? "North" : "South";
        cout << "You begin moving " << direction << "...\n";

        int temp = rand() % 100 + 1;
        if (temp >= 50) {
            CreateDB();
            string tempName = DefensiveBack_Name[rand() % currentDefensiveBack_Names];
            currentDefensiveBack_ = tempName;
            cout << currentDefensiveBack_ << " wants to line up against you!\n";
            sleep(2);
            Versus();
        } else {
            cout << "Keep moving to find comp.\n";
            sleep(2);
            HUD();
        }
    } 
    else if (choice == 2) {
        // Rest to recover stamina
        cout << "You get in an ice bath for 10 minutes. Then use the massage gun for 5 minutes.\n";
        
        int restored = 10 * player.totalStamina;
        player.stamina += restored;
        if (player.stamina > 100) player.stamina = 100;

        cout << "Your stamina is now: " << player.stamina << " (+ " << restored << ")\n";
        sleep(1);
        HUD();
    } 
    else {
        cout << "Invalid choice. Try again.\n";
        sleep(2);
        Moving();
    }
}

void LevelUp() {

    while (player.xp >= player.xp_to_stars) {
        player.xp -= player.rate_to_stars;

        // Increase XP threshold for next star
        player.xp_to_stars += static_cast<int>(floor((player.current_stars + 1) * pow(2.0, player.current_stars / 5.0)));

        // Level up logic
        if (player.current_stars < player.maxStars) {
            player.current_stars++;
            cout << "Congrats on receiving another Star! Total stars: " << player.current_stars << endl;
        } else {
            cout << "Congrats! You're now a 5-star player!\n";
        }

        // Boost stamina as a reward
        player.totalStamina += static_cast<int>(floor(10 * pow(1.5, player.level / 5.0)));
        if (player.totalStamina > 100) player.totalStamina = 100;

        player.level++; // Increase level for future boosts
        cout << "Stamina boosted to: " << player.totalStamina << "\n";
        cout << "Level: " << player.level << " | XP to next star: " << player.xp_to_stars << "\n\n";
    }

    sleep(3);
    HUD();
}

void CreateDB() {

    DefensiveBack_rating = (rand() % 10) + 80; // 60-89 rating
    DefensiveBack_stars = (rand() % 6) + 1;    // 1 to 5 stars
    DefensiveBack_xp = DefensiveBack_stars * 10;
}


