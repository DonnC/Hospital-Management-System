#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Doctor.h"

using namespace std;

void Doctor::regPersonnel()
{
    string nam, gendr, file_pw;
    int i_d, eg;

    getchar();

    cout << "Doctor Registration. Provide registration details." << endl;
    cout << "Name: " << endl;
    getline(cin, nam);

    cout << "Gender: " << endl;
    getline(cin, gendr);

    cout << "File access password: " << endl;
    getline(cin, file_pw);

    cout << "Age: " << endl;
    cin >> eg;

    cout << "Unique ID: " << endl;
    cin >> i_d;

    setName(nam);
    setId(i_d);
    setAge(eg);
    setSex(gendr);
    setFilePwd(file_pw);

    cout << "\n";

    cout << "Registering Doctor.";
    for(int animate= 0; animate < 5; animate++)
    {
        cout << ".";
        Sleep(500);
    }

    cout << " " << endl;
    clog << personnel_post << ": '" << getName() << "' registered. Now available for work!\n" << endl;
}

void Doctor::retrivePatientDetails()
{
    int id;
    string f_pwd;

    cout << "To view Patient record, enter your credentials below " << endl;
    cout << "Unique ID: " << endl;
    cin >> id;

    cout << "Enter record file name to access" << endl;
    cin >> patient_file;

    cout << "File access password: " << endl;
    cin >> f_pwd;

    if ((validate_id(id)) && (getFilePwd() == f_pwd ))
    {
        displayPatientData();
    }

    else{
        cerr << "Error: Authorization to Patient Record declined!" << endl;
    }
}

string Doctor::acknwNurseMedPrescription()
{
    time_t now = time(0);
    char *dt = ctime(&now);

    // give access to medication to nurses

    cout << "\nYou can go ahead to give patient the following drug details:" << endl;
    cout << setw(75) << setfill('_') << " " << endl;
    cout << "Drug:          " << setw(60) << setfill(' ') << "Panado(Pain Killer)" << endl;
    cout << "Duration:      " << setw(60) << "2 weeks course" << endl;
    cout << "Instructions:  " << setw(60) << "2 tablets/day after every meal" << endl;
    cout << "Prescribed at:  " << setw(60) << dt;
    cout << "Personnel:     " << setw(60) << personnel_post << endl;

    prescription =  "Drug:          \t\tPanado(Pain Killer)\n";
    prescription += "Duration:      \t\t2 weeks course\n";
    prescription += "Instructions:  \t\t2 pills/day after every meal\n";
    prescription += "Prescriber:    \t\t" + personnel_post + "\n";

    return prescription;

}

void Doctor::checkNurseAppointments()
{
    // check appointments from Nurses, saved to a file
    int id;
    cout << "Welcome Doctor. To check Nurse appointments, enter your 'id' below: " << endl;
    cin >> id;

    cout << "Enter record name to access" << endl;
    cin >> appointments_file;

    if (validate_id(id))
    {
        clog << "\nStatus: searching for appointments.";
        for(int animate= 0; animate < 4; animate++)
        {
            cout << ".";
            Sleep(500);
        }

        cout << " " << endl;

        string f_hand = HospitalDatabaseSearch(appointments_file);

        if(f_hand != "None")
        {
            Save appointments_record;

            string app_records = appointments_record.read_from_disk(f_hand);

            cout << app_records << endl;
        }

        else
        {
            HospitalDatabaseSearch(f_hand);
        }

    }

    else
    {
        cerr << "Error: You are not authorized to access Nurse Appointments!\n" << endl;
    }

}

void Doctor::displayPatientData()
{
    string f_hand = HospitalDatabaseSearch(patient_file);

    if(f_hand != "None")
    {
        Save patient_record;

        string p_data = patient_record.read_from_disk(f_hand);

        cout << p_data << endl;
    }

    else
    {
        HospitalDatabaseSearch(f_hand);
    }
}

Doctor::~Doctor()
{
    //dtor
}
