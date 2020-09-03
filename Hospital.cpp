#include <iostream>
#include <string>
#include <Windows.h>                                // access sleep function

#include "Hospital.h"

using namespace std;

Hospital::Hospital()
{
    // default ctor
    hospitalDatabase[0] = "patient.txt";
    hospitalDatabase[1] = "appointments.txt";
    hospitalDatabase[2] = "prescriptions.txt";

}

// getters definitions
int Hospital::getAge()
{
    return age;
}

string Hospital::getName()
{
    return name;
}

int Hospital::getId()
{
    return unique_id;
}

string Hospital::getSex()
{
    return sex;
}

string Hospital::getFilePwd()
{
    return patient_file_pwd;
}

// setters definitions
void Hospital::setAge(int m_age)
{
    age = m_age;
}

void Hospital::setId(int id)
{
    unique_id = id;
}

void Hospital::setName(string m_name)
{
    name = m_name;
}

void Hospital::setSex(string gender)
{
    sex = gender;
}

void Hospital::setFilePwd(string pwd)
{
    patient_file_pwd = pwd;

}

// validate
bool Hospital::validate_id(int id)
{
    // validate personnel unique id
    if (getId() == id)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// query database files
string Hospital::HospitalDatabaseSearch(string search_query)
{
    // check if record given is in Hospital database
    search_query += ".txt";
    string record_root_dir = "./data/";

    for(int record_count=0; record_count < DATABASE_SIZE; record_count++)
    {
        // return record if it exists

        if(search_query == hospitalDatabase[record_count])
        {
            // append record to root dir
            string record_found = record_root_dir + hospitalDatabase[record_count];

            return record_found;
        }

        else
            continue;

    }

    cerr << "Status: Record file '"<< search_query << "' not found in Hospital Database!\n" << endl;

    return "None";
}

void Hospital::regPersonnel()
{
    // member registration
    cout << "Hospital Staff Registration" << endl;

}

void Hospital::displayPatientData()
{
    // get patient data
    cout << "Hospital Patient Information" << endl;
}

bool Hospital::login(string _name, int _pin)
{
    // login personnel after registration
    cout << "\nAttempting log in.";
    for(int animate= 0; animate < 3; animate++)
    {
        // animate logging in loading
        cout << ".";
        Sleep(500);
    }

    if (validate_id(_pin) && getName() == _name)
    {
        return true;
    }

    else
    {
        return false;
    }
}

Hospital::~Hospital()
{
    // dtor
}
