#include "Account.h"

void Account::enterFName()
{
    std::cout << "Enter your First Name: ";
    std::cin >> firstName;
}

void Account::enterLName()
{
    std::cout << "Enter your Last Name: ";
    std::cin >> lastName;
}

void Account::enterAge()
{
    std::cout << "Enter your age: ";
    std::cin >> age;
}

void Account::enterPassword()
{
    std::cout << "Enter your password: ";
    std::cin >> password;
}

const std::string& Account::getFName() const
{
    return firstName;
}

const std::string& Account::getLName() const
{
    return lastName;
}

const std::string& Account::getAge() const
{
    return age;
}

const std::string& Account::getPassword() const
{
    return password;
}

// Function to create the account for specific role
void Account::createAccount(const char* fileName)
{
    system("cls");

    enterFName();
    enterLName();
    enterAge();

    std::ofstream myFile(fileName, std::ios::app);

    std::cout << "As Patient, Medic or Manager: ";
    std::string option{};
    std::cin >> option;

    if (option == "Patient")
    {
        enterPassword();
        std::cout << "Enter your disease: ";
        std::getline(std::cin >> std::ws, disease);

        myFile << getFName() << ' ' << getLName() << ' '
               << getAge() << ' ' << getPassword() << ' '
               << patient << ' ' << disease << '\n';

    }
    else if (option == "Medic")
    {
        enterPassword();

        std::cout << "Enter your university where you studied: ";
        std::getline(std::cin >> std::ws, university);

        std::cout << "Enter your specialization: ";
        std::getline(std::cin >> std::ws, specialization);

        myFile << getFName() << " " << getLName() << " "
               << getAge() << " " << getPassword() << " "
               << medic << " " << "\"" << university << "\" \"" << specialization << "\"\n";
    }
    else if (option == "Manager")
    {
        enterPassword();

        myFile << getFName() << ' ' << getLName() << ' '
               << getAge() << ' ' << getPassword() << ' '
               << manager << '\n';
    }
    else
    {
        std::cout << "Invalid option!\n";
    }

    myFile.close();

    std::cout << "\n\nThis account is created succesfully!";
    std::cout << "\nPress ENTER to continue...";
    _getch();
}

void Account::modifyDetails(const char* fileName, const std::string& role,
    const std::string& oldLine, const std::string& newLine)
{
    std::ifstream myFile(fileName);
    std::ofstream tempFile("Temp.txt");
    std::string line{};

    while (std::getline(myFile, line))
    {
        if (line != oldLine)
        {
            tempFile << line << std::endl;
        }
        else
        {
            tempFile << newLine << std::endl;
        }
    }

    myFile.close();
    tempFile.close();

    remove(fileName);
    rename("Temp.txt", fileName);

    std::cout << "\nDetails updated successfully\n";
}

// Function to show all accounts that has been created
void Account::showAllAccounts(const char* fileName)
{
    system("cls");
    std::ifstream myFile(fileName, std::ios::in);
    if (!myFile)
    {
        std::cerr << "\nFile can't be opened!" << '\n';
        exit(0);
    }

    std::string line{};
    std::cout << "Enter the role(Patient, Medic, Manager): ";
    std::string role{};
    std::cin >> role;
    if (role == "Patient")
    {
        while (std::getline(myFile, line))
        {
            if (line.find(role) != std::string::npos)
            {
                std::istringstream iss { line };
                if (iss >> firstName >> lastName >> age >> password >> patient)
                {
                    std::getline(iss >> std::ws, disease);

                    std::cout << "First Name: " << firstName << '\n';
                    std::cout << "Last Name: " << lastName << '\n';
                    std::cout << "Age: " << age << '\n';
                    std::cout << "Password: " << password << '\n';
                    std::cout << "Role: " << patient << '\n';
                    std::cout << "Disease: " << disease << '\n';
                    std::cout << "------------------------------------\n";
                }
                else
                {
                    std::cerr << "Error! Can't open the file with details!\n";
                }
            }
        }
    }
    else if (role == "Medic")
    {
        while (std::getline(myFile, line))
        {
            if (line.find(role) != std::string::npos)
            {
                std::istringstream iss { line };
                if (iss >> firstName >> lastName >> age >> password >> medic)
                {
                    iss.ignore();
                    std::getline(iss, university, '"');
                    std::getline(iss, university, '"');
                    iss.ignore();
                    std::getline(iss, specialization, '"');
                    std::getline(iss, specialization, '"');

                    std::cout << "First Name: " << firstName << '\n';
                    std::cout << "Last Name: " << lastName << '\n';
                    std::cout << "Age: " << age << '\n';
                    std::cout << "Password: " << password << '\n';
                    std::cout << "Role: " << role << '\n';
                    std::cout << "University: " << university << '\n';
                    std::cout << "Specialization: " << specialization << '\n';
                    std::cout << "----------------------------------------\n";
                }
                else
                {
                    std::cout << "Error! Can't open the file with details!\n";
                }
            }
        }
    }
    else if (role == "Manager")
    {
        while (std::getline(myFile, line))
        {
            if (line.find(role) != std::string::npos)
            {
                std::istringstream iss { line };
                {
                    if (iss >> firstName >> lastName >> age >> password >> manager)
                    {
                        std::cout << "First Name: " << firstName << '\n';
                        std::cout << "Last Name: " << lastName << '\n';
                        std::cout << "Age: " << age << '\n';
                        std::cout << "Password: " << password << '\n';
                        std::cout << "Role: " << role << '\n';
                        std::cout << "----------------------------------------\n";
                    }
                    else
                    {
                        std::cout << "Error! Can't open the file with details\n";
                    }
                }
            }
        }
    }

    myFile.close();
    std::cout << "\nPress ENTER to continue...";
    _getch();
}

