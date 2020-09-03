/**
    * @author:    Donald Chinhuru, Part 2.2 Electronic Engineering NUST
    * @project:   Hospital Personnel Interface Project with OOP
    * @created:   13 Mar 2019
    * @modified:  26 Apr 2019
    * @course:    OOP with C++
    * @lecturer:  L Gundha
*/

// global default header files
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

// include user defined header files
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"

using namespace std;

// function prototypes declarations
void menu();
void nurseMenu();
void doctorMenu();
void initDisplay();
void run();
int selection();

// run program in main function
int main()
{

    initDisplay();

    cout << "\t\t\tWELCOME TO HOSPITAL DASHBOARD INTERFACE\n";

    run(); // do hospital operation

    return 0;
}

// function prototypes definitions
void menu()
{
    cout << "\nChoose Hospital Personnel operations below" << endl;
    cout << "*Hint: Use the number on the left for selection\n"
         << endl;
    cout << "1. Patient" << endl;
    cout << "2. Nurse  " << endl;
    cout << "3. Doctor " << endl;
    cout << "4. Exit   " << endl;
}

int selection()
{
    // return user selected entry;
    int choice;

    getchar();

    cout << "Select your option: " << endl;
    cin >> choice;

    return choice;
}

void initDisplay()
{
    cout << setw(80) << setfill('*') << " " << endl;
    cout << "Project :   HOSPITAL DASHBOARD SYSTEM" << endl;
    cout << "Student :   DONALD CHINHURU" << endl;
    cout << "Number  :   N0173320W" << endl;
    cout << "Course  :   TEE 2233 OOP" << endl;
    cout << "YEAR    :   PART 2.2 YEAR 2 2019" << endl;
    cout << "LECTURER:   MR L GUNDA" << endl;
    cout << setw(80) << setfill('*') << " \n"
         << endl;
    Sleep(200);
}

void patientMenu()
{

    Patient *patient;
    patient = new Patient;

    patient->getData();
    system("cls"); // clears the screen
    patient->displayPatientData();
    patient->saveData();
    patient->getPrescription();

    // free up space
    delete patient;
    patient = NULL;

    run(); // go to Main menu
}

void doNurse(Nurse &nurse)
{
    Hospital *hosp;

    hosp = &nurse;

    string nurse_name;
    int nurse_pin;

    getchar();
    Sleep(100);

    cout << "\t\t\t\t\t Nurse Login Portal" << endl;
    cout << "Login Name: " << endl;
    getline(cin, nurse_name);

    cout << "Login ID: " << endl;
    cin >> nurse_pin;

    // do login
    if (hosp->login(nurse_name, nurse_pin))
    {
        cout << "\nNurse details Login successful\n"
             << endl;
    }

    else
    {
        cout << "\nCould not validate Nurse. Register below\n"
             << endl;
        nurseMenu();
    }

    cout << "Welcome Nurse. What do you want to do?" << endl;
    cout << "1. Book Appointment to Doctor" << endl;
    cout << "2. Doctor's prescribed medicine to Patient" << endl;
    cout << "3. Access Patient record" << endl;
    cout << "4. Return to Main menu" << endl;

    int nur_choice = selection();

    cout << "\n";

    switch (nur_choice)
    {
    case 1:
        system("cls");
        nurse.bookDocAppointment();
        doNurse(nurse); // return to nurse Menu
        break;

    case 2:
        system("cls");
        nurse.ackwDocPrescription();
        doNurse(nurse);
        break;

    case 3:
        system("cls");
        hosp->displayPatientData();
        doNurse(nurse);
        break;

    case 4:
        system("cls");
        run(); // return to main menu
        break;

    default:
        cout << "No valid input received. Exiting..\n"
             << endl;
        break;
    }
}

void doDoctor(Doctor &doctor)
{
    Hospital *hosp;

    hosp = &doctor;

    string doc_name;
    int doc_pin;

    getchar();
    Sleep(100);

    cout << "\t\t\t\t\t Doctor Login Portal" << endl;
    cout << "Doctor Name: " << endl;
    getline(cin, doc_name);

    cout << "Doctor ID: " << endl;
    cin >> doc_pin;

    // do login
    if (hosp->login(doc_name, doc_pin))
    {
        cout << "\nDoctor '" << doc_name << "' Login successful\n"
             << endl;
    }

    else
    {
        cout << "\nDoctor '" << doc_name << "' not found. Register below\n"
             << endl;
        doctorMenu();
    }

    cout << "Welcome Doctor. What do you want to do?" << endl;
    cout << "1. Check Appointments from Nurse" << endl;
    cout << "2. Access Patient record" << endl;
    cout << "3. Drug prescription to Nurse" << endl;
    cout << "4. Go to Main Menu" << endl;

    int doc_choice = selection();

    cout << "\n";

    switch (doc_choice)
    {
    case 1:
        system("cls");
        doctor.checkNurseAppointments();
        doDoctor(doctor); //return to Doctor Menu
        break;

    case 2:
        system("cls");
        doctor.retrivePatientDetails();
        doDoctor(doctor);
        break;

    case 3:
        system("cls");
        doctor.acknwNurseMedPrescription();
        doDoctor(doctor);
        break;

    case 4:
        system("cls");
        run();
        break;

    default:
        cout << "No valid input received. Exiting..\n"
             << endl;
        break;
    }
}

void nurseMenu()
{
    Hospital *hosp;
    Nurse nurse;

    hosp = &nurse;
    hosp->regPersonnel();

    doNurse(nurse);
}

void doctorMenu()
{
    Hospital *hosp;
    Doctor doctor;

    hosp = &doctor;
    hosp->regPersonnel();

    doDoctor(doctor);
}

void run()
{
    menu(); // display menu

    int choice = selection();

    cout << "\n";

    switch (choice)
    {
    case 1:
        // Patient Class operations
        patientMenu();
        break;

    case 2:
        // Nurse Class operations
        nurseMenu();
        break;

    case 3:
        // Doctor class operations
        doctorMenu();
        break;

    case 4:
        Sleep(50);
        cout << "Hospital Dashboard system exiting.." << endl;
        exit(1);
        break;

    default:
        cout << "Not a valid option. Try again later!\n"
             << endl;
        exit(1);
        break;
    }
}
