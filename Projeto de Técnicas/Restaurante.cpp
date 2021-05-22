#include "Restaurante.h"

void Restaurante::informacoesTexto(Restaurante R){
	R.nome = "Comida Bacana";
	R.tipo = "Restaurante";
	R.hora_func = "11 às 15 horas e 17 às 22 horas";
	R.telefone = "(83) 3342-2762";
}

void Restaurante::imprimeInformacoes(Restaurante R){
	cout << "\tEstabelecimento:" << endl << "Nome: " << R.nome << endl << "Tipo: " << R.tipo << endl <<
		"Horario de funcionamento: " << R.hora_func << endl << "Telefone: " << R.telefone << endl;
}

int CCONV Restaurante::TagHandler(Restaurante RE)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(RE.rfid, 1);

	if ((RE.tagval[0] == 0x31) && (RE.tagval[1] == 0x64) && (RE.tagval[2] == 0x30) && (RE.tagval[3] == 0x30) && (RE.tagval[4] == 0x64)){
		PlaySound(TEXT("Restaurante.wav"), NULL, SND_SYNC);
		RE.imprimeInformacoes(RE);
		cout << "Tag Read: " << RE.tagval << endl;
	}
	return 0;
}