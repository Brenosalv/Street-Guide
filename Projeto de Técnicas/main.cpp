#include "RFID.h"
#include "Endereco.h"
#include "Estabelecimento.h"
#include "Bancos.h"
#include "Bar.h"
#include "Calcados.h"
#include "Eletrodomesticos.h"
#include "Policia.h"
#include "Escola.h"
#include "PostoDeSaude.h"
#include "Restaurante.h"
#include "Roupa.h"
#include "Farmacia.h"
#include "Lanchonete.h"
#include "Consultorio.h"

int main() {
	RFID phidget;
	Bancos b;
	Bar ba;
	Calcados c;
	Consultorio con;
	Lanchonete l;
	Farmacia f;
	Roupa r;
	Restaurante re;
	Policia p;
	Eletrodomesticos e;
	Endereco end;
	PostoDeSaude pds;
	Escola esc;
	bool ligado = true;

	phidget.rfid_simple(phidget);

	b.informacoesTexto(b);
	ba.informacoesTexto(ba);
	c.informacoesTexto(c);
	con.informacoesTexto(con);
	l.informacoesTexto(l);
	f.informacoesTexto(f);
	r.informacoesTexto(r);					//Atribui valores aos atributos das instâncias das classes.
	re.informacoesTexto(re);
	p.informacoesTexto(p);
	e.informacoesTexto(e);
	end.informacoesTexto(end);
	pds.informacoesTexto(pds);
	esc.informacoesTexto(esc);

	while (ligado == true) {

		b.TagHandler(b);
		ba.TagHandler(ba);
		c.TagHandler(c);
		con.TagHandler(con);
		l.TagHandler(l);
		f.TagHandler(f);					//Emite áudio e texto conforme a tag lida.
		r.TagHandler(r);
		re.TagHandler(re);
		p.TagHandler(p);
		e.TagHandler(e);
		end.TagHandler(end);
		pds.TagHandler(pds);
		esc.TagHandler(esc);
	}

	return 0;
}