bool Account::showAccount(const char* fileName)
{
    system("cls");

    std::ifstream myFile(fileName, std::ios::in);

    std::cout << "Enter First Name: ";
    std::string _fName{};
    std::cin >> _fName;

    std::cout << "Enter password: ";
    std::string _password{};
    std::cin >> _password;

    if (!myFile.is_open())
    {
        std::cerr << "\nThe file can't be opened!\n";
        return false;
    }

    std::string line{};
    std::string oldLine{};
    while (std::getline(myFile, line))
    {
        std::istringstream iss { line };
        std::string role{};
        std::string tFName{};
        std::string tLName{};
        std::string tAge{};
        std::string tPassword{};

        if (iss >> tFName >> tLName >> tAge >> tPassword >> role)
        {
            if (role == patient)
            {
                std::getline(iss >> std::ws, disease);
                if (tFName == _fName && tPassword == _password)
                {
                    pd.sFName = tFName;
                    pd.sLName = tLName;
                    pd.sAge = tAge;
                    pd.sPassword = tPassword;
                    pd.sDisease = disease;

                    system("cls");
                    std::cout << "\nYou successfully logged in for " << pd.sFName << " account!\n";
                    std::cout << "First Name: " << pd.sFName << '\n';
                    std::cout << "Last Name: " << pd.sLName << '\n';
                    std::cout << "Age: " << pd.sAge << '\n';
                    std::cout << "Password: " << pd.sPassword << '\n';
                    std::cout << "Disease: " << pd.sDisease << '\n';

                    oldLine = line;
                    myFile.close();

                    char ch{};
                    do
                    {
                        std::cout << "\nDo you want to modify any details? (y/n): ";
                        std::cin >> ch;

                        if (ch == 'y' || ch == 'Y')
                        {
                            std::cout << "\nWhat do you want to modify?\n";
                            std::cout << "[1] First Name" << std::endl;
                            std::cout << "[2] Last Name" << std::endl;
                            std::cout << "[3] Age" << std::endl;
                            std::cout << "[4] Password" << std::endl;
                            std::cout << "[5] Disease" << std::endl;
                            char option{};
                            std::cout << "Enter your option: ";
                            std::cin >> option;

                            switch (option)
                            {
                                case '1': std::cout << "Enter new First Name: ";
                                          std::cin >> pd.sFName;
                                          break;

                                case '2': std::cout << "Enter new Last Name: ";
                                          std::cin >> pd.sLName;
                                          break;

                                case '3': std::cout << "Enter new Age: ";
                                          std::cin >> pd.sAge;
                                          break;

                                case '4': std::cout << "Enter new Password: ";
                                          std::cin >> pd.sPassword;
                                          break;

                                case '5': std::cout << "Enter new Disease: ";
                                          std::cin >> pd.sDisease;
                                          break;

                                default: std::cout << "Invalid option!";
                            }

                            std::ostringstream nLineStream{};
                            nLineStream << pd.sFName << " " << pd.sLName << " "
                                        << pd.sAge << " " << pd.sPassword << " "
                                        << patient << " " << pd.sDisease;
                            modifyDetails(fileName, patient, oldLine, nLineStream.str());
                            oldLine = nLineStream.str();
                        }
                    } while (ch == 'y' || ch == 'Y');

                    //myFile.close();
                    std::cout << "\nPress ENTER to continue...\n";
                    _getch();
                    return true;
                }
            }
            else if (role == medic)
            {
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
                std::getline(iss, university, '"');
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
                std::getline(iss, specialization, '"');

                if (tFName == _fName && tPassword == _password)
                {
                    md.sFName = tFName;
                    md.sLName = tLName;
                    md.sAge = tAge;
                    md.sPassword = tPassword;
                    md.sUniversity = university;
                    md.sSpecialization = specialization;

                    std::cout << "\nYou successfully logged in for " << md.sFName << " account!\n";
                    std::cout << "First Name: " << md.sFName << '\n';
                    std::cout << "Last Name: " << md.sLName << '\n';
                    std::cout << "Age: " << md.sAge << '\n';
                    std::cout << "University: " << md.sUniversity << '\n';
                    std::cout << "Specialization: " << md.sSpecialization << '\n';

                    oldLine = line;
                    myFile.close();

                    char ch{};
                    do
                    {
                        std::cout << "\nDo you want to modify any details? (y/n): ";
                        std::cin >> ch;

                        if (ch == 'y' || ch == 'Y')
                        {
                            std::cout << "\nWhat do you want to modify?\n";
                            std::cout << "[1] First Name" << std::endl;
                            std::cout << "[2] Last Name" << std::endl;
                            std::cout << "[3] Age" << std::endl;
                            std::cout << "[4] Password" << std::endl;
                            std::cout << "[5] University" << std::endl;
                            std::cout << "[6] Specialization" << std::endl;
                            char option{};
                            std::cout << "Enter your option: ";
                            std::cin >> option;

                            switch (option)
                            {
                                case '1': std::cout << "Enter new First Name: ";
                                          std::cin >> md.sFName;
                                          break;

                                case '2': std::cout << "Enter new Last Name: ";
                                          std::cin >> md.sLName;
                                          break;

                                case '3': std::cout << "Enter new Age: ";
                                          std::cin >> md.sAge;
                                          break;

                                case '4': std::cout << "Enter new Password: ";
                                          std::cin >> md.sPassword;
                                          break;

                                case '5': std::cout << "Enter new University: ";
                                          std::getline(std::cin >> std::ws, md.sUniversity);
                                          break;

                                case '6': std::cout << "Enter new Specialization: ";
                                          std::getline(std::cin >> std::ws, md.sSpecialization);
                                          break;

                                default: std::cout << "Invalid option!";
                            }

                            std::ostringstream nLineStream{};
                            nLineStream << md.sFName << " " << md.sLName << " "
                                        << md.sAge << " " << md.sPassword << " "
                                        << medic << " \"" << md.sUniversity << "\" \""
                                        << md.sSpecialization << "\"";
                            modifyDetails(fileName, medic, oldLine, nLineStream.str());
                            oldLine = nLineStream.str();
                        }
                    } while (ch == 'y' || ch == 'Y');

                    //myFile.close();
                    std::cout << "\Press ENTER to continue...";
                    _getch();
                    return true;
                }
            }
        }
    }

    myFile.close();
    std::cout << "\nIncorrect username, password or maybe this user don't have an account!\n";
    std::cout << "Press ENTER to continue...";
    _getch();
    return false;
}

