#include "Estabelecimento.h"

class Calcados : public Estabelecimento, public RFID, public Endereco
{
public:
	Calcados();
	
	int CCONV TagHandler(Calcados);
	void informacoesTexto(Calcados);
	void imprimeInformacoes(Calcados);
};

