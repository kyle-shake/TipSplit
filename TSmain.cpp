//File: TSmain.cpp
//Author: Kyle Shake
//Date Created: 10/17/16
//Date Last Modified: 10/17/16

/* README: 

10/17 - Program will compile; however, not complete
      - If entering a name for bartender with space, program gets stuck in an infinite loop
      - Would like to find way to clear screen after starting program, entering name and hours,
        returning to main menu, etc.
      - Unable to determine if calculations work correctly
*/




#include "Bartenders.h"
#include <iostream>
#include <string>




using namespace std;

int main(){
    
    cout << "\tTTTTTTTTTTTTTTT\t" << "IIIIIIIIIIIIIII\t" << "PPPPPPPPPPPPPPP" << endl;
    cout << "\tTTTTTTTTTTTTTTT\t" << "IIIIIIIIIIIIIII\t" << "PPPPPPPPPPPPPPP" << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPP      PPPP" << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPP      PPPP" << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPP      PPPP" << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPP      PPPP" << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPPPPPPPPPPPP" << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPPPPPPPPPPPP" << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPP          " << endl;
    cout << "\t     TTTTT     \t" << "     IIIII     \t" << "PPPPP          " << endl;
    cout << "\t     TTTTT     \t" << "IIIIIIIIIIIIIII\t" << "PPPPP          " << endl;
    cout << "\t     TTTTT     \t" << "IIIIIIIIIIIIIII\t" << "PPPPP          " << endl;
    cout << endl << endl << endl << endl << endl;



    cout << "ssssssssss\t" << "          \t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "ssssssssss\t" << "          \t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "ssss      \t" << "          \t" << "  llll    \t" << "          \t" << "tttttttttt" << endl;
    cout << "ssss      \t" << "          \t" << "  llll    \t" << "          \t" << "tttttttttt" << endl;
    cout << "ssssssssss\t" << "pppppppppp\t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "ssssssssss\t" << "pppppppppp\t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "      ssss\t" << "pppp  pppp\t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "      ssss\t" << "pppp  pppp\t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "ssssssssss\t" << "pppppppppp\t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "ssssssssss\t" << "pppppppppp\t" << "  llll    \t" << "   iiii   \t" << "   tttt   " << endl;
    cout << "          \t" << "pppp      \t" << "          \t" << "          \t" << "          " << endl;
    cout << "          \t" << "pppp      \t" << "          \t" << "          \t" << "          " << endl;
    cout << "          \t" << "pppp      \t" << "          \t" << "          \t" << "          " << endl;
    cout << "          \t" << "pppp      \t" << "          \t" << "          \t" << "          " << endl;

    cout << endl << endl << "Welcome to TipSplit!" << endl;

    string userinput;
    BartenderList Bartender_List;
    int originaltips = 0;
    int totaltips = 0;
    do{
        cout << "Please choose from the following menu items:" <<endl;
        cout << "1) Add a bartender" << endl;
        cout << "2) Add/change total amount of tips" << endl;
        cout << "3) Calculate tips" << endl;
        cout << "4) Reprint tips" << endl;
        cout << "5) Delete bartender" << endl;
        cout << "6) Find bartender" << endl;
        cout << "Q to quit TipSplit" << endl;
        cout << "Menu Option: ";
        cin >> userinput;
        if (userinput == "1"){
            string BTname = Bartender_List.get_name();
            float BThours = Bartender_List.get_hours();
            int tips = 0;
            Bartender_List.insertBartender(BTname, BThours, tips);
        }
        else if(userinput == "2"){
            cout << "What is the total amount of tips? (Before tipping anyone out)" << endl;
            cin >> originaltips;
            string isthatcorrect;
            cout << "Is $" << originaltips << " correct? (\'Y\' for yes, \'N\' for no)" << endl;
            cin >> isthatcorrect;
            while (isthatcorrect == "N" || isthatcorrect == "n"){
                cout << "What is the correct amount of tips? (Before tipping anyone out)" << endl;
                cin >> originaltips;
                cout << "Is $" << originaltips << " correct now? (\'Y\' for yes, \'N\' for no)" << endl;

                cin >> isthatcorrect;
            }
           totaltips = originaltips;
        }
        else if (userinput == "3"){
            Bartender_List.tip_calc(totaltips);
            Bartender_List.print_tips();
        }
        else if (userinput == "4"){
            Bartender_List.print_tips();
        }
        else if (userinput == "5"){
            string nametodel;
            cout << "Who do you need to delete from the list?" << endl;
            cin >> nametodel;
            bool deletionconfirmed = Bartender_List.delete_BT(nametodel, totaltips);
            
            if (deletionconfirmed){
                cout << nametodel << " was found and deleted." << endl;
                cout << "Returning to Main Menu" << endl;
            }
            else {
                cout << nametodel << " was not found in the list." << endl;
            }
       }
       else if (userinput == "6"){

           /* string nametosearch;
            Bartender *BTptr, *prevBT;

            cout << "What name are you searching for?" << endl;
            cin >> nametosearch;

            bool BTfound = Bartender_List.find_BT(nametosearch, BTPtr, prevBT);

            if (BTfound){
                cout << nametosearch << " found." << endl;
                cout << "What do you want to do with " << nametosearch << "\?" << endl;
                string userselects;
                cout << "1) Replace name" << endl;
                cout << "2) Replace hours" << endl;
                cout << "3) Print tips and hours" << endl;
                cin >> userselects;
                if (userselects == "1"){ */
            cout << "Function not yet ready." << endl;
       }

/* README:
10/17 - Created rough draft of most of program. Still need to finish find and replace function.
      - Desire to add recalculations after delete/replace
*/
                    

    }while(userinput != "Q" && userinput != "q");


return 0;

}
