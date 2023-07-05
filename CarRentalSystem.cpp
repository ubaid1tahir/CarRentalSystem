using namespace std;
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<conio.h>

class Customer {
    static int id;
    string name;
    string email;
    string password;
public:
    Customer(){

    }
    Customer(string name, string email, string password) {
        id++;
        this->name = name;
        this->email = email;
        this->password = password;
        addAccount();
    }
    void addAccount() {
        fstream account;
        account.open("Accounts", ios::app);
        if (account.is_open()) {
            account << "{" << id << "," << name << "," << email << "," << password << "}" << endl;
        }
        account.close();
    }
    string getName() {
        return name;
    }
    string getEmail() {
        return email;
    }
    string getPassword() {
        return password;
    }
    void setName(string _name) {
        name = _name;
    }
    void setEmail(string _email) {
        email = _email;
    }
    void setPassword(string _password) {
        password = _password;
    }
};
int Customer::id = 0;

void menu() {
    cout << "\t\t\t ************ Welcome To Car Rental System **************" << endl;
}

bool isAuthorize(string email, string password) { // to be changed
        fstream file;
        file.open("Accounts", ios::in);
        if (file.is_open()) {
            while (file) {
                string str = "";
                getline(file, str);
                int commas = 0;
                int emailCharacters = 0;
                string emailStr;
                int passwordCharacters = 0;
                string passwordStr;
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] == ',') {
                        commas++;
                    }
                    if (commas == 2 && str[i] != ',') {
                        emailCharacters++;
                        emailStr += str[i];
                    }
                    if (commas == 3 && str[i] != ',') {
                        passwordCharacters++;
                        passwordStr += str[i];
                    }
                    int result1 = email.compare(emailStr);
                    int result2 = password.compare(passwordStr);
                    if (result1 == 0 && result2 == 0) {
                        return true;
                    }
                }
                commas = 0;
            }
        }
        return false;
}
class Car {
protected:
    static int id;
    string makeAndModelYear;
    string engineType;
    int engineSize;
    int length;
    int width;
    string company;
    long rentperday;
public:
    Car() {

    }
    Car(string company, string makeModelYear, string engineType, int engineSize, int length, int width, long _rent) {
        id++;
        this->company = company;
        this->makeAndModelYear = makeModelYear;
        this->engineType = engineType;
        this->engineSize = engineSize;
        this->length = length;
        this->width = width;
        this->rentperday = _rent;
        addCar();
    }
    
    string getCompany() {
        return company;
    }
    long getRentPerDay() {
        return rentperday;
    }
    void addCar() {
        fstream cars;
        cars.open("Cars", ios::app);
        cars << "{" << id << "," << company << "," << makeAndModelYear << "," << engineType << "," << engineSize << ","
            << length << "," << width << "," << rentperday << "}" << endl;
        cars.close();
        cout << "Your car is successfully added :)" << endl;
    }
    void SearchCars() {
        fstream cars;
        cars.open("Cars", ios::in);
        cout << "Id" << "\t | " << "Make And Model Year" << "\t |" << "Engine Type" << "\t |" << "Engine Size" << "\t |" << "Length" << "\t |" << "Width" << "\t |" << "RentPerDay" << endl;
        if (cars.is_open()) {
            while (cars) {
                string str = "";
                getline(cars, str);
                cout << str << endl;

            }
        }
        cars.close();
    }
    void ViewRentedCars() {
        fstream rent;
        rent.open("RentedCars", ios::in);
        cout << "Id" << "\t | " << "Make And Model Year" << "\t |" << "Engine Type" << "\t |" << "Engine Size" << "\t |" << "Length" << "\t |" << "Width" << "\t |" << "RentPerDay" << endl;
        if (rent.is_open()) {
            while (rent) {
                string str = "";
                getline(rent, str);
                cout << str << endl;

            }
        }
        rent.close();
    }
    string SearchCars(string criteria, string value) {
        int choose;
        if (criteria == "Id") {
            choose = 0;
        }
        if (criteria == "makeandmodelyear") {
            choose = 1;
        }
        else if (criteria == "enginetype") {
            choose = 2;
        }
        else if (criteria == "enginesize") {
            choose = 3;
        }
        else if (criteria == "length") {
            choose = 4;
        }
        else if (criteria == "width") {
            choose = 5;
        }
        else if (criteria == "rentperday") {
            choose = 6;
        }
        if (criteria == "company") {
            choose = 7;
        }
        fstream cars;
        cars.open("Cars", ios::in);
        if (cars.is_open()) {
            while (cars) {
                string str = "";
                getline(cars, str);
                int commas = 0;
                string zero;
                string first;
                string second;
                string third;
                string fourth;
                string fifth;
                string sixth;
                string seventh;
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] == ',') {
                        commas++;
                    }
                    if (commas == 0 && str[i] != ',' && str[i]!='{' && choose == 0) {
                        zero += str[i];
                    }
                    if (commas == 2 && str[i] != ',' && choose == 1) {
                        first += str[i];
                    }
                    if (commas == 3 && str[i] != ',' && choose == 2) {
                        second += str[i];
                    }
                    if (commas == 4 && str[i] != ',' && choose == 3) {
                        third += str[i];
                    }
                    if (commas == 5 && str[i] != ',' && choose == 4) {
                        fourth += str[i];
                    }
                    if (commas == 6 && str[i] != ',' && choose == 5) {
                        fifth += str[i];
                    }
                    if (commas == 7 && str[i] != ',' && str[i]!='{' && str[i] != '}' && choose == 6) {
                        sixth += str[i];
                    }
                    if (commas == 1 && str[i] != ',' && str[i] != '{' && str[i] != '{' && choose == 7) {
                        seventh += str[i];
                    }
                }
                int result;
                
