// Cisp400PigHw1AnnaKubrak.cpp
// Anna Kubrak, CISP 400
// 09/08/24

#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


// Specification C4 - Three Functions 
// Function Prototypes
void ProgramGreeting();
void GetName();
int D6();
int RandomNumber(int, int);
void NumericMenu();
void PlayGame();
void PlayAgain();
void LogActivity();
void PlayerTurn();
void CompTurn();


// Specification C1 - Fixed Seed
unsigned int seed = 0;




int main() {
    ProgramGreeting();
}

void ProgramGreeting() {
    cout << "Welcome to Pig!\n" << endl;

    // explain rules of game
    cout << "Here are the rules of the game: " << endl;
    cout << "Each turn, the active player faces a decision to either roll or hold." << endl;
    cout << "If you choose to roll the die and roll a 1 - you lose your turn. No points are added to the grand total." << endl;
    cout << "If you roll a number between 2-6 - the number you rolled is added to your turn total." << endl;
    cout << "If you choose to hold - your turn total is added to the grand total. It is now the next players turn." << endl;
    cout << "You will be playing against a computer. You will take turns. The player that gets 100 points first is the winner." << endl;
    cout << "Let's start!" << endl;

    //get name of player after program greeting
    GetName();
}


// Specification C2 - Student Name
void GetName() {
    cout << "What is your name" << endl;
    string hPlayer;
    cin >> hPlayer;
    cout << "Hello " << hPlayer << "!" << endl;
}



//die, calls RandomNumber(1, 6)
// Specification A1 - D6() function
int D6() {
    return RandomNumber(1, 6);
}

// Specification B3 - hiScore on Heap
int* hiScore = new int (0);

// Specification A2 - RandomNumber() function
int RandomNumber(int lo, int hi) {
    return rand() % hi + lo;
}


// Specification C3 - Numeric Menu
void NumericMenu() {
    cout << "Actions:" << endl;
    cout << "1. Roll" << endl;
    cout << "2. Hold" << endl;
    cout << "3. Quit" << endl;
    cout << "\n";

    cout << "Choose your action: ";
    int action;
    cin >> action;
    cout << endl;
    cout << "You chose to " << action << "." << endl;

    if (action == 1) {
        int D6();
    }

    if (action == 2) {
        cout << "Your turn total has been added to your grand total.\n It is now the computer's turn." << endl;
    }

    if (action == 3 ) {
        cout << "You have decided to quit the game." << endl;
        exit(0);
    }
}


//game loop
void PlayGame() {

    //generate who goes first
    srand(time(0));
    int player = rand() % 2 + 1;
    if(player == 1){
    cout << "You will go first.\n" << endl;
     }
    if(player == 2){
    cout << "The computer will go first.\n" << endl;
    }

    int playerMove, compMove;
    int playerGrandTotal, compGrandTotal;


    while (playerGrandTotal < 100 && compGrandTotal < 100) {
        if(player == 1) {
           PlayerTurn();
        }
        
        if(player == 2) {
            CompTurn();
        }
    }

}

void PlayerTurn() {
    cout << "It's your turn." << endl;
    NumericMenu();
    

}

void CompTurn() {
    cout << "It is the computer's turn." << endl;
            D6();
            if (D6 == 1 ) {
            }
}


// Specification A4 - Play Again Option
void PlayAgain() {
    cout << "Would you like to play again? y/n" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        PlayGame();
    } else 
    cout << "Thank you for playing. Goodbye!" << endl;
    exit(0);
}


// Specification B2 - Function Activity to Disk
void LogActivity(const string& functionName) {
    ofstream outputFile;
    outputFile.open("log.txt");
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        char buffer[80];
        strftime(buffer, 80, "%m/%d/%Y %I:%M:%S %p", localTime);
        outputFile << buffer << "Function Called:" << functionName << endl;
    outputFile.close();
}




// Specification B1 - Display Turn Stats

// Specification B4 – Display hiScore
// Specification A3 - Games Played Counter

