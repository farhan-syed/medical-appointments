//
//  patient.cpp
//  MedicalApplication
//
//  Created by Farhan Syed on 8/3/20.
//  Copyright © 2020 Farhan Syed. All rights reserved.
//

#include "patient.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

class Patient{
public:
    int id;
    string first;
    string last;
    string dob;
    int age;
    int weight;
    char gender;
    string icdIllness;
    string insurance;
    void write();
};

void Patient::write()
{
    ofstream write;
    write.open("patients.txt", fstream::app);
    write << id << " " << first << " " << last << " " << dob << " " << age << " " << weight << " " << gender << " " << icdIllness << " " << insurance << endl;
    write.close();
    
    
    cout << endl;
    cout << "New patient added." << endl;
    cout << "First Name: " << first << endl;
    cout << "Last Name: " << last << endl;
    cout << "DOB (mm/dd/yy): " << dob << endl;
    cout << "Age: " << age << endl;
    cout << "Weight (lbs): " << weight << endl;
    cout << "Gender (m/f): " << gender << endl;
    cout << "ICD Code: " << icdIllness << endl;
    cout << "Insurance: " << insurance << endl;
    cout << endl;
    
}

void install(){
    
    ifstream patients("patients.txt");
    
    int count = 0;
    int  *countPointer;

    countPointer = &count;
    
    string line;
    
    while (getline(patients, line))
        *countPointer = count + 1;
    
    Patient patient;
    char choice = 'y';
    int i = 0;
    do{
        
        
        cout << "Please enter patient information: \n";
        patient.id = *countPointer + 1;
        cout << "First Name: ";
        cin >> patient.first;
        cout << "Last Name: ";
        cin >> patient.last;
        cout << "DOB (mm/dd/yy): ";
        cin >> patient.dob;
        cout << "Age: ";
        cin >> patient.age;
        cout << "Weight (lbs): ";
        cin >> patient.weight;
        cout << "Gender (m/f): ";
        cin >> patient.gender;
        cout << "ICD Illness: ";
        cin >> patient.icdIllness;
        cout << "Has Insurance (ppo/hmo/none): ";
        cin >> patient.insurance;
        
        
        patient.write();
        i++;
        cout << "Enter information for a new patient?(y/n)";
        cin >> choice;
    } while(choice!='n');

}
