#include "Bancos.h"

void Bancos::informacoesTexto(Bancos B){
	B.nome = "Banco Box";
	B.tipo = "Banco de atendimento ao cliente, caixas eletrônico e convencional";
	B.hora_func = "10 às 16 horas";
	B.telefone = "0800 728 0002";
}

void Bancos::imprimeInformacoes(Bancos B){
	cout << "\tEstabelecimento:" << endl << "Nome: " << B.nome << endl << "Tipo: " << B.tipo << endl <<
		"Horario de funcionamento: " << B.hora_func << endl << "Telefone: " << B.telefone << endl;
}

int CCONV Bancos::TagHandler(Bancos B)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(B.rfid, 1);

	if ((B.tagval[0] == 0x31) && (B.tagval[1] == 0x66) && (B.tagval[2] == 0x30) && (B.tagval[3] == 0x30) && (B.tagval[4] == 0x62)){
		PlaySound(TEXT("Banco.wav"), NULL, SND_SYNC);
		B.imprimeInformacoes(B);
		cout << "Tag Read: " << B.tagval << endl;
	}
	return 0;
}