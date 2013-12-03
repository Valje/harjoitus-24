#include "maarittely.h"

int Valikko(void) // Naytetaan valikko ja kysytaan kayttajalta numero, joka palautetaan
{

	int valinta;

	cout << "VALIKKO" << endl
		<< "0: Lopeta" << endl
		<< "1: Lisaa henkilo" << endl
		<< "2: Nayta henkilo" << endl
		<< "3: Nayta kaikki henkilot" << endl
		<< "4: Poista henkilon tiedot" << endl
		<< "5: Tallenna tiedot tiedostoon" << endl
		<< "6: Hae tiedot tiedostosta" << endl;

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

void Tallenna(HENK henkilot[], int laskuri)
{
	ofstream tdsto("tiedot.csv");  

	tdsto << "NIMI;IKA;KNUMERO" << endl;
	for (int i = 0; i < laskuri; i++)
	{
		tdsto << henkilot[i].etun << ";" << henkilot[i].matka << ";" << henkilot[i].hattu << endl;
	}
	tdsto << endl;

	tdsto.close();
}

void HaeTiedot(int laskuri)
{
	char otsikko[40], nimi[20];
	int ika, knumero;

	ifstream lue("tiedot.csv");

	lue.getline(otsikko, 40);
	cout << otsikko << endl;

	while (laskuri > 0){
	lue.get(nimi, 20, ';');
	lue.get(); // lue ; pois
	lue >> ika;
	lue.get(); // lue ; pois
	lue >> knumero;
	lue.get(); // lue enter pois

	cout << nimi << " " << ika << " " << knumero << endl;
	
	laskuri--;
	
	}

	lue.close();
}