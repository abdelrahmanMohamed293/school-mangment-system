#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
int numStudents = 0;
int numTeachers = 0;
int day, month;

class Date {
private:
    int month;
    int day;
public:
    void setDate(int d, int m) {
        day = d;
        month = m;
    }
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
};

class Student {
private:
    string Name;
    string classStudent;
    int RollNo;
public:
    void set(string n, string c, int r) {
        Name = n;
        classStudent = c;
        RollNo = r;
    }
    string getName() {
        return Name;
    }
    string getClass() {
        return classStudent;
    }
    int getRoll() {
        return RollNo;
    }
    void addRecord(Student*& arr, int& n) {
        string name, classS;
        int rol;
        cout << "Adding student record" << endl;
        Student* newArr = new Student[n + 1];
        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];
        }
        cout << "Enter name of student" << endl;
        cin >> name;
        cin.ignore();
        cout << "Enter class of student" << endl;
        cin >> classS;
        cin.ignore();
        cout << "Enter RollNo" << endl;
        cin >> rol;
        newArr[n].set(name, classS, rol);
        delete[] arr;
        arr = newArr;
        n++;
        cout << "The data of the new student:" << endl;
        cout << "Name: " << arr[n - 1].getName() << "\nClass: " << arr[n - 1].getClass() << "\nRoll: " << arr[n - 1].getRoll() << endl;
    }
    void modifyRecord(Student*& arr, int& n) {
        bool e = 0;
        string x, y;
        int z;
        cout << "enter the roll num of student to modifyer" << endl;
        cin >> z;
        for (int i = 0; i < n; i++) {
            if (z == arr[i].getRoll()) {
                cout << "modifying student record" << endl;
                cout << "the data before modifier" << endl;
                cout << arr[i].getName() << "\n" << arr[i].getClass() << "\n" << arr[i].getRoll() << endl;
                cin.ignore();
                cout << "enter modifier name of student" << endl;
                cin >> x;
                cin.ignore();
                cout << "enter modifier class of student" << endl;
                cin >> y;
                cin.ignore();
                cout << "enter modifier RollNo" << endl;
                cin >> z;
                arr[i].set(x, y, z);
                cout << "after modifying" << endl;
                cout << "name is " << arr[i].getName() << endl;
                cout << "classStudent after modifying is " << arr[i].getClass() << endl;
                cout << "rollnumber after modifying is " << arr[i].getRoll() << endl;
                e++;
            }
        }
        if (e != 1) {
            cout << "this roll num not found to be modifiy" << endl;
        }
    }
    void searchRecord(Student*& arr, int& n) {
        bool x = 0;
        int roll;
        cout << "enter rollnumber to search" << endl;
        cin >> roll;
        for (int i = 0; i < n; i++) {
            if (roll == arr[i].getRoll()) {
                cout << "Name of student is " << arr[i].getName() << endl;
                cout << "class of student is " << arr[i].getClass() << endl;
                cout << "rollno of student is " << arr[i].getRoll() << endl;
                x = 1;
            }
        }
        if (x == 0) {
            cout << "the user not found" << endl;
        }
    }
    void deleteRecord(Student*& arr, int& n) {
        int rol;
        cout << "enter rolnumber to delete" << endl; \
            cin >> rol;
        vector<Student> vec(arr, arr + n);
        for (auto i = vec.begin(); i != vec.end(); i++) {
            if (rol == i->getRoll()) {
                vec.erase(i);
                break;
            }
        }
        delete[] arr;
        n = vec.size();
        arr = new Student[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = vec[i];
        }
    }
    void fee() {
        int da, mo;
        int fine = 0;
        const int due = 3000;
        cout << "calculate fee of student" << endl;
        cout << "enter day and month" << endl;
        cin >> da >> mo;
        if (da > 31 || da < 0 || mo>12 || mo < 0) {
            cout << "the day you enter is wrong try again" << endl;
            cin >> da >> mo;
        }
        int totalfee = 40000;
        if (da > 10 && da < 20) {
            fine = (totalfee * 10) / 100;
        }
        else if (da >= 20 && da < 25) {
            fine = (totalfee * 20) / 100;
        }
        else if (da >= 25) {
            fine = (totalfee * 30) / 100;
        }
        cout << "the normal fees is equal to " << totalfee << endl;
        totalfee += fine + due;
        cout << "the fine is equal to " << fine << endl;
        cout << "the due is equal " << due << endl;
        cout << "the total fee after adding fine is equal to " << totalfee << endl;
    }
};

