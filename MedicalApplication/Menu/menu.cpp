//
//  menu.cpp
//  MedicalApplication
//
//  Created by Farhan Syed on 8/4/20.
//  Copyright © 2020 Farhan Syed. All rights reserved.
//

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

#include "menu.hpp"
#include "patient.hpp"
#include "appointment.hpp"
#include "showAppointment.hpp"

using namespace std;


void showMenu(){
    
    int selection;

    do {

        cout<< endl << "|--------------------------------------|";
        cout<< endl << "|        1 - Create New Patient        |";
        cout<< endl << "|--------------------------------------|";
        cout<< endl << "|        2 - Create Appointment        |";
        cout<< endl << "|--------------------------------------|";
        cout<< endl << "|        3 - Show Appointments         |";
        cout<< endl << "|--------------------------------------|";
        cout<< endl << "|               4 - Exit               |";
        cout<< endl << "|--------------------------------------|";
        cout << endl;
        cout<< endl << "Enter selection:  ";
        cin>>selection;
        
        cout << endl;
        
        switch(selection)

        {


            case 1 : install();
        break;
            case 2 : createAppointment();
        break;
            case 3 : displayAppointment();
        break;
            case 4 :{cout<<"\n Exit \n";}
        break;
        default : cout<<"\n Invalid selection";

        }

        cout<<"\n";
        
    } while (selection != 4);
}


