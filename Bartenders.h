//File: Bartenders.h
//Author: Kyle Shake
//Date Created: 10/17/16
//Date Last Modified: 10/17/16


#ifndef BARTENDERS_H
#define BARTENDERS_H
#include <string>

using namespace std;

struct Bartender
{
    string name; 
    float hours;
    int tips;
    Bartender* next;
};



class BartenderList
{
    private:
        Bartender* head;
    public:
        BartenderList();
        BartenderList(const BartenderList& src);
        bool insertBartender(string, float, int);
        string get_name();
        bool get_hours();
        void tip_calc(int&);
        bool percent_off_top(int&);
        void print_tips();
        bool find_BT(string, Bartender*&, Bartender*&);
        bool delete_BT(string, int&);
        ~BartenderList();
};

#endif
