#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

#include "Nurse.h"
#include "Doctor.h"

using namespace std;

void Nurse::regPersonnel()
{
    string nam, gendr, file_pw;
    int i_d, eg;

    getchar();

    cout << "Nurse Registration form. Input your profile details" << endl;
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

    cout << "Registering Nurse in system .";
    for(int animate= 0; animate < 4; animate++)
    {
        cout << ".";
        Sleep(500);
    }

    cout << " " << endl;
    clog << personnel_post << ": '" << getName() << "' registered. Now available for work!\n" << endl;
}

void Nurse::bookDocAppointment()
{
    // book appoint to Dr
    int id;
    cout << "Welcome Nurse. To book an appointment, enter your 'id' below: " << endl;
    cin >> id;

    cout << "Input record file name for appointment booking" << endl;
    cin >> appointments_file;

    if (validate_id(id))
    {

        string ap_hand = HospitalDatabaseSearch(appointments_file);

        if(ap_hand != "None")
        {
            Save book_appointment;

            cout << "\nBook an Appointment to Doctor!. Enter details: " << endl;

            getAppointmentDetails();

            book_appointment.save_to_disk(ap_hand, appointment);

            cout << "\nAppointment booked!\n" << endl;
        }
    }

    else
    {
        clog << "Error: No Nurse matches the 'unique id' provided!\n" << endl;
    }
}

void Nurse::getAppointmentDetails()
{
    srand(time(0));                                      // start random, with time to make it change every time code runs
    int bed_number  = rand() % 50 + 1;                   // add 1 so as not to get a 0
    int ward_number = rand() % 30 + 1;

    string pat_name, pat_details, query;

    getchar();

    cout << "Enter patient's name:" << endl;
    getline(cin, pat_name);

    cout << "Enter patient's nature of sickness:" << endl;
    getline(cin, pat_details);

    cout << "Enter appointment details:" << endl;
    getline(cin, query);

    appointment += personnel_post + "\t\t\t\t" + getName() + "\n";
    appointment += "Ref Patient     \t\t" + pat_name + "\n";
    appointment += "Patient ward no.\t\t" + to_string(ward_number) + "\n";
    appointment += "Patient bed no. \t\t" + to_string(bed_number) + "\n";
    appointment += "Patient Details \t\t" + pat_details + "\n";
    appointment += "Appointment     \t\t" + query + "\n";
}

void Nurse::ackwDocPrescription()
{
    // prescribe details from Doctor to Patient
    // create doc pointer
    Doctor *doctor;
    doctor = new Doctor;

    int id;
    cout << "For drug prescription from Doctor, enter your 'id' below: " << endl;
    cin >> id;

    cout << "Input record file to access Doctor's prescriptions: " << endl;
    cin >> prescription_file;

    string presc_hand = HospitalDatabaseSearch(prescription_file);

    if((presc_hand != "None") && (validate_id(id)))
    {
        Save prescribe_to_file;

        string presr = doctor->acknwNurseMedPrescription();

        if (presr != "None")
        {
            prescribe_to_file.save_to_disk(presc_hand, presr);
        }

    }

    else
    {
        cerr << "Error: Could not prescribe medication from an unverified practitioner!" << endl;
    }

    // free up space
    delete doctor;
    doctor = NULL;

}

void Nurse::displayPatientData()
{
    string psd;

    getchar();

    cout << "Input file name to access: " << endl;
    getline(cin, patient_file);

    cout << "Input password to access this file: " << endl;
    getline(cin, psd);

    string f_hand = HospitalDatabaseSearch(patient_file);

    if(f_hand != "None")
    {
        Save patient_record;

        cout << "\nPatient Record accessed from Nurse Portal!" << endl;

        string p_data = patient_record.read_from_disk(f_hand);

        // display patient details from database
        cout << p_data << endl;
    }
}

Nurse::~Nurse()
{
    //dtor
}
