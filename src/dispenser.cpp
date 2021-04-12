#include "dispenser.h"

Dispenser::Dispenser()
{
    char fileName[] = "../config/notes.json";

    if (!std::ifstream(fileName))
    {
        std::ofstream file(fileName);
        if (!file)
        {
            //Arquivo nao pôde ser criado.
        }
        else
        {
            file << "{\"noteValue\":\"0\",\"noteQuantity\":0}";
            file.close();
        }
    }
    else
    {
        std::fstream my_file;
        my_file.open(fileName, std::ios::in);
        if (!my_file) 
        {
            std::cout << "No such file";
        }
        else 
        {
            std::string str;
            char ch;

            while (1) 
            {
                my_file >> ch;
                if (my_file.eof())
                {
                    break;
                }
                str += ch;                 
            }
            bool condition = populateSystemNotes(str);
        }
        my_file.close();
    }
}

std::list<int> Dispenser::getAvailableNotes()
{
    std::list<int> availableNotes;
    std::list<notesValues>::iterator it;

    for(it = mNotesValues.begin(); it != mNotesValues.end(); ++it)
    {
        if((*it).quantity > 0)
        {
            availableNotes.push_back((*it).value);
        }
    }
    return availableNotes;
}

bool Dispenser::debitNote(notesValues nv)
{
    if(true)
    {
        return true;
    }
}

bool Dispenser::releaseNotes()
{
    if(true)
    {
        return true;
    }
}

int Dispenser::getTotalBalance()
{
    int total = 0;

    std::list<notesValues>::iterator it;
    for(it = mNotesValues.begin(); it != mNotesValues.end(); ++it)
    {
        total += ((*it).value * (*it).quantity);
    }

    return total;
}

void Dispenser::addNotes(int quantity, int value)
{
    notesValues n;
    n.quantity = quantity;
    n.value = value;
    mNotesValues.push_back(n);
}

std::string Dispenser::getAvailableNotesString()
{
    std::string str;
    std::list<notesValues>::iterator it;

    for(it = mNotesValues.begin(); it != mNotesValues.end(); ++it)
    {
        if((*it).quantity > 0)
        {
            str += std::to_string((*it).value);
            str += " | ";
        }
    }
    return str;
}

bool Dispenser::populateSystemNotes(std::string jsonString)
{
    const char* json = jsonString.c_str();
    rapidjson::Document d;
    d.Parse(json);
    // rapidjson::Value& s = d["notes"];
    // std::cout <<  << std::endl;

    rapidjson::Value& s = d["note2"];
    auto b = s.FindMember("noteValue");
    auto c = s.FindMember("noteQuantity");

    if (b != s.MemberEnd())
    {   
        addNotes(c->value.GetInt(), b->value.GetInt());
    }

    s = d["note5"];
    b = s.FindMember("noteValue");
    c = s.FindMember("noteQuantity");

    if (b != s.MemberEnd())
    {   
        addNotes(c->value.GetInt(), b->value.GetInt());
    }

    s = d["note10"];
    b = s.FindMember("noteValue");
    c = s.FindMember("noteQuantity");

    if (b != s.MemberEnd())
    {   
        addNotes(c->value.GetInt(), b->value.GetInt());
    }

    s = d["note20"];
    b = s.FindMember("noteValue");
    c = s.FindMember("noteQuantity");

    if (b != s.MemberEnd())
    {   
        addNotes(c->value.GetInt(), b->value.GetInt());
    }

    s = d["note50"];
    b = s.FindMember("noteValue");
    c = s.FindMember("noteQuantity");

    if (b != s.MemberEnd())
    {   
        addNotes(c->value.GetInt(), b->value.GetInt());
    }

    s = d["note100"];
    b = s.FindMember("noteValue");
    c = s.FindMember("noteQuantity");

    if (b != s.MemberEnd())
    {   
        addNotes(c->value.GetInt(), b->value.GetInt());
    }

    s = d["note200"];
    b = s.FindMember("noteValue");
    c = s.FindMember("noteQuantity");

    if (b != s.MemberEnd())
    {   
        addNotes(c->value.GetInt(), b->value.GetInt());
    }

    return true;

    //auto a = s.GetInt();
    //std::cout << json << std::endl;
}