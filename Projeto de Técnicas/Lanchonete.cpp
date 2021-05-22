#include "Lanchonete.h"

void Lanchonete::informacoesTexto(Lanchonete L){
	L.nome = "Mc Pateta’s";
	L.tipo = "Lanchonete";
	L.hora_func = "9 às 22 horas";
	L.telefone = "(83) 3231-3819"; // O telefone ta diferente do do audio.
}

void Lanchonete::imprimeInformacoes(Lanchonete L){
	cout << "\tEstabelecimento:" << endl << "Nome: " << L.nome << endl << "Tipo: " << L.tipo << endl <<
		"Horario de funcionamento: " << L.hora_func << endl << "Telefone: " << L.telefone << endl;
}

int CCONV Lanchonete::TagHandler(Lanchonete L)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(L.rfid, 1);

	if ((L.tagval[0] == 0x31) && (L.tagval[1] == 0x66) && (L.tagval[2] == 0x30) && (L.tagval[3] == 0x30) && (L.tagval[4] == 0x64)){
		PlaySound(TEXT("Lanchonete.wav"), NULL, SND_SYNC);
		L.imprimeInformacoes(L);
		cout << "Tag Read: " << L.tagval << endl;
	}
	return 0;
}