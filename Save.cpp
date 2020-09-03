// Save.cpp implementation
// save information to local disk
// act as access to hospital database
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>                              // file operations header file

#include "Save.h"

using namespace std;

void Save::save_to_disk(string f_name, string contents)
{
    time_t now = time(0);
    char *dt = ctime(&now);                         // convert to string

    ofstream f_patient (f_name);

    if (f_patient.is_open())
    {
        f_patient << contents;
        f_patient << "Date Added:\t\t\t" << dt;
        f_patient.close();
    }

    else
    {
        cerr << "Error: Could not write data to, " << f_name << "!\n";
    }
}

string Save::read_from_disk(string f_name)
{
    string line;

    if(fexists(f_name))
    {
        ifstream record(f_name);

        if(record.is_open())
        {
            while(getline(record, line))
            {
                file_contents += line + "\n";
            }

            record.close();
        }

        else
        {
            cerr << "Error: There was a problem reading file, " << f_name << endl;
        }
    }

    else
    {
        cerr << "Error: Failed to read. Record file '" << f_name << "' doest not exist!" << endl;
    }

    return file_contents;
}

bool Save::fexists(string filename)
{
    // check if a given file exists
    ifstream ifile(filename);

    if(ifile)
    {
        return (bool)ifile;
    }

    else
    {
        return false;
    }

}
