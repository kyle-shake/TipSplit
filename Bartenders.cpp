//File: Bartenders.cpp
//Author: Kyle Shake
//Date Created: 10/17/16
//Date Last Modified: 10/17/16



#include "Bartenders.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;


//Initial Constructor
BartenderList::BartenderList(){
    head = NULL;
}

//Copy Constructor
BartenderList::BartenderList(const BartenderList& src){
    head = NULL;
    Bartender* BTcur;
    BTcur = src.head;
    
    Bartender* prevBT = NULL;
    while (BTcur != NULL){
        Bartender* newBT;
        newBT = new Bartender;
        if (newBT == NULL) //dynamic allocation failed
        	{cout << "Memory allocation error!" << endl;
        	exit(1);}
        newBT->name = BTcur->name;
        newBT->hours = BTcur->hours;
        newBT->tips = BTcur->tips;
      
        if (prevBT == NULL)	head = newBT;
        else	prevBT->next = newBT;
    
        newBT->next = NULL;
  
        prevBT = newBT;
        BTcur = BTcur->next;
    }
}

//Adding a bartender into the front of the Linked List
bool BartenderList::insertBartender(string BTname, float BThours, int BTtips){
    Bartender* newBT = new Bartender;
    if (newBT == NULL) //dynamic allocation failed
        { return false; }

    newBT->name = BTname;
    newBT->hours = BThours;
    newBT->tips = BTtips;
    newBT->next = head;

    head = newBT;

    return true;
}

//Simple UI function to get name of bartender
string BartenderList::get_name(){

    string BTname;
    cout << "What is this bartender's name?" << endl;
    cin >> BTname;
    return BTname;

}

//Simple UI function to get number of hours
bool BartenderList::get_hours(){
    float BThours;
    cout << "How many hours did this bartender work?" << endl;
    cin >> BThours;
    return BThours;
}


//Calculating tips for each bartender
void BartenderList::tip_calc(int &totaltips){
   
    percent_off_top(totaltips); //Must take the percentage and flat tip outs off the top
   
    float totalhours;
    Bartender* BTcur;
    BTcur = head;

    while(BTcur != NULL){
        totalhours += BTcur->hours;  //Accumulating total hours
        BTcur = BTcur->next;
    }

    float perhourwage = totaltips/totalhours; //Calculating hourly wage 
    
    BTcur = head;
    while(BTcur != NULL){
        BTcur->tips = int(BTcur->hours * perhourwage); //Multiplying hourly wage by number of
        BTcur = BTcur->next;
    }                                                   // hours and rounding by typecase


/* ****README:  Do I want to put some code that double checks the calculations and returns the boolean if calculations were done correctly or incorrectly? Something to think about****  */


}


//If you need to pay someone a percentage of total tips
bool BartenderList::percent_off_top(int &totaltips){
    string userinput;
    bool keepgoing;

    cout << "Do you have to pay anyone based on total tips? (\'Y\' or \'N\')" << endl; //Prompt user if need to pay
                                                                     //someone percentage or flat rate off the top
    do{
    cin >> userinput;    
    if (userinput == "Y" || userinput == "y"){
         cout << "Do you pay a percentage or flat rate?(\'P\' for percentage or \'F\' for flat rate)" << endl;
         cin >> userinput;
         if (userinput == "P" || userinput == "p"){  //Calculating tipout based on percentage of total tips
             cout << "What is their percentage? (Do not include % symbol)" << endl;
             float percentage;
             cin >> percentage;
             if (percentage > 1) 	percentage = percentage/100; //if user inputs in percentage form
             int ptips =int(percentage * totaltips); //Calculate percentage tip and typecast to int for subtraction
             cout << "You owe them $" << ptips << endl;
             totaltips -= ptips; // update totaltips
             cout << "Tip pool total is now $" << totaltips << endl;
         }
         else if (userinput == "F" || userinput == "f"){ //Calculating tipout based on flat rate
             cout << "What is their flat fee? (Do not include $ symbol)" << endl;
             int flatfee;
             cin >> flatfee;
             totaltips -= flatfee; // update totaltips
             cout << "Tip pool total is now $" << totaltips << endl;
         }
         cout << "Do you pay anyone else based on total tips? (\'Y\' or \'N\')" << endl; //Reprompt user for 
     } 									//additional tipouts
     else	keepgoing = false;
     }while(keepgoing);

}

//Printing the Bartender Linked List
void BartenderList::print_tips(){
    Bartender* BTcur = head;
    
    while (BTcur != NULL){   //While there are more elements in the linked list
        cout << "*" << BTcur->name << setw(15) << BTcur->hours << "hours" << setw(15) << "$" << BTcur->tips << setw(115) << endl;
        BTcur = BTcur->next;
    }
    cout << endl;
}


//Finding a bartender by name

bool BartenderList::find_BT(string BTname, Bartender* &BT_to_del_ptr, Bartender* &prevBT){
   
    prevBT = NULL; BT_to_del_ptr = NULL;
    Bartender* BTcur = head;
    
    while(BTcur != NULL){
        if (BTcur->name == BTname)	break;
        prevBT = BTcur;
        BTcur = BTcur->next; 
    }
  
    if (BTcur == NULL)	return false; //List is empty or name was not found
    else{                     //found a match
        BT_to_del_ptr = BTcur;
        return true;
    }
}

//Using find_BT function to find bartender based on name, reorganizing Bartender Linked List and then deleting 
// the pointer to that particular bartender
bool BartenderList::delete_BT(string BTname, int &totaltips){

    Bartender *prevBT, *BT_del_ptr;
    prevBT = NULL; BT_del_ptr = NULL;

    if (!find_BT(BTname, BT_del_ptr, prevBT))	return false; //Bartender name was not found, unable to delete
    
    cout << "Are you sure you wish to delete " << BT_del_ptr->name << "\? (\'Y\' or \'N\')" << endl;
    string userinput;
    cin >> userinput;

    if(userinput == "Y" || userinput == "y"){
        if (prevBT != NULL){			
             prevBT->next = BT_del_ptr->next; //Reassign previous Bartender's pointer to the one
        }					//after the Bartender to be deleted

        else	head = BT_del_ptr->next; // The first node is the one to be deleted
        
 
/* Should we recalculate money here? Subtract the hours? TBD */
 
        delete BT_del_ptr;
        return true;
    }

}       

BartenderList::~BartenderList(){
    Bartender *BTcur, *delptr;

    BTcur = head;

    while(BTcur != NULL){
        delptr = BTcur;
        BTcur = BTcur->next;
        delete delptr;
    }
   
    head = NULL;
}





   
