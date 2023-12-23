//Name: Robert Ward
//Date: 12/22/2023
/*Purpose: the purpose to this program is to intake the specified variables from the console for a hotel management system,
* it then outputs that in proper format into the txt file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <filesystem>

using namespace std;

// Class for rendering different menus
class Rendering {
public:
    // Display main menu options
    void renderMenu1() {
        cout << endl;
        cout << "******Robert's Hotel******" << endl;
        cout << "1. Add Guest" << endl;
        cout << "2. Remove Guest" << endl;
        cout << "3. List" << endl;
        cout << "4. Exit" << endl;
        cout << "**************************" << endl;
        cout << ": ";
    }

    // Display preferred room menu
    void renderPreferedRoom() {
        cout << endl << "******input your guest's prefered room******" << endl;
        cout << "1. Single Room" << endl;
        cout << "2. Connecting Room" << endl;
        cout << "3. Suite" << endl;
        cout << "4. Presidential Suite" << endl;
        cout << "********************************************" << endl;
        cout << ": ";
    }

    // Prompt for entering guest's name for deletion
    void renderDeletion() {
        cout << "******Enter guest's name******" << endl;
        cout << ": ";
    }
};

// Class for managing user-related operations
class User {
public:
    // Remove a guest from the database
    void removeGuest(const string& filePath, const string& guestName) {
        // Open input file and create a temporary file for modification
        ifstream inputFile(filePath);
        ofstream tempFile("/Users/" + string(getenv("USER")) + "/Desktop/final project/temp.txt");

        // Check if files are opened successfully
        if (!inputFile.is_open() || !tempFile.is_open()) {
            cerr << "Failed to open the file." << endl;
            return;
        }

        string line;
        bool guestFound = false;

        // Iterate through input file to find and skip the guest to be removed
        while (getline(inputFile, line)) {
            if (line.find("name: " + guestName) != string::npos) {
                guestFound = true;
                for (int i = 0; i < 4; ++i) {
                    getline(inputFile, line);
                }
            } else {
                tempFile << line << endl;
            }
        }

        // Close input and temporary files
        inputFile.close();
        tempFile.close();

        // If guest not found, display a message and return
        if (!guestFound) {
            cout << "Guest not found." << endl;
            return;
        }

        // Open input and temporary files again
        inputFile.open(filePath);
        while (getline(inputFile, line)) {
            // Skip lines containing the removed guest's name
            if (line.find("name: " + guestName) == string::npos) {
                tempFile << line << endl;
            }
        }

        // Close input and temporary files
        inputFile.close();
        tempFile.close();

        // Open input and temporary files to clear the original file
        ofstream patientsFile(filePath, ios::trunc);
        ifstream tempInput("/Users/" + string(getenv("USER")) + "/Desktop/final project/temp.txt");

        // Write contents of the temporary file back to the original file
        patientsFile << tempInput.rdbuf();
        tempInput.close();
        patientsFile.close();

        // Clear the temporary file
        tempFile.open("/Users/" + string(getenv("USER")) + "/Desktop/final project/temp.txt", ios::trunc);
        tempFile.close();

        // Success output
        cout << endl << "Guest removed successfully." << endl << endl;
    }

    // List all guests in the database
    void list(const string& filePath) {
        // Open input file
        ifstream inputFile(filePath);

        // Check if file is opened successfully
        if (!inputFile.is_open()) {
            cerr << "Failed to open the file." << endl;
            return;
        }

        string line;

        // Iterate through input file to find and display guest information
        while (getline(inputFile, line)) {
            if (line.find("name: ") != string::npos) {
                cout << endl << "Guest Information:" << endl;
                cout << line << endl;
                for (int i = 0; i < 4; ++i) {
                    getline(inputFile, line);
                    cout << line << endl;
                }
                cout << "---------------------------" << endl;
            }
        }

        // Close input file
        inputFile.close();
    }

    // Get user input for various operations
    void getUserInput1(string& end, const string& filePath, ofstream& outputFile, int input) {
        Rendering rendererer;

        const double single = 100;
        const double connect = 200;
        const double suite = 300;
        const double presSuite = 400;
        double pricePaid;

        string description, name, roomChoice;
        int days, room, roomNum;

        // Display main menu and get user input
        rendererer.renderMenu1();
        cin >> input;
        cin.ignore();

        switch (input) {
            // Add Guest
            case 1:
                cout << endl << "Input your guest's name: ";
                getline(cin, name);

                cout << endl << "Input your guest's general description: ";
                getline(cin, description);

                // Render the preferred room menu
                rendererer.renderPreferedRoom();
                cin >> room;
                cin.ignore();

                // Generate room information based on user input
                if (room == 1) {
                    roomNum = rand() % 10;
                    roomChoice = "Single Room #" + to_string(roomNum);
                    pricePaid = single;
                } else if (room == 2) {
                    roomNum = rand() % 20 + 10;
                    roomChoice = "Connecting Room #" + to_string(roomNum);
                    pricePaid = connect;
                } else if (room == 3) {
                    roomNum = rand() % 30 + 20;
                    roomChoice = "Suite #" + to_string(roomNum);
                    pricePaid = suite;
                } else if (room == 4) {
                    roomNum = rand() % 40 + 30;
                    roomChoice = "Presidential Suite #" + to_string(roomNum);
                    pricePaid = presSuite;
                }

                cout << endl << "Input how many days this guest will be here for: ";
                cin >> days;

                // Check if the reservation is for more than a year
                if (days > 365) {
                    cout << endl << "Sorry, the guest cannot reserve a room for more than a year." << endl;
                    break;
                }

                cin.ignore();

                // Write guest information to the file
                outputFile << "name: " << name << endl;
                outputFile << "room type: " << roomChoice << endl;
                outputFile << "price paid: $" << pricePaid * (double) days << endl;
                outputFile << "days at the hotel: " << days << endl;
                outputFile << "description: "<< description << endl << endl;
                break;

            case 2:
                rendererer.renderDeletion();
                cin >> name;
                removeGuest(filePath, name);
                break;

            case 3:
                list(filePath);
                break;

            case 4:
                end = "n";
                break;

            default:
                cout << endl << "Invalid input, please try again later." << endl;
                break;
        }
    }
};

int main () {

    User user;

    //inputs for general description of the patient
    string input, description, end = " ";
    int age, days;

    //grabs the username for the computers current user
    const char* username = getenv("USER");
    
    //sets the file path for writing to the txt file
    string filePath = "/Users/" + string(username) + "/Desktop/final project/Guests.txt";

    ofstream outputFile(filePath, ios::app);

    //checks for if the file is open, if the file is closed while the program is running it will send an error message
    if (!outputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return -1;
    }

    //loop
    while (true) {
        int input;

        user.getUserInput1(end, filePath, outputFile, input);

        if (end == "n") {
            break;
            end = " ";
        } else {
            continue;
        }

        //asks user if they want to log another patient to the database
        cout << "would you like to enter another input? y/n" << endl;
        cin >> end;
        cin.ignore();

        if (end != "y") {
            break;
        } else {
            continue;
        }
    }
    
    outputFile.close();

    //success message
    cout << "Data written to file successfully." << endl;

    return 0;
}