class Teacher {
private:
    string name;
    string position;
public:
    void setT(string n, string p) {
        name = n;
        position = p;
    }
    string getTname() {
        return name;
    }
    string getposition() {
        return position;
    }
    void addRecord(Teacher*& arr, int& n) {
        cout << "adding teacher record" << endl;
        Teacher* newArr = new Teacher[n + 1];
        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];
        }
        cout << "Enter name of teacher" << endl;
        cin >> name;
        cin.ignore();
        cout << "Enter position of teacher" << endl;
        cin >> position;
        cin.ignore();
        newArr[n].setT(name, position);
        delete[] arr;
        arr = newArr;
        n++;
        cout << "The data of the new techer or staff:" << endl;
        cout << "Name: " << arr[n - 1].getTname() << "\nposition: " << arr[n - 1].getposition() << endl;
    }
    void modifyRecord(Teacher*& arr, int& n) {
        string name, position;
        bool y = 0;
        cout << "enter name you want to modifiy" << endl;
        cin >> name;
        for (int i = 0; i < n; i++) {
            if (name == arr[i].getTname()) {
                cout << "modifying techer or staff record" << endl;
                cout << "the data before modifier" << endl;
                cout << arr[i].getTname() << "\n" << arr[i].getposition() << endl;
                cin.ignore();
                cout << "enter modifier name of teacher or staff" << endl;
                cin >> name;
                cin.ignore();
                cout << "enter modifier position of teacher" << endl;
                cin >> position;
                cin.ignore();
                arr[i].setT(name, position);
                cout << "after modifying" << endl;
                cout << "name is " << arr[i].getTname() << endl;
                cout << "postion after modifying is " << arr[i].getposition() << endl;
                y++;
            }
        }
        cin.ignore();
        if (y == 0) {
            cout << "this name not found to modifiy" << endl;
        }
    }
    void searchRecord(Teacher*& arr, int& n) {
        bool y = 0;
        string name;
        cout << "enter name of staff to search" << endl;
        cin >> name;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            if (name == arr[i].getTname()) {
                cout << "the name of teacher or staff is " << arr[i].getTname() << endl;
                cout << "the position of teacher or staff is " << arr[i].getposition() << endl;
                y = 1;
            }
        }
        if (y == 0) {
            cout << "the name is not found" << endl;
        }
    }
    void deleteRecord(Teacher*& arr, int& n) {
        string name;
        cout << "enter name you want to delete" << endl;
        cin >> name;
        vector<Teacher> vec(arr, arr + n);
        for (auto i = vec.begin(); i != vec.end(); i++) {
            if (name == i->getTname()) {
                vec.erase(i);
                break;
            }
        }
        delete[] arr;
        n = vec.size();
        arr = new Teacher[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = vec[i];
        }
    }
    void salary() {
        Date x;
        int d, m;
        int salary;
        int payPerday = 300;
        cout << "enter day and month you entered the work" << endl;
        cin >> d >> m;
        x.setDate(d, m);
        if (d < 31) {
            d = 31 - d;
            x.setDate(d, m);
        }
        salary = x.getDay() * payPerday;
        cout << "salary is equal = " << salary << endl;
    }
};

bool chkdate(int day, int month) {
    while (day > 31 || day <= 0 || month > 12 || month <= 0) {
        if (day > 31 || day <= 0) {
            cout << "The valid day is wrong" << endl;
            cout << "Enter day again" << endl;
            cin >> day;
        }
        if (month > 12 || month <= 0) {
            cout << "The valid month is wrong" << endl;
            cout << "Enter month again" << endl;
            cin >> month;
        }
    }
    return true;
}

void start() {
    cout << "Welcome to school billing system" << endl;
    cout << "Please enter account type" << endl;
    cout << "1: Student" << endl;
    cout << "2: Teacher and staff" << endl;
    cout << "3: Exit" << endl;
}

void exit() {
    cout << "now  you are out of the program" << endl;
}

int main() {
    Student* studentRecords = nullptr;
    Teacher* teacherRecords = nullptr;
    int account, choice;
    cout << "=====================================" << endl;
    cout << "Welcome to school billing system" << endl;
    cout << "=====================================" << endl;

    cout << "please Enter day and month" << endl;
    cin >> day >> month;

    while (chkdate(day, month)) {
        start();
        cin >> account;
        switch (account) {
        case 1:
            cout << "Welcome to student menu" << endl;
            cout << " 1: Add record\n 2: Search record\n 3: Modify record\n 4: Delete record\n 5: Calculate fee\n 6: Exit" << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                if (numStudents == 0) {
                    studentRecords = new Student[1];
                }
                studentRecords[0].addRecord(studentRecords, numStudents);

                break;
            case 2:
                if (numStudents == 0) {
                    cout << "there are no data yet" << endl;
                }
                else {
                    studentRecords[0].searchRecord(studentRecords, numStudents);
                }
                break;
            case 3:
                if (numStudents == 0) {
                    cout << "there are no data to be modifiyer" << endl;
                }
                else {
                    studentRecords[0].modifyRecord(studentRecords, numStudents);
                }
                break;
            case 4:
                if (numStudents == 0) {
                    cout << "there are no data to be deleted" << endl;
                }
                else {
                    studentRecords[0].deleteRecord(studentRecords, numStudents);
                }
                break;
            case 5:
                if (numStudents == 0) {
                    cout << "there are no student to calculate its fees" << endl;
                }
                else {
                    studentRecords[0].fee();
                }
                break;
            case 6:
                exit();
                return 0;
                break;
            }
            break;
        case 2:
            cout << "Welcome to teacher and staff menu" << endl;
            cout << " 1: Add record\n 2: Search record\n 3: Modify record\n 4: Delete record\n 5: Calculate salary\n 6: Exit" << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                if (numTeachers == 0) {
                    teacherRecords = new Teacher[1];
                }
                teacherRecords[0].addRecord(teacherRecords, numTeachers);
                break;
            case 2:
                if (numTeachers == 0) {
                    cout << "there are no data yet" << endl;
                }
                else {
                    teacherRecords[0].searchRecord(teacherRecords, numTeachers);
                }
                break;
            case 3:
                if (numTeachers == 0) {
                    cout << "there are no data to be modifiyer" << endl;
                }
                else {
                    teacherRecords[0].modifyRecord(teacherRecords, numTeachers);
                }
                break;
            case 4:
                if (numTeachers == 0) {
                    cout << "there are no data yet to delete" << endl;
                }
                else {
                    teacherRecords[0].deleteRecord(teacherRecords, numTeachers);
                }
                break;
            case 5:
                teacherRecords[0].salary();
                break;
            case 6:
                exit();
                return 0;
                break;
            }
            break;
        case 3:
            exit();
            return 0;
        }
    }
}