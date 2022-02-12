#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;

int option;
bool quit=false;
string tempName;
string tempPassw;
string tempEmail;

class Account
{
private:
    string name;
    string password;
    string email;

public:
    Account();
    Account(string _name, string _password, string _email)
         {
             name = _name;
             password = _password;
             email = _email;
         }
    ~Account(){};

    string getPassword() const
    {
        return password;
    }
    string getName() const
    {
        return name;
    }
    string getEmail() const
    {
        return email;
    }

};

std::vector<Account> accounts;  // VECTOR DECLARATION

void showMenu() // SHOW MENU
{
    std::cout << "*********[ACCOUNT MANAGING SYSTEM]*********" << std::endl;
    std::cout << "1: Create account " << std::endl;
    std::cout << "2: Delete account " << std::endl;
    std::cout << "3: Log accounts " << std::endl;
    std::cout << "4: Exit " << std::endl;
}
void createAcc(std::vector<Account>& accounts)  // CREATING NEW ACCOUNT AND PLACING IT IN VECTOR "accounts"
{
    std::cout << "Name: ";
    std::cin >> tempName;
    std::cout << "Password: ";
    std::cin >> tempPassw;
    std::cout << "Email: ";
    std::cin >> tempEmail;
    Account newAccount(tempName, tempPassw, tempEmail);

    accounts.push_back(newAccount);
}
/* void deleteAcc(std::vector<Account> &accounts)
{
    /* std::vector<Account>::iterator it;
    it = std::remove_if(accounts.begin(), accounts.end(), isExistingAcc());
    accounts.erase(it, accounts.end()); 
    remove(accounts.begin(), accounts.end(), isExistingAcc());
} */
void deleteAcc(std::vector<Account>& accounts)
{
    string delName, delPassword, delEmail;
    std::cout << "Name: ";
    std::cin >> delName;
    std::cout << std::endl;
    std::cout << "Password: ";
    std::cin >> delPassword;
    std::cout << "Email: ";
    std::cin >> delEmail;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getName() == delName && delPassword == accounts[i].getPassword())
           {    accounts.erase(std::remove(accounts.begin(), accounts.end(), delName), accounts.end());
                accounts.erase(std::remove(accounts.begin(), accounts.end(), delPassword), accounts.end());
                accounts.erase(std::remove(accounts.begin(), accounts.end(), delEmail), accounts.end());
           }
    }
    /*     std::vector<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end();)
    {
        /* delName = (*it).getName();
        delPassword = (*it).getPassword(); 
        if (delName == (*it).getName() && delPassword == (*it).getPassword())
        {
            // store the return value from erase!!
            //accounts.erase(std::remove(accounts.begin(),accounts.end(), isExistingAcc()), accounts.end());
            //it = accounts.erase(it);
        }
        else
        {
            // increment here rather than in the for loop incrementer
            it++;
        }
    }  */
}
void logAcc(const std::vector<Account> &accounts)
{
    std::cout << "[REGISTERED ACCOUNTS]" << std::endl;
    for (int i = 0; i < accounts.size(); i++)
    {
        std::cout <<"Name: "<< accounts[i].getName() << std::endl;
        std::cout <<"Password: "<< accounts[i].getPassword() << std::endl;
        std::cout <<"Email: "<< accounts[i].getEmail() << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
/* bool isExistingAcc() 
{
    string delName, delPassword,delEmail;
    std::cout << "Name: ";
    std::cin >> delName;
    std::cout << std::endl;
    std::cout << "Password: ";
    std::cin >> delPassword;
    std::cout << "Email: ";
    std::cin >> delEmail;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getName() == delName && accounts[i].getPassword() == delPassword && accounts[i].getEmail()==delEmail)
            {
                return 1;
            }
        else
            return 0;
    }
} */
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