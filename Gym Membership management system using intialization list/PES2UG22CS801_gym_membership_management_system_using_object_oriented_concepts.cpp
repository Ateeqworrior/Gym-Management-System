#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Member {
//private:
    string name;
    int age;
    bool attendance;
    string membershipPlan;
    string startDate;
    string endDate;
    double height;
    double weight;
    string phoneNumber;
    string address;
    string loginID;
    string password;
    double monthlyFee;
    double yearlyFee;

    void setFeesBasedOnPlan() {
        if (membershipPlan == "Monthly") {
            monthlyFee = 5000.0;  // Default monthly fee
            yearlyFee = 0.0;
        } else if (membershipPlan == "Yearly") {
            monthlyFee = 0.0;
            yearlyFee = 50000.0;  // Default yearly fee
        }
    }

public:
    Member(string name, int age, string membershipPlan, string startDate, string endDate, double height, double weight, string phoneNumber, string address, string loginID, string password) {
        this->name = name;
        this->age = age;
        this->attendance = false;
        this->membershipPlan = membershipPlan;
        this->startDate = startDate;
        this->endDate = endDate;
        this->height = height;
        this->weight = weight;
        this->phoneNumber = phoneNumber;
        this->address = address;
        this->loginID = loginID;
        this->password = password;
        setFeesBasedOnPlan();
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    bool getAttendance() {
        return attendance;
    }

    void setAttendance(bool attendance) {
        this->attendance = attendance;
    }

    string getMembershipPlan() {
        return membershipPlan;
    }

    string getStartDate() {
        return startDate;
    }

    string getEndDate() {
        return endDate;
    }

    double getHeight() {
        return height;
    }

    double getWeight() {
        return weight;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    string getAddress() {
        return address;
    }

    string getLoginID() {
        return loginID;
    }

    string getPassword() {
        return password;
    }

    double getMonthlyFee() {
        return monthlyFee;
    }

    double getYearlyFee() {
        return yearlyFee;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Membership Plan: " << membershipPlan << endl;
        cout << "Start Date: " << startDate << endl;
        cout << "End Date: " << endDate << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Monthly Fee: " << monthlyFee << endl;
        cout << "Yearly Fee: " << yearlyFee << endl;
    }
};

class Gym {
private:
    vector<Member> ve;

public:
    Gym() {}

    void add(string name, int age, string membershipPlan, string startDate, string endDate, double height, double weight, string phoneNumber, string address, string loginID, string password) {
        Member member(name, age, membershipPlan, startDate, endDate, height, weight, phoneNumber, address, loginID, password);
        ve.push_back(member);
        cout << "Member Added:" << endl;
        member.displayDetails();
        cout << endl;
    }

    Member* authenticate(string loginID, string password) {
        for (int i = 0; i < ve.size(); i++) {
            if (ve[i].getLoginID() == loginID && ve[i].getPassword() == password) {
                return &ve[i];
            }
        }
        return NULL;
    }

    void markAttendance(string name) {
        for (int i = 0; i < ve.size(); i++) {
            if (ve[i].getName() == name) {
                ve[i].setAttendance(true);
                cout << "Attendance marked for member: " << ve[i].getName() << endl;
            }
        }
    }

    void fees() {
        double total = 0;
        for (int i = 0; i < ve.size(); i++) {
            if (ve[i].getAttendance()) {
                if (ve[i].getMembershipPlan() == "Monthly") {
                    total += ve[i].getMonthlyFee();
                } else if (ve[i].getMembershipPlan() == "Yearly") {
                    total += ve[i].getYearlyFee() / 12; // Assuming attendance is calculated on a monthly basis
                }
            }
        }
        cout << "Total Fees: " << total << endl << endl;
    }
};

int main() {
    Gym gym;

    // Sample member for login purposes (This is for demonstration; normally, you'd add members through the interface)
    gym.add("Ateeq Ur Rahaman", 20, "Yearly", "2024-01-01", "2024-12-31", 1.80, 75.0, "9113963212", "davanagere", "Ateeq", "ateeq123");

    cout << "***** Ateeq Worrior Fitness Membership management System  *****" << endl;

    string loginID, password;
    Member* loggedInMember = NULL;

    // Login Loop
    while (loggedInMember == NULL) {
        cout << "Enter Login ID: ";
        cin >> loginID;
        cout << "Enter Password: ";
        cin >> password;
        loggedInMember = gym.authenticate(loginID, password);
        if (loggedInMember == NULL) {
            cout << "Invalid login credentials. Please try again." << endl << endl;
        }
    }

    int value;
    while (true) {
        cout << "1. for add member: " << endl;
        cout << "2. for mark attendance: " << endl;
        cout << "3. for Total fees: " << endl;
        cout << "0. for exit: " << endl;
        cout << "Enter choice: ";
        cin >> value;

        if (value == 1) {
            system("cls");
            string name, membershipPlan, startDate, endDate, phoneNumber, address, newLoginID, newPassword;
            int age;
            double height, weight;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter membership plan (Monthly/Yearly): ";
            getline(cin, membershipPlan);
            cout << "Enter start date (YYYY-MM-DD): ";
            getline(cin, startDate);
            cout << "Enter end date (YYYY-MM-DD): ";
            getline(cin, endDate);
            cout << "Enter height (meters): ";
            cin >> height;
            cout << "Enter weight (kg): ";
            cin >> weight;
            cin.ignore();
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter login ID: ";
            getline(cin, newLoginID);
            cout << "Enter password: ";
            getline(cin, newPassword);
            gym.add(name, age, membershipPlan, startDate, endDate, height, weight, phoneNumber, address, newLoginID, newPassword);
        } else if (value == 2) {
            system("cls");
            string name;
            cout << "Enter name: ";
            cin >> name;
            gym.markAttendance(name);
        } else if (value == 3) {
            system("cls");
            gym.fees();
        } else if (value == 0) {
            exit(0);
        } else {
            system("cls");
            cout << "Invalid input" << endl << endl;
        }
    }
    return 0;
}

