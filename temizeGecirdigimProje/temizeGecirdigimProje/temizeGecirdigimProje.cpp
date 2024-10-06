/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:Proje
**				ÖÐRENCÝ ADI...............:Veysel Aras
**				ÖÐRENCÝ NUMARASI.:B211210026
**				DERS GRUBU…………:1-A
****************************************************************************/



#include <iostream>
#include<fstream>
#include <string>

using namespace std;

class YemekBilgileri {
public:
	string yemekAdi;
	string gerekliMalzeme, gerekliMalzeme2, gerekliMalzeme3;
	float gerekliGram, gerekliGram2, gerekliGram3;
	float fiyat;
	float gramaj;
	int yemekSayisi=0;
	int kalanYemek=0;
	float kar;
	void satilanYemek() {
		if(yemekSayisi>0){
			kalanYemek = yemekSayisi - rand() % yemekSayisi;
		}
	}
	void guncelleme() {
		
		int sayi;
		cout << "1- Yemek Adi: " << yemekAdi << endl;
		cout << "2- Gramaj: " << gramaj << endl;
		cout << "3- Fiyat: " << fiyat << endl;
		cout << "4- Kar: " << kar << endl;
		cout << endl  << "Guncellemek istediginiz bilginin sayisini giriniz: ";
		cin >> sayi;
		string a;
		switch (sayi)
		{
		case 1:
			cout << "Yeni yemek adini giriniz: ";
			getline(cin >> ws, yemekAdi);
			cout << endl << "Yemek adi guncellenmistir" << endl;
			break;
		case 2:

			cout << "Yeni yemek gramajini giriniz: ";
			getline(cin >> ws, a);
			gramaj = stof(a);
			cout << endl << "Yemek gramaji guncellenmistir" << endl;
			break;
		case 3:
			cout << "Yeni yemek fiyatini giriniz: ";
			getline(cin >> ws, a);
			fiyat = stof(a);
			cout << endl << "Yemek fiyati guncellenmistir" << endl;
			break;
		case 4:
			cout << "Yeni yemek kar fiyatini giriniz: ";
			getline(cin >> ws, a);
			kar = stof(a);
			cout << endl << "Yemek kar fiyati guncellenmistir" << endl;

			break;
		default:
			break;
		}
		

	}
};

class MalzemeIslemleri {
public:
	string malzemeAdi;
	float kilogram=100.00;
	
};

int main()
{
	ifstream yemekListesi;
	yemekListesi.open("yemekListesi.txt");
	YemekBilgileri yemekBilgileri[25];
	MalzemeIslemleri malzemeIslemleri[30];
	string siparisListesi[100] = {};
	int sayac = 0;
	while (yemekListesi.good())
	{
		string satir;
		getline(yemekListesi, satir);
		yemekBilgileri[sayac].yemekAdi = satir;
		yemekBilgileri[sayac].gramaj = 0.400;
		sayac++;
	}
	yemekListesi.close();

	ifstream malzemeOkuma;
	malzemeOkuma.open("MalzemeListesi.txt");
	int sayac2 = 0;
	
	while (malzemeOkuma.good())
	{
		char ch;
		malzemeOkuma >> yemekBilgileri[sayac2].gerekliMalzeme >> yemekBilgileri[sayac2].gerekliGram;
		malzemeOkuma >> ch;
		if (ch == 'c') {
			sayac2++;
			continue;
		}
		else {
			malzemeOkuma >> yemekBilgileri[sayac2].gerekliMalzeme2 >> yemekBilgileri[sayac2].gerekliGram2;
		}
		malzemeOkuma >> ch;
		if (ch == 'c') {
			sayac2++;
			continue;
		}
		else {
			malzemeOkuma >> yemekBilgileri[sayac2].gerekliMalzeme3 >> yemekBilgileri[sayac2].gerekliGram3;
		}
		malzemeOkuma >> ch;
		sayac2++;
	}
	malzemeOkuma.close();


	ifstream fiyatListesi;
	fiyatListesi.open("fiyatListesi.txt", ios::app);
	int sayacc = 0;
	string ch;
	while (fiyatListesi.good())
	{
		fiyatListesi >> yemekBilgileri[sayacc].fiyat >> yemekBilgileri[sayacc].kar ;
		getline(fiyatListesi, ch);
		sayacc++;
		
	}
	fiyatListesi.close();

	ifstream depoOkuma;
	depoOkuma.open("depo.txt");
	int sayac3 = 0;
	while (depoOkuma.good())
	{
		depoOkuma >> malzemeIslemleri[sayac3].malzemeAdi >> malzemeIslemleri[sayac3].kilogram;
		sayac3++;
	}
	depoOkuma.close();
	int secenek;
	char karar='e';
	system("cls");
	do
	{
		
		
		cout << "HOSGELDINIZ" << endl << endl << endl;
		cout << "A- Kayit ekleme, silme, güncelleme, mevcut yemek cesidi goruntuleme islemleri icin 1 tusuna basýnýz" << endl;
		cout << "B- Yemek sayisi belirleme islemi icin 2 tusuna basýnýz"<< endl;
		cout << "C- Finans menusune gecmek icin 3 tusuna basiniz" << endl;
		cin >> secenek;
		int var = 0, bak = 0, bak2 = 0, bak3 = 0;;
		system("cls");
		int sayi;
		string okunanDeger, okunanDeger2, okunanDeger3;
		switch (secenek)
		{
		case 1:
			
			cout << "MENU" << endl << endl;
			cout << "1- Kayit ekleme " << endl;
			cout << "2- Kayit Silme " << endl;
			cout << "3- Kayit Guncelleme " << endl;
			cout << "4- Mevcut yemek cesidi goruntuleme" << endl;
			cin >> secenek;
			
			switch (secenek)
			{
			case 1:
				cout << "Yemek ismi giriniz: ";
				getline(cin >>ws, yemekBilgileri[sayac].yemekAdi);
				cout << endl;
				cout << "Gramaj giriniz: ";
				
				getline(cin ,okunanDeger);
				yemekBilgileri[sayac].gramaj = stof(okunanDeger);
				cout << endl;
				cout << "yemeginiz kaç malzemeden olusuyor: ";
				cin >> sayi;
				if (sayi == 1) {
					cout << "Malzeme ardýndan gramaj giriniz (malzeme adi birlesik olsun): ";
					cin >> yemekBilgileri[sayac].gerekliMalzeme >> yemekBilgileri[sayac].gerekliGram;
					
					for (int i = 0; i < sayac3; i++)
					{
						
						if (yemekBilgileri[sayac].gerekliMalzeme == malzemeIslemleri[i].malzemeAdi)
							bak = 1;
							break;
												
					}
					if (bak!=1)
					{
						malzemeIslemleri[sayac3].malzemeAdi=yemekBilgileri[sayac].gerekliMalzeme;
						sayac3++;
					}
					cout << endl;
					cout << "Fiyat bilgisi giriniz: ";
					cin >> okunanDeger;
					yemekBilgileri[sayac].fiyat = stof(okunanDeger);
					cout << endl;
					cout << "Kar bilgisi giriniz: ";
					cin>>okunanDeger2;
					yemekBilgileri[sayac].kar = stof(okunanDeger2);
					cout << endl;
					sayac++;
				}
				else if(sayi==2)
				{
					cout << "Malzeme ardýndan gramaj giriniz (malzeme adi birlesik olsun): ";
					cin >> yemekBilgileri[sayac].gerekliMalzeme >> okunanDeger >> yemekBilgileri[sayac].gerekliMalzeme2 >> okunanDeger2 ;
					yemekBilgileri[sayac].gerekliGram = stof(okunanDeger); yemekBilgileri[sayac].gerekliGram2 = stof(okunanDeger2); 
					cout << endl;
					for (int i = 0; i < sayac3; i++)
					{

						if (yemekBilgileri[sayac].gerekliMalzeme == malzemeIslemleri[i].malzemeAdi)
							bak = 1;
						break;

					}

					if (bak != 1)
					{
						 malzemeIslemleri[sayac3].malzemeAdi= yemekBilgileri[sayac].gerekliMalzeme ;
						sayac3++;
					}


					for (int i = 0; i < sayac3; i++)
					{

						if (yemekBilgileri[sayac].gerekliMalzeme2 == malzemeIslemleri[i].malzemeAdi)
							bak2 = 1;
						break;

					}

					if (bak2 != 1)
					{
						malzemeIslemleri[sayac3].malzemeAdi=yemekBilgileri[sayac].gerekliMalzeme2 ;
						sayac3++;
					}




					cout << "Fiyat bilgisi giriniz: ";
					cin >> okunanDeger;
					yemekBilgileri[sayac].fiyat = stof(okunanDeger);
					cout <<endl<< "Kar bilgisi giriniz: ";
					cin >> okunanDeger2;
					yemekBilgileri[sayac].kar = stof(okunanDeger2);
					cout << endl;
					cout << endl;
					sayac++;
				}
				else if (sayi==3)
				{
					cout <<endl<< "Malzeme ardýndan gramaj giriniz (malzeme adi birlesik olsun): ";
					cin >> yemekBilgileri[sayac].gerekliMalzeme >> okunanDeger >> yemekBilgileri[sayac].gerekliMalzeme2 >> okunanDeger2 >> yemekBilgileri[sayac].gerekliMalzeme3 >> okunanDeger3;
					yemekBilgileri[sayac].gerekliGram = stof(okunanDeger); yemekBilgileri[sayac].gerekliGram2 = stof(okunanDeger2); yemekBilgileri[sayac].gerekliGram3 = stof(okunanDeger3);
					cout << endl;
					for (int i = 0; i < sayac3; i++)
					{

						if (yemekBilgileri[sayac].gerekliMalzeme == malzemeIslemleri[i].malzemeAdi)
							bak = 1;
						break;

					}

					if (bak != 1)
					{
						yemekBilgileri[sayac].gerekliMalzeme = malzemeIslemleri[sayac3].malzemeAdi;
						sayac3++;
					}
					
					for (int i = 0; i < sayac3; i++)
					{

						if (yemekBilgileri[sayac].gerekliMalzeme2 == malzemeIslemleri[i].malzemeAdi)
							bak = 1;
						break;

					}

					if (bak != 1)
					{
						 malzemeIslemleri[sayac3].malzemeAdi= yemekBilgileri[sayac].gerekliMalzeme2 ;
						 sayac3++;
					}
					
					for (int i = 0; i < sayac3; i++)
					{

						if (yemekBilgileri[sayac].gerekliMalzeme3 == malzemeIslemleri[i].malzemeAdi)
							bak = 1;
						break;

					}

					if (bak != 1)
					{
						malzemeIslemleri[sayac3].malzemeAdi=yemekBilgileri[sayac].gerekliMalzeme3  ;
						sayac3++;
					}
					cout << "Fiyat bilgisi giriniz: ";
					cin >> okunanDeger;
					yemekBilgileri[sayac].fiyat = stof(okunanDeger);
					cout << endl;
					cout << "Kar bilgisi giriniz: ";
					cin >> okunanDeger2;
					yemekBilgileri[sayac].kar = stof(okunanDeger2);
					cout << endl;
					sayac++;
				}
				cout << endl << "Yemeginiz eklenmistrir" << endl;
				
				
				cout << "Menuye donmek icin e yaziniz ";
				cin >> karar;
				system("cls");
				break;
			case 2:
				for (int i = 0; i < sayac; i++)
				{
					cout << i + 1 << "- " << yemekBilgileri[i].yemekAdi << endl;

				}
				int sayi;
				cout << "Silmek istediðiniz yemegin sayisini giriniz: ";
				cin >> sayi;
				sayac--;
				yemekBilgileri[sayi-1].yemekAdi = yemekBilgileri[sayac].yemekAdi;
				yemekBilgileri[sayi-1].gramaj = yemekBilgileri[sayac].gramaj;
				yemekBilgileri[sayi - 1].fiyat = yemekBilgileri[sayac].fiyat;
				yemekBilgileri[sayi - 1].gerekliGram = yemekBilgileri[sayac].gerekliGram;
				yemekBilgileri[sayi - 1].gerekliGram2 = yemekBilgileri[sayac].gerekliGram2;
				yemekBilgileri[sayi - 1].gerekliGram3 = yemekBilgileri[sayac].gerekliGram3;
				yemekBilgileri[sayi - 1].gerekliMalzeme = yemekBilgileri[sayac].gerekliMalzeme;
				yemekBilgileri[sayi - 1].gerekliMalzeme2 = yemekBilgileri[sayac].gerekliMalzeme2;
				yemekBilgileri[sayi - 1].gerekliMalzeme3 = yemekBilgileri[sayac].gerekliMalzeme3;
				yemekBilgileri[sayi - 1].kar = yemekBilgileri[sayac].kar;
				yemekBilgileri[sayac].yemekAdi = "";
				cout << endl << "Yemek silinmiþtir"<<endl;
				cout << "Menuye donmek icin e yaziniz";
				cin >> karar;

				system("cls");
				break;
			case 3:
				cout << "Mevcut Yemek Cesidi " << endl << endl;
				
				for (int i = 0; i < sayac; i++)
				{
					cout << i + 1 << "- " << yemekBilgileri[i].yemekAdi << endl;

				}
				cout << "Guncellemek istediginiz yemegin sayisini giriniz: ";
				cin >>sayi;
				yemekBilgileri[sayi-1].guncelleme();

				system("cls");
				break;
			case 4:
				cout << "Mevcut Yemek Cesidi " << endl << endl;
				for (int i = 0; i < sayac; i++)
				{
					cout << i + 1 << "- " << yemekBilgileri[i].yemekAdi << endl;

				}
				cout << "Menuye donmek icin e yaziniz ";
				cin >> karar;
				system("cls");
				break;
			default:
				cout << "Geceresiz bir karakter girdiniz" << endl<<endl<<endl;
				cout << "Menuye donmek icin e yaziniz ";
				cin >> karar;
			}
			break;
		case 2:
			cout << "Yemek Sayisi Belirleme Ekrani" << endl << endl;
			int yemekSayisi;
			for(int i = 0; i < sayac;i++) {
				cout << i + 1 << "- " << yemekBilgileri[i].yemekAdi <<": ";
				cin >> yemekBilgileri[i].yemekSayisi;
				cout << endl;
			}
			cout << "Yemek sayilari belirlenmiþtir" << endl;
			cout << "Menuye donmek icin e yaziniz ";
			cin >> karar;
			system("cls");
			break;
		case 3:
			karar = 'h';
			break;
		default:
			cout << "Geceresiz bir karakter girdiniz" << endl<<endl<<endl;
			cout << "Menuye donmek icin e yaziniz ";
			cin >> karar;
			break;
			break;
		
		}
	} while (karar=='e');
	int var = 0;
	for (int  i = 0; i < sayac; i++)
	{
		for (int j = 0; j < sayac3; j++)
		{
			if (yemekBilgileri[i].gerekliMalzeme == malzemeIslemleri[j].malzemeAdi) {
				if ((malzemeIslemleri[j].kilogram - yemekBilgileri[i].gerekliGram * yemekBilgileri[i].yemekSayisi)>0)
				{
					malzemeIslemleri[j].kilogram = malzemeIslemleri[j].kilogram - yemekBilgileri[i].gerekliGram * yemekBilgileri[i].yemekSayisi;
				}
				else
				{
					siparisListesi[sayac2] = malzemeIslemleri[i].malzemeAdi;
					yemekBilgileri[i].yemekSayisi = 0;
					yemekBilgileri[i].kalanYemek = 0;
					sayac2++;
					break;
				}
				
			}
			else if (yemekBilgileri[i].gerekliMalzeme2==malzemeIslemleri[j].malzemeAdi)
			{
				if ((malzemeIslemleri[j].kilogram - yemekBilgileri[i].gerekliGram2 * yemekBilgileri[i].yemekSayisi) > 0)
				{
					malzemeIslemleri[j].kilogram = malzemeIslemleri[j].kilogram - yemekBilgileri[i].gerekliGram2 * yemekBilgileri[i].yemekSayisi;
				}
				else
				{
					siparisListesi[sayac2] = malzemeIslemleri[i].malzemeAdi;
					yemekBilgileri[i].yemekSayisi = 0;
					yemekBilgileri[i].kalanYemek = 0;
					sayac2++;
					break;
				}
			}
			else if (yemekBilgileri[i].gerekliMalzeme3 == malzemeIslemleri[i].malzemeAdi) {
				if ((malzemeIslemleri[j].kilogram - yemekBilgileri[i].gerekliGram3 * yemekBilgileri[i].yemekSayisi) > 0)
				{
					malzemeIslemleri[j].kilogram = malzemeIslemleri[j].kilogram - yemekBilgileri[i].gerekliGram3 * yemekBilgileri[i].yemekSayisi;
				}
				else
				{
					siparisListesi[sayac2] = malzemeIslemleri[i].malzemeAdi;
					yemekBilgileri[i].yemekSayisi = 0;
					yemekBilgileri[i].kalanYemek = 0;
					sayac2++;
					break;
				}
			}
			
		}
		
		
	}

	ofstream depo;
	depo.open("depo.txt");
	
	for (int i = 0; i < sayac3; i++)
	{
		depo << malzemeIslemleri[i].malzemeAdi << " " << malzemeIslemleri[i].kilogram << endl;
	}

	depo.close();

	ofstream malzemeListesi;
	malzemeListesi.open("malzemeListesi.txt");

	for (int i = 0; i < sayac; i++)
	{
		if (yemekBilgileri[i].gerekliGram3 >0) {
			malzemeListesi << yemekBilgileri[i].gerekliMalzeme << " " << yemekBilgileri[i].gerekliGram << " b " << yemekBilgileri[i].gerekliMalzeme2 << " " << yemekBilgileri[i].gerekliGram2 << " b " << yemekBilgileri[i].gerekliMalzeme3 <<" " << yemekBilgileri[i].gerekliGram3 << " c" << endl;
		}
		else if (yemekBilgileri[i].gerekliGram2>0)
		{
			malzemeListesi << yemekBilgileri[i].gerekliMalzeme << " " << yemekBilgileri[i].gerekliGram << " b " << yemekBilgileri[i].gerekliMalzeme2 << " " << yemekBilgileri[i].gerekliGram2 << " c" << endl;
		}
		else if (yemekBilgileri[i].gerekliGram>0) {
			malzemeListesi << yemekBilgileri[i].gerekliMalzeme << " " << yemekBilgileri[i].gerekliGram << " c" << endl;
		}
	}
	malzemeListesi.close();

	ofstream yemeklistesi;
	yemeklistesi.open("yemekListesi.txt");
	for (int i = 0; i < sayac; i++)
	{
		yemeklistesi << yemekBilgileri[i].yemekAdi << endl;
	}
	yemeklistesi.close();

	
	ofstream fiyatlistesi;
	fiyatlistesi.open("fiyatListesi.txt");
	for (int i = 0; i < sayac; i++)
	{
		fiyatlistesi << yemekBilgileri[i].fiyat <<" "<< yemekBilgileri[i].kar << endl;
	}
	fiyatlistesi.close();

	system("cls");

	for (int i = 0; i < sayac; i++)
	{
		yemekBilgileri[i].satilanYemek();
	}


	do{
		float toplamKar=0;
		cout << "FINANS MENUSU" << endl << endl;
		cout << "1- Uretilen yemek-satilan yemek raporu " << endl;
		cout << "2- Maliyet-kar raporu" << endl;
		cout << "3- Kalan yemek adedi" << endl;
		cout << "4- Siparis Listesi" << endl;
		cin >> secenek;
		switch (secenek)
		{
		case 1:
			
			for (int i = 0; i < sayac; i++)
			{

				cout << "Satilan " << yemekBilgileri[i].yemekAdi << " adedi= " << yemekBilgileri[i].yemekSayisi - yemekBilgileri[i].kalanYemek << endl << "Kalan " << yemekBilgileri[i].yemekAdi << " adedi= " << yemekBilgileri[i].kalanYemek << endl;
			}
			cout << "Finans menusune donmek icin e yaziniz ";
			cin >> karar;
			break;
		case 2:
			
			for (int i = 0; i < sayac; i++)
			{
				cout<<yemekBilgileri[i].yemekAdi<<" yemeginden edilen kar-zarar= " << yemekBilgileri[i].kar * yemekBilgileri[i].yemekSayisi - yemekBilgileri[i].kalanYemek * yemekBilgileri[i].fiyat<<endl;
				toplamKar += yemekBilgileri[i].kar * yemekBilgileri[i].yemekSayisi - yemekBilgileri[i].kalanYemek * yemekBilgileri[i].fiyat;
			}
			cout << endl << endl << "Toplam kar-zarar= " << toplamKar << endl;
			cout << "Finans menusune donmek icin e yaziniz ";
			cin >> karar;
			break;
		case 3:
			for (int i = 0; i < sayac; i++)
			{
				cout << "Kalan " << yemekBilgileri[i].yemekAdi << " adedi= " << yemekBilgileri[i].kalanYemek << endl;
			}
			cout << "Finans menusune donmek icin e yaziniz ";
			cin >> karar;
			break;
		case 4:
			for (int i = 0;i<sayac2  ; i++)
			{
				if (siparisListesi[i] != "")
					cout << siparisListesi[i] << endl;
			}
			cout << "Finans menusune donmek icin e yaziniz ";
			cin >> karar;
			break;
		default:
			cout << "Geceresiz bir karakter girdiniz" << endl;
			cout << "Finans menusune donmek icin e yaziniz ";
			cin >> karar;
			break;
		}
		system("cls");
	}while(karar=='e');


	cout << "Program sonlanmistir"<< endl << endl;
}