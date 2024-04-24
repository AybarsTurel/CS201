//
//  main.cpp
//  aturel_THE0
//
//  Created by Aybars TÜREL on 6.03.2021.
//

// Sevki Aybars Turel THE0

#include <iostream>
#include <string>
using namespace std;
int main() {
    string username;
    double midtermexam, finalexam, weightedexamaverage, THE1, THE2, THE3, THE4, THE5, quiz1, quiz2, quiz3, quiz4, ratio1, takehomeavr, takehomegrade, quizavr, quizgrade, ratio2, coursenumericgrade;
    int count1, count2;
    
    cout << "The purpose of this program is to calculate your CS201 grade." << endl;
    cout << "What is your name? ";
    cin >> username;
    cout << "Hello " << username << ", what are your midterm and final exam grades? ";
    cin >> midtermexam >> finalexam;
    if (midtermexam == -100 || finalexam == -100) {
        cout << username << ", one of your midterm or final exam grade is -100, you will fail the course!" << endl;
    }
    else if (midtermexam == -1 || finalexam == -1){
        if (midtermexam == -1) {
            cout << username << ", you did not enter the midterm exam, you will fail the course!" << endl;
            
        }
        else if (finalexam == -1) {
            cout << username << ", you did not enter the final exam, you will fail the course!" << endl;
        }
        
        
    }
    else
    {
        weightedexamaverage = (0.30 * midtermexam + 0.30 * finalexam) / 0.6;
        if (weightedexamaverage < 30) {
            cout << username << ", your weighted exam average is less than 30, you will fail the course!" << endl;
        }
        else
        {
            cout << "What are the grades of your 5 take-home exams? ";
            cin >> THE1 >> THE2 >> THE3 >> THE4 >> THE5;
            count1 = 0;
            if (THE1 == -100) {
                count1 = count1 + 1 ;
            }
            if (THE2 == -100){
                count1 = count1 + 1;
            }
            if (THE3 == -100){
                count1 = count1 + 1;
            }
            if (THE4 == -100){
                count1 = count1 + 1;
            }
            if (THE5 == -100){
                count1 = count1 + 1;
            }
            if (count1 >= 2) {
                cout << username << ", at least two of your THE grades are -100, you will fail the course!" << endl;
            }
            else {
                takehomeavr = ((THE1 * 3) + (THE2 * 4) + (THE3 * 4) + (THE4 * 4) + (THE5 * 5)) / 20;
                ratio1 = takehomeavr / weightedexamaverage;
                if (takehomeavr < 0) {
                    takehomegrade = takehomeavr;
                }
                else if (ratio1 <= 2)
                {
                    takehomegrade = takehomeavr;
                }
                else if (ratio1 > 2 && ratio1 < 3){
                    takehomegrade = takehomeavr * (3 - ratio1);
                }
                else if (ratio1 >= 3){
                    takehomegrade = 0;
                }
                
                cout << "What are the grades of your 4 quizzes? ";
                cin >> quiz1 >> quiz2 >> quiz3 >> quiz4;
                
                count2 = 0;
                
                if (quiz1 == -100) {
                    count2 += 1;
                }
                if (quiz2 == -100) {
                    count2 += 1;
                }
                if (quiz3 == -100) {
                    count2 += 1;
                }
                if (quiz4 == -100) {
                    count2 += 1;
                }
                if (count2 >= 2) {
                    cout << username << ", at least two of your quiz grades are -100, you will fail the course!" << endl;
                    
                }
                else if (count1 == 1 && count2 == 1) {
                    cout << username << ", one of your THE and one of your quiz grades is -100, you will fail the course!" << endl;
                    
                    
                }
                else {
                    quizavr = (quiz1 + quiz2 + quiz3 + quiz4) / 4;
                    ratio2 = quizavr / weightedexamaverage;
                    if (quizavr < 0) {
                        quizgrade = quizavr;
                    }
                    else if (ratio2 <= 2)
                    {
                        quizgrade = quizavr;
                    }
                    else if (ratio2 > 2 && ratio2 < 3){
                        quizgrade = quizavr * (3 - ratio2);
                    }
                    else if (ratio2 >= 3)
                    {
                        quizgrade = 0;
                    }
                    
                    coursenumericgrade = (quizgrade * 0.2 )+ (takehomegrade * 0.2) + (midtermexam * 0.3) + (finalexam * 0.3);
                    cout << username << ", your weighted exam average is: " << weightedexamaverage << endl;
                    cout << username << ", your THE average is: "<< takehomeavr << " and you will get " << takehomegrade << " of it." << endl;
                    cout << username << ", your quiz average is: "<< quizavr << " and you will get " << quizgrade << " of it." << endl;
                    cout << username << ", your grade for CS201 is: " << coursenumericgrade << endl;
                }
            }
            
            
            
            
            }
        }
    
    
    return 0;
}