bool Account::deleteAcc(const char* fileName)
{
    system("cls");
    std::ifstream myFile(fileName, std::ios::in);

    std::cout << "Enter your First Name: ";
    std::string _fName{};
    std::cin >> _fName;

    std::cout << "Enter your password: ";
    std::string _password{};
    std::cin >> _password;

    if (!myFile.is_open())
    {
        std::cerr << "\nThe file can't be opened!\n";
        return false;
    }

    std::string line{};
    std::string oldLine{};
    std::string role{};

    bool accFound { false };

    while (std::getline(myFile, line))
    {
        std::istringstream iss { line };
        std::string tFName{};
        std::string tLName{};
        std::string tAge{};
        std::string tPassword{};
        std::string tRole{};

        if (iss >> tFName >> tLName >> tAge >> tPassword >> tRole)
        {
            if (tFName == _fName && tPassword == _password)
            {
                oldLine = line;
                role = tRole;
                accFound = true;
                break;
            }
        }
    }

    myFile.close();

    if (accFound)
    {
        char ch{};
        std::cout << "Are you sure you want to delete this account? (y/n): ";
        std::cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            std::ifstream file(fileName);
            std::ofstream tempFile("Temp.txt");
            while (std::getline(file, line))
            {
                if (line != oldLine)
                {
                    tempFile << line << std::endl;
                }
            }

            file.close();
            tempFile.close();

            remove(fileName);
            rename("Temp.txt", fileName);

            std::cout << "\nAccount deleted successfully!\n";
            std::cout << "\nPress ENTER to continue...";
            _getch();
            return true;
        }
        else
        {
            std::cout << "\nAccount deletion canceled.\n";
            std::cout << "\nPress ENTER to continue...";
            _getch();
            return true;
        }
    }
    else
    {
        std::cout << "\nIncorrect username, password or account doesn't exist!\n";
        std::cout << "\nPress ENTER to continue...";
        _getch();
        return false;
    }
}

