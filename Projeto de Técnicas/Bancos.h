#include "Estabelecimento.h"

//falta altera��es

class Bancos : public Estabelecimento, public RFID, public Endereco {
protected:
	//bool atendimento, cc, atm; 				//cc -> "caixa convencional" || atm -> "caixa eletr�nico"    
public:
	Bancos();

	int CCONV TagHandler(Bancos);
	void informacoesTexto(Bancos);
	void imprimeInformacoes(Bancos);
};
