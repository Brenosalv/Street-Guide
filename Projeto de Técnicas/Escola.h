#include "Estabelecimento.h"

class Escola : public Estabelecimento, public RFID, public Endereco
{
public:
	Escola();
	
	int CCONV TagHandler(Escola);
	void informacoesTexto(Escola);
	void imprimeInformacoes(Escola);
};

