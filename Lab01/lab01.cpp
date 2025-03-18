//Building a Simple Decision-Making Program
#include <iostream>
using namespace std;

int main () {
int temperature; //To store the outside temperature.
double budget; //To store the user's available budget.
int weatherCode; //To represent the weather (1 for sunny, 2 for rainy, 3 for cloudy).
cout << "What is the current temperature in degrees?: ";
cin >> temperature;
cout << "What is your avaliable budget?: ";
cin >> budget;
cout << "What is the current weather conditon like? (1 for sunny, 2 for rainy, 3 for cloudy): ";
cin >> weatherCode;

if (weatherCode == 1 && temperature > 75)
if (budget > 20) {
cout << "Go to the beach!" << endl;
}
else {
cout << "Have a picnic." << endl;
}
else if (weatherCode == 2)
if (budget >15) {
cout << "Go to a Museum." << endl;
}
else {
cout << "Watch a Movie at home." << endl;
}
else if (weatherCode == 3 || temperature < 60)
cout << "Visit a Coffee Shop." << endl;
}