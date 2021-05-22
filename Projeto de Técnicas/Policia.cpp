#include "Policia.h"

void Policia::informacoesTexto(Policia P){
	P.nome = "52ª Delegacia de Policia Militar da Paraiba";
	P.tipo = "Policia Militar";
	P.hora_func = "24 horas";
	P.telefone = "190";
}

void Policia::imprimeInformacoes(Policia P){
	cout << "\tEstabelecimento:" << endl << "Nome: " << P.nome << endl << "Tipo: " << P.tipo << endl <<
		"Horario de funcionamento: " << P.hora_func << endl << "Telefone: " << P.telefone << endl;
}

int CCONV Policia::TagHandler(Policia P)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(P.rfid, 1);

	if ((P.tagval[0] == 0x32) && (P.tagval[1] == 0x31) && (P.tagval[2] == 0x30) && (P.tagval[3] == 0x30) && (P.tagval[4] == 0x34)){
		PlaySound(TEXT("Polícia.wav"), NULL, SND_SYNC);
		P.imprimeInformacoes(P);
		cout << "Tag Read: " << P.tagval << endl;
	}
	return 0;
}