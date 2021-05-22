#include "Estabelecimento.h"

class Bar : public Estabelecimento, public RFID, public Endereco
{
public:
	Bar();
	
	int CCONV TagHandler(Bar);
	void informacoesTexto(Bar);
	void imprimeInformacoes(Bar);
};

