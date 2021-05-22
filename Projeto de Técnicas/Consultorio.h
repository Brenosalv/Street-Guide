#include "Estabelecimento.h"

class Consultorio : public Estabelecimento, public RFID, public Endereco
{
public:
	Consultorio();
	
	int CCONV TagHandler(Consultorio);
	void informacoesTexto(Consultorio);
	void imprimeInformacoes(Consultorio);
};

