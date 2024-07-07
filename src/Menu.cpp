#include "Menu.h"

void SpecialFunc::setColor(unsigned char color)
{
    SetConsoleTextAttribute( GetStdHandle ( STD_OUTPUT_HANDLE ), color );
}

void SpecialFunc::gotoxy(int x, int y)
{
    static HANDLE h = nullptr;
    if (!h)
    {
        h = GetStdHandle( STD_OUTPUT_HANDLE );
    }
    COORD c = { x, y };
    SetConsoleCursorPosition( h, c );
}

void SpecialFunc::marginsPattern(int x, int y)
{
    for (int i { 0 }; i < x; i++)
    {
        for (int j { 0 }; j < y; j++)
        {
            if (i <= 1 || i >= x - 2)
            {
                std::cout << '*';
            }
            else
            {
                if (j <= 1 || j >= y - 2)
                {
                    std::cout << '*';
                }
                else
                {
                    std::cout << ' ';
                }
            }
        }
        std::cout << '\n';
    }
}

void SpecialFunc::credits()
{
    system("cls");
    marginsPattern(29, 120);
    gotoxy(37, 11);
    std::cout << "This project was made by Str1k3rFl0" << std::endl;
    gotoxy(2, 26);
    std::cout << "Press ENTER to go to main menu...";
    _getch();
}

void Menu::patientMenu(Account& acc)
{
    char ch{};
    const char* fileName { "logIn.txt" };

    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        gotoxy(45, 6);
        std::cout << "============================";
        gotoxy(45, 8);
        std::cout << "      HIPODROM HOSPITAL     ";
        gotoxy(45, 10);
        std::cout << "============================";
        gotoxy(50, 14);
        setColor( 0x07 );
        std::cout << "[1] ACCOUNT DETAILS" << std::endl;
        gotoxy(50, 15);
        setColor( 0x04 );
        std::cout << "[2] DELETE ACCOUNT" << std::endl;
        gotoxy(50, 16);
        setColor( 0x0C );
        std::cout << "[0] BACK TO MENU" << std::endl;
        gotoxy(2, 28);
        std::cout << "Choose an option :: ";
        std::cin >> ch;
        system("cls");
        switch (ch)
        {
            case '1': acc.showPDetails(); break;
            case '2': acc.deleteAcc(fileName); break;
            case '0': mainMenu(); break;
            default: std::cout << '\a';
        }
    } while (ch != '0');
}

void Menu::medicMenu(Account& acc)
{
    char ch{};
    const char* fileName { "logIn.txt" };

    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        gotoxy(45, 6);
        std::cout << "============================";
        gotoxy(45, 8);
        std::cout << "      HIPODROM HOSPITAL     ";
        gotoxy(45, 10);
        std::cout << "============================";
        gotoxy(50, 14);
        setColor( 0x07 );
        std::cout << "[1] ACCOUNT DETAILS" << std::endl;
        gotoxy(50, 15);
        setColor( 0x04 );
        std::cout << "[2] DELETE ACCOUNT" << std::endl;
        gotoxy(50, 16);
        setColor( 0x0C );
        std::cout << "[0] BACK TO MENU" << std::endl;
        gotoxy(2, 28);
        std::cout << "Choose an option :: ";
        std::cin >> ch;
        system("cls");
        switch (ch)
        {
            case '1': acc.showMDetails(); break;
            case '2': acc.deleteAcc(fileName); break;
            case '0': mainMenu(); break;
            default: std::cout << '\a';
        }
    } while (ch != '0');
}

void Menu::adminMenu(Account& acc)
{
    char ch{};

    const char* fileName { "logIn.txt" };

    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        gotoxy(45, 6);
        std::cout << "============================";
        gotoxy(45, 8);
        std::cout << "      HIPODROM HOSPITAL     ";
        gotoxy(45, 10);
        std::cout << "============================";
        gotoxy(50, 14);
        setColor( 0x07 );
        std::cout << "[1] ACCOUNT DETAILS" << std::endl;
        gotoxy(50, 15);
        setColor( 0x0A );
        std::cout << "[2] SHOW ALL ACCOUNTS" << std::endl;
        gotoxy(50, 16);
        setColor( 0x0F );
        std::cout << "[3] SHOW SPECIFIC ACCOUNT" << std::endl;
        gotoxy(50, 17);
        setColor( 0x0C );
        std::cout << "[4] SORT PATIENT BY" << std::endl;
        gotoxy(50, 18);
        setColor( 0x0B );
        std::cout << "[5] SORT MEDIC BY" << std::endl;
        gotoxy(50, 19);
        setColor( 0x0D );
        std::cout << "[6] DELETE ALL ACCOUNTS" << std::endl;
        gotoxy(50, 20);
        setColor( 0x0C );
        std::cout << "[0] BACK TO MENU" << std::endl;
        gotoxy(2, 28);
        std::cout << "Choose an option :: ";
        std::cin >> ch;
        system("cls");
        switch (ch)
        {
            case '1': acc.showADetails(); break;
            case '2': acc.showAllAccounts(fileName); break;
            case '3': acc.showAccount(fileName); break;
            case '4': acc.sortPatients(fileName); break;
            case '5': acc.sortMedics(fileName); break;
            case '6': acc.deleteAllAcc(fileName); break;
            case '0': mainMenu(); break;
            default: std::cout << '\a';
        }
    } while (ch != '0');
}

void Menu::mainMenu()
{
    char ch{};
    const char* fileName { "logIn.txt" };

    Account acc{};

    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        marginsPattern(29, 120);

        gotoxy(45, 6);
        std::cout << "============================";
        gotoxy(45, 8);
        std::cout << "      HIPODROM HOSPITAL     ";
        gotoxy(45, 10);
        std::cout << "============================";
        gotoxy(50, 13);
        setColor( 0x0A );
        std::cout << "[1] CREATE ACCOUNT" << std::endl;
        gotoxy(50, 14);
        setColor( 0x07 );
        std::cout << "[2] PATIENT MENU" << std::endl;
        gotoxy(50, 15);
        setColor( 0x0D );
        std::cout << "[3] MEDIC MENU" << std::endl;
        gotoxy(50, 16);
        setColor( 0x0C );
        std::cout << "[4] ADMIN MENU" << std::endl;
        gotoxy(50, 17);
        setColor( 0x0F );
        std::cout << "[5] CREDITS" << std::endl;
        gotoxy(50, 18);
        setColor( 0x0B );
        std::cout << "[0] EXIT" << std::endl;
        gotoxy(2, 26);
        std::cout << "Choose an option :: ";
        std::cin >> ch;
        system("cls");
        switch (ch)
        {
            case '1': acc.createAccount(fileName); break;
            case '2': if (acc.logInPatient(fileName)) { patientMenu(acc); } break;
            case '3': if (acc.logInMedic(fileName)) { medicMenu(acc); } break;
            case '4': if (acc.logInAdmin(fileName)) { adminMenu(acc); } break;
            case '5': credits(); break;
            case '0': exit(0);
            default: std::cout << '\a';
        }
    } while (ch != '0');
}
