#include "Estabelecimento.h"

//falta alterações

class Bancos : public Estabelecimento, public RFID, public Endereco {
protected:
	//bool atendimento, cc, atm; 				//cc -> "caixa convencional" || atm -> "caixa eletrônico"    
public:
	Bancos();

	int CCONV TagHandler(Bancos);
	void informacoesTexto(Bancos);
	void imprimeInformacoes(Bancos);
};
