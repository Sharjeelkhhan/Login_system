#include<iostream>
#include<dos.h>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<iomanip>
using namespace std;
void devKind()
{ 
    //this function shows devkind on the console with green colour
    cout << endl << endl << endl;
    cout << "\033[32m";
    cout << "\t\t\t  888888    88888  88  88  88   88  8888  888       88  888888" << endl;
    cout << "\t\t\t  88   88   88     88  88  88  88    88   88 88     88  88   88" << endl;
    cout << "\t\t\t  88    88  88888  88  88  8888      88   88   88   88  88    88" << endl;
    cout << "\t\t\t  88   88   88     88  88  88  88    88   88     88 88  88   88" << endl;
    cout << "\t\t\t  888888    88888   8888   88   88  8888  88        88  888888" << endl;
    cout << endl;
    Sleep(800);
    system("cls");
}
void devKind2()
{
    //this function shows devkind on the console with yellow colour
    cout << endl << endl << endl;
    cout << "\033[33m";
    cout << "\t\t\t  888888    88888  88  88  88   88  8888  888       88  888888" << endl;
    cout << "\t\t\t  88   88   88     88  88  88  88    88   88 88     88  88   88" << endl;
    cout << "\t\t\t  88    88  88888  88  88  8888      88   88   88   88  88    88" << endl;
    cout << "\t\t\t  88   88   88     88  88  88  88    88   88     88 88  88   88" << endl;
    cout << "\t\t\t  888888    88888   8888   88   88  8888  88        88  888888" << endl;
    cout << endl;
    Sleep(800);
    system("cls");
}
void ViewActivities()
{
    //this function is option of admin to view all activities of users
    ifstream filedata("activities.txt");
    string fileline;
    if (filedata.is_open()) {
        // Print table headers
        cout << setw(15) << left << "Activity" << endl;
        cout << "----------------------------------------" << endl;

        while (getline(filedata, fileline)) {

            // Print user and activity in a formatted manner
            cout << left << fileline << endl;
        }
        cout << endl << endl;
        filedata.close();
        system("pause");
        system("cls");
    }
}
void ShowSignup(string nameFromFile)
{
    //this function writes in file about the user who just signed in
    ofstream activity("activities.txt", ios::app);
    if (activity.is_open()) {
        activity << "A NEW USER " << nameFromFile << "@ " << "JUST SIGNED UP" << endl;
        activity.close();
    }
    else {
        cout << "Error opening the file." << endl;
    }

}
void ShowLogin(string nameFromFile)
{
    //this function writes in file when a user logs in to the system
    ofstream activity("activities.txt", ios::app);
    if (activity.is_open()) {
        activity << "USER " << nameFromFile << " " << "JUST LOGGED IN" << endl;
        activity.close();
    }
    else {
        cout << "Error opening the file." << endl;
    }

}
void DisplayID(string nameFromFile)
{
    //this function finds the user id from file and displays on console
    ifstream inFile0("new.txt");
    string line2;
    int c = 1;
    int current = 0;
    bool flag = false;
    while (getline(inFile0, line2)) {

        if (line2 == nameFromFile) {
            current = c;
            flag = true;
            break; // exit loop once the ID is found
        }
        c++;
    }
    inFile0.close();
    ifstream inFile("new.txt");
    string line;
    int lineNum = current + 4; // line number to be replaced
    int currentLine = 1;
    bool replaced = false;
    while (getline(inFile, line)) {
        if (currentLine == lineNum) {

            cout << setw(22) << left << "SR-NO:" << line << endl;

            break; // exit loop once the line is found
        }
        currentLine++;
    }
    cout << endl;
    inFile.close();
}
void GenerateId()
{
    //this function keeps update of total users and gives serial number in accending order
    int num = 0;
    ofstream file1("database.txt", ios::app);
    ofstream file2("new.txt", ios::app);
    ifstream myfile("ID.txt");
    if (myfile >> num)
    {
        num++;
    }
    myfile.close();
    ofstream out("ID.txt");
    out << num;
    file1 << "SR-" << num << endl;
    file2 << "SR-" << num << endl;
    file1.close();
    file2.close();
    out.close();
    system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\tSIGN IN SUCCESSFUL, PLEASE WAIT";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                system("cls");
}
class Person {   //a person class
public:
    string name;
    int age;   //attributes of class
    string pass;
    Person() : name("\0"), age(0), pass("\0") {} //default constructor
   void person(string n, int i, string p)  //setter(initializes class attributes)
    {
        name = n;
        age = i;
        pass = p;
    }
   void ChangePass(string passwordFromFile,string roll)
   {
       //this function is to change password
       ofstream write("activities.txt", ios::app);
       ifstream inFile0("database.txt");
       string line2,filepath;
       int Jumpline=1;
       int c = 1;
       int current = 0;
       while (!inFile0.eof())
       {
           getline(inFile0, line2);
           if (line2 == roll)
           {
               current = c;
           }
           c++;
       }
       inFile0.close();

           ifstream inFile("database.txt");
           ofstream outFile("new.txt");
           string line;

           int lineNum = current + Jumpline; // line number to be replaced
           int currentLine = 1;
           bool replaced = false;
           string replace;
           cout << "Enter you current password: ";
           cin >> pass;
           while (pass != passwordFromFile)
           {
               cout << "Incorrect! Please enter again: ";
               cin >> pass; //input current pass so it assures system that the owner s changing password
           }
           cout << "Enter new password:";
           cin.ignore();
           getline(cin, replace);  //reads strings in file
           while (getline(inFile, line)) {
               if (currentLine == lineNum && !replaced) {
                   // replace the line with new line
                   outFile << replace << endl;
                   replaced = true;
                   cout << "Operation successful" << endl;
                   write << "USER " << roll << " UPDATED PASSWORD TO " << replace<<endl;
                   system("pause");
                   system("cls");
               }
               else {
                   // write the original line
                   outFile << line << endl;
               }
               currentLine++;
           }


           inFile.close();
           outFile.close();
           //
           remove("database.txt"); //removes file
           rename("new.txt", "database.txt"); //rename new file with old one
   }
    ~Person() {} // class's destructor
};

