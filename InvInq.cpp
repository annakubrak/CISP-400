//CISP400inventoryInquisitorHw3AnnaKubrak.cpp
//Anna Kubrak, CISP 400
//10/27/2024

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

//FunctionPrototypes
void ProgramGreeting();
void inputValidation(int&, int&, double&);


// Specification B1 - Date class
//used date class from previous assignment

class Date {
private:
    int day, month, year;

public:
    void setDate(int m, int d, int y) {
        day = d;
        month = m;
        year = y;

    }
    void getDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        day = ltm->tm_mday;
        month = 1 + ltm->tm_mon;
        year = 1900 + ltm->tm_year;
    }
    void printDate() const {
        cout << (month < 10 ? "0" : "") << month << "/" << (day < 10 ? "0" : "") << day << "/" << year << endl;
    }
};
class RandNo {
public:
    RandNo(const RandNo&) = delete;
    RandNo& operator=(const RandNo&) = delete;
    // Specification A3 - Overload operator»
    friend std::istream& operator>>(std::istream& input, RandNo& random) {
        int seed;
        input >> seed;
        std::srand(static_cast<unsigned int>(seed));
        return input;
    }
    // get an instance of random number generator
    static RandNo& get_instance() {
        static RandNo instance;
        return instance;
    }
    // Method to generate a random floating point value between min and max
    float random_float(float min, float max) {
        return min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max - min)));
    }
private:
    // Prevent instantiation
    RandNo() {
        std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random number generator
    }
};

struct item {
public:
    //item id number, 5 digits only
    int itemID;

    //quantity at hand, non neg
    int quantityAvailable;

    //wholesale cost, non neg
    double wholesaleCost;

    //retail cost, +wholesale cost by rand 10-50% for each item
    double retailCost;

    //date added, use system date
    Date dateAdded;
    item(int ID, int quantity, double newWholesaleCost){
        itemID = ID;
        quantityAvailable = quantity;
        wholesaleCost = newWholesaleCost;
        retailCost = wholesaleCost * RandNo::get_instance().random_float(1.1, 1.5);
        dateAdded = Date();
    }
    item(){} // default

    // Specification A2 - Overload operator«
    // Specification A2 - Overload operator«
    friend std::ostream& operator<<(std::ostream& output, item& item){
        output << item.itemID << "\t" << item.quantityAvailable << '\t' << item.wholesaleCost << "\t" << item.retailCost; // TODO // include the date somehow
        return output;
    }
};



// TODO // Integrate logger with other functions
// Specification B3 - Logger Class
class Logger {

    private:
      void logger(const string& functionName) {
         ofstream outputFile;
        outputFile.open("log.txt");
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        char buffer[80];
        strftime(buffer, 80, "%m/%d/%Y %I:%M:%S %p", localTime);
        outputFile << buffer << "Function Called:" << functionName << endl;
        outputFile.close();
      };

};



int main() {
  // Specification A4 - UnitTest() function in main()

  ProgramGreeting();

  // Specification C2 - Dynamic Array
  //initialize to 1 element
  item* inventory = new item[1];
  int size = 1;


  bool progrun = true;

  do {
  // Specification C1 - Alpha Menu
  cout << "Main Menu:" << endl;
  cout << "<A>dd Inventory" << endl;
  cout << "<D>elete Inventory" << endl;
  cout << "<E>dit Inventory" << endl;
  cout << "<P>rint Inventory" << endl;
  cout << "<Q>uit Inventory" << endl;

  char choice;

  // Specification C4 - Menu Input Validation
      bool inputValid;
      do {
          inputValid = true;
          cout << "Choose an option:" << endl;
          cin >> choice;
          // TODO // capitalize choice to validate
          if (!(choice == 'A' || choice == 'D' || choice == 'E' || choice == 'P' || choice == 'Q')){
            inputValid = false;
            cout << "Please select a valid menu option.";
          }

      } while (!inputValid);
      switch (choice) {
          case 'A': {
              //Add Inventory
              int itemID, quantityAvailable;
              double wholesaleCost;
              // Specification B4 - Inventory Entry Input Validation  
              inputValidation(itemID, quantityAvailable, wholesaleCost);
              item newItem = item(itemID, quantityAvailable, wholesaleCost);

              item* pTmp = new item[size + 1];
              // Specification C3 - Resize Array
              for (int i = 0; i < size; i++) {
                  pTmp[i] = inventory[i];
              }
              pTmp[size] = newItem;              
              size++;
              delete[] inventory;
              inventory = pTmp;
            break;
          }

          case 'D': {
              //Delete Inventory - Remove the last element of your inventory array and shrink it.
              if (size > 0) {
                  item* pTmp = new item[size - 1];
                  for (int i = 0; i < size - 1; ++i) {
                      pTmp[i] = inventory[i];
                  } 
                  --size;
                  delete[] inventory;
                  inventory = pTmp;
              }
              else {
                cout << "Inventory already empty.\n";
              }
            break;
          }
            
          case 'E': {
            // Specification A1 - Edit Inventory
              //Edit Inventory - Enter a record index number and allow the client to change the                      values. You do not need to edit the data values as those are fixed for this                          assignment.
              int targetID;
              cout << "What ID would you like to edit?" << endl;
              cin >> targetID;
              int location = -1;
              for (int i = 0; i < size; i++){
                if (inventory[i].itemID == targetID){
                    location = i;
                }
              }
              if (location != -1){
                cout << "Enter the new info for updated record." <<endl;
                int itemID, quantityAvailable;
                double wholesaleCost;
                inputValidation(itemID, quantityAvailable, wholesaleCost);
                item newItem = item(itemID, quantityAvailable, wholesaleCost);
                inventory[location] = newItem;
              } else {
                cout << "No item with given ID found." <<endl;
              }
              break;
          }

          case 'P': {
              //Display Inventory - Display all the records in your inventory array
              cout << "Printing Your Items\n";
              cout << "ID\tQuantity\tWholesale\tRetail\n"; // TODO // Date if implemented
              for (int i = 0; i < size; i++){
                cout << inventory[i] << '\n';
              }
              break;
          }

          case 'Q': {
              //quit inventory
              cout << "Quitting..." << endl;
              progrun = false;
              break;
          }
      }
  } while (progrun);
}

void ProgramGreeting() {
  cout << "Welcome to the Inventory Inquisitor." << endl;
  cout << "Written by Anna Kubrak, October 27, 2024" << endl;
}

void inputValidation(int& ID, int& qty, double& wholesaleCost){
    bool inputValid;
    do{
        std::cout << "Enter the ID: ";
        std::cin >> ID;
        std::cout << "Enter the wholesale cost: ";
        std::cin >> wholesaleCost;
        std::cout << "Enter the available quantity: ";
        std::cin >> qty;
        
        int IDLength = std::to_string(ID).length();
        inputValid = true;
        if (qty < 0) {
            std::cout << "Quantity cannot be negative.\n";
            inputValid = false;
        }
        if (IDLength < 5){
            std::cout << "ID length too short.\n";
            inputValid = false;
        }
        if (IDLength > 5){
            std::cout << "ID length too long.\n";
            inputValid = false;
        }
        if (wholesaleCost < 0.0f) {
            std::cout << "Wholesale cannot be negative.\n";
            inputValid = false;
        }
    }while (!inputValid);
}