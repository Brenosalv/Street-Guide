#include "Estabelecimento.h"

//falta altera��es
class Policia : public Estabelecimento, public RFID, public Endereco{

	string especializacao;

public:
	Policia();
	
	int CCONV TagHandler(Policia);
	void informacoesTexto(Policia);
	void imprimeInformacoes(Policia);
};