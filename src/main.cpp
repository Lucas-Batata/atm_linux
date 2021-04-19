#include <vector>
#include <string>
#include <cmath>
#include "../include/keyboard.h"
#include "../include/dispenser.h"
#include <gtkmm.h>
#include <iostream>
#include <thread> 

Dispenser dispenser;
Keyboard keyboard;

using namespace Gtk;

Window * pWindow;
Entry * lbl_display, *lbl_messages;
Button * btn_enter, * btn_clear, * btn_cancel, * btn_0,
             * btn_1, * btn_2, * btn_3,* btn_4, * btn_5, 
            * btn_6, * btn_7, * btn_8, * btn_9, *btn_removeLast;


void updateLcd()
{
	std::string strDisplay = "R$ " + std::to_string(keyboard.getTotalValue()) + ",00";
	lbl_display->set_text(strDisplay);
}

void on_btn_0_clicked()
{
	keyboard.insertValue(0);
	updateLcd();
}
void on_btn_1_clicked()
{
	keyboard.insertValue(1);
	updateLcd();
}

void on_btn_2_clicked()
{
	keyboard.insertValue(2);
	updateLcd();
}

void on_btn_3_clicked()
{
	keyboard.insertValue(3);
	updateLcd();
}

void on_btn_4_clicked()
{
	keyboard.insertValue(4);
	updateLcd();
}

void on_btn_5_clicked()
{
	keyboard.insertValue(5);
	updateLcd();
}

void on_btn_6_clicked()
{
	keyboard.insertValue(6);
	updateLcd();
}

void on_btn_7_clicked()
{
	keyboard.insertValue(7);
	updateLcd();
}

void on_btn_8_clicked()
{
	keyboard.insertValue(8);
	updateLcd();
}

void on_btn_9_clicked()
{
	keyboard.insertValue(9);
	updateLcd();
}

void on_btn_enter_clicked()
{
	uint keyboardValue = keyboard.getTotalValue();
	int dispenserTotalBalance = dispenser.getTotalBalance();
	if(keyboardValue <= dispenserTotalBalance)
	{
		int valuePossible = dispenser.withdraw(keyboardValue, false);
		if(valuePossible == keyboardValue)
		{
			int transactionOk = dispenser.withdraw(keyboardValue, true);
			lbl_messages->set_text("Saque efetuado com sucesso!");
		}
		else
		{
			lbl_messages->set_text("Não possuímos notas para esse valor.");
		}
	}
	else
	{
		lbl_messages->set_text("Valor indisponível.");
	}

	keyboard.clearKeyboard();
	updateLcd();
}

void on_btn_clear_clicked()
{
	keyboard.clearKeyboard();
	updateLcd();
}

void on_btn_removeLast_clicked()
{
	keyboard.removeLastValue();
	updateLcd();
}

void on_btn_cancel_clicked()
{
    updateLcd();
	lbl_messages->set_text("");
}



int main (int argc, char ** argv)
{
    auto app =  Gtk::Application::create(argc, argv, "org.gtkmm.example");
    auto refBuilder = Builder::create();

    refBuilder->add_from_file("../GUI/gladeInterface.glade");
    refBuilder->get_widget("window", pWindow);

    if(pWindow)
    {
        refBuilder->get_widget("btn_0", btn_0);
        refBuilder->get_widget("btn_1", btn_1);
        refBuilder->get_widget("btn_2", btn_2);
        refBuilder->get_widget("btn_3", btn_3);
        refBuilder->get_widget("btn_4", btn_4);
        refBuilder->get_widget("btn_5", btn_5);
        refBuilder->get_widget("btn_6", btn_6);
        refBuilder->get_widget("btn_7", btn_7);
        refBuilder->get_widget("btn_8", btn_8);
        refBuilder->get_widget("btn_9", btn_9);
        refBuilder->get_widget("btn_clear", btn_clear);
        refBuilder->get_widget("btn_cancel", btn_cancel);
		refBuilder->get_widget("btn_removeLast", btn_removeLast);
        refBuilder->get_widget("btn_enter", btn_enter);
        refBuilder->get_widget("lbl_display", lbl_display);
		refBuilder->get_widget("lbl_messages", lbl_messages);
    }

    if(btn_0)
    {
        btn_0->signal_clicked().connect(sigc::ptr_fun(on_btn_0_clicked));
    }

    if(btn_1)
    {
        btn_1->signal_clicked().connect(sigc::ptr_fun(on_btn_1_clicked));
    }

    if(btn_2)
    {
        btn_2->signal_clicked().connect(sigc::ptr_fun(on_btn_2_clicked));
    }

    if(btn_3)
    {
        btn_3->signal_clicked().connect(sigc::ptr_fun(on_btn_3_clicked));
    }

    if(btn_4)
    {
        btn_4->signal_clicked().connect(sigc::ptr_fun(on_btn_4_clicked));
    }

    if(btn_5)
    {
        btn_5->signal_clicked().connect(sigc::ptr_fun(on_btn_5_clicked));
    }

    if(btn_6)
    {
        btn_6->signal_clicked().connect(sigc::ptr_fun(on_btn_6_clicked));
    }

    if(btn_7)
    {
        btn_7->signal_clicked().connect(sigc::ptr_fun(on_btn_7_clicked));
    }
    
    if(btn_8)
    {
        btn_8->signal_clicked().connect(sigc::ptr_fun(on_btn_8_clicked));
    }

    if(btn_9)
    {
        btn_9->signal_clicked().connect(sigc::ptr_fun(on_btn_9_clicked));
    }

    if(btn_enter)
    {
        btn_enter->signal_clicked().connect(sigc::ptr_fun(on_btn_enter_clicked));
    }
    
    if(btn_clear)
    {
        btn_clear->signal_clicked().connect(sigc::ptr_fun(on_btn_clear_clicked));
    }

    if(btn_cancel)
    {
        btn_cancel->signal_clicked().connect(sigc::ptr_fun(on_btn_cancel_clicked));
    }

	if(btn_removeLast)
    {
        btn_removeLast->signal_clicked().connect(sigc::ptr_fun(on_btn_removeLast_clicked));
    }


    app->run(*pWindow);

    delete pWindow;
    
    return 0;
}



//g++ main.cpp dispenser.cpp display.cpp keyboard.cpp -o graphic $(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic

