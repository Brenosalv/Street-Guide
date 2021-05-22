#include "Roupa.h"

void Roupa::informacoesTexto(Roupa R){
	R.nome = "Marina Modas";
	R.tipo = "Loja de roupas femininas";
	R.promocao = "Cardigan de 100 reais por 50 reais";
	R.hora_func = "8 às 18 horas";
	R.telefone = "(83) 3337-6512";
}

void Roupa::imprimeInformacoes(Roupa R){
	cout << "\tEstabelecimento:" << endl << "Nome: " << R.nome << endl << "Tipo: " << R.tipo << endl <<
		"Promocao: " << R.promocao << endl << "Horario de funcionamento: " << R.hora_func << endl << "Telefone: " << R.telefone << endl;
}

int CCONV Roupa::TagHandler(Roupa RO)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(RO.rfid, 1);

	if ((RO.tagval[0] == 0x30) && (RO.tagval[1] == 0x31) && (RO.tagval[2] == 0x30) && (RO.tagval[3] == 0x30) && (RO.tagval[4] == 0x39)){
		PlaySound(TEXT("Loja de roupas.wav"), NULL, SND_SYNC);
		RO.imprimeInformacoes(RO);
		cout << "Tag Read: " << RO.tagval << endl;
	}
	return 0;
}