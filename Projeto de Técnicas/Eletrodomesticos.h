#include "Estabelecimento.h"

class Eletrodomesticos : public Estabelecimento, public RFID, public Endereco
{
public:
	Eletrodomesticos();
	
	int CCONV TagHandler(Eletrodomesticos);
	void informacoesTexto(Eletrodomesticos);
	void imprimeInformacoes(Eletrodomesticos);
};

