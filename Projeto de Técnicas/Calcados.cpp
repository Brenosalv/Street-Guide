#include "Calcados.h"

void Calcados::informacoesTexto(Calcados CA){
	CA.nome = "Wesley Calcados";
	CA.tipo = "Loja de calçados masculinos e femininos";
	CA.hora_func = "8 às 18 horas";
	CA.telefone = "(83) 3339-2097";
}

void Calcados::imprimeInformacoes(Calcados CA){
	cout << "\tEstabelecimento:" << endl << "Nome: " << CA.nome << endl << "Tipo: " << CA.tipo << endl <<
		"Horario de funcionamento: " << CA.hora_func << endl << "Telefone: " << CA.telefone << endl;
}

int CCONV Calcados::TagHandler(Calcados CA)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(CA.rfid, 1);

	if ((CA.tagval[0] == 0x31) && (CA.tagval[1] == 0x31) && (CA.tagval[2] == 0x30) && (CA.tagval[3] == 0x30) && (CA.tagval[4] == 0x62)){
		PlaySound(TEXT("Loja de calçados.wav"), NULL, SND_SYNC);
		CA.imprimeInformacoes(CA);
		cout << "Tag Read: " << CA.tagval << endl;
	}
	return 0;
}