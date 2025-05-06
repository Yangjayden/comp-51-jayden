#include "Player.h"

Player::Player(){

    name = " ";
    attribute = " ";
    number = " ";
    playerAttribute = {"SpeedKilla", "DeepThreat", "FirstDownMerchant", "Mr.Consistent", "CertifiedHands"};

    stars = 0, totalRating = 0, maxStars = 5, rest = 0, stamina = 100;

    stars = 1, current_rating = 0, base_rating = 65, maxRating = 99, rate_to_stars = current_stars * 20 + 15, minStars = 0, maxStars = 5;
}

void Player::playerCreation() {
    
    int counter = 0;

    cout << "Enter Player's Name: ";
    cin >> name;

    cout << "Enter Character's Attribute (choose one of the following):\n";
    cout << "SpeedKilla\n";
    cout << "DeepThreat\n";
    cout << "FirstDownMerchant\n";
    cout << "Mr.Consistent\n";
    cout << "CertifiedHands\n";
    cout << "Type below your attribute: \n";
    cin >> attribute;

    // Convert the attribute to lowercase for easy comparison
    for (int i = 0; i < attribute.length(); i++) {
        attribute[i] = tolower(attribute[i]);
    }

    // Determine stars based on the chosen attribute
    if (attribute == "speedkilla") {
        current_stars = 2;
        current_rating = 60;
    }
    else if (attribute == "deepthreat") {
        current_stars = 3;
        current_rating = 62;
    }
    else if (attribute == "firstdownmerchant") {
        current_stars = 1;
        current_rating = 58;
    }
    else if (attribute == "mr.consistent") {
        current_stars = 3;
        current_rating = 65;
    }
    else if (attribute == "certifiedhands") {
        current_stars = 2;
        current_rating = 56;
    }
    else {
        current_stars = 1;
        current_rating = 57;
    }

    cout << "\n";
    cout << "Enter Characters Jersey Number: #";
    cin >> number;
    system("clear");


    for(int i = 0; i <= counter; i++) {
        if(i == 0)
            cout << "Player Loading.\n";
        if(i == 1)
            cout << "Player Loading..\n";
        if (i == 2){
            cout << "Player Loading...\n";
            break;
        }

        sleep(1);
        system("clear");
        counter++;
    }

    name[0] = toupper(name[0]);
    attribute[0] = toupper(attribute[0]);
    number[0] = toupper(number[0]);

    totalRating = current_rating;
    maxRating = 99;
}

