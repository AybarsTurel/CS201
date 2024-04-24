


//Sevki Aybars Turel 28238

#include <iostream>
#include <string>



using namespace std;

void getInput(string exerciseType, double &min, int &reps, double &liftedWeight1) {
    
    if (exerciseType == "Lunges" || exerciseType == "Push Ups" || exerciseType == "Pull Ups")
    {
        cout << exerciseType << ": ";
        cin >> min >> reps;
        liftedWeight1 = 1.0;
        
    }
    else if (exerciseType == "Weight Lifting")
    {
        cout << exerciseType << ": ";
        cin >> min >> reps >> liftedWeight1;
        
    }
    
    
}


bool inputCheck(double weight, double min1, int reps1, double min2, int reps2, double min3, int reps3, double liftedWeight1, double min4, int reps4)
{
    
    
    if (weight < 30)
    {
        cout << "Weight out of range!" << endl;
        return false;
    }
    else if ((liftedWeight1 <= 0 || liftedWeight1 > 35))
    {
        cout << "Lifted weight out of range!" << endl;
        return false;
    }
    else if (((reps1 < 0 || reps1 > 50) || (reps2 < 0 || reps2 > 50)  || (reps3 < 0 || reps3 > 50) || (reps4 < 0 || reps4 > 50)))
    {
        cout << "Reps out of range!" << endl;
        return false;
    }
    else if ((min1 < 0 || min1 > 2000 ) || (min2 < 0 || min2 > 2000)  || (min3 < 0 || min3 > 2000) || (min4 < 0 || min4 > 2000))
    {
        cout << "Minute out of range!" << endl;
        return false;
    }
    else {
        return true;
    }
}
    
void calculateMET(string exercise, int reps, double &met){
    
    if (exercise == "Lunges")
    {
        if (reps < 15)
        {
            met = 3;
        }
        else if (reps >= 15 && reps < 30)
        {
            met = 6.5;
        }
        else if (reps >= 30)
        {
            met = 10.5;
        }
    }
    else if (exercise == "Push Ups")
    {
        if (reps < 15)
        {
            met = 4;
        }
        else if (reps >= 15)
        {
            met = 7.5;
        }
    }
    else if (exercise == "Pull Ups")
    {
        if (reps < 25)
        {
            met = 5;
        }
        else if (reps >= 25)
        {
            met = 9;
        }
    }
}

void calculateWeightLiftMET(int reps, double liftedWeight1, double &met){
    if (liftedWeight1 < 5) {
        if (reps < 20)
        {
            met = 3;
        }
        else if (reps >= 20 && reps < 40)
        {
            met = 5.5;
        }
        else if (reps >= 40)
        {
            met = 10;
        }
    }
    else if (liftedWeight1 >= 5 && liftedWeight1 < 15)
    {
        if (reps < 20)
        {
            met = 4;
        }
        else if (reps >= 20 && reps < 40)
        {
            met = 7.5;
        }
        else if (reps >= 40)
        {
            met = 12;
        }
    }
    else if (liftedWeight1 >= 15)
    {
        if (reps < 20)
        {
            met = 5;
        }
        else if (reps >= 20 && reps < 40)
        {
            met = 9;
        }
        else if (reps >= 40)
        {
            met = 13.5;
            
        }
    }
}

void displayResult(double difference, double total, double weight, double lungeMET, double pushupMET, double pullupMET, double weightliftMET, double lungeCalorie, double pushupCalorie, double pullupCalorie, double weightliftCalorie){
    cout << "From lunges, you burned " << lungeCalorie << " calories." << endl;
    cout << "From push ups, you burned " << pushupCalorie << " calories." << endl;
    cout << "From pull ups, you burned " << pullupCalorie << " calories." << endl;
    cout << "From weight lifting, you burned " << weightliftCalorie << " calories." << endl;
    cout << "You burned " << total << " calories." << endl;
    cout << endl;
    
    if (difference > 0) {
        
        cout << "You have surpassed your goal! You can eat something worth " << difference << " calories :)" << endl;
    }
    else if ( difference == 0){
        
        cout << "Congratulations! You have reached your goal!" << endl;
        
        
    }
    else if (difference < 0) {
        
        cout << "You did not reach your goal by " << (-1 * difference) << " calories."<< endl;
        cout << "You need to do lunges " << (200 * (-1 * difference)/(weight * 3.5 * lungeMET)) << " minutes more to reach your goal or," << endl;
        cout << "You need to do push ups " << (200 * (-1 * difference) /(weight * 3.5 * pushupMET)) << " minutes more to reach your goal or," << endl;
        cout << "You need to do pull ups " << (200 * (-1 * difference) /(weight * 3.5 * pullupMET)) << " minutes more to reach your goal or," << endl;
        cout << "You need to do weight lifting " << (200 * (-1 * difference) /(weight * 3.5 * weightliftMET)) << " minutes more to reach your goal." << endl;
    }
    
    
    
}


void computeResults(double weight, double goal, int repsLunge, int repsPushUp, int repsPullUp, int repsWeightLift, double minLunge, double minPushUp, double minPullUp, double minWeightLift, double liftedWeight){
    
    double lungeMET, pushupMET, pullupMET, weightliftMET,lungeCalorie, pushupCalorie, pullupCalorie, weightliftCalorie, difference, total;
    
    calculateMET("Lunges", repsLunge, lungeMET);
    lungeCalorie = minLunge * (lungeMET * 3.5 * weight)/200 ;
    calculateMET("Push Ups", repsPushUp, pushupMET);
    pushupCalorie = minPushUp * (pushupMET * 3.5 * weight)/200 ;
    calculateMET("Pull Ups", repsPullUp, pullupMET);
    pullupCalorie = minPullUp * (pullupMET * 3.5 * weight)/200 ;
    calculateWeightLiftMET(repsWeightLift, liftedWeight, weightliftMET);
    weightliftCalorie = minWeightLift * (weightliftMET * 3.5 * weight)/200 ;
    total = lungeCalorie + pushupCalorie + pullupCalorie + weightliftCalorie;
    difference = total - goal;
    displayResult(difference, total, weight, lungeMET, pushupMET, pullupMET, weightliftMET, lungeCalorie, pushupCalorie, pullupCalorie, weightliftCalorie);
}



    int main() {
    string name;
    double weight, minLunge,  minPushUp,  minPullUp,  liftedWeight, minWeightLift, goal, liftedWeight1, liftedWeight2, liftedWeight3;
    int  repsLunge, repsPushUp, repsPullUp, repsWeightLift;
    
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Welcome " << name << ", please enter your weight(kg): ";
    cin >> weight;
    cout << name << ", please enter minutes and repetitions in a week for the activities below." << endl;
    getInput("Lunges", minLunge, repsLunge, liftedWeight1);
    getInput("Push Ups", minPushUp, repsPushUp, liftedWeight2);
    getInput("Pull Ups", minPullUp, repsPullUp, liftedWeight3);
    cout << name << ", please enter minutes, repetitions and lifted weight in a week for the activities below."<< endl;
    getInput("Weight Lifting", minWeightLift, repsWeightLift, liftedWeight);
    cout << name << ", please enter your weekly calorie burn goal: ";
    cin >> goal;
    
    if (inputCheck(weight, minLunge, repsLunge, minPushUp, repsPushUp, minPullUp, repsPullUp, liftedWeight, minWeightLift, repsWeightLift)){
        computeResults(weight, goal, repsLunge, repsPushUp, repsPullUp, repsWeightLift, minLunge, minPushUp, minPullUp, minWeightLift, liftedWeight);
        
    }
    
    
    
    return 0;
}
    
