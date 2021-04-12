#include <iostream>
#include <vector>
#include <string>
#include "display.h"
#include "keyboard.h"
#include "dispenser.h"

const int MAXVALUEDEBIT = 20000;

void initializeMessages(std::string, Display);

int main(void)
{
	Display display;
	Keyboard keyboard;
	Dispenser dispenser;
	
	int numPressed = 0;
	unsigned int totalValue = 0;
	std::string strMessage = "";

	std::list<int> availableNotes = dispenser.getAvailableNotes();
	std::list<int>::iterator it;

    strMessage = dispenser.getAvailableNotesString();

	initializeMessages(strMessage, display);

	for(;;)
	{
		totalValue = keyboard.getTotalValue();

		numPressed = keyboard.getKeyInput();
		
		if(numPressed >= 0)
		{
			if((numPressed + totalValue) < MAXVALUEDEBIT)
			{
				keyboard.insertValue(numPressed);
			}
			else
			{
				display.showMessage("\nO valor máximo de saque é: R$ " + std::to_string(MAXVALUEDEBIT) + "\n" );
			}
		}
		else if(numPressed == -1)
		{
			keyboard.clearKeyboard();
		}
		else if(numPressed == -2)
		{
			keyboard.removeLastValue();
		}
		else
		{
			break;
		}

		totalValue = keyboard.getTotalValue();

		strMessage = "R$ ";
		strMessage += std::to_string(totalValue);
		strMessage += ",00\n";
		
		display.showMessage(strMessage);
	}

	/*Etapa de liberar valor para o usuário. Se valor > 1*/
	if(totalValue > 1)
	{

	}

	return 0;
}

void initializeMessages(std::string availableNotes, Display dsp)
{
	dsp.showMessage("OLá. Bem vindo ao caixa eletrônico!\n");
	dsp.showMessage("Notas disponíveis: ");
	//Mostrar Notas disponíveis
	dsp.showMessage(availableNotes);
	dsp.showMessage("\nDigite o valor que deseja sacar.\n");
	dsp.showMessage("OU\n");
	dsp.showMessage("Digite r para apagar o ultimo número digitado.\n");
	dsp.showMessage("Digite c para apagar todos os números digitados.\n");
}