int main()
{
    Person obj;
    int option, age;  //variables
    string name, pass, nameFromFile, passwordFromFile, pass2,rno,info,birthYear,id,adminID="9520",line2,filename,roll;
    ofstream myfile("database.txt", ios::app); // Open the file in append mode for writing
    ofstream cfile("new.txt", ios::app);
    ifstream file("new.txt"); // Open another file object for reading
    bool correct = false;
    bool flag = false;
    devKind();
    devKind2();
    devKind();
    devKind2();
    system("Color 70"); //background and text colour
   
    do {
        cout << endl;
        //menu driven program
        cout << setw(74) << "Welcome to Login system" << endl;
        cout << endl << endl << endl;
        cout << setw(64)<< "1)LOGIN" << endl;
        cout << setw(65) << "2)SIGNUP" << endl;
        cout << setw(64) << "3)ADMIN" << endl;
        cout << setw(63) << "4)EXIT" << endl;
        cout<< setw(64) << "Select:";
        cin >> option;

        while (option < 1 || option > 4)
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice. Please enter a value between 1 and 3." << endl;
            cin >> option;
        }

        switch (option)
        {
        case 1:
            if (file.is_open())
            {
                do {
                    cout << "Enter username: ";
                    cin >> name;
                    for (int i = 0; i < name.length(); i++)
                    {
                        if (name[i] != '@') {
                            correct = false;
                        }
                        else {
                            correct = true;
                            break;
                        }
                    }
                    if (correct == false) {
                        cout << "Incorrect! HINT: your username is your name with @ at the end" << endl;
                    }
                } while (correct == false);
                do {
                    cout << "Enter password: ";
                    cin >> pass;

                    while (!file.eof()) {
                        getline(file, nameFromFile);
                        getline(file, passwordFromFile);
                        getline(file, info);
                        getline(file, birthYear);
                        getline(file, id);
                        if (passwordFromFile == pass && nameFromFile == name) {
                            flag = true;
                            pass2 = pass;
                            break;
                        }
                    }

                    if (flag == false) {
                        cout << "Error! Wrong credentials. Enter again:" << endl;
                        do {
                            correct = false;

                            cout << "Enter username: ";
                            cin >> name;

                            for (int i = 0; i < name.length(); i++) {
                                if (name[i] != '@') {
                                    correct = false;
                                }
                                else {
                                    correct = true;
                                    break;
                                }
                            }

                            if (correct == false) {
                                cout << "Incorrect! HINT: your username is your name with @ at the end" << endl;
                            }
                        } while (correct == false);
                        file.clear();
                        file.seekg(0);
                    }
                } while (flag == false);
            }
            if (flag)
            { 
                ShowLogin(nameFromFile);
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                system("cls");
                do {
                    cout << "WELCOME USER " << nameFromFile << endl;
                    cout << "1)View your information" << endl;
                    cout << "2)Change password" << endl;
                    cout << "3)About " << endl;
                    cout << "4)EXit" << endl;
                    cout << "Select: ";
                    cin >> option;
                    while (option < 1 || option>4)
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid choice. Please enter a value between 1 and 4." << endl;
                        cin >> option;
                    }
                    switch (option)
                    {
                    case 1:
                        
                            while (file >> filename)
                            {
                                if (filename == nameFromFile)
                                {
                                    file >> nameFromFile >> pass;
                                    break;
                                }
                            }
                            file.close();
                            cout << "YOUR Information" << endl;
                            cout << "-------------------" << endl;
                            cout << setw(22) << left << "USERNAME:" << nameFromFile << endl;
                            cout << setw(22) << left << "PASSWORD:" << pass << endl;
                            cout << setw(22) << left << "NAME:" << info << endl;
                            cout << setw(22) << left << "age:" << birthYear << endl;
                            DisplayID(nameFromFile);
                            system("pause");
                            system("cls");
                        
                        break;
                    case 2:
                        obj.ChangePass(passwordFromFile,nameFromFile);
                        break;
                    case 3:
                        system("cls");
                        string heading = "devkind";
                        string output = "We deliver smart web applications with cutting edge solutions and modern technology to optimize the business processes. Our integrated solutions are combined with hands-on in-depth business practices and lucrative strategic plans at every stage. With a personalized experience, we deliver solutions to grow with technology in the future.";

                        int consoleWidth = 80; // Assuming console width of 80 characters

                        // Print the heading centered in the console
                        cout << setw(consoleWidth / 2 + heading.length() / 2) << right << heading << endl;

                        // Print an empty line
                        cout << endl;

                        // Split the output into multiple lines to fit within the console width
                        size_t pos = 0;
                        while (pos < output.length()) {
                            string line = output.substr(pos, consoleWidth);
                            cout << setw(consoleWidth / 2 + line.length() / 2) << right << line << endl;
                            pos += consoleWidth;
                        }
                        system("pause");
                        system("cls");
                        break;
                    }

                } while (option != 4);
            }
            break;

        case 2:
           
            cout << "Enter name:";
            getline(cin >> ws, name);
            cout << "Enter your age:";
            cin >> age;
            if (age < 18)
            { //checking user's age during sign up
                cout << "You must be atleast 18 to signup"<<endl;
                Sleep(3000);
                system("pause");
                system("cls");
                break;
            }
            cout << "Enter password:";
            cin >> pass;
            myfile << name << "@" << endl;
            myfile << pass << endl;
            myfile << name << endl;
            myfile << age << endl;
            cfile << name << "@" << endl;
            cfile << pass << endl;
            cfile << name << endl;
            cfile << age << endl;
            myfile.close();
            cfile.close();
            GenerateId();
            ShowSignup(name);
            obj.person(name, age, pass);
            break;

        case 3:
            cout << "Enter adminID: ";
            cin >> rno;
            while (rno != adminID)
            {
                cout << "Incorrect! enter again: ";
                cin >> rno;
            }
            do {
                cout << "Welcome Admin " << endl;
                cout << "1)Show user activities"<<endl;
                cout << "2)EXIT" << endl;
                cout << "Select: ";
                cin >> option;
                while (option < 1 || option>2)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid choice. Please enter 1 or 2." << endl;
                    cin >> option;
                }
                if (option == 1)
                {
                    ViewActivities();
                }
            } while (option != 2);
            system("cls");
            break;
        case 4:
            exit(0);
        default:
            break;
        }

    } while (option != 4);

    return 0;
}
