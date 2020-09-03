#ifndef NURSE_H
#define NURSE_H

#include "Hospital.h"
#include "Save.h"
#include <string>

// define Nurse class and the operations

class Nurse : public Hospital
{
    public:
        void bookDocAppointment();
        void getAppointmentDetails();
        void ackwDocPrescription();

        // virtual functions
        void regPersonnel();
        void displayPatientData();

        /** Default destructor */
        ~Nurse();

    protected:

    private:
        string appointment;
        string personnel_post = "Nurse";
        string patient_file;
        string appointments_file;
        string prescription_file;
};

#endif // NURSE_H
