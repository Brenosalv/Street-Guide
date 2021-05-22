#include "PostoDeSaude.h"

void PostoDeSaude::informacoesTexto(PostoDeSaude P){
	P.nome = "Plantonista: Doutor Giuseppe";
	P.tipo = "Posto de saúde da família";
	P.hora_func = "24 horas";
	P.telefone = "(83) 3355-6442"; //Telefone diferente do do audio.
}

void PostoDeSaude::imprimeInformacoes(PostoDeSaude P){
	cout << "\tEstabelecimento:" << endl << "Nome: " << P.nome << endl << "Tipo: " << P.tipo << endl <<
		"Horario de funcionamento: " << P.hora_func << endl << "Telefone: " << P.telefone << endl;
}

int CCONV PostoDeSaude::TagHandler(PostoDeSaude PO)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(PO.rfid, 1);

	if ((PO.tagval[0] == 0x32) && (PO.tagval[1] == 0x31) && (PO.tagval[2] == 0x30) && (PO.tagval[3] == 0x30) && (PO.tagval[4] == 0x36)){
		PlaySound(TEXT("Posto de saúde.wav"), NULL, SND_SYNC);
		PO.imprimeInformacoes(PO);
		cout << "Tag Read: " << PO.tagval << endl;
	}
	return 0;
}