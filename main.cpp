#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;

int option;
bool quit=false;
string tempUserName;
string tempPassw;
string tempEmail;

class Account
{
private:
    string m_userName;
    string m_password;
    string m_email;

public:
    Account();
    Account(string _userName, string _password, string _email)
         {
             m_userName = _userName;
             m_password = _password;
             m_email = _email;
         }
    ~Account(){};

    string getPassword() const
    {
        return m_password;
    }
    string getName() const
    {
        return m_userName;
    }
    string getEmail() const
    {
        return m_email;
    }

};

std::vector<Account> accounts;  // VECTOR DECLARATION

void showMenu() // SHOW MENU ON CONSOLE
{
    std::cout << "************[ACCOUNT MANAGING SYSTEM]************" << std::endl;
    std::cout << "              1: Create account                  " << std::endl;
    std::cout << "              2: Delete account                  " << std::endl;
    std::cout << "              3: Log accounts                    " << std::endl;
    std::cout << "              4: Exit                            " << std::endl;
}
void createAcc(std::vector<Account>& accounts)  // CREATING NEW ACCOUNT AND PLACING IT IN VECTOR "accounts"
{
    std::cout << "Username: ";
    std::cin >> tempUserName;
    std::cout << "Password: ";
    std::cin >> tempPassw;
    std::cout << "Email: ";
    std::cin >> tempEmail;
    Account newAccount(tempUserName, tempPassw, tempEmail);  // CREATING TEMPORARY OBJECT

    accounts.push_back(newAccount);
}

void deleteAcc(std::vector<Account>& accounts)  // REMOVING AND ERASING OBJECT FROM VECTOR "accounts"
{
    string delName,delPassword,delEmail;        // TEMPORARY VARIABLES FOR USER INPUT
    std::cout << "Username: ";
    std::cin >> delName;
    std::cout << "Password: ";
    std::cin >> delPassword;
    std::cout << "Email: ";
    std::cin >> delEmail;
    bool isFound = false;
    std::vector <Account>::iterator it;

        for (it = accounts.begin(); it != accounts.end(); it++)
            {
                if (delName==it->getName() && delPassword==it->getPassword() && delEmail==it->getEmail()) 
                    {
                        it = accounts.erase(it); 
                        it--; 
                        isFound = true;  // USER TO BE DELETED 
                    }
            }
        if (!isFound) 
            std::cout << "[INVALID USER INPUT]"<< std::endl;    
      
}
void logAcc(const std::vector<Account> &accounts)
    {
        std::cout << "[REGISTERED ACCOUNTS]" << std::endl;
        for (int i = 0; i < accounts.size(); i++)
            {
                std::cout <<"Username: "<< accounts[i].getName() << std::endl;
                std::cout <<"Password: "<< accounts[i].getPassword() << std::endl;
                std::cout <<"Email: "<< accounts[i].getEmail() << std::endl;
                std::cout << std::endl;
            }
        std::cout << std::endl;
    }

int main()

{
    system("cls");
    showMenu();
    while(!quit)
        {
            std::cout << "Select an option from above: ";
            std::cin >> option;
        
            switch (option)
            {
                case 1:
                    createAcc(accounts);
                    system("cls");
                    showMenu();
                    break;
                case 2:
                    deleteAcc(accounts);
                    system("cls");
                    showMenu(); 
                    break;
                case 3:
                    system("cls");
                    logAcc(accounts);
                    showMenu();
                    break;
                case 4:
                    quit = true;
                    system("cls");
                    break;
                default:
                    system("cls");
                    std::cout << "[INVALID OPTION]";
                    showMenu();
                    break;
            }        
        }
    std::cin.get();
    return 0;
}