#include <iostream>
#include <string>
#include<limits>

//Global Array Days of week
const std::string DAYS_OF_WEEK[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};
//Global Array Months of Year
const std::string MONTHS_OF_YEAR[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

void runMenu();
int main() {
    runMenu();
    return 0;
}
//functions
int display();
void invalidInput();

void invalidInput () {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//Menus Options
int display() {
    std::cout << "-----Welcome-----\n" << std::endl;
    std::cout << "1) Get Day Name by Number\n" << std::endl;
    std::cout << "2) Get Month Name by Number\n" << std::endl;
    std::cout << "3) Quit\n" << std::endl;
    std::cout << "Enter your Choice: \n" << std::endl;

    //Invalid Input for Display Menu
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        invalidInput();
        return - 1;
    }
    return choice;
}

void runMenu() {
    int choice;
    do {
        choice = display();
        //Menu Selection
        switch (choice) {
            case 1: {
                int day;
                while (true) {
                    std::cout << "Enter a Day by Number (1-7): ";
                    std::cin >> day;
                    //Invalid Input for Day
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input. Please Enter a Number\n";
                    }
                    else if (day >= 1 && day <= 7) {
                        std::cout << "The day is " << DAYS_OF_WEEK[day - 1] << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Invalid Day, Please input numbers 1-7\n" << std::endl;
                    }
                }
                break;
            }
            case 2: {
                int month;
                while (true) {
                    std::cout << "Enter a Month by Number (1-12): ";
                    std::cin >> month;
                    //Invalid input for Month
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input. Please Enter a Number\n";
                    }
                    else if (month >= 1 && month <= 12) {
                        std::cout << "The month is " << MONTHS_OF_YEAR[month - 1] << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Invalid Month, Please input numbers 1-12\n" << std::endl;
                    }
                }
                break;
            }
            case 3:
                std::cout << "Exiting Program...\n";
                break;
            default:
                std::cout << "Invalid Choice, Please Try Again\n";
                break;
        }
    }
    while (choice != 3);
}