#include "Farmacia.h"

void Farmacia::informacoesTexto(Farmacia F){
	F.nome = "PharmaMed";
	F.tipo = "Farmácia";
	F.hora_func = "8 às 20 horas";
	F.telefone = "(83) 3310-5000";
}

void Farmacia::imprimeInformacoes(Farmacia F){
	cout << "\tEstabelecimento:" << endl << "Nome: " << F.nome << endl << "Tipo: " << F.tipo << endl <<
		"Horario de funcionamento: " << F.hora_func << endl << "Telefone: " << F.telefone << endl;
}

int CCONV Farmacia::TagHandler(Farmacia F)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(F.rfid, 1);

	if ((F.tagval[0] == 0x31) && (F.tagval[1] == 0x66) && (F.tagval[2] == 0x30) && (F.tagval[3] == 0x30) && (F.tagval[4] == 0x38)){
		PlaySound(TEXT("Farmácia PharmaMed.wav"), NULL, SND_SYNC);
		F.imprimeInformacoes(F);
		cout << "Tag Read: " << F.tagval << endl;
	}
	return 0;
}