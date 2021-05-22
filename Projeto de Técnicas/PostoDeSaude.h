#include "Estabelecimento.h"

class PostoDeSaude : public Estabelecimento, public RFID, public Endereco {
public:
	PostoDeSaude();
	
	int CCONV TagHandler(PostoDeSaude);
	void informacoesTexto(PostoDeSaude);
	void imprimeInformacoes(PostoDeSaude);
};

