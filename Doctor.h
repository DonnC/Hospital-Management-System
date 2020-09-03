#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <ctime>
#include "Hospital.h"
#include "Save.h"

/**
    * high level access for the Doctor
    * Can access all other personnel in the Hospital
    * Have access Patient's Files through FileIO
*/

class Doctor : public Hospital
{
    public:
        void retrivePatientDetails();
        void checkNurseAppointments();                                    // Nurse's appointments
        string acknwNurseMedPrescription();                               // give right to medication

        // virtual functions
        void regPersonnel();
        void displayPatientData();

        /** Default destructor */
        ~Doctor();

    protected:
        string prescription;                                      // patient prescription

    private:
        string personnel_post =  "Doctor";
        string appointments_file;
        string patient_file;
};

#endif // DOCTOR_H
