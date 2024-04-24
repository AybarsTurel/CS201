//Sevki Aybars Turel

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string findHouse(int score)
{   string house = "";
    if (score < 10) {
        house = "Hufflepuff";
    }
    else if (score >= 10 && score < 15)
    {
        house = "Ravenclaw";
    }
    else if (score >= 15 && score < 21)
    {
        house = "Gryffindor";
    }
    else if (score >= 21)
    {
        house = "Slytherin";
    }
    return house;
}

int main() {
    ifstream answersKey, answers;
    string filename1, filename2, name, lastname, line1, word1, line2, word2;
    int score = 0, value = 0;
    bool check = true;
    cout << "Hello and welcome to the Hogwarts house sorting hat program!" << endl;
    cout << "When I call your name, you'll come forth, I shall place the sorting hat on your head, and you will be sorted into your houses." << endl;
    do
    {
        cout << "Enter the name of the key file: ";
        cin >> filename1;
        answersKey.open(filename1.c_str());
        if (answersKey.fail())
        {
            cout << "Error: Cannot open file " << filename1 << endl;
        }
    } while (answersKey.fail());
    
    do
    {
        cout << "Enter the name of the answer file: ";
        cin >> filename2;
        answers.open(filename2.c_str());
        if (answers.fail())
        {
            cout << "Error: Cannot open file " << filename2 << endl;
        }
        
    } while (answers.fail());
    
    while (getline(answers, line1))
    {
        if (line1 != "\r")
        {
            istringstream input(line1);
            input >> name >> lastname;
            while (getline(answersKey, line2) && input >> word1 )
            {
                if (line2 != "\r")
                {
                    istringstream input2(line2);
                    check = true;
                    while (input2 >> word2 && check)
                    {
                        value ++;
                        if (word1 == word2)
                        {
                            score += value;
                            value = 0;
                            check = false;
                        
                        }
                    }
                }
            }
            cout << "Oh! we have " << name << " " << lastname << " under the sorting hat. " << name << ", you scored " << score << " points, you are a " << findHouse(score) << "!" << endl;
            score = 0;
            answersKey.clear();
            answersKey.seekg(0);
        }
    }
            

    
                
    answersKey.close();
    answers.close();
    
    return 0;
}
