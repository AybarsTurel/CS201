
// Sevki Aybars Turel 28238


#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;


bool wordChecker(string secretWord){
        for (int i = 0; i < secretWord.length() ; i++)
        {
            if (!((secretWord.substr(i,1) >= "a" && secretWord.substr(i,1) <= "z") || (secretWord.substr(i,1) >= "A" && secretWord.substr(i,1) <= "Z")))
            {
                
                return false;
            }
           
        }
        return true;
    }

void representedSecretWord(string secretWord, string &representedWord){
    representedWord = "";
    for (int i = 0; i < secretWord.length(); i++) {
        representedWord += "-";
    }
}

bool letterChecker(string guess, string letters)
{
    for (int i = 0; i < letters.length(); i++) {
        if (guess.substr(0,1) == letters.substr(i,1) )
        {
            return false;
        }
    }
    return true;
}

void updatedFunction(string & hidedWord, string guess, string secretWord){
    for (int k = 0; k < secretWord.length(); k++) {
        if (guess.at(0) == secretWord.at(k)) {
            hidedWord.at(k)= guess.at(0);
        }
        else if (hidedWord.at(k) >= 'a' && hidedWord.at(k) <= 'z'){
            hidedWord.at(k) = hidedWord.at(k) ;
        }
        else
        {
            hidedWord.at(k) = '-';
        }
    
    }
}

void showOutput(int lives , string name2){
    if (lives == 5) {
        cout << "You have no free guess left." << endl;
    }
    else if (lives == 4 || lives == 3){
        cout << "You have lost a leg!" << endl;
    }
    else if (lives == 2 || lives == 1){
        cout << "You have lost an arm!" << endl;
    }
    else if (lives == 0){
        cout << "You have lost a head! GAME OVER!" << endl;
        cout << name2 << " lost the game :(";
    }
}
 
int main() {
    string name1, name2, secretWord;
   
    cout << "Welcome to the HANGMAN GAME" << endl;
    cout << "---------------------------" << endl;
    cout << "Player one, please enter your name: ";
    cin >> name1;
    cout << "Player two, please enter your name: ";
    cin >> name2;
    cout << "OK " << name1 << " and " << name2 << ". Let's start the game!" << endl;
    cout << name1 << ", please input the word you want " << name2 << " to guess: ";
    cin >> secretWord;
    while (wordChecker(secretWord) == false) {
        cout << "Invalid word! Try again."<< endl;
        cout << name1 << ", please input the word you want " << name2 << " to guess: ";
        cin >> secretWord;
        
    }
    string hidedWord, choice, guess, choice1;
    ToLower(secretWord);
    representedSecretWord(secretWord, hidedWord);
    cout << name2 << ", you have 1 free guess, after that you will lose limbs!" << endl;
    cout << "The word is: " << hidedWord << endl;
    string letters = " ";
    int lives = 6;
    while (lives > 0)
    {
        while (choice != "1" && choice != "2")
        {
            cout << name2 << ", do you want to guess the word(1) or guess a letter(2)? ";
            cin >> choice;
            if (choice != "1" && choice != "2")
            {
                cout << "Invalid option!" << endl;
                cout << "The word is: " << hidedWord << endl;
            }
            else if (choice == "1" || choice == "2")
            {
                cout << "Your guess: ";
                cin >> guess;
                ToLower(guess);
            }
        }
        
        if (choice == "1")
        {
            if ((wordChecker(guess) == false))
            {
                cout << "Invalid entry! Try again." << endl;
                cout << "The word is: " << hidedWord << endl;
                choice = "";
            }
            else if (guess != secretWord){
                lives = lives - 1;
                showOutput(lives, name2);
                cout << "The word is: " << hidedWord << endl;
                choice = "";
            }
            else if (guess == secretWord){
                cout << "The word is: " << guess << endl;
                cout << "Congratulations " << name2 << ", you won!" << endl;
                cout << name2 << " won the game!";
                lives = 0;
            }
        }
        else if (choice == "2")
        {
            if (guess.length() > 1 || wordChecker(guess) == false)
            {
                cout << "Invalid entry! Try again." << endl;
                cout << "The word is: " << hidedWord << endl;
                choice = "";
            }
            else if (letterChecker(guess, letters) == false)
            {
                cout << "Guess entered before! Try again." << endl;
                choice = "";
                cout << "The word is: " << hidedWord << endl;
            }
            else if (letterChecker(guess, secretWord) == true)
            {
                lives = lives - 1;
                showOutput(lives, name2);
                if (lives != 0) {
                    cout << "The word is: " << hidedWord << endl;
                }
                letters = letters + guess;
                choice = "";
            }
            else
            {
                updatedFunction(hidedWord, guess, secretWord);
                if(hidedWord == secretWord)
                {
                    cout << "The word is: " << hidedWord << endl;
                    cout << "Congratulations " << name2 << ", you won!" << endl;
                    cout << name2 << " won the game!";
                    lives = 0;
                }
                else
                {
                    cout << "The word is: " << hidedWord << endl;
                    letters = letters + guess;
                    choice = "";
                }
                
            }
        }
}

    return 0;
}
    
