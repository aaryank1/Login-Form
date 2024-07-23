#include<iostream>
#include<fstream>
using namespace std;

void Intro(){
    cout<<"1. Login"<<endl;
    cout<<"2. SignUp"<<endl;
    cout<<"3. Forgot Password"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter Your Choice: ";
}

class form{
    string UserName, Email, Password;
    string searchname, searchpwd, searchemail;
    fstream file;
    public:
    void login(){
        cout<<"--------------------Login--------------------"<<endl;
        cout<<"Enter Your User Name: ";
        cin.ignore();
        getline(cin, searchname);

        cout<<"Enter Your Password: ";
        getline(cin, searchpwd);

        file.open("login.txt", ios::in);
        getline(file, UserName, '*');
        getline(file, Email, '*');
        getline(file, Password, '\n');

        while(!file.eof()){
            if(UserName==searchname){
                if(Password==searchpwd){
                    cout<<"Login Successful!"<<endl;
                    return;
                }
                else{
                    cout<<"Password is Incorrect\nPlease Try Again!"<<endl;
                    return;
                }
            }
            getline(file, UserName, '*');
            getline(file, Email, '*');
            getline(file, Password, '\n');
        }
        file.close();
        cout<<"Invalid Credentials\nLogin Failed. Please Try Again!"<<endl;
    }
    void signup(){
        cout<<"Enter Your User Name: ";
        cin.ignore();
        getline(cin, UserName);
        cout<<"Enter Your Email Address: ";
        getline(cin, Email);
        cout<<"Enter Your Password: ";
        getline(cin, Password);

        file.open("login.txt", ios::out | ios::app);
        file<<UserName<<"*"<<Email<<"*"<<Password<<endl;
        file.close();

        cout<<"SignUp Successful"<<endl;
    }
    void forgotpwd(){
        cout<<"Enter Your User Name: ";
        cin.ignore();
        getline(cin, searchname);
        cout<<"Enter Your Email: ";
        getline(cin, searchemail);

        file.open("login.txt", ios::in);
        getline(file, UserName, '*');
        getline(file, Email, '*');
        getline(file, Password, '\n');

        while(!file.eof()){
            if(searchname==UserName && searchemail==Email){
                cout<<"Account Found\nYour Password is: "<<Password<<endl;
                return;
            }
            else{
                cout<<"Account Doesn't Exist"<<endl;
                return;
            }
        }
        file.close();
    }
};

int main(){
    form user;
    char choice;
    bool exit=false;

    while(!exit){
        cout<<"1. Login"<<endl;
        cout<<"2. SignUp"<<endl;
        cout<<"3. Forgot Password"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Your Choice: ";

        cin>>choice;

        switch(choice){
            case '1':
                user.login();
                break;
            case '2':
                user.signup();
                break;
            case '3':
                user.forgotpwd();
                break;
            case '4':
                exit = true;
                break;

            default:
            cout<<"Invalid Selection!"<<endl;
        }
    }
    
    system("pause");
    return 0;
}