void Account::deleteAllAcc(const char* fileName)
{
    system("cls");

    std::cout << "Are you sure you want to delete all accounts? (y/n): ";
    char ch{};
    std::cin >> ch;

    if (ch == 'y' || ch == 'Y')
    {
        std::ofstream myFile(fileName, std::ofstream::trunc);
        if (!myFile.is_open())
        {
            std::cerr << "\nThis file can't be opened!\n";
        }
        myFile.close();
    }

    std::cout << "\nAll accounts are deleted with success!\n";
    _getch();
}

bool Account::logInPatient(const char* fileName)
{
    system("cls");

    std::ifstream myFile(fileName, std::ios::in);

    std::cout << "Enter your First Name: ";
    std::string _fName{};
    std::cin >> _fName;

    std::cout << "Enter your password: ";
    std::string _password{};
    std::cin >> _password;

    if (!myFile)
    {
        std::cerr << "\nThis file can't be opened!\n";
        return false;
    }

    std::string line{};
    while (std::getline(myFile, line))
    {
        std::istringstream iss { line };
        std::string role{};
        if (iss >> firstName >> lastName >> age >> password >> role && role == patient)
        {
            std::getline(iss >> std::ws, disease);

            if (firstName == _fName && password == _password)
            {
                pd.sFName = firstName;
                pd.sLName = lastName;
                pd.sAge = age;
                pd.sPassword = password;
                pd.sDisease = disease;

                myFile.close();
                std::cout << "\nYou succesfully logged in!\n";
                std::cout << "\nPress ENTER to continue...";
                _getch();
                return true;
            }
        }
    }

    myFile.close();
    std::cout << "\nIncorrect username, password or maybe you are not a patient!\n";
    std::cout << "\nPress ENTER to continue...";
    _getch();
    return false;
}

bool Account::logInMedic(const char* fileName)
{
    system("cls");

    std::ifstream myFile(fileName, std::ios::in);

    std::cout << "Enter your First Name: ";
    std::string _fName{};
    std::cin >> _fName;

    std::cout << "Enter your password: ";
    std::string _password{};
    std::cin >> _password;

    if (!myFile.is_open())
    {
        std::cerr << "\nThe file can't be opened!\n";
        return false;
    }

    std::string line{};
    while (std::getline(myFile, line))
    {
        std::istringstream iss { line };
        std::string role{};
        std::string tempFirstName, tempLastName, tempAge, tempPassword;

        if (iss >> tempFirstName >> tempLastName >> tempAge >> tempPassword >> role && role == medic)
        {
            std::string tempUniversity, tempSpecialization;

            iss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
            std::getline(iss, tempUniversity, '"');

            iss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
            std::getline(iss, tempSpecialization, '"');

            if (tempFirstName == _fName && tempPassword == _password)
            {
                md.sFName = tempFirstName;
                md.sLName = tempLastName;
                md.sAge = tempAge;
                md.sPassword = tempPassword;
                md.sUniversity = tempUniversity;
                md.sSpecialization = tempSpecialization;

                myFile.close();
                std::cout << "\nYou successfully logged in!\n";
                std::cout << "\nPress ENTER to continue...";
                _getch();
                return true;
            }
        }
    }

    myFile.close();
    std::cout << "\nIncorrect username, password or maybe you are not a medic!\n";
    std::cout << "\nPress ENTER to continue...";
    _getch();
    return false;
}

