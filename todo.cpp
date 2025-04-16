//source header

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string getstring(const string& task) {
    string input;
    getline(cin, input);
    return input;
};

struct todo {
    //use an id number
    int taskID;

    //for task name
    string task; 

    // Specification C1 - Overload «
    //Overload the stream insertion operator to output a TODO.

};


// Specification A3 - System Date.
//Pull the date for your TODO record directly from the system date method.
class date {
private:
    int day;
    int month;
    int year;
    char buffer[80];

public:
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

date() {
    strftime(buffer, 80, "%m/%d/%Y", localTime);
}

};


//Function Prototypes
void ProgramGreeting();
void todoMenu(todo* &tasks, int &size, string &task);
void addTask(todo* &tasks, int &size, string &task);
void displayTasks(todo* tasks, int size, string &task);
void removeTask(todo* &tasks, int &size, string &task);


int main() {
    ProgramGreeting();

      todo* tasks = new todo[1];
      int size = 1;

    todoMenu(tasks, size, task);


}

void ProgramGreeting() {
    cout << "TODO LIST" << endl;
}

void todoMenu(todo* &tasks, int &size, string &task) {
    cout << "+ Add Task" << endl;
    cout << "? Display Task" << endl;
    cout << "- Remove Task" << endl;

    char choice;
    string task;

    bool inputValid;

    do {
        inputValid = true;
        cout << "What would you like to do: ";
        cin >> choice;
    } while (!inputValid);
        
        switch (choice) {

        // Specification B1 - + Symbol
        //Allow the user to enter tasks with a "+" symbol.
        case '+': {
            addTask(tasks, size, task);
            break;
        }


        // Specification B2 - ? Symbol
        //Allow the user to display all tasks with a ? symbol.
        case '?': {
            displayTasks(tasks, size, task);
            break;
        }



        // Specification B3 - - symbol
        //Allow the user to remove a task with a "-" symbol (use an ID num-ber to remove the TODO).
        //This doesn’t necessary mean you need to delete it immediately.
        case '-': {
            removeTask(tasks, size, task);
            break;
        }

        }



}

void addTask(todo* &tasks, int &size, string &task) {


    cout << "What is your task?" << endl;
    cin >> task;
    cout << "Adding task " << task << endl;
}

void displayTasks(todo* tasks, int size, string &task){
    
      for (int i = 0; i < size; i++){
        cout << tasks[i] << '\n';
      }
    
    
}

void removeTasks(todo* &tasks, int &size, string &task) {
    int taskID;
    cout << "What is the ID of the task you want to remove?" << endl;
    cin >> taskID;
    cout << "Removing task " << taskID << endl;
    
}
 


//Specification C2 - Overload »
//Overload thestream extraction operator to input a TODO.
// Specification C3 - Test TODO’s
//Generate at least 5 TODO’s in your component testing method.

//Specification C4 - TODO array
//Put your TODO’s in a dynamic array of TODO’s




//Specification B4 - Persistence
//Have your TODO list survive program termination by dumping the TODO’s to disk when program ends.
//Load the data when the program first runs - if the file exists.

// Specification A1 - Overload Copy Constructor
//Overload the default copy constructor to handle your TODO’s.
//Do this even if you don’t have any pointers in your TODO ob-ject/struct.
//This is a great method to put in your component test-ing method.

// Specification A2 - Overload Assignment Operator
//To handle TODO assignment.



// Specification A4 - Overload Constructor
//Allow empty input for an add from the menu. However, empty adds trigger the regular constructor
//which creates a test record filled with obviously dummy data.
//When the client actually enters data during an add,
//trigger an overloaded constructed filling it with the data supplied by the client.