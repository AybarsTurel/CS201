
//Sevki Aybars Turel

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct reserveDataBase
{   int sailorID;
    int boatID;
    string date;
    string boatName;
    string sailorName;
    string colour;
    double rating;
    double age;
};

void SelectSortName (vector<reserveDataBase> & data)
{ //    I have taken this function from lecture notes and I modified.
    int j, k, minIndex;
    double temp3, temp4;
    string temp1, temp2,temp5;
    unsigned long numElts = data.size();
    for(k=0; k < numElts - 1; k++){
        minIndex = k;
        for(j=k+1; j < numElts; j++)
            if (data[j].date == data[minIndex].date)
            {
                if (data[j].sailorName < data[minIndex].sailorName)
                {
                    minIndex = j;
                }
            }
        temp1 = data[k].sailorName;
        data[k].sailorName = data[minIndex].sailorName;
        data[minIndex].sailorName = temp1;
        temp2 = data[k].boatName;
        data[k].boatName = data[minIndex].boatName;
        data[minIndex].boatName = temp2;
        temp3 = data[k].age;
        data[k].age = data[minIndex].age;
        data[minIndex].age = temp3;
        temp4 = data[k].rating;
        data[k].rating = data[minIndex].rating;
        data[minIndex].rating = temp4;
        temp5 = data[k].colour;
        data[k].colour = data[minIndex].colour;
        data[minIndex].colour = temp5;

        
        
        

        
        
        
    }
}



void SelectSort(vector<reserveDataBase> & data){
//    I have taken this function from lecture notes and I modified.
    int j, k, minIndex, temp2, temp3;
    string temp1;
    unsigned long numElts = data.size();
    for(k=1; k < numElts - 1; k++){
        minIndex = k;
        for(j=k+1; j < numElts; j++)
            if (data[j].date < data[minIndex].date)
            {
               minIndex = j;
            }
        temp1 = data[k].date;
        data[k].date = data[minIndex].date;
        data[minIndex].date = temp1;
        temp2 = data[k].boatID;
        data[k].boatID = data[minIndex].boatID;
        data[minIndex].boatID = temp2;
        temp3 = data[k].sailorID;
        data[k].sailorID = data[minIndex].sailorID;
        data[minIndex].sailorID = temp3;
        
        
    }
}



int main() {
    string Filename1, Filename2 = "Boats.txt", Filename3 = "Sailors.txt";
    string reserveLine, date, boatline, boatName, boatColor, sailorsLine,surname, word;
    double rating, age;
    int sailorID, boatID;
    ifstream reserveFile, boatsFile, sailorsFile;
    
    cout << "Enter filename for reservation database: ";
    cin >> Filename1;
    
    reserveFile.open(Filename1.c_str());
    boatsFile.open(Filename2.c_str());
    sailorsFile.open(Filename3.c_str());
    if (reserveFile.fail() || boatsFile.fail() || sailorsFile.fail())
    {
        cout << "Cannot open the files. Exiting..." << endl;
    }
    else
    {
        vector <string> calculator;
        
        while (getline(reserveFile, reserveLine)) {
            istringstream input(reserveLine);
            input >> word;
            calculator.push_back(word);
        }
        reserveFile.clear();
           
        reserveFile.seekg(0);
        
       
        vector <reserveDataBase> data(calculator.size());
        
        
        int i = 0;
        while (getline(reserveFile, reserveLine))
        {
            istringstream input(reserveLine);
            input >> sailorID >> boatID >> date;
            data[i].sailorID = sailorID;
            data[i].boatID = boatID;
            data[i].date = date;
            i++;
        }
        SelectSort(data);
        while (getline(sailorsFile, sailorsLine)) {
            istringstream input(sailorsLine);
            input >> sailorID >> surname >> rating >> age;
            for (int i = 1 ; i < calculator.size(); i++) {
                if (sailorID == data[i].sailorID)
                {
                    data[i].sailorName = surname;
                    data[i].rating = rating;
                    data[i].age = age;
                }
            }
        }
        
        
        while (getline(boatsFile, boatline)) {
            istringstream input(boatline);
            input >> boatID >> boatName >> boatColor;
            for (int i = 1 ; i < calculator.size(); i++) {
                if (boatID == data[i].boatID)
                {
                    data[i].boatName = boatName;
                    data[i].colour = boatColor;
                }
            }
        }
        SelectSortName(data);
      
      
    
for (int i = 1; i < calculator.size(); i++) {
    cout << data[i].date << " -> " << data[i].sailorName << "(" << data[i].age << "," << data[i].rating << ") has reserved " <<  data[i].boatName << "(" << data[i].colour << ")" << endl;
    }
    
    reserveFile.close();
    boatsFile.close();
    sailorsFile.close();
    }
    
    return 0;
}
