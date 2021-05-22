#include "Estabelecimento.h"

class Farmacia : public Estabelecimento, public RFID, public Endereco {
public:
	Farmacia();
	
	int CCONV TagHandler(Farmacia);
	void informacoesTexto(Farmacia);
	void imprimeInformacoes(Farmacia);
};

