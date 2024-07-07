#ifndef MENU_H
#define MENU_H

#include <windows.h>
#include <iostream>
#include <conio.h>

#include "Account.h"

class SpecialFunc
{
protected:
    SpecialFunc() = default;
    void setColor(unsigned char color);
    void gotoxy(int x, int y);
    void marginsPattern(int x, int y);
    void credits();
};

class Menu : public SpecialFunc
{
public:
    Menu() = default;
    void mainMenu();
    void patientMenu(Account& acc);
    void medicMenu(Account& acc);
    void adminMenu(Account& acc);
};

#endif // MENU_H