                switch (choose)
                {
                case 0:
                    result = value.compare(zero);
                    if (result == 0) {
                        return str;
                    }
                    break;
                case 1:
                    result = value.compare(first);
                    if (result == 0) {
                        return str;
                    }
                    break;
                case 2:
                    result = value.compare(second);
                    if (result == 0) {
                        return str;
                    }
                    break;
                case 3:
                    result = value.compare(third);
                    if (result == 0) {
                        return str;
                    }
                    break;
                case 4:
                    result = value.compare(fourth);
                    if (result == 0) {
                        return str;
                    }
                    break;
                case 5:
                    result = value.compare(fifth);
                    if (result == 0) {
                        return str;
                    }
                    break;
                case 6:
                    result = value.compare(sixth);
                    if (result == 0) {
                        return str;
                    }
                    break;
                case 7:
                    result = value.compare(seventh);
                    if (result == 0) {
                        return str;
                    }
                    break;
                default:
                    cout << "Error" << endl;
                    break;
                }

                commas = 0;
            }// end of first iteration
        }
    }
    bool isAuthorizeRent(string email, string password) {
        fstream file;
        file.open("RentedCars", ios::in);
        if (file.is_open()) {
            while (file) {
                string str = "";
                getline(file, str);
                int commas = 0;
                int emailCharacters = 0;
                string emailStr;
                int passwordCharacters = 0;
                string passwordStr;
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] == ',') {
                        commas++;
                    }
                    if (commas == 2 && str[i] != ',') {
                        emailCharacters++;
                        emailStr += str[i];
                    }
                    if (commas == 3 && str[i] != ',') {
                        passwordCharacters++;
                        passwordStr += str[i];
                    }
                    int result1 = email.compare(emailStr);
                    int result2 = password.compare(passwordStr);
                    if (result1 == 0 && result2 == 0) {
                        return true;
                    }
                }
                commas = 0;
            }
        }
        return false;
    }
    void returnCar(Customer & obj) {
        fstream cars;
        cars.open("Cars",ios::app);
        string line;
        fstream file; // file - rentedCars
        file.open("RentedCars", ios::in);
        if (isAuthorizeRent(obj.getEmail(), obj.getPassword())) {
            if (file.is_open()) {
                while (file) {
                    string str = "";
                    getline(file, str);
                    int commas = 0;
                    int emailCharacters = 0;
                    string emailStr;
                    int passwordCharacters = 0;
                    string passwordStr;
                    for (int i = 0; i < str.length(); i++) {
                        if (str[i] == ',') {
                            commas++;
                        }
                        if (commas == 2 && str[i] != ',') {
                            emailCharacters++;
                            emailStr += str[i];
                        }
                        if (commas == 3 && str[i] != ',') {
                            passwordCharacters++;
                            passwordStr += str[i];
                        }
                    }
                    int result1 = obj.getEmail().compare(emailStr);
                    int result2 = obj.getPassword().compare(passwordStr);
                    if (result1 == 0 && result2 == 0) {
                        line = str;
                        break;
                    }
                    commas = 0;
                }
            }
        }

        fstream tempfile;
        tempfile.open("tempfile", ios::app);
        if (file.is_open()) {
            while (file) {
                string str = "";
                getline(file, str);
                if (str != line) {
                    tempfile << str << endl;
                }
            }
        }// tempfile -> RentedCars
        tempfile.close();
        file.close();
        if (remove("RentedCars") != 0)
            perror("Error.. Try Later");
        char oldname[] = "tempfile";
        char newname[] = "RentedCars";
        if (rename(oldname, newname) != 0)
            perror("Error.. Try Later");
        int commas = 0;
        string content;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                commas++;
            }
            if (commas >= 4) {
                content += line[i];
            }
        }
        cars << "{" << content << "}" << endl;
        cout << "You are successfully returned car" << endl;
        cars.close();
    }
};



class RentedCar : public Car {
public:

