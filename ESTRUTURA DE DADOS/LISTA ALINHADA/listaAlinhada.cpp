#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
TLista lista;



// ====================================== FIM DA BASE ============================

void inicializa(TLista *DB){
    head();
    DB->inicioF = NULL;
    DB->inicioA = NULL;
    DB->fimF = NULL;
    DB->fimA = NULL;

    insereAtor(DB,"Tobey Maguire");
	insereAtor(DB,"Christen Dusten");
	insereAtor(DB,"Charlton Heston");
	insereAtor(DB,"Sophia Loren");
	insereAtor(DB,"Kirk Douglas");
	insereAtor(DB,"Michael Douglas");
	insereAtor(DB,"Mira Sorvino");
	insereAtor(DB,"Tom Cruise");
	insereAtor(DB,"Jennifer Connelly");
	insereAtor(DB,"Kelly McGillis");
	insereAtor(DB,"Kathleen Turner");
	insereAtor(DB,"Danny DeVito");
	insereAtor(DB,"Sylvester Stallone");
	insereAtor(DB,"Talia Shire");
	insereAtor(DB,"Hayley Atwell");
	insereAtor(DB,"Chris Evans");
	insereAtor(DB,"Sebastian Stan");
	insereAtor(DB,"Sidney Potier");
	insereAtor(DB,"Charlie Chaplin");
	insereAtor(DB,"Paulette Goddard");
	insereAtor(DB,"Bruce Willis");
	insereAtor(DB,"Cybill Shepherd");
	insereAtor(DB,"Genevieve Page");
	insereAtor(DB,"Roy Scheider");
	insereAtor(DB,"Richard Dreyfuss");
	insereAtor(DB,"Edna Purviance");
	insereAtor(DB,"Jackie Coogan");
	insereAtor(DB,"Lulu");
	insereAtor(DB,"Judy Geeson");
	
	insereFilme(DB,"O Garoto", 1921);
	insereFilme(DB,"Tempos Modernos", 1936);
	insereFilme(DB,"SPARTACUS", 1958);
	insereFilme(DB,"El Cid", 1961);
	insereFilme(DB,"To Sir With Love", 1967);
	insereFilme(DB,"Tubarao", 1976);
	insereFilme(DB,"O Poderoso Chefao", 1972);
	insereFilme(DB,"A Joia do NILO", 1986);
	insereFilme(DB,"Moonlighting", 1985);
	insereFilme(DB,"Tudo por uma Esmeralda", 1985);
	
	criaElenco(DB,"El Cid","Charlton Heston");
	criaElenco(DB,"El Cid","Sophia Loren");
	criaElenco(DB,"El Cid","Genevieve Page");
	criaElenco(DB,"Tubarao","Roy Scheider");
	criaElenco(DB,"Tubarao","Richard Dreyfuss");
	criaElenco(DB,"A Joia do NILO","Michael Douglas");
	criaElenco(DB,"A Joia do NILO","Kathleen Turner");
	criaElenco(DB,"A Joia do NILO","Danny DeVito");
	criaElenco(DB,"O Garoto","Charlie Chaplin");
	criaElenco(DB,"O Garoto","Edna Purviance");
	criaElenco(DB,"O Garoto","Jackie Coogan");
	criaElenco(DB,"To Sir With Love","Sidney Potier");
	criaElenco(DB,"To Sir With Love", "Judy Geeson");
	criaElenco(DB,"To Sir With Love", "Lulu");
	criaElenco(DB,"Moonlighting", "Cybill Shepherd");
	criaElenco(DB,"Moonlighting", "Bruce Willis");
	criaElenco(DB,"Tudo por uma Esmeralda", "Michael Douglas");
	criaElenco(DB,"Tudo por uma Esmeralda", "Kathleen Turner");
	criaElenco(DB,"Tempos Modernos", "Charlie Chaplin");
	criaElenco(DB,"Tempos Modernos", "Paulette Goddard");
    copy();
}

int main(){
    inicializa(&lista);
    return 0;
}