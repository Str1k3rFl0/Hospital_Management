#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <algorithm>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <string>

class Account
{
public:
    struct sPDetails
    {
        std::string sFName{};
        std::string sLName{};
        std::string sAge{};
        std::string sPassword{};
        std::string sDisease{};
    }; sPDetails pd;

    struct sMDetails : sPDetails
    {
        std::string sUniversity{};
        std::string sSpecialization{};
    }; sMDetails md;

private:
    std::string firstName{};
    std::string lastName{};
    std::string age{};
    std::string password{};
    std::string disease{};
    std::string university{};
    std::string specialization{};

    std::string patient{ "Patient" };
    std::string medic{ "Medic" };
    std::string manager{ "Manager" };

    std::vector<sPDetails> patients{};
    std::vector<sMDetails> medics{};

public:
    // Functions to enter
    // First Name, Last Name
    // Age and Password
    void enterFName();
    void enterLName();
    void enterAge();
    void enterPassword();

    // Getters for
    // First Name, Last Name
    // Age and Password
    const std::string& getFName() const;
    const std::string& getLName() const;
    const std::string& getAge() const;
    const std::string& getPassword() const;

    // Function to create an Account
    void createAccount(const char* fileName);

    // Function to LogIn for patient
    // and function to show details for
    // current patient
    bool logInPatient(const char* fileName);
    void showPDetails();

    // Function to LogIn for medic
    // and function to show details for
    // current medic
    bool logInMedic(const char* fileName);
    void showMDetails();

    // Function to LogIn for admin
    // and function to show details for
    // current Manager/Admin
    bool logInAdmin(const char* fileName);
    void showADetails();

    // Function to modify Details for patient or medic
    void modifyDetails(const char* fileName, const std::string& role,
        const std::string& oldLine, const std::string& newLine);

    // Function to show all accounts
    // or just a specific account
    void showAllAccounts(const char* fileName);
    bool showAccount(const char* fileName);

    // Function to delete an specific account
    // or to delete all accounts
    bool deleteAcc(const char* fileName);
    void deleteAllAcc(const char* fileName);

    // Functions to compare patient by
    // First Name, Last Name, Age or Disease
    static bool compareByFNameP(const sPDetails& p1, const sPDetails& p2);
    static bool compareByLNameP(const sPDetails& p1, const sPDetails& p2);
    static bool compareByAgeP(const sPDetails& p1, const sPDetails& p2);
    static bool compareByDisP(const sPDetails& p1, const sPDetails& p2);
    void sortPatients(const char* fileName);

    // Functions to compare medic by
    // First Name, Last name, Age
    // University and Specialization
    static bool compareByFNameM(const sMDetails& m1, const sMDetails& m2);
    static bool compareByLNameM(const sMDetails& m1, const sMDetails& m2);
    static bool compareByAgeM(const sMDetails& m1, const sMDetails& m2);
    static bool compareByUnivM(const sMDetails& m1, const sMDetails& m2);
    static bool compareBySpecM(const sMDetails& m1, const sMDetails& m2);
    void sortMedics(const char* fileName);
};

#endif // ACCOUNT_H
