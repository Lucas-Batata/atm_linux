#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "display.h"
#include "keyboard.h"
#include "dispenser.h"

const int MAXVALUEDEBIT = 99999;

void initializeMessages(std::string, Display);

int main(int argc, char *argv[ ])
{
	bool trueOperation = false;

	if(argc>1)
		if (strcmp(argv[1], "true") == 0)
			trueOperation = true;


	Display display;
	Keyboard keyboard;
	Dispenser dispenser;

	do
	{
		int numPressed = 0;
		unsigned int totalValue = 0;
		std::string strMessage = "";
		std::string balanceAtm = std::to_string(dispenser.getTotalBalance());
		std::cout << "Balance: " + balanceAtm << std::endl;
		strMessage = dispenser.getAvailableNotesString();

		initializeMessages(strMessage, display);

		for(;;)
		{
			totalValue = keyboard.getTotalValue();

			numPressed = keyboard.getKeyInput();
			
			if(numPressed >= 0)
			{
				if(((floor(log10(abs(numPressed))) + 1) + (floor(log10(abs(totalValue))) + 1)) < 6)
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

			//display.showMessage("clear");
			
			totalValue = keyboard.getTotalValue();

			strMessage = "R$ ";
			strMessage += std::to_string(totalValue);
			strMessage += ",00\n";
			
			display.showMessage(strMessage);
		}

		/*Etapa de liberar valor para o usuário. Se valor > 1*/
		if(totalValue > 1)
		{	
			/*Só faz uma consulta para saber se será possível fazer o saque*/
			int available = dispenser.withdraw(totalValue, false);
					
			/*Se o valor de saque foi o mesmo que o solicitado*/
			if( available == totalValue)
			{
				/*Faz a operação real de liberar as notas*/
				int available = dispenser.withdraw(totalValue, trueOperation);
				display.showMessage("\nSaque completo!\n");
			}
			else if (available < 1)
			{
				display.showMessage("\nFalha ao efetuar saque.");
				display.showMessage("\nValor próximo ao solicitado: ");
				display.showMessage(std::to_string(abs(available)));
			}
			else
			{
				display.showMessage("\nFalha ao efetuar saque.\n");
				display.showMessage("Valor disponível: \n");
				display.showMessage(std::to_string(available));
			}
		}
		else
		{
			display.showMessage("\nNão existe valor de saque.\n");
			return 0;
		}

		keyboard.clearKeyboard();
		display.showMessage("\n\n");

	}while(true);

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

