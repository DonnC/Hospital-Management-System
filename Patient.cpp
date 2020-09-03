/*
  Patient.cpp
  Patient implementation
*/
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>

#include "Patient.h"

using namespace std;

void Patient::getData()
{
    // gather all the patient data
    string p_name, p_sex;
    int p_age;

    getchar();

    cout << "Please enter your sick report details below: " << endl;
    cout << "Enter your full name: " << endl;
    getline(cin, p_name);

    cout << "Enter your gender: " << endl;
    getline(cin, p_sex);

    cout << "Enter nature of sickness: " << endl;
    getline(cin, sickness);

    cout << "Enter your age: " << endl;
    cin >> p_age;

    setName(p_name);
    setAge(p_age);
    setSex(p_sex);
    genNums();

}

void Patient::displayPatientData()
{
    // current date/time based on local machine
    time_t now = time(0);
    char *dt = ctime(&now);                         // convert to string

    cout << "\n" << endl;
    cout << setw(80) << setfill('_') << "" << endl;
    cout << setw(40) << setfill(' ') << personnel_post <<  " Record \n" << endl;
    cout << "Name      " << setw(50) << setfill('.') << getName() << endl;
    cout << "Age       " << setw(50) << getAge() << endl;
    cout << "Gender    " << setw(50) << getSex() << endl;
    cout << "Sickness  " << setw(50) << sickness << endl;
    cout << "Ward No.  " << setw(50) << ward_number << endl;
    cout << "Bed No.   " << setw(50) << bed_number << endl;
    cout << "Date Added " << setw(50) << dt << endl;
    cout << setw(80) << setfill('_') << "_" << endl;
}

string Patient::ageConvert()
{
    // convert int age to string
    string age_str;
    int age_ = getAge();

    age_str = to_string(age_);

    return age_str;
}

void Patient::createData()
{
    // create data stream
    data_stream += "Name:      \t\t\t" + getName() + "\n";
    data_stream += "Gender:    \t\t\t" + getSex() + "\n";
    data_stream += "Age:       \t\t\t" + ageConvert() + "\n";
    data_stream += "Ward:      \t\t\t" + ward_number + "\n";
    data_stream += "Bed:       \t\t\t" + bed_number + "\n";
    data_stream += "Condition: \t\t\t" + sickness + "\n";

}

void Patient::saveData()
{
    // save data to file using the Save Class
    Save patient_data;

    // create data stream of patient
    createData();

    // check if file is in database
    string _file = HospitalDatabaseSearch("patient");

    if(_file != "None")
        patient_data.save_to_disk(_file, data_stream);

    else
        HospitalDatabaseSearch("patient");

}

void Patient::getPrescription()
{
    Save prescription;

    string presc_file = HospitalDatabaseSearch("prescriptions");

    if(presc_file != "None")
    {
        cout << "\nWaiting for medication from Nurse.";
        for(int animate= 0; animate < 5; animate++)
        {
            cout << ".";
            Sleep(500);
        }

        cout << "\nYou are advised to take the following for your health to recover" << endl;
        cout << prescription.read_from_disk(presc_file) << endl;
    }

}

void Patient::genNums()
{
    srand(time(0));
    int bed  = rand() % 50 + 1;
    int ward = rand() % 30 + 1;

    bed_number = to_string(bed);            // convert to string
    ward_number = to_string(ward);
}
