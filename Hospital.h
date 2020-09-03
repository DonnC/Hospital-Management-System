#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <iostream>

using namespace std;

// Base template for hospital personnels and operations

class Hospital
{
    public:
        // constructor
        Hospital();

        // declare getters
        string getName();
        string getSex();
        int    getAge();
        int    getId();
        string getFilePwd();

        // declare setters
        void setName(string);
        void setAge(int);
        void setId(int);
        void setSex(string);
        void setFilePwd(string);

        // validation of personnel
        bool validate_id(int);
        bool login(string, int);

        // query database for hospital record
        string HospitalDatabaseSearch(string);

        // virtual functions
        virtual void regPersonnel();
        virtual void displayPatientData();

        ~Hospital();

    protected:
        string personnel_post = "General Member";              // patient / nurse / doctor

    private:
        string name;
        string sex;
        string patient_file_pwd;
        string hospitalDatabase[3];

        int age;
        int unique_id;
        int DATABASE_SIZE = 3;
};

#endif // HOSPITAL_H
