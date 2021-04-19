#include "../include/dispenser.h"

Dispenser::Dispenser()
{
    char fileName[] = "../config/notes.json";

    /*Cria o arquivo .json caso ele não exista*/
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
        /*Tenta acessar o arquivo caso ele exista e salva o  conteudo em uma string*/
        std::fstream my_file;
        my_file.open(fileName, std::ios::in);
        if (!my_file) 
        {
            std::cout << "No such file";
        }
        else 
        {
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
            /*Passa o conteudo do arquivo .json para popular a estrutura de dados lista*/
            /*a função retorna true caso nao ocorreu uma exceção*/
            bool condition = populateSystemNotes(str);
        }
        my_file.close();
    }
}

/*Retorna uma lista de notas disponiveis*/
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

/*Decrementa unidades da nota na lista fake, ou da lista oficial*/
bool Dispenser::debitNote(notesValues nv, std::list<notesValues>& lnv )
{
    std::list<notesValues>::iterator it;

    for(it = lnv.begin(); it != lnv.end(); ++it)
    {
        if((*it).value == nv.value)
        {
            if((*it).quantity > 0)
            {
                (*it).quantity -= 1;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

bool Dispenser::releaseNotes(int val, bool subtract, std::list<notesValues>* pList)
{
    char fileName[] = "../config/notes.json";
    bool removeOk = false;

    notesValues n;
    n.quantity = 1;
    n.value = val;

    /*Tentativa de remover unidades da nota desejada*/
    if(debitNote(n, *pList))
    {
        /*Se for para realmente liberar as notas o json é modificado*/
        if(subtract)
        {
            /*Acessa o json para decrementá-lo*/
            if (std::ifstream(fileName))
            {
                const char* json = str.c_str();
                rapidjson::Document d;
                d.Parse(json);

                std::string valString = "note" + std::to_string(val); 
                const char* find = valString.c_str(); 
                rapidjson::Value& s = d[find];

                auto c = s.FindMember("noteQuantity");

                if (c != s.MemberEnd())
                {   
                    std::ofstream file(fileName);
                    c->value.SetInt(c->value.GetInt() - 1);
                    
                    // Stringify the DOM
                    rapidjson::StringBuffer buffer;
                    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
                    d.Accept(writer);

                    file << buffer.GetString();
                    str = buffer.GetString();
                    file.close();
                    removeOk = true;
                }
            }
        }
        else
        {
            removeOk = true;
        }
    }

    return removeOk;
}

/*retorna o saldo total do caixa*/
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

/*retorna o saldo total do caixa de uma lista específica*/
int Dispenser::getTotalBalance(std::list<notesValues> localList)
{
    int total = 0;

    std::list<notesValues>::iterator it;
    for(it = localList.begin(); it != localList.end(); ++it)
    {
        total += ((*it).value * (*it).quantity);
    }

    return total;
}

/*Usado para adicionar notas na lista*/
/*Usado somente pelo método que lê o json*/
void Dispenser::addNotes(int quantity, int value)
{
    notesValues n;
    n.quantity = quantity;
    n.value = value;
    mNotesValues.push_back(n);
}

/*Retorna uma string formatada das notas disponíveis*/
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

/*Adiciona notas na Lista com base no json*/
bool Dispenser::populateSystemNotes(std::string jsonString)
{
    const char* json = jsonString.c_str();
    rapidjson::Document d;
    d.Parse(json);
    
    std::string notep = "";
    const char* notec;
    std::vector<int> vectorp = {2,5,10,20,50,100,200};

    for (int i = 0; i < vectorp.size(); i++)
    {
        notep = "note" + std::to_string(vectorp[i]);
        notec = notep.c_str();
        rapidjson::Value& s = d[notec];
        auto b = s.FindMember("noteValue");
        auto c = s.FindMember("noteQuantity");

        if (b != s.MemberEnd())
        {   
            addNotes(c->value.GetInt(), b->value.GetInt());
        }
    }
    
    return true;
}

/*Método para saque. Recebe o valor de saque e um bool se é uma transação real ou não*/
/*Retorna o valor liberado. Ou valor total do banco. Ou valor mais próximo do solicitado disponível, só que negativo*/
int Dispenser::withdraw(int valueWithdraw, bool subtract)
{
    std::list<notesValues>* pList;

    /*Se for uma consulta para realmente liberar as notas a lista real é passada como referencia*/
    if(subtract)
    {
        pList = &mNotesValues;
    }
    else
    {   
        /*Se não for uma consulta para realmente liberar as notas é criado uma lista com uma cópia da original*/
        pList = new std::list<notesValues>(mNotesValues);
    }

    int originalValue = getTotalBalance();
    int withdraw = valueWithdraw;

    /*Se valor solicitado for maior que o disponível, retorna valor total disponível*/
    if(valueWithdraw > originalValue)
    {
        return originalValue;
    }

    int counter = 0;
    std::list<int> availableNotes = getAvailableNotes();
    std::reverse(availableNotes.begin(), availableNotes.end());
    std::list<int>::iterator it;

    int unityNumber = valueWithdraw % 10;

    /*Se o número for uma exceção aos números que podem ser subtraidos do maior para o menor, eu tento subtrair tres notas de R$6
        para o número ser facilmente subtraido na próxima etapa*/

    if((unityNumber == 3) or (unityNumber == 6)  or (unityNumber == 8) or (unityNumber == 3))
    {
        for (int i = 0; i < 3; i++)
        {
            if(releaseNotes(2, subtract, pList))
            {
                valueWithdraw -= 2;
                if(valueWithdraw < 1)
                {
                    return withdraw;
                }
            }
            else
            {
                break;
            }
        }
    }

    
    for(it = availableNotes.begin(); it != availableNotes.end(); ++it)
    {
        while(valueWithdraw >= *it)
        {
            if(releaseNotes(*it, subtract, pList))
            {
                valueWithdraw -= *it;
                if(valueWithdraw < 1)
                {   
                    /*Retorna o valor solicitado, se o saque saiu como o esperado*/
                    return withdraw;
                }
            }
            else
            {
                break;
            }
        }
    }

     /*Retorna valor mais próximo do solicitado*/
    return ((originalValue - getTotalBalance(*pList)) * -1);
}