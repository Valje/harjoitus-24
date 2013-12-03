// Valtteri Ahonen
// Harjoitus 24

#include <iostream>
using namespace std;


struct HENK{
	char etun[20];
	float matka;
	int hattu;
};

//Aliohjelmat
int Valikko(void);
void TulostaHenkilo(HENK henkilot);
void TulostaKaikkiHenkilot(HENK henkilot[], int laskuri);
void LisaaHenkilo(HENK henkilot[], int *lkm);


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
			laskuri++; // Tama pitaisi saada aliohjelman sisaan, mutta ei nyt riko mitaan, kun tietoja ei kuitenkaan voi poistaa
			break;

		case 2: // Tulostetaan viimeksi annettu tieto
			TulostaHenkilo(henkilot[laskuri-1]);
			break;

		case 3: 
			// Tulostetaan kaikki tallennetut tiedot
			TulostaKaikkiHenkilot(henkilot, laskuri);
			break;

		default:
			cout << "No sun taytyy valita joku noista numeroista tietysti!" << endl;
			break;
		}
	}while(lippu);

}

int Valikko(void) // Naytetaan valikko ja kysytaan kayttajalta numero, joka palautetaan
{

	int valinta;

	cout << "VALIKKO" << endl
		<< "0: Lopeta" << endl
		<< "1: Lisaa henkilo" << endl
		<< "2: Nayta henkilo" << endl
		<< "3: Nayta kaikki henkilot" << endl
		<< "4: Poista henkilon tiedot"
		<< "5: Tallenna tiedot tiedostoon"
		<< "6: Hae tiedot tiedostosta";

	cin >> ws >> valinta;


	return valinta;
}

void LisaaHenkilo(HENK henkilot[], int *laskuri) // Kysellaan uuden henkilon tiedot ja syotetaan paikalleen
{
	if (*laskuri < 10){
		cout << "Anna etunimi: ";
		cin >> henkilot[*laskuri].etun;
		cout << endl << "Anna koulumatka: ";
		cin >> henkilot[*laskuri].matka;
		cout << endl << "Anna hatun koko: ";
		cin >> henkilot[*laskuri].hattu;
		cout << endl;

	}
	else
	{
		cout << "Valitettavasti uusia yhteystietoja ei enaa mahdu." << endl;
	}
}

void TulostaHenkilo(HENK henkilot) // Ei kaytossa, tulostaa edellisen syotetyn tiedon
{
	cout << endl << "Tallennetut tiedot muodossa <nimi> <koulumatka> <hatun koko>:" << endl;
	cout << henkilot.etun << " " << henkilot.matka << " " << henkilot.hattu << endl;
	cout << endl;
}

void TulostaKaikkiHenkilot(HENK henkilot[], int laskuri) // Tulostaa kaikki tallennetut tiedot
{
	cout << endl << "Tallennetut tiedot muodossa <nimi> <koulumatka> <hatun koko>:" << endl;
	for (int i = 0; i < laskuri; i++)
	{
		cout << henkilot[i].etun << " " << henkilot[i].matka << " " << henkilot[i].hattu << endl;
	}
	cout << endl;
}