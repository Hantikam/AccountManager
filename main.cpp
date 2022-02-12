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
    string m_name;
    string m_password;
    string m_email;

public:
    Account();
    Account(string _name, string _password, string _email)
         {
             m_name = _name;
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
        return m_name;
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
    std::cout << "Name: ";
    std::cin >> tempName;
    std::cout << "Password: ";
    std::cin >> tempPassw;
    std::cout << "Email: ";
    std::cin >> tempEmail;
    Account newAccount(tempName, tempPassw, tempEmail);

    accounts.push_back(newAccount);
}

void deleteAcc(std::vector<Account>& accounts) //   REMOVING AND ERASING OBJECT FROM VECTOR "accounts"
{
    string delName,delPassword,delEmail;
    std::cout << "Name: ";
    std::cin >> delName;
    std::cout << std::endl;
    std::cout << "Password: ";
    std::cin >> delPassword;
    std::cout << "Email: ";
    std::cin >> delEmail;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getName() == delName && delPassword == accounts[i].getPassword() && delEmail==accounts[i].getEmail())
           {
                /* accounts.erase(std::remove(accounts.begin(), accounts.end(), delName), accounts.end());
                accounts.erase(std::remove(accounts.begin(), accounts.end(), delPassword), accounts.end());
                accounts.erase(std::remove(accounts.begin(), accounts.end(), delEmail), accounts.end()); */
                //accounts.erase(std::remove(accounts.begin(), accounts.end(), accounts[i]), accounts.end());
                //it= remove(accounts.begin(),accounts.end(), accounts[i]);
                bool isFound = false;
                std::vector <Account>::iterator it3;
                for (it3 = accounts.begin(); it3 != accounts.end(); ++it3) {
                    if (delName==it3->getName() && delPassword==it3->getPassword() && delEmail==it3->getEmail()) {
                    it3 = accounts.erase(it3); // After erasing, it3 is now pointing the next location.
                    --it3; // Go to the prev location because of ++it3 in the end of for loop.
                    isFound = true;
    }
                if (!isFound) 
                {
                    std::cout << "[INVALID USER INPUT]"<<std::endl;
                }
}

           }
    
    
    }  
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
    std::cout<<accounts.size()<<std::endl;
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