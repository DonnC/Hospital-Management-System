#ifndef PATIENT_H
#define PATIENT_H

#include "Hospital.h"
#include "Save.h"               // access fileIO functions

/**
 * Patient Operations
 * Patient enters their details
 * Details are saved to files
 * Nurse/Dr can then retrieve the information and offer service
*/

class Patient : public Hospital
{
    public:
        void displayPatientData();
        void getPrescription();         // get prescription from Nurse/Doctor
        void getData();
        void saveData();                    // save patient data to disk
        void createData();                  // create patient data stream
        void genNums();                     // generate random bed & ward nums
        string ageConvert();

    protected:
        string personnel_post    = "Patient";

    private:
        string bed_number;
        string ward_number;
        string sickness;
        string data_stream;

};

#endif // PATIENT_H
