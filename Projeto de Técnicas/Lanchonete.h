#include "Endereco.h"

class Lanchonete : public Estabelecimento, public RFID, public Endereco
{
public:
	Lanchonete();
	
	int CCONV TagHandler(Lanchonete);
	void informacoesTexto(Lanchonete);
	void imprimeInformacoes(Lanchonete);
};