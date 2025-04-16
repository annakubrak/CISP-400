//Cisp400gpaAnalyzerHw2AnnaKubrak.cpp
//Anna Kubrak, CISP 400
//09/29/24


#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cstdlib>

// Specification C1 - Three Functions
//Function Prototypes
void ProgramGreeting();
void MainMenu();
void AddGrade();
void DisplayAllGrades();
void ProcessAllGrades();
void UnitTest();
void LogActivity(const std::string& functionName);

// Specification A1 - Date class
class Date {
    public:
    private:


    // Specification A2 - External date initialization
    // Specification A3 - Component Test Method in Date
};

// Specification B4 - Highlight Failing Grades
class FancyText {
    public:
        const std::string RED = "\x1B[31m";


};

// Specification B1 - Dynamic Array
// Specification B2 - Add Elements
template <typename T>
class array {
    private:
        T* dynamic_array = new T[0];
        size_t size = 0;
    public:
    ~array() {
        delete[] dynamic_array;
    }

    void addelement(const T& element) {

    }

    void removeElement(const T& element) {
        
    }

    
};

int main() {
    ProgramGreeting();
    MainMenu();

}

void ProgramGreeting() {
    std::cout << "Welcome to the GPA Analyzer.\n";

}

void MainMenu() {

    std::cout << "Main Menu\n";
    std::cout << "1. Add Grade\n";
    std::cout << "2. Display All Grades\n";
    std::cout << "3. Process all Grades\n";
    std::cout << "4. Quit Program\n";
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "\n";

    // Specification B3 - Menu Input Validation
    if(choice > 4 || choice < 1) {
        std::cout << "Invalid input. Please enter a number from 1 to 4.\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";
    }

    switch(choice) {
        case 1: {
            AddGrade();
        }

        case 2: {
            DisplayAllGrades();
        }

        case 3: {
            ProcessAllGrades();
        }

        case 4: {
            std::cout << "Quitting program.\n";\
            exit(0);
        }
    }


}

void AddGrade() {
    std::cout << "Add Grade\n";
    int grade;
    std::cin >> grade;

}

// Specification C2 - Print Scores
void DisplayAllGrades() {
    std::cout << "Display All Grades\n";
}

// Specification C3 - Compute GPA
void ProcessAllGrades(){
    std::cout << "Processing all grades\n";
}



// Specification A4 - Unit Test
void UnitTest() {

}




// Specification C4 - Function Activity to Disk
void LogActivity(const std::string& functionName) {
    std::ofstream outputFile;
    outputFile.open("log.txt");
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    char buffer[80];
    strftime(buffer, 80, "%m/%d/%Y %I:%M:%S %p", localTime);
    outputFile << buffer << "Function Called:" << functionName << std::endl;
    outputFile.close();
}









