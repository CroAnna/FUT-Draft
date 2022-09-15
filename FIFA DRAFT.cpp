#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
struct tigrac{
	char pozicija[10];
	string prezime[30]={"Horvat","Novacic","Grgic","Brkic","Filipovic","Martinec","Mandzukic","Modric","Lovren","Kalinic","Kralj", "Vrane", "Jaksic", "Bazulj", "Mihovic", "Markovic", "Zoric", "Sebalj", "Macinkovic", "Pavlic", "Miksic","Balic","Zlataric","Kovacic","Lipovac","Kos","Golubic","Furac","Tokic","Lukovcic"};
	string ime[30]={"Marko", "Luka", "Fran", "Josip", "Lovro", "Mihael", "Leon", "Ivan", "Mateo", "Juraj","Martin", "Kristijan", "Karlo", "Niko", "Denis", "Jakov","Rafael","Pavao","Sebastian","Danijel","Noa","Andrija","Roko","Adam","Bruno","Marin","Filip","Jan","Maks","Teodor"};
	int random_ime=0;
	int random_prezime=0;
	int brzina=0;
	int visina=0;
	string zvjezdice;	
	int broj_dresa;
}; 
struct tnogometas{
	string pozicija;
	string ime;
	string prezime;
	string zvjezdice;
	int broj_dresa;
	tnogometas *sljedeci;
};
struct tnogometas_struct{
	string pozicija;
	string ime;
	string prezime;
	string zvjezdice;
	int broj_dresa;
};
tigrac igrac[12];

int golman=1, obrana, veza, napad, br_igraca;

bool igraci_odabrani=false;

void unos_igraca(string poz, tnogometas *lista){
	tnogometas_struct nogometas;
	
	int broj,odabir;

	for (int j=0; j<5; j++){
		cout << j+1 << ". = ";
		broj=rand()%30; //random broj za ime, broj je koje se ime koristi iz onih ponudenih
		igrac[j].random_ime = broj;
		cout << igrac[j].ime[broj]<< " ";

		broj=rand()%30; //sad random za prezime
		igrac[j].random_prezime = broj;
		cout << igrac[j].prezime[broj]<< endl; // PREZIME
			
		igrac[j].broj_dresa=rand()%99+1; //brojevi od 1 do 99 
		cout << "Broj dresa: " << igrac[j].broj_dresa << endl; // BRZINA	
		
		igrac[j].visina=rand()%60+160; // random za visinu znaci bar 160 i onda random do +60 (drugi nacin je 220 + 160) = od 160 do 220 cm
		cout << "Visina igraca: " << igrac[j].visina << endl; // VISINA
		
		igrac[j].brzina=rand()%10+1; // prema brzini dobivaju zvjezdice
			if(igrac[j].brzina==0) igrac[j].zvjezdice="*";
			if(igrac[j].brzina==1) igrac[j].zvjezdice="*";
			if(igrac[j].brzina==2) igrac[j].zvjezdice="**";
			if(igrac[j].brzina==3) igrac[j].zvjezdice="**";
			if(igrac[j].brzina==4) igrac[j].zvjezdice="***";
			if(igrac[j].brzina==5) igrac[j].zvjezdice="***";
			if(igrac[j].brzina==6) igrac[j].zvjezdice="***";
			if(igrac[j].brzina==7) igrac[j].zvjezdice="****";
			if(igrac[j].brzina==8) igrac[j].zvjezdice="****";
			if(igrac[j].brzina==9) igrac[j].zvjezdice="*****";
			if(igrac[j].brzina==10) igrac[j].zvjezdice="*****";

		cout << "Zvjezdice: " << igrac[j].zvjezdice; // ZVJEZDICE
		cout << endl << endl;
	}
	
	do{
		cout << "Odabir: ";
		cin >> odabir;
	}while(odabir>5 || odabir<1);
	
	for(int j=0;j<11;j++){
		if(j==odabir-1) { // -1 jer indeksi krecu od 0
			if(poz=="golman")strcpy(igrac[j].pozicija, "golman");
			if(poz=="obrana")strcpy(igrac[j].pozicija, "obrana");
			if(poz=="veza")strcpy(igrac[j].pozicija, "veza");
			if(poz=="napad")strcpy(igrac[j].pozicija, "napad");
					
			cout <<"\nOdabrani igrac: " <<igrac[j].pozicija<< " = " <<igrac[j].ime[igrac[j].random_ime] << " " << igrac[j].prezime[igrac[j].random_prezime] << ", Broj dresa: " << igrac[j].broj_dresa<< ",  " << igrac[j].zvjezdice<< ", Visina: " << igrac[j].visina << " cm\n------------------------------------------------------\n";
			
			tnogometas *novi, *zadnji;
			zadnji=lista;
			while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
			novi=new tnogometas;
			zadnji->sljedeci=novi;
			novi->sljedeci=NULL;
			novi->ime=igrac[j].ime[igrac[j].random_ime];
			novi->prezime=igrac[j].prezime[igrac[j].random_prezime];
			novi->zvjezdice=igrac[j].zvjezdice;
			novi->pozicija=igrac[j].pozicija;
			novi->broj_dresa=igrac[j].broj_dresa;
		break;
		}
	}
}

