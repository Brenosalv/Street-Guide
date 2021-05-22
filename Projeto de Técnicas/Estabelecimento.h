#include "Endereco.h"

class Estabelecimento : public Endereco, public RFID{
protected:
	string nome;
	string tipo;
	string hora_func;
	string promocao;
	string telefone;
public:
	Estabelecimento();

	virtual int CCONV TagHandler(Estabelecimento);
	virtual void informacoesTexto(Estabelecimento);
	virtual void imprimeInformacoes(Estabelecimento);
};


//FAZER CASTING COM O ATRIBUTO HORARIO DE FUNCIONAMENTO(COM OS QUE SÃO DE HORARIO DE FUNCIONAMENTO COMERCIAL).