#include <iostream>
#include <string>
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()
using namespace std;

class Car {
public:
    //    TODO: make, model, year, originalPrice, currentPrice, isOwned
    string make;
    string model;
    int year;
    double originalPrice;
    double currentPrice;
    bool isOwned; 
    // 2) Constructor: sets originalPrice/currentPrice to 10000, isOwned to false
    //    TODO: Car(const std::string &mk, const std::string &md, int yr) { ... }
    Car(const string &mk, const string &md, int yr){
        make = mk;
        model = md;
        year = yr;
        originalPrice = 10000;
        currentPrice = 10000;
        isOwned = false;
    }
    // 3) Method getCarInfo() returning something like "2010 Toyota Camry"
    //    TODO: std::string getCarInfo() { ... }
    string getCarInfo() const {
        return to_string(year) + " " + make + " " + model;
    }
    // 4) buyCar(double &userMoney)
    //    - If not owned and userMoney >= currentPrice:
    //      - set isOwned = true
    //      - userMoney -= currentPrice
    //      - reduce currentPrice by 10% of originalPrice
    //      - return true
    //    - else return false
    bool buyCar(double &userMoney) {
        if (!isOwned && userMoney >= currentPrice) {
            isOwned = true;
            userMoney -= currentPrice;
            reducePriceByTenPercent();
            return true;
        }
        return false;
    }

    // 5) sellCar(double &userMoney)
    //    - If owned:
    //      - set isOwned = false
    //      - userMoney += currentPrice
    //      - reduce currentPrice by 10% of originalPrice
    //      - return true
    //    - else return false
    bool sellCar(double &userMoney) {
        if (isOwned) {
            isOwned = false;
            userMoney += currentPrice;
            reducePriceByTenPercent();
            return true;
        }
        return false;
    }

    // 6) reducePriceByTenPercentOfOriginal()
    //    - currentPrice -= 0.10 * originalPrice
    //    - clamp currentPrice at 0 if it goes negative
    void reducePriceByTenPercent() {
        currentPrice -= 0.10 * originalPrice;
        if (currentPrice < 0) {
            currentPrice = 0;
        }
    }
};

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // User starts with $100,000
    double userMoney = 100000.0;

    // Create 3 cars, each with an initial price of $10,000
    // TODO: e.g., Car car1("Toyota", "Camry", 2010);
    //             Car car2("Tesla", "Model 3", 2022);
    //             Car car3("Ford", "Mustang", 1967);
    Car car1("Honda", "Civic Si", 2012);
    Car car2("Honda", "Civic TypeR", 2025);
    Car car3("Tesla", "Model 3", 2021);

    // Perform 10 transactions
    for (int i = 1; i <= 10; ++i) {
        std::cout << "\n--- Transaction " << i << " ---\n";

        // Random index 0 to 2
        int carIndex = std::rand() % 3;
        // Random action 0 = buy, 1 = sell
        int action = std::rand() % 2;

        // TODO: If carIndex == 0, we operate on car1
        //       If carIndex == 1, operate on car2
        //       Else operate on car3

        // For each case, check:
        //   if (action == 0) call buyCar(...)
        //   else call sellCar(...)
        // Print messages accordingly
    if (carIndex == 0) {
        if (action == 0) {
            if (car1.buyCar(userMoney)) {
            cout << "Bought " << car1.getCarInfo() << " for $" << userMoney << endl;
        }
        else {
            cout << "Could NOT buy " << car1.getCarInfo() << " (already owned or insufficient funds) " << userMoney << endl;
        }
       } else {
            if (car1.sellCar(userMoney)) {
                cout << "Sold " << car1.getCarInfo() << " for $" << userMoney << endl;
            } else {
                cout << "Could NOT sell " << car1.getCarInfo() << " (not currently owned) " << userMoney << endl;
            }

        }
    }
else if (carIndex == 1) {
    if (action == 0) {
        if (car2.buyCar(userMoney)) {
            cout << "Bought " << car2.getCarInfo() << " for $" << userMoney << endl;
        } 
        else {
            cout << "Could NOT buy " << car2.getCarInfo() << " (already owned or insufficient funds) " << userMoney << endl;
        }
    } else {
        if (car2.sellCar(userMoney)) {
            cout << "Sold " << car2.getCarInfo() << " for $" << userMoney << endl;
        } 
        else {
        if (car2.sellCar(userMoney)) {
            cout << "Could NOT sell " << car2.getCarInfo() << " (not currently owned) " << userMoney << endl;
        }
    }
}
}
else {
    if (action == 0) {
        if (car3.buyCar(userMoney)) {
            cout << "Bought " << car3.getCarInfo() << " for $" << userMoney << endl;
        } else {
            cout << "Could NOT buy " << car3.getCarInfo() << " (already owned or insufficient funds) " << userMoney << endl;
        }
    } else {
        if (car3.sellCar(userMoney)) {
            cout << "Sold " << car3.getCarInfo() << " for $" << userMoney << endl;
        } else {
            cout << "Could NOT sell " << car3.getCarInfo() << " (not currently owned) " << endl;
        }
    }
}

        // Print updated user balance
        cout << "User balance: $" << userMoney << endl;
    }

    // Final Report
    std::cout << "\n\n--- Final Report After 10 Transactions ---\n" << endl;
    // Print userMoney
    cout << "User final balance: $" << userMoney << endl;
    // Print each car's originalPrice, currentPrice, and ownership status
    // TODO
    Car cars[3] = {car1, car2, car3};

    for (int i = 0; i < 3; ++i) {
        cout << cars[i].getCarInfo() << " | ";
        cout << "Original Price: $" << cars[i].originalPrice << " | " << endl;
        cout << "Current Price: $" << cars[i].currentPrice << " | " << endl;
        cout << "Currently Owned? " << (cars[i].isOwned ? "Yes" : "No") << endl;
    }
    return 0;
}