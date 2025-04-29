#include <iostream>
#include <string>
#include <algorithm> // for std::transform

enum Day { sunday = 1, monday, tuesday, wednesday, thursday, friday, saturday }; 

int main() {
    Day today;
    std::string dayName;

    std::cout << "Enter day today: ";
    std::cin >> dayName;

    
    std::transform(dayName.begin(), dayName.end(), dayName.begin(), ::tolower);


    if (dayName == "sunday") today = sunday;
    else if (dayName == "monday") today = monday;
    else if (dayName == "tuesday") today = tuesday;
    else if (dayName == "wednesday") today = wednesday;
    else if (dayName == "thursday") today = thursday;
    else if (dayName == "friday") today = friday;
    else if (dayName == "saturday") today = saturday;
    else {
        std::cerr << "Invalid day name entered." << std::endl;
        return 1;
    }

    int dayNumber = static_cast<int>(today);

    std::cout << "Value of today is: " << dayNumber << std::endl;

    
    std::string dayOfWeek;
    switch (today) {
        case sunday: dayOfWeek = "Sunday"; break;
        case monday: dayOfWeek = "Monday"; break;
        case tuesday: dayOfWeek = "Tuesday"; break;
        case wednesday: dayOfWeek = "Wednesday"; break;
        case thursday: dayOfWeek = "Thursday"; break;
        case friday: dayOfWeek = "Friday"; break;
        case saturday: dayOfWeek = "Saturday"; break;
    }
    std::cout << "Today is " << dayOfWeek << std::endl;

    return 0;
}