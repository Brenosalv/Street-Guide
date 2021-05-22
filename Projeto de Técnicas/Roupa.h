#include "Estabelecimento.h"

class Roupa : public Estabelecimento, public RFID, public Endereco {
public:
	Roupa();
	
	int CCONV TagHandler(RFID);
	void informacoesTexto(Roupa);
	void imprimeInformacoes(Roupa);
};