void ispis_nogometasa(tnogometas *lista){
	tnogometas *tekuci = lista->sljedeci;
	cout << "\n-----------------------------------\n*-*-*-* ISPIS POSTAVE *-*-*-*\n-----------------------------------\n\n";
	while(tekuci){
		cout << tekuci->pozicija << endl;
		cout << "Ime i prezime: " << tekuci->ime << " " << tekuci->prezime << endl;
		cout << "\tBroj dresa: " << tekuci->broj_dresa << endl;
		cout << "\tZvjezdice: " << tekuci->zvjezdice << endl;
		cout << "\n-----------------------------------\n";
		tekuci=tekuci->sljedeci;
	}
}

void pretrazivanje(tnogometas *lista,int dres){
  tnogometas *tekuci=lista->sljedeci;
  bool pronaden=false;
  while (tekuci){
    if (tekuci->broj_dresa==dres){
	    cout << tekuci->pozicija << endl;
		cout << "Ime i prezime: " << tekuci->ime << " " << tekuci->prezime << endl;
		cout << "\tBroj dresa: " << tekuci->broj_dresa << endl;
		cout << "\tZvjezdice: " << tekuci->zvjezdice << endl;
		cout << "\n---------------------------\n";
		pronaden=true;
	    break;
    }
    tekuci=tekuci->sljedeci;
  }
  if(pronaden==false) cout << "\nNema igraca s tim brojem dresa.\n\n";
}
void pretrazivanje_poz(tnogometas *lista,string trazi){
    tnogometas *tekuci=lista->sljedeci;
    bool pronaden=false;
    cout << "\n-----------------------------------------\n*-*-*-* ISPIS PO POZICIJI: " << trazi << " *-*-*-*\n-----------------------------------------\n\n";
    while (tekuci){
    if (tekuci->pozicija==trazi){
		cout << tekuci->ime << " " << tekuci->prezime << " " << tekuci->broj_dresa << endl;
		pronaden=true;
    }
    tekuci=tekuci->sljedeci;
  }
  if(pronaden==false) cout << "Netocan unos.\n";
cout <<endl<<endl;
}

int main (){ 
	srand(time(0)); // to dvoje tak mora ic za random brojeve
	rand();
	tnogometas *lista_nogometasa = new tnogometas;
	lista_nogometasa->sljedeci=NULL;	
	int izbor;
	do{
		cout << "*-*-*-*-*-*-*---- DOBRODOSLI ----*-*-*-*-*-*-*\nUnesi zeljenu formaciju:\n";
		cin >> obrana >> veza >> napad;
		br_igraca=golman+obrana+veza+napad;
	}while(br_igraca!=11);
	
	do{
		do{
			cout << "*-*-*-*-*-*-*-* IZBORNIK *-*-*-*-*-*-*-*\n\t1-odabir postave\n\t2-ispis odabranih\n\t3-Pretrazivanje prema poziciji\n\t4-Pretrazivanje po dresu\n";
			cin >> izbor;
		}while(izbor<1&&izbor>9);	
		
		switch(izbor){
			case 1:{
					int a;
					string poz;
					if(igraci_odabrani==true){
						cout << "Postava je vec odabrana...\n";
						break;
					}
					unos_igraca(poz="golman",lista_nogometasa); // golman
					for (int i=0; i<obrana; i++)unos_igraca(poz="obrana",lista_nogometasa); // obrana
					for (int i=0; i<veza; i++)unos_igraca(poz="veza",lista_nogometasa); // veza
					for (int i=0; i<napad; i++)unos_igraca(poz="napad",lista_nogometasa); // napad
					igraci_odabrani=true;
				break;
			}
			case 2:{
				ispis_nogometasa(lista_nogometasa);
				break;
			}
			case 3:{
				string trazi;
				cout << "Odaberi poziciju: (golman, obrana, veza, napad) ";
				cin >> trazi;
				pretrazivanje_poz(lista_nogometasa,trazi);
				break;
			}
			case 4:{
				int dres;
				cout << "Unesi broj dresa: ";
				cin >> dres;
				pretrazivanje(lista_nogometasa, dres);
				break;
			}	
		}	
	}while(izbor!=9);
cout << endl;
system ("pause");
return 0;
}
