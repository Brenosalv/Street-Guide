#include "Consultorio.h"

void Consultorio::informacoesTexto(Consultorio C){
	C.nome = "Doutor Yago Monteiro";
	C.tipo = "Consultorio Medico";
	C.hora_func = "8 às 12 e 14 às 17 horas";
	C.telefone = "(83) 2101-2055";
}

void Consultorio::imprimeInformacoes(Consultorio C){
	cout << "\tEstabelecimento:" << endl << "Nome: " << C.nome << endl << "Tipo: " << C.tipo << endl <<
		"Horario de funcionamento: " << C.hora_func << endl << "Telefone: " << C.telefone << endl;
}

int CCONV Consultorio::TagHandler(Consultorio C)
{
	//turn on the Onboard LED
	CPhidgetRFID_setLEDOn(C.rfid, 1);

	if ((C.tagval[0] == 0x30) && (C.tagval[1] == 0x31) && (C.tagval[2] == 0x30) && (C.tagval[3] == 0x37) && (C.tagval[4] == 0x57)){
		PlaySound(TEXT("Consultório médico.wav"), NULL, SND_SYNC);
		C.imprimeInformacoes(C);
		cout << "Tag Read: " << C.tagval << endl;
	}
	return 0;
}