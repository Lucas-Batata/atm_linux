#ifndef DISPENSER_H
#define DISPENSER_H

#include <list>
#include <iterator>
#include <string>
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
        std::list<notesValues> mDebitNotes;
        bool debitNote(notesValues);
        bool releaseNotes();
        bool populateSystemNotes(std::string jsonString);

    public:
        Dispenser();
        void addNotes(int quantity, int value);
        std::list<int> getAvailableNotes();
        int getTotalBalance();
        std::string getAvailableNotesString();
};


#endif