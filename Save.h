#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include <string>
using namespace std;

class Save
{
public:
    void save_to_disk(string f_name, string contents);
    string read_from_disk(string f_name);
    bool fexists(string filename);

private:
    string file_contents = "Record Information\n";
};

#endif // SAVE_H_INCLUDED
// done
