
// Sevki Aybars Turel

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Reservation.h"
using namespace std;

int main()
{
    string filename1 = "Boats.txt";
    string filename2 = "Sailors.txt";
    string filename3;
    string reserveLine, boatsLine, sailorsLine, operation, date ,boatName, boatColor, sailorName;
   
   
    ifstream reserveFile, boatsFile, sailorsFile;
    
    cout << "Enter filename for reservation database: ";
    cin >> filename3;
    boatsFile.open(filename1.c_str());
    sailorsFile.open(filename2.c_str());
    reserveFile.open(filename3.c_str());
    
    if (reserveFile.fail() || boatsFile.fail() || sailorsFile.fail())
    {
        cout << "Cannot open the files. Exiting..." << endl;
    }
   
    return 0;
}
