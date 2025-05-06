#pragma once
#include "mainn.h"



class Player{
public:
    Player();
 
    string name, attribute, number;
    vector<string> playerAttribute; 
    vector<int>test;
    int xp, xp_to_stars, rating, totalRating, maxRating, rest;
    int level, stars, current_stars, current_rating, base_rating;
    int rate_to_stars, minStars, maxStars, totalStamina, stamina; 
    
    void playerCreation();

};