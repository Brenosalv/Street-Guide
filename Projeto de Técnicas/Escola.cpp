#include "Escola.h"

void Escola::informacoesTexto(Escola Esc){
	Esc.nome = "Universidade Federal de Campina Grande";
	Esc.tipo = "Universidade";
	Esc.hora_func = "6 às 22 horas";
	Esc.telefone = "(83) 2101-1000";
}

void Escola::imprimeInformacoes(Escola Esc){
	cout << "\tEstabelecimento:" << endl << "Nome: " << Esc.nome << endl << "Tipo: " << Esc.tipo << endl <<
		"Horario de funcionamento: " << Esc.hora_func << endl << "Telefone: " << Esc.telefone << endl;
}

int CCONV Escola::TagHandler(Escola ES)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(ES.rfid, 1);

	if ((ES.tagval[0] == 0x30) && (ES.tagval[1] == 0x34) && (ES.tagval[2] == 0x36) && (ES.tagval[3] == 0x30) && (ES.tagval[4] == 0x31)){
		PlaySound(TEXT("Escola.wav"), NULL, SND_SYNC);
		ES.imprimeInformacoes(ES);
		cout << "Tag Read: " << ES.tagval << endl;
	}
	return 0;
}