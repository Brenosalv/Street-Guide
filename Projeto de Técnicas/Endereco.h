#include "RFID.h"

class Endereco : public RFID{
	char *Rua;
	char *bairro;
	char *CEP;
public:
	Endereco();

	int CCONV TagHandler(Endereco);
	void informacoesTexto(Endereco);
	void imprimeInformacoes(Endereco);
};
