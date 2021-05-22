#include "Estabelecimento.h"

class Restaurante : public Estabelecimento, public RFID, public Endereco
{
public:
	Restaurante();
	
	int CCONV TagHandler(Restaurante);
	void informacoesTexto(Restaurante);
	void imprimeInformacoes(Restaurante);
};