    void rentCar(Customer & obj) {
        fstream rent;
        string id;
        rent.open("RentedCars", ios::app);
        if (isAuthorize(obj.getEmail(), obj.getPassword())) {
            SearchCars();
            system("pause");
            cout << "Enter the id of the car which do you want to rent :";
            cin >> id;
            string car = SearchCars("Id", id);
            cout << car << endl;
            system("pause");
            fstream file;
            file.open("Cars", ios::in);
            fstream tempfile;
            tempfile.open("tempfile", ios::app);
            if (file.is_open()) {
                while (file) {
                    string str = "";
                    getline(file, str);
                    if (str != car) {
                        tempfile << str << endl;
                    }
                }
            }
            tempfile.close();
            file.close();
            if (remove("Cars") != 0)
                perror("Error.. Try Later");
            char oldname[] = "tempfile";
            char newname[] = "Cars";
            if (rename(oldname, newname) != 0)
                perror("Error.. Try Later");
            rent << "{" << id << "," << obj.getName() << "," << obj.getEmail() << "," << obj.getPassword() << "," << car << "}" << endl;
            cout << "You are successfully rented car" << endl;
        }
        else {
            cout << "The customer is not present in our records" << endl;
        }
        rent.close();
    }

    void sale() {
        fstream file;
        file.open("RentedCars", ios::in);

    }
};
int Car::id = 0;

void dashboardScreen() {
    cout << "Welcome to Dashboard" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. Search Cars" << endl;
    cout << "3. Search Cars with different criteria" << endl;
    cout << "4. Register Customer" << endl;
    cout << "5. Rent a car" << endl;
    cout << "6. Return a car" << endl;
    cout << "7. Check available cars" << endl;
    cout << "8. Check Rented Cars" << endl;
    cout << "9. Exit" << endl;
}
int main()
{
    // first time makes your account so that you can login
    fstream account;
    account.open("Accounts", ios::in);
    if (account.is_open()) {
        while (account) {
            string str = "";
            getline(account, str);
            if (str == "") {
                Customer c1("admin","admin","1234");
                break;
            }
        }
    }
    string email, password,name;
    char choose;
    string value;
    // for adding cars 
    string company;
    string makeAndModelYear;
    string engineType;
    int engineSize;
    int length;
    int width;
    long rentperday;
    string criteria;
    // end
    menu();
    cout << "\t\t\t ******** Login To Proceed ******" << endl;
    cout << "\t\t\t Email   :";
    cin >> email;
    cout << "\t\t\t Password :";
    cin >> password;
    if (isAuthorize(email, password)) {
        cout << "You are successfully logged in :)" << endl;
        system("pause");
        system("cls");
        do {
            menu();
            dashboardScreen();
            cout << "Enter your choice" << endl;
            choose = _getch();
            if (choose == '1') {
                cout << "Enter company :";
                cin >> company;
                cout << "Enter make and model year of the car :";
                cin >> makeAndModelYear;
                cout << "Enter engine type :";
                cin >> engineType;
                cout << "Enter engine size :";
                cin >> engineSize;
                cout << "Enter dimensions " << endl;
                cout << "Enter length of a car :";
                cin >> length;
                cout << "Enter width of a car :" << endl;
                cin >> width;
                cout << "Enter rent per day of this car :";
                cin >> rentperday;
                Car car(company, makeAndModelYear, engineType, engineSize, length, width, rentperday);
            }
            else if (choose == '2') {
                Car car;
                car.SearchCars();
            }
            else if (choose == '3') {
                Car car;
                cout << "Enter criteria :";
                cin >> criteria;
                cout << "Enter value of entered criteria :";
                cin >> value;
                cout << car.SearchCars(criteria, value) << endl;
            }
            else if (choose == '4') {
                cout << "Enter name of the customer :";
                cin >> name;
                cout << "Enter email :";
                cin >> email;
                cout << "Enter password :";
                cin >> password;
                Customer(name, email, password);
                cout << "Customer`s account is successfully created :)" << endl;
            }
            else if (choose == '5') {
                cout << "Enter name of the customer :" << endl;
                cin >> name;
                cout << "Enter email :";
                cin >> email;
                cout << "Enter password :";
                cin >> password;
                Customer c1;
                c1.setName(name);
                c1.setEmail(email);
                c1.setPassword(password);
                RentedCar rt;
                rt.rentCar(c1);
            }
            else if (choose == '6') {
                cout << "Enter name of the customer :" << endl;
                cin >> name;
                cout << "Enter email :";
                cin >> email;
                cout << "Enter password :";
                cin >> password;
                Customer c1;
                c1.setName(name);
                c1.setEmail(email);
                c1.setPassword(password);
                Car car;
                car.returnCar(c1);
            }
            else if (choose == '7') {
                Car car;
                car.SearchCars();
            }
            else if (choose == '8') {
                Car car;
                car.ViewRentedCars();
            }
            else if (choose == '9') {
                return false;

            }
            system("pause");
            system("cls");
        }while (true);
    }
    else {
        cout << "Invalid Login :(" << endl;
    }
}