bool Account::logInAdmin(const char* fileName)
{
    system("cls");

    std::ifstream myFile(fileName, std::ios::in);

    std::cout << "Enter your First Name: ";
    std::string _fName{};
    std::cin >> _fName;

    std::cout << "Enter your password: ";
    std::string _password{};
    std::cin >> _password;

    if (!myFile.is_open())
    {
        std::cerr << "\nThe file can't be opened!\n";
        return false;
    }

    std::string line{};
    while (std::getline(myFile, line))
    {
        std::istringstream iss { line };
        std::string role{};
        if (iss >> firstName >> lastName >> age >> password >> role && role == manager)
        {
            if (firstName == _fName && password == _password)
            {
                pd.sFName = firstName;
                pd.sLName = lastName;
                pd.sAge = age;
                pd.sPassword = password;

                myFile.close();
                std::cout << "\nYou succesfully logged in!\n";
                std::cout << "\nPress ENTER to continue...";
                _getch();
                return true;
            }
        }
    }

    myFile.close();
    std::cout << "\nIncorrect username, password or maybe you are not an admin!\n";
    std::cout << "\nPress ENTER to continue...";
    _getch();
    return false;
}

void Account::showPDetails()
{
    system("cls");

    std::cout << "\nPatient Details: \n";
    std::cout << "First Name: " << pd.sFName << '\n';
    std::cout << "Last Name: " << pd.sLName << '\n';
    std::cout << "Age: " << pd.sAge << '\n';
    std::cout << "Disease: " << pd.sDisease << '\n';

    std::cout << "\nPress ENTER to continue...";
    _getch();
}

void Account::showMDetails()
{
    system("cls");

    std::cout << "\nPatient Details: \n";
    std::cout << "First Name: " << md.sFName << '\n';
    std::cout << "Last Name: " << md.sLName << '\n';
    std::cout << "Age: " << md.sAge << '\n';
    std::cout << "University: " << md.sUniversity << '\n';
    std::cout << "Specialization: " << md.sSpecialization << '\n';

    std::cout << "\nPress ENTER to continue...";
    _getch();
}

void Account::showADetails()
{
    system("cls");

    std::cout << "\nPatient Details: \n";
    std::cout << "First Name: " << pd.sFName << '\n';
    std::cout << "Last Name: " << pd.sLName << '\n';
    std::cout << "Age: " << pd.sAge << '\n';

    std::cout << "\nPress ENTER to continue...";
    _getch();
}

bool Account::compareByFNameP(const sPDetails& p1, const sPDetails& p2)
{
    return p1.sFName < p2.sFName;
}

bool Account::compareByLNameP(const sPDetails& p1, const sPDetails& p2)
{
    return p1.sLName < p2.sLName;
}

bool Account::compareByAgeP(const sPDetails& p1, const sPDetails& p2)
{
    // We convert string to integer using std::stoi();
    return std::stoi(p1.sAge) < std::stoi(p2.sAge);
}

bool Account::compareByDisP(const sPDetails& p1, const sPDetails& p2)
{
    return p1.sDisease < p2.sDisease;
}

bool Account::compareByFNameM(const sMDetails& m1, const sMDetails& m2)
{
    return m1.sFName < m2.sFName;
}

bool Account::compareByLNameM(const sMDetails& m1, const sMDetails& m2)
{
    return m1.sLName < m2.sLName;
}

bool Account::compareByAgeM(const sMDetails& m1, const sMDetails& m2)
{
    return std::stoi(m1.sAge) < std::stoi(m2.sAge);
}

bool Account::compareByUnivM(const sMDetails& m1, const sMDetails& m2)
{
    return m1.sUniversity < m2.sUniversity;
}

bool Account::compareBySpecM(const sMDetails& m1, const sMDetails& m2)
{
    return m1.sSpecialization < m2.sSpecialization;
}

