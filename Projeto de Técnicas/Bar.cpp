#include "Bar.h"

void Bar::informacoesTexto(Bar B){
	B.nome = "Bar do Brito";
	B.tipo = "Bar";
	B.hora_func = "17 às 00 horas";
	B.promocao = "Chopp por 1 real";
}

void Bar::imprimeInformacoes(Bar B){
	cout << "\tEstabelecimento:" << endl << "Nome: " << B.nome << endl << "Tipo: " << B.tipo << endl <<
		"Horario de funcionamento: " << B.hora_func << endl << "Promocao: " << B.promocao << endl;
}

int CCONV Bar::TagHandler(Bar BA)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(BA.rfid, 1);

	if ((BA.tagval[0] == 0x31) && (BA.tagval[1] == 0x66) && (BA.tagval[2] == 0x30) && (BA.tagval[3] == 0x30) && (BA.tagval[4] == 0x36)){
		PlaySound(TEXT("Bar.wav"), NULL, SND_SYNC);
		BA.imprimeInformacoes(BA);
		cout << "Tag Read: " << BA.tagval << endl;
	}
	return 0;
}