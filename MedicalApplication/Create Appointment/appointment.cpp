//
//  appointment.cpp
//  MedicalApplication
//
//  Created by Farhan Syed on 8/4/20.
//  Copyright © 2020 Farhan Syed. All rights reserved.
//

#include "patient.hpp"
#include <iostream>
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


void selectPatient(){
    
    vector<string> patient;
    int patientSelection;
    vector<string> doctor;
    int doctorSelection;
    int timeSelection;
    
    ifstream patients("patients.txt");
    
    string id, first, last, dob, age, weight, gender, illness, insurance;
    
    while(patients >> id >> first >> last >> dob >> age >> weight >> gender >> illness >> insurance){
        patient.push_back(first + " " + last);
    }
    
    cout << "Select a patient to make an appointment for: " << endl;

    for (int i=0; i<patient.size(); i++) {
        cout << i + 1  << ". " << patient[i] << endl;
       }
    cin >> patientSelection;
    
    patients.close();
    
    ifstream doctors("doctors.txt");
    
    string doctorId, doctorName;
    
    while (doctors >> doctorId >> doctorName){
        doctor.push_back(doctorName);
    }
    
    cout << endl << "Select a doctor: " << endl;
    
    for (int i=0; i<doctor.size(); i++) {
        cout << i + 1  << ". " << "Dr. " << doctor[i] << endl;
    }
    
    cin >> doctorSelection;
    
    doctors.close();
    
    cout << "Select a time: " << endl;
    
    
    cout << endl <<
    "1. 8:00  am  - 9:00  am \n" <<
    "2. 9:00  am  - 10:00 am \n" <<
    "3. 10:00 am  - 11:00 am \n" <<
    "4. 11:00 am  - 12:00 pm \n" <<
    "5. 12:00 pm  - 1:00  pm \n" <<
    "6. 1:00  pm  - 2:00  pm \n" <<
    "7. 2:00  pm  - 3:00  pm \n" <<
    "8. 3:00  pm  - 4:00  pm \n" <<
    "9. 4:00  pm  - 5:00  pm \n" <<
    "10. 5:00  pm  - 6:00  pm \n";

    
    string times[10] = {
        "8 am 9 am",
        "9 am 10 am",
        "10 am 11 am",
        "11 am 12 pm",
        "12 pm 1 pm",
        "1 pm 2 pm",
        "2 pm 3 pm",
        "3 pm 4 pm",
        "4 pm 5 pm",
        "5 pm 6 pm"
    };
    
    cin >> timeSelection;
    
    ofstream write;
    write.open("appointments.txt", fstream::app);
    write << patient[patientSelection - 1] << " " << doctor[doctorSelection - 1] << " " << times[timeSelection - 1] << endl;
    write.close();
    
    cout << endl << "Appointment was created for " << patient[patientSelection - 1] << " with Dr. " << doctor[doctorSelection - 1] << endl;
    
}


void createAppointment(){
    
    selectPatient();
    
}