void Account::sortPatients(const char* fileName)
{
    system("cls");

    // Clear the vector before read from file!!!
    patients.clear();

    std::ifstream myFile(fileName, std::ios::in);

    if (!myFile.is_open())
    {
        std::cerr << "\nThe file can't be opened!\n";
        return;
    }

    std::string line{};
    while (std::getline(myFile, line))
    {
        std::istringstream iss { line };
        std::string tRole{};
        std::string tFName{};
        std::string tLName{};
        std::string tAge{};
        std::string tPassword{};
        std::string tDisease{};

        if (iss >> tFName >> tLName >> tAge >> tPassword >> tRole && tRole == "Patient")
        {
            std::getline(iss >> std::ws, tDisease);

            sPDetails patient { tFName, tLName, tAge, tPassword, tDisease };
            patients.push_back(patient);
        }
    }

    myFile.close();

    std::cout << "\nSort by:" << std::endl
              << "[1] First Name" << std::endl
              << "[2] Last Name" << std::endl
              << "[3] Age" << std::endl
              << "[4] Disease" << std::endl
              << "\nEnter your option: ";
    char ch{};
    std::cin >> ch;

    switch (ch)
    {
    /*
    case '1':
        std::sort(patients.begin(), patients.end(), [this](const sPDetails& p1, const sPDetails& p2)
        { return compareByFNameP(p1, p2); }); break;

    case '2':
        std::sort(patients.begin(), patients.end(), [this](const sPDetails& p1, const sPDetails& p2)
        { return compareByLNameP(p1, p2); }); break;

    case '3':
        std::sort(patients.begin(), patients.end(), [this](const sPDetails& p1, const sPDetails& p2)
        { return compareByAgeP(p1, p2); }); break;

    case '4':
        std::sort(patients.begin(), patients.end(), [this](const sPDetails& p1, const sPDetails& p2)
        { return compareByDisP(p1, p2); }); break;
    */


        case '1': std::sort(patients.begin(), patients.end(), compareByFNameP); break;
        case '2': std::sort(patients.begin(), patients.end(), compareByLNameP); break;
        case '3': std::sort(patients.begin(), patients.end(), compareByAgeP);   break;
        case '4': std::sort(patients.begin(), patients.end(), compareByDisP);   break;
        default: std::cout << "Invalid option!"; return;
    }

    std::cout << "\nSorted Patients:\n";
    for (const auto& p : patients)
    {
        std::cout << "First Name: " << p.sFName
                  << ", Last Name: " << p.sLName
                  << ", Age: " << p.sAge
                  << ", Disease: " << p.sDisease << '\n';
    }

    std::cout << "\nPress ENTER to continue...";
    _getch();
}

void Account::sortMedics(const char* fileName)
{
    system("cls");

    // Clear the vector before reading the file
    medics.clear();

    std::ifstream myFile(fileName, std::ios::in);

    if (!myFile.is_open())
    {
        std::cerr << "\nThe file can't be opened!\n";
        return;
    }

    std::string line{};
    while (std::getline(myFile, line))
    {
        std::istringstream iss { line };
        std::string tRole{};
        std::string tFName{};
        std::string tLName{};
        std::string tAge{};
        std::string tPassword{};
        std::string tUniversity{};
        std::string tSpecialization{};

        if (iss >> tFName >> tLName >> tAge >> tPassword >> tRole && tRole == "Medic")
        {
            iss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
            std::getline(iss, tUniversity, '"');
            iss.ignore(std::numeric_limits<std::streamsize>::max(), '"');
            std::getline(iss, tSpecialization, '"');

            sMDetails medic { tFName, tLName, tAge, tPassword, tUniversity, tSpecialization };
            medics.push_back(medic);
        }
    }

    myFile.close();
    std::cout << "\nSort by:" << std::endl
              << "[1] First Name" << std::endl
              << "[2] Last Name" << std::endl
              << "[3] Age" << std::endl
              << "[4] University" << std::endl
              << "[5] Specialization" << std::endl
              << "\nEnter your option: ";
    char ch{};
    std::cin >> ch;

    switch (ch)
    {
        case '1': std::sort(medics.begin(), medics.end(), compareByFNameM); break;
        case '2': std::sort(medics.begin(), medics.end(), compareByLNameM); break;
        case '3': std::sort(medics.begin(), medics.end(), compareByAgeM);   break;
        case '4': std::sort(medics.begin(), medics.end(), compareByUnivM);  break;
        case '5': std::sort(medics.begin(), medics.end(), compareBySpecM);  break;
        default: std::cout << "Invalid option!"; return;
    }

    std::cout << "\nNumber of medics read and stored: " << medics.size() << '\n';

    std::cout << "\nSorted Medics:\n";
    for (const auto& m : medics)
    {
        std::cout << "\nFirst Name: " << m.sFName
                  << ", Last Name: " << m.sLName
                  << ", Age: " << m.sAge
                  << ", University: " << m.sUniversity
                  << ", Specialization: " << m.sSpecialization << '\n';
    }

    std::cout << "\nPress ENTER to continue...";
    _getch();
}
