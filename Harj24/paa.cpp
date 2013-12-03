// Valtteri Ahonen
// Harjoitus 24
// 3.12.2013
// Henkilon poistaminen toteutettu vahan huijaten, mutta toimii.

#include "maarittely.h"

int main()
{
	HENK henkilot[10];

	int valinta;
	int laskuri = 0;
	int *lkm = &laskuri;
	bool lippu = true;

	do{
		valinta = Valikko(); // Naytetaan valikko

		switch (valinta)
		{
		case 0:
			lippu = false; // poistutaan do-loopista ja ohjelma loppuu
			break;

		case 1: // Kysellaan kayttajalta henkilon tiedot ja tallennetaan tietuetaulukkoon
			LisaaHenkilo(henkilot, lkm);
			if (laskuri < 10){
				laskuri++;}
			break;

		case 2:
			// Tulostetaan edellisen henkilon tiedot
			TulostaHenkilo(henkilot[laskuri-1]);
			break;

		case 3:
			// Tulostetaan kaikki tallennetut tiedot
			TulostaKaikkiHenkilot(henkilot, laskuri);
			break;

		case 4:
			// Jos poistetaan vain viimeksi lisatyn henkilon tiedot, niin laskuria vaan yks taaksepain, spacet tai nollat tilalle ja lopuksi taas laskuria taaksepain, etta seuraavat kayttajan antamat tiedt menee paalle.
			laskuri--;
			cout << "Edellinen tieto on poistettu.";
			break;

		case 5:
			Tallenna(henkilot, laskuri);
			break;

		case 6:
			HaeTiedot(laskuri);
			break;

		default:
			cout << "No sun taytyy valita joku noista numeroista tietysti!" << endl;
			break;
		}
	}while(lippu);

}