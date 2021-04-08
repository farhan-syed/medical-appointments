//
//  showAppointment.cpp
//  MedicalApplication
//
//  Created by Farhan Syed on 8/4/20.
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

#include "showAppointment.hpp"


class Person {
public:
    string first;
    string last;
    virtual void print()
    {
        cout << first + last << endl;
    }
};

class Appointment: public Person {
public:
    string doctor;
    string startTime;
    string endTime;
    void print()
    {
        cout << first + last << endl;
    }
};


void displayAppointment(){
    
    Person* basePtr;
    Appointment d;
    basePtr = &d;
    
    vector<Appointment> appointment;
    
    ifstream appointmentFile("appointments.txt");
    
    string pFirst, pLast, doctor, startTime, meridiem1, endTime, meridiem2;
    
    int count = 0;
    
    while(appointmentFile >> pFirst >> pLast >> doctor >> startTime >> meridiem1 >> endTime >> meridiem2){
        Appointment newAppointment;
        newAppointment.first = pFirst;
        newAppointment.last = pLast;
        newAppointment.doctor = doctor;
        newAppointment.startTime = startTime + meridiem1;
        newAppointment.endTime = endTime + meridiem2;
        appointment.push_back(newAppointment);
        count++;
    }
    
    for (int i = 0; i < count; ++i){
        
        cout << "Patient Appointment" << endl;
        cout << "Name: " + appointment[i].first + " " + appointment[i].last << endl;
        cout << "Doctor: Dr. " + appointment[i].doctor << endl;
        cout << "Start Time: " + appointment[i].startTime << endl;
        cout << "End Time: " + appointment[i].endTime << endl;
        
        cout << endl;
        
    }
    
}
