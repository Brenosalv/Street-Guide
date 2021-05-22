#include "Eletrodomesticos.h"

void Eletrodomesticos::informacoesTexto(Eletrodomesticos E){
	E.nome = "Casas Paraiba";
	E.tipo = "Loja de eletrodomésticos";
	E.promocao = "Tablet de 300 reais por 200 reais"
		E.hora_func = "8 às 18 horas";
	E.telefone = "(83) 3322-5221";
}

void Eletrodomesticos::imprimeInformacoes(Eletrodomesticos E){
	cout << "\tEstabelecimento:" << endl << "Nome: " << E.nome << endl << "Tipo: " << E.tipo << endl <<
		"Promocao: " << E.promocao << endl << "Horario de funcionamento: " << E.hora_func << endl << "Telefone: " << E.telefone << endl;
}

int CCONV Eletrodomesticos::TagHandler(Eletrodomesticos E)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(E.rfid, 1);

	if ((E.tagval[0] == 0x31) && (E.tagval[1] == 0x66) && (E.tagval[2] == 0x30) && (E.tagval[3] == 0x30) && (E.tagval[4] == 0x37)){
		PlaySound(TEXT("Loja de eletrodomésticos.wav"), NULL, SND_SYNC);
		E.imprimeInformacoes(E);
		cout << "Tag Read: " << E.tagval << endl;
	}
	return 0;
}