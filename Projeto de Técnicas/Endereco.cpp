#include "Endereco.h"

void Endereco::informacoesTexto(Endereco End){
	End.Rua = "Avenida Eustáquio Rangel";
	End.bairro = "Grupo 15";
	End.CEP = "10000-100";
}

void Endereco::imprimeInformacoes(Endereco End){
	cout << "\tEndereco:" << endl << "Rua: " << End.Rua << endl << "Bairro: " << End.bairro << endl;
}

int CCONV Endereco::TagHandler(Endereco E)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(E.rfid, 1);

	if ((E.tagval[0] == 0x31) && (E.tagval[1] == 0x35) && (E.tagval[2] == 0x30) && (E.tagval[3] == 0x30) && (E.tagval[4] == 0x34)){
		PlaySound(TEXT("Endereço.wav"), NULL, SND_SYNC);
		E.imprimeInformacoes(E);
		cout << "Tag Read: " << E.tagval << endl;
	}
	return 0;
}