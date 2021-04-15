#ifndef DISPENSER_H
#define DISPENSER_H

#include <algorithm>
#include <list>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

typedef struct notes
{
    int value;
    int quantity;
}notesValues;


class Dispenser
{
    private:
        std::list<notesValues> mNotesValues;
        bool debitNote(notesValues nv, std::list<notesValues>& lnv );
        bool populateSystemNotes(std::string jsonString);
        std::string str;
        bool releaseNotes(int val, bool subtract, std::list<notesValues> *pList);
        void addNotes(int quantity, int value);
        int getTotalBalance(std::list<notesValues> localList);
    public:
        Dispenser();
        std::list<int> getAvailableNotes();
        std::string getAvailableNotesString();
        int getTotalBalance();
        /*Se subtract true, faz o debito das notas. Se não só retorna se o valor mais próximo do solicitado.*/
        int withdraw(int valueWithdraw, bool subtract); 
};


#endif