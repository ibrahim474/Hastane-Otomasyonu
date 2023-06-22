	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <locale.h>
	#include <conio.h>
	#include <time.h>
	#include <windows.h>

	
	struct hasta {    // hasta  yap�s� (struct) tan�mlamas�
	
		char ad[20] ;
		char soyad[20] ;
	    int tel;
		int tc ;
		int klinikNo;
		int doktorNo;
		char durum;
		char rtarih[20];
		char rsaat [20];
		int siraNo;
		
};
	
	struct doktor {    //  doktor  yap�s� (struct) tan�mlamas�
		char ad[20] ;
		char soyad[20] ;
		char sifre [20] ;
		char dtarih[20] ;
		int klinikNo;
		int doktorNo;
		char tc[11];
	
	};
	
void hastaKayit() {
    system("cls");
    struct hasta h1;
    struct doktor d1;
    int sonuc = 0; //// Sonuc de�i�keni, doktor bulunup bulunmad���n� kontrol etmek i�in kullan�l�r

    printf("HASTA KAYIT EKRANI\n");
    printf("TC        : ");  scanf("%d", &h1.tc); // Kullan�c�dan T.C. numaras� al�n�r ve h1.tc de�i�kenine atan�r
    printf("AD        : "); scanf(" %[^\n]s", h1.ad);
    printf("SOYAD     : "); scanf(" %[^\n]s", h1.soyad);
    printf("GSM       : "); scanf("%d", &h1.tel);
      char cevap;
        printf("Randevu ALMAK �STER M�S�N�Z? (E/H): ");
        
        scanf(" %c", &cevap); //// Kullan�c�n�n cevab� al�n�r
        if(cevap == 'E' || cevap == 'e') {
           printf("Randevu tarihi : "); scanf(" %[^\n]s", h1.rtarih);

printf("Saati : 09.00, 10.00, 11.00, 12.00, 13.00, 14.00, 15.00, 16.00, 17.00\n"); printf("Saati: ");  scanf(" %[^\n]s", &h1.rsaat);
printf("Klinikler : 1-KBB, 2-Fizik Tedavi , 3-cocuk hastaliklari, 4-noroloji, 5-dahiliye, 6-Kadin hastaliklari , 7-Dis Hastaliklar�, 8- ortopedi, 9- Genel Cerrahi, 10- goz hastaliklari \n") ;
                printf("KLINIK NO : "); scanf("%d", &h1.klinikNo);
                FILE *ptr = fopen("doktor.dat", "r+b");
                FILE *ptr2 = fopen("doktorlaryedek.dat", "r+b");
                while(fread(&d1, sizeof(struct doktor), 1, ptr) > 0) {
                    if(h1.klinikNo == d1.klinikNo) {
                        sonuc = 1;
                        printf("%d\t%s\t%s\n", d1.doktorNo, d1.ad, strupr(d1.soyad));
                       
         
                    }
                }
                 
                fclose(ptr);
                if(sonuc == 0) {
                    printf("Bu bolumun doktoru yok. Bu klinik icin Doktor Kayit islemi Oldugu zaman kayit islemi gerceklesecektir. ilginiz icin Tesekkurler. !!!\n");
                } else {
                    printf("DOKTOR NO : "); scanf("%d", &h1.doktorNo); //scanf" fonksiyonu, kullan�c�n�n girdi�i tamsay�y� okur ve "%d" bi�imlendirme karakteri, scanf'in okuyaca�� verinin tamsay� oldu�unu belirtir
                    h1.durum = 0;
                    FILE *hPtr = fopen("hasta.dat", "a+b");
                    FILE *hPtr2 = fopen("yedek.dat", "wb");
                    fwrite(&h1, sizeof(struct hasta), 1, hPtr);
                   printf("RANDEVUNUZ ONAYLANDI.  GECM�S OLSUN!");
                    fclose(hPtr);
                }
                
                
            
        } else if (cevap == 'H' || cevap == 'h') {
            char cevap1;
            printf("RANDEVUSUZ SEK�LDE HASTA KAYD�N�Z YAPILS�N M� ? S�RA NUMARAS� VER�LECEKT�R. (E/H): ");
            
            scanf(" %c", &cevap1);
            if(cevap1 == 'E' || cevap1 == 'e') {

                printf("Klinikler : 1-KBB, 2-Fizik Tedavi , 3-cocuk hastaliklari, 4-noroloji, 5-dahiliye, 6-Jinekoloji , 7-Dis Hastaliklar�, 8- ortopedi, 9- Genel Cerrahi, 10- goz hastaliklari \n") ;
                printf("KLINIK NO : ");
                scanf("%d", &h1.klinikNo);
                FILE *ptr = fopen("doktor.dat", "r+b");
                FILE *ptr2 = fopen("doktorlaryedek.dat", "r+b");
                while(fread(&d1, sizeof(struct doktor), 1, ptr) > 0) {
                    if(h1.klinikNo == d1.klinikNo) {
                        sonuc = 1;
                        printf("%d\t%s\t%s\n", d1.doktorNo, d1.ad, strupr(d1.soyad));
                       
         
                    }
                }
                fclose(ptr);
                if(sonuc == 0) { //// e�er sonu� hala 0 ise (yani doktor bulunamad�ysa)
                    printf("Bu bolumun doktoru yok. Bu klinik icin Doktor Kayit islemi Oldugu zaman kayit islemi gerceklesecektir. ilginiz icin Tesekkurler. !!!\n");
                } else {
                    printf("DOKTOR NO : "); scanf("%d", &h1.doktorNo);
                    h1.durum = 0; // hasta durumu 0 olarak atan�r
                    FILE *hPtr = fopen("hastarandevusuz1.dat", "a+b");
                    FILE *hPtr2 = fopen("yedek.dat", "wb");
                    fwrite(&h1, sizeof(struct hasta), 1, hPtr);
                    printf("HASTA KAYD�N�Z GERCEKLESM�ST�R. GE�M�S OLSUN! ");
                     srand(time(NULL)); // rastgele say� �retmek i�in time fonksiyonu kullan�l�r
                int siraNo = rand() % 100 + 1; // 1 ile 100 aras�nda rastgele bir say� �retir
                printf("S�ra numaran�z: %d\n", siraNo);
                                

                    fclose(hPtr);
                }
            }
        }
}


void randevuiptal() {
    system("cls");

    struct hasta h1;
    struct doktor d1;
    int tc, sonuc = 0;
    printf("RANDEVU ARAMA/�PTAL ETME! \n");
    printf("Lutfen T.C kimlik numaran�z� giriniz.      : ");scanf("%d", &tc);
    FILE *ptr = fopen("hasta.dat", "r+b"); //// hastalar dosyas� a��l�r (okuma ve yazma modunda)
    FILE *ptr2 = fopen("yedekdosya1.dat", "w+b"); //// yedek dosyas� a��l�r (yazma modunda)

    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) {
        if (tc != h1.tc) //"tc" de�i�keninin "h1.tc" de�i�keninin de�erine e�it olmad���n� kontrol ediyor.
            fwrite(&h1, sizeof(struct hasta), 1, ptr2); // hastan�n bilgileri yedek dosyaya yaz�l�r
        else { // e�er hastan�n TC kimlik numaras� e�le�irse
            sonuc = 1;
            break;
        }
    }

    fclose(ptr);
    fclose(ptr2);

    if (sonuc == 0) { 
        printf("%d T.C Nolu Hasta Kaydi  bulunamadi \n", tc);
    } else {
        printf(" TC                : %d \n", h1.tc);
        printf(" AD                : %s \n", h1.ad);
        printf(" SOYAD             : %s \n", h1.soyad);
        printf(" TELEFON NUMARASI  : %d \n", h1.tel);
        printf(" RANDEVU TAR�H�  : %s \n", h1.rtarih);
        printf(" RANDEVU SAAT�  : %s \n", h1.rsaat);
         printf("DOKTOR NO :  %d \n", h1.doktorNo);
        char cevap1;
        printf("RANDEVUNUZ �PTAL ED�LS�N M� ? (E/H): ");
        scanf(" %c", &cevap1);

        if (cevap1 == 'E' || cevap1 == 'e') {
            ptr = fopen("hasta.dat", "r+b");
            ptr2 = fopen("yedekdosya1.dat", "w+b");

            sonuc = 0; // sonuc de�i�kenini s�f�rla

            while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) {
                if (tc != h1.tc)
                    fwrite(&h1, sizeof(struct hasta), 1, ptr2);
                    
                    
                else
                    sonuc = 1;
                    
            }

            fclose(ptr);
            fclose(ptr2);

            if (sonuc == 0) { //// e�er sonu� hala 0 ise (yani hastan�n kayd� bulunamad�ysa)
                printf("%d T.C Nolu Hasta Kaydi  bulunamadi \n", tc);
            } else {
                remove("hasta.dat");
                rename("yedekdosya1.dat", "hasta.dat"); //// yedekdosya1.dat dosyas� hasta.dat olarak yeniden adland�r�l�yor
                printf("Randevunuz iptal edildi \n");
            }
        }
    }
}
	

	void DoktoryeniKayit()
	{
	
	
		system("cls")  ;
		struct doktor d1;
			setlocale(LC_ALL, "Turkish");
		printf("Doktor kayit ekrani \n") ;
			printf("TC       : ") ;  scanf(" %[^\n]s", d1.tc ) ;
			printf("AD        : ") ;  scanf(" %[^\n]s", d1.ad ) ;
		printf("SOYAD     : ") ;  scanf(" %[^\n]s", d1.soyad ) ;
		printf("Dogum tarihi     : ") ;  scanf(" %[^\n]s", d1.dtarih ) ;
		printf("PAROLA   : ") ; scanf(" %[^\n]s",  d1.sifre ) ;
	
		system("cls")  ;
		printf("Klinikler : 1-KBB, 2-Fizik Tedavi , 3-cocuk hastaliklari, 4-noroloji, 5-dahiliye, 6-Jinekoloji , 7-Dis Hastaliklar�, 8- ortopedi, 9- Genel Cerrahi, 10- goz hastaliklari \n") ;
		printf("KLINIK NO : ") ;  scanf("%d", &d1.klinikNo ) ;
		printf("DOKTOR NO : ") ;  scanf("%d", &d1.doktorNo ) ;
	
		FILE *ptr= fopen("doktor.dat", "a+b") ;
		fwrite( &d1, sizeof(struct doktor), 1, ptr ) ;
		fclose(ptr) ;
		printf("Doktor kaydi tamam \n") ;
	
	}
	
	void muayeneEt(struct doktor d1) {
    system("cls");
    struct hasta h1;
    int sonuc = 0, sayac = 0;
    char aciklama[50];
    char dosyaAdi[7];
    dosyaAdi[0] = d1.ad[0];
    dosyaAdi[1] = d1.soyad[0];
    dosyaAdi[2] = '.';
    dosyaAdi[3] = 't';
    dosyaAdi[4] = 'x';
    dosyaAdi[5] = 't';
    dosyaAdi[6] = '\0';

    FILE* mPtr = fopen(dosyaAdi, "a"); //ekleme modunda a��l�yor.
    if (mPtr == NULL) { //// Dosya a��lamazsa hata mesaj� verilir ve fonksiyondan ��k�l�r.
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("\nBekleyen Hastalar\n\n");
    FILE* ptr = fopen("hasta.dat", "r+b"); // "hasta.dat" dosyas� a��l�yor ve okuma-yazma modunda a��l�yor.
       
    if (ptr == NULL) {
        printf("Dosya acilamadi!\n");
        fclose(mPtr);
        return;
    }

    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) { // Dosyadaki her hasta i�in kontrol yap�l�r.
        if (d1.doktorNo == h1.doktorNo && h1.durum == 0) { // Dosyadan bir hasta okunur ve i�lem yap�l�r
            sonuc = 1; // En az bir hasta varsa sonuc de�i�keni 1 olur.
            printf("Hasta bilgileri:\n");
            printf("Ad: %s\nSoyad: %s\nTC: %d\nRandevu tarihi: %s\nRandevu saati: %s\n", h1.ad, h1.soyad, h1.tc, h1.rtarih, h1.rsaat);
            printf("%s hastasinin muayene sonucu:", h1.ad);
            scanf(" %[^\n]s", aciklama); // Muayene sonucu kullan�c� taraf�ndan girilir.
            h1.durum = 1; // Hasta durumu g�ncellenir.
            fprintf(mPtr, "%d\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, aciklama);
            fseek(ptr, (sayac)*sizeof(struct hasta), SEEK_SET); // Dosya konumu ayarlan�r.
            fwrite(&h1, sizeof(struct hasta), 1, ptr); // Hasta bilgileri dosyaya yazd�r�l�r.
            break;
        }
        sayac++; // Dosya konumunu g�ncelle.
    }

    fclose(ptr);
    fclose(mPtr);

    if (sonuc == 0) { // En az bir hasta yoksa, "Bekleyen hastaniz kalmadi!" mesaj� yazd�r�l�r.
 
    } else {  // En az bir hasta varsa, muayeneEt fonksiyonu tekrar �a�r�l�r.
        muayeneEt(d1);
    }

    sonuc = 0; // De�i�kenler s�f�rlan�r.
    sayac = 0;
    FILE* ptr2 = fopen("hastarandevusuz1.dat", "r+b");
        printf("RANDEVUSUZ ");
    if (ptr2 == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    while (fread(&h1, sizeof(struct hasta), 1, ptr2) > 0) { // Dosyadaki her hasta i�in kontrol yap�l�r.
        if (d1.doktorNo == h1.doktorNo && h1.durum == 0) { // Doktor numaras� ve durumu kontrol edilir.
            sonuc = 1; // En az bir hasta varsa sonuc de�i�keni 1 olur.
            printf("Hasta bilgileri:\n");
            printf("Ad: %s\nSoyad: %s\nTC: %d\n", h1.ad, h1.soyad, h1.tc);
            printf("%s hastasinin muayene sonucu:", h1.ad);
            scanf(" %[^\n]s", aciklama); // Muayene sonucu kullan�c� taraf�ndan girilir.
            h1.durum = 1; // Hasta durumu g�ncellenir.
            fprintf(mPtr, "%d\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, aciklama);
            fseek(ptr2, (sayac)*sizeof(struct hasta), SEEK_SET); // Dosya konumu ayarlan�r.
            fwrite(&h1, sizeof(struct hasta), 1, ptr2); // Hasta bilgileri dosyaya yazd�r�l�r.
            break;
        }
        sayac++; // Dosya konumunu g�ncelle.
    }

    fclose(ptr2);
    fclose(mPtr);

    if (sonuc == 0) { // En az bir hasta yoksa, "Bekleyen hastaniz kalmadi!" mesaj� yazd�r�l�r.
        printf("Bekleyen hastaniz kalmadi! \n");
    } else {
        muayeneEt(d1);
    }
}

void bekleyenHastalar(struct doktor d1) {
    system("cls");

    struct hasta h1;
    int sonuc = 0;

    printf("Bekleyen Hastalara iliskin ekran\n");

    FILE* ptr = fopen("hasta.dat", "rb");
      
    if (ptr == NULL) { // Dosya a��lamazsa hata mesaj� yazd�r�l�r ve fonksiyondan ��k�l�r.
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("TC\tAd\tSoyad\tRandevu tarihi\tRandevu saati\n");

    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) { // Dosyadaki her hasta i�in kontrol yap�l�r.
        if (d1.doktorNo == h1.doktorNo && h1.durum == 0) { // Doktor numaras� ve durumu kontrol edilir.
            sonuc = 1; // En az bir hasta varsa sonuc de�i�keni 1 olur.
            printf("%d\t%s\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, h1.rtarih, h1.rsaat);
        }
    }

    fclose(ptr);

    FILE* hPtr = fopen("hastarandevusuz1.dat", "rb");

    if (hPtr == NULL) {  // Dosya a��lamazsa hata mesaj� yazd�r�l�r ve fonksiyondan ��k�l�r
        printf("Dosya acilamadi!\n");
        return;
    }

    while (fread(&h1, sizeof(struct hasta), 1, hPtr) > 0) {
        if (d1.doktorNo == h1.doktorNo && h1.durum == 0) {
            sonuc = 1;
            printf("%d\t%s\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, h1.rtarih, h1.rsaat);
        }
    }

    fclose(hPtr);

    if (sonuc == 0) {
        printf("Bekleyen hastaniz yok!\n");
    } else {
        muayeneEt(d1); // Bekleyen hasta varsa muayeneEt() fonksiyonu �a�r�l�r.
    }
}
	void doktorGiris()
	{
	
	system("cls") ;
	setlocale(LC_ALL, "Turkish");
	struct doktor d1; //d1 ad�nda struct doktor tipinde bir veri yap�s� olu�turur.
	
	char tc[11], sifre[20];  //tc ve sifre ad�nda karakter dizileri olu�turur ve sonuc de�i�kenini s�f�r olarak ayarlar.
	int sonuc=0;
	
	printf("Doktor giris ekrani \n") ;
	printf("TC : ") ; scanf(" %[^\n]s", tc ) ;
	printf("Parola : ") ; scanf(" %[^\n]s", sifre ) ;
	
	FILE *ptr= fopen("doktor.dat", "r+b") ; //doktor.dat dosyas�n� okuma ve yazma modunda a�ar.

	while( fread ( &d1, sizeof(struct doktor), 1, ptr ) >0 ) //ptr dosya i�aret�isinden struct doktor boyutunda veri okur ve d1 yap�s�na yazar
	{
	if ( (strcmp(tc, d1.tc) == 0) && (strcmp(sifre, d1.sifre) == 0) )
	
	{
		sonuc=1;
		printf("Dr. %s %s hos geldiniz ... \n", d1.ad, strupr( d1.soyad )  ) ;
		break;
	}
	}


	fclose(ptr) ; if( sonuc==0 )
	{
	printf("hatali kullanici adi veya parola ! \n") ;
	}
	
	else
	{
	
	bekleyenHastalar(d1);
	
	}
	}
	
	void parolahatirlatma()
	{
		{
		system("cls") ;
		struct doktor d1;
		printf("Parola hatirlatma ekrani \n") ;
		char tc[20], dtarih[20] ;
		printf("TC       : ") ; scanf(" %[^\n]s",  tc ) ;
		printf("DO�UM TAR�H�N�Z      : ") ; scanf(" %[^\n]s", dtarih ) ;
		int sonuc= 0;
	
		FILE *ptr  = fopen( "doktor.dat", "r+b" ) ;
	
	
		while( fread ( &d1, sizeof(doktor), 1, ptr )  !=NULL  ) //ptr dosya i�aret�isinden struct doktor boyutunda veri okur ve d1 yap�s�na yazar
		{
			if( strcmp( tc ,d1.tc )==0 && strcmp( dtarih, d1.dtarih  ) ==0  ) //E�er tc ve dtarih de�erleri d1 yap�s�ndaki tc ve dtarih alanlar� ile e�le�irse, sonuc de�i�keninin de�eri bir yap�l�r ve while d�ng�s�nden ��k�l�r.
			{
				sonuc=1;
				break;
			}
		}
		fclose(ptr) ;
		if( sonuc ==0   )
		printf("%s ve %s ile eslesen kayit yok \n", tc, dtarih ) ;
	
		else
		{
			printf("%s %s  sifreniz : %s \n", d1.ad, d1.soyad, d1.sifre  ) ;
		}
	
	
	}
	}
	
	void doktorlariListele()
	{
		system("cls")  ;
			setlocale(LC_ALL, "Turkish");
		struct doktor d1; //d1 ad�nda struct doktor tipinde bir veri yap�s� olu�turur.

		int adet=0; //adet de�i�kenini s�f�r olarak ayarlar 
	
		printf("%s\t%s\t%s\t%s\t%s\t%s\n", "kNo", "dNo", "T.C", "AD", "SOYAD","DOGUM TAR�H�" ) ; //kNo, dNo, T.C, AD ve SOYAD s�tun ba�l�klar�yla birlikte bir tablo ba�l��� ekrana yazd�r�r.
	
		FILE *ptr= fopen("doktor.dat", "r+b") ;
		while( fread( &d1, sizeof(struct doktor), 1, ptr ) >0  ) //d1 yap�s�na dosyadan struct doktor boyutunda veri okur. Dosyada okunacak veri kalmad��� s�rece while d�ng�s� devam eder.
		{
			adet++; //adet de�i�keninin de�erini bir art�r�r
			printf("%d\t%d\t%s\t%s\t%s\t%s\n", d1.klinikNo, d1.doktorNo, d1.tc, d1.ad, d1.soyad,d1.dtarih) ; //d1 yap�s�ndaki klinikNo, doktorNo, tc, ad ve soyad alanlar� ekrana yazd�r�r.
		}
	
		fclose(ptr) ;
		printf("Doktor Sayisi %d", adet )	 ;
	}
void hastalariListele()
{
    setlocale(LC_ALL, "Turkish");
    system("cls");
    struct hasta h1;
    int adet = 0;
    printf("HASTALAR� L�STELEME EKRANI ! \n");
    printf("%s\t%s\t%s\t%s\n", "TC", "AD", "SOYAD", "TEL");

    FILE *ptr = fopen("hasta.dat", "rb"); // hasta.dat dosyas�ndan hasta bilgilerini oku ve ekrana yazd�r
    FILE *hPtr = fopen("hastarandevusuz1.dat", "rb");

    while (fread(&h1, sizeof(struct hasta), 1, ptr)) {
        adet++;
        printf("%d\t%s\t%s\t%d\n", h1.tc, h1.ad, h1.soyad, h1.tel);
    }

    while (fread(&h1, sizeof(struct hasta), 1, hPtr)) {
        adet++;
        printf("%d\t%s\t%s\t%d\n", h1.tc, h1.ad, h1.soyad, h1.tel);
    }

    fclose(ptr);
    fclose(hPtr);
    printf("Hasta Sayisi: %d\n", adet); // Toplam hasta say�s�n� ekrana yazd�r
}

	void HastaKayitGuncelleme() {
    system("cls");
    int secim;
    setlocale(LC_ALL, "Turkish");
    struct hasta h1;           
    char ad_yeni[20];
    char soyad_yeni[20];
    int tel_yeni;
    char adres_yeni[100];
    int tc_yeni;

    int sonuc=0, sayac=0; // Sonu� ve sayac de�i�kenlerini tan�mlar.
    printf("HASTALARI G�NCELLEME EKRANI\n");
    printf("G�ncelleme yapmak istedi�iniz hastan�n T.C kimlik NOsu: ");
    scanf("%d", &tc_yeni);

    FILE *ptr = fopen("hasta.dat", "r+b"); // Hasta dosyas�n� okuma ve yazma modunda a�ar.
    FILE *hPtr = fopen("hastarandevusuz1.dat", "r+b");
    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0)
    {
        if (tc_yeni == h1.tc) //// T.C kimlik numaras� e�le�irse,
        {
            sonuc=1; // // Sonuc de�i�kenini 1 yapar.
            printf("%d\t%s\t%s\t%d\n", h1.tc, h1.ad, h1.soyad, h1.tel); // Hasta bilgilerini ekrana yazd�r�r.
            break;
        }
        sayac++; // Sayac de�i�kenini artt�r�r.
    }
    while (fread(&h1, sizeof(struct hasta), 1, hPtr) > 0)
    {
        if (tc_yeni == h1.tc)
        {
            sonuc=1;
            printf("%d\t%s\t%s\t%d\n", h1.tc, h1.ad, h1.soyad, h1.tel);
            break;
        }
    }
    fclose(hPtr);

    if (sonuc == 0) // Sonu� de�i�keni hala 0 ise, kay�t yoktur
    {
        printf("%d TC NUMARALI KAYIT YOK!\n", tc_yeni);
        fclose(ptr);
    }
    else // Kay�t varsa,
    {
        printf("TC: ");
        scanf("%d", &tc_yeni);
        printf("AD: ");
        scanf(" %[^\n]s", ad_yeni);
        printf("SOYAD: ");
        scanf(" %[^\n]s", soyad_yeni);

        while (1) { // Ge�erli bir GSM numaras� girilene kadar d�ng� devam eder.
            printf("GSM: ");
            int ret = scanf("%d", &tel_yeni);
            if (ret == 1) {  // Ge�erli bir girdi varsa, d�ng� sona ere
                break;
            }
            printf("Ge�ersiz giris. L�tfen ge�erli  sayi degeri giriniz.\n");
                while (getchar() != '\n');
        }

        rewind(ptr); //
                 // Yeni hasta bilgileri, hasta yap�s�na aktar�l�r.

        h1.tc = tc_yeni;
        strcpy(h1.ad, ad_yeni);
        strcpy(h1.soyad, soyad_yeni);
        h1.tel = tel_yeni;

        fseek(ptr, (sayac - 1) * sizeof(struct hasta), 0); // Dosya konum g�stergesini belirtilen kayda getirir.
        fwrite(&h1, sizeof(struct hasta), 1, ptr); // Dosyaya yeni verileri yazar.
        fclose(ptr);
        printf("G�ncelleme i�lemi ba�ar�yla tamamland�.\n");
    }

    printf("0- Ana men�ye d�n\n");
    printf("Se�iminiz: ");
    scanf("%d", &secim);
    switch (secim)
    {
        case 0:
            break;
        default:
            printf("Hatal� se�im yapt�n�z, ana men�ye y�nlendiriliyorsunuz.\n");
            break;
    }
}
	
void Kayitsilme()
{
    system("cls");
    int secim;
    struct hasta h1;
    int tc, sonuc = 0; // tc numaras� ve sonu� de�i�kenleri tan�mlan�r
    printf("KAYIT S�LME EKRANI !\n");
    printf("S�LMEK �STED�GINIZ VATANDASIN T.C KIMLIK NUMARASI: ");
    scanf("%d", &tc);
    FILE *ptr = fopen("hasta.dat", "r+b");
    FILE *hPtr = fopen("hastarandevusuz1.dat", "rb");
    FILE *ptr2 = fopen("yedekdosya.dat", "w+b");
    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) // hasta.dat dosyas�ndaki t�m kay�tlar okunur
    {
        if (tc != h1.tc) //"tc" de�i�keninin "h1.tc" de�i�keninin de�erine e�it olmad���n� kontrol ediyor.
        {
            fwrite(&h1, sizeof(struct hasta), 1, ptr2); // h1 yap�s� yedekdosya.dat dosyas�na yaz�l�r
        }
        else
        {
            sonuc = 1; // e�er aranan tc numaras� h1.tc numaras�na e�itse sonuc de�i�keni 1 olur
        }
    }
    while (fread(&h1, sizeof(struct hasta), 1, hPtr) > 0) // hastarandevusuz1.dat dosyas�ndaki t�m kay�tlar okunur
    {
        if (tc != h1.tc)
        {
            fwrite(&h1, sizeof(struct hasta), 1, ptr2);
        }
        else
        {
            sonuc = 1; // e�er aranan tc numaras� h1.tc numaras�na e�itse sonuc de�i�keni 1 olur
        }
    }
    fclose(ptr);
    fclose(hPtr);
    fclose(ptr2);
    if (sonuc == 0) // e�er sonuc de�i�keni hala 0 ise
    {
        printf("%d T.C Nolu Hasta Kaydi bulunamadi \n", tc);
    }
    else
    {
        remove("hasta.dat"); // hasta.dat dosyas� silinir
        remove("hastarandevusuz1.dat");
        rename("yedekdosya.dat", "hasta.dat");
        printf("Hasta Kaydi Silindi\n");
    }
    printf("0- Ana menuye don\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);
    switch (secim)
    {
    case 0:  // e�er se�im 0 ise
        break;
    default:
        printf("Hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz\n");
    }
}
	void hastaara()
{
    system("cls");
    
    struct hasta h1;
    int tc, sonuc = 0; // tc numaras� ve sonu� de�i�kenleri tan�mlan�r
    printf("HASTA KAYIT ARAMA EKRANI ! \n");
    printf("ARAMAK ISTEDIGINIZ VATANDASIN T.C KIMLIK NUMARASI: ");
    scanf("%d", &tc);
    
    FILE *ptr = fopen("hasta.dat", "rb");
    FILE *hPtr = fopen("hastarandevusuz1.dat", "rb");
    
    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) // hasta.dat dosyas�ndaki t�m kay�tlar okunur
    {
        if (tc == h1.tc) // e�er aranan tc numaras� h1.tc numaras�na e�itse
        {
            sonuc = 1; // sonuc de�i�keni 1 olur
            break;
        }
    }
    
    if (sonuc == 0) // e�er sonuc de�i�keni hala 0 ise
    {
        while (fread(&h1, sizeof(struct hasta), 1, hPtr) > 0) // hastarandevusuz1.dat dosyas�ndaki t�m kay�tlar okunur
        {
            if (tc == h1.tc) // e�er aranan tc numaras� h1.tc numaras�na e�itse
            {
                sonuc = 1;
                break;
            }
        }
    }
    
    if (sonuc == 0) // e�er sonuc de�i�keni hala 0 ise
    {
        printf("%d T.C Nolu Hasta Kaydi bulunamadi \n", tc);
    }
    else
    {
        printf("TC: %d \n", h1.tc);
        printf("AD: %s \n", h1.ad);
        printf("SOYAD: %s \n", h1.soyad);
        printf("TELEFON NUMARASI: %d \n", h1.tel);
    }
    
    fclose(ptr);
    fclose(hPtr);
}
	 ;
	
	void hastaGiris()
	{
		system("cls") ;
		printf("Hasta giris ekrani \n") ;
	
		int secim;
		printf("1- RANDEVU AL /HASTA KAY�T \n") ;
		printf("2- RANDEVULARIM / RANDEVU �PTAL ET! \n");
	;
	;
		printf("0- Ana menuye don \n") ;
		printf("Seciminiz : ") ;   scanf("%d", &secim) ;
	
		switch(secim )
		{
			case 1: hastaKayit(); break;
	        case 2: randevuiptal(); break;
	
			case 0:  break;
			default : printf("hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz \n") ;
		}
	}
	
	
	void DoktorGiris()
	{
	system("cls") ;
		printf("	Doktor   giris ekrani \n") ;
	int secim;
		printf("1- DOKTOR GIRIS BOLUMU \n") ;
		printf("2- PAROLA HATIRLATMA EKRANI \n") ;
		;
	;
		printf("0- Ana menuye don \n") ;
		printf("Seciminiz : ") ;   scanf("%d", &secim) ;
	
		switch(secim )
		{
			case 1: doktorGiris(); break;
			case 2: parolahatirlatma(); break;
			case 0:  break;
			default : printf("hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz \n") ;
		}
	}
	
	
	void sekreterGiris()
	{
		system("cls") ;
		printf("  SEKRETER G�R�S EKRANI\n\n") ;
		int secim;
		printf("1- HASTA  KAYIT \n") ;
		printf("2- DOKTOR  KAYIT \n") ;
		printf("3- DOKTORLARI LISTELE \n") ;
		printf("4- KAYITLI HASTALARI LISTELE \n") ;
		printf("5- HASTA ARA \n") ;
		printf("6- HASTA KAYDI GUNCELLEME \n") ;
		printf("7- HASTA KAYDI SILME \n") ;
	;
	;
		printf("0- Ana menuye don \n") ;
		printf("Seciminiz : ") ;   scanf("%d", &secim) ;
	
		switch(secim )
		{
			case 1: hastaKayit(); break; // Hasta kayd� yapmak i�in hastaKayit() fonksiyonunu �a��r�r.
			case 2: DoktoryeniKayit() ; break;
			case 3: doktorlariListele(); break;
		    case 4: hastalariListele(); break;
		    case 5: hastaara(); break;
		    case 6: HastaKayitGuncelleme(); break;
		    case 7: Kayitsilme (); break;
		 
			case 0:  break; //Kullan�c�n�n ��k�� yapmak istedi�i durumda program� sonland�r�r.
			default : printf("hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz \n") ;
		}
	}
	
	int menu() {
	setlocale(LC_ALL, "Turkish");
	int secim; //Kullan�c�n�n se�ti�i men� se�ene�ini tutmak i�in bir de�i�ken tan�mlan�r.
	
	printf("\n\n HASTANE OTOMASYON PROGRAMI \n\n");
	
	printf("   1-  HASTA G�R�� \n");
	printf("   2-  SEKRETER G�R�� \n");
	printf("   3-  DOKTOR G�R�� \n");
	printf("   0- Programi Kapat \n");
	printf("   Seciminiz :  ");
	
	while (scanf("%d", &secim) != 1 || (secim != 0 && secim != 1 && secim != 2 && secim != 3)) {  /* Kullan�c�n�n ge�erli bir se�im yapmas� i�in while d�ng�s� kullan�l�r.
	                                                                                             scanf() fonksiyonuyla kullan�c�n�n se�imi okunur ve ge�erli bir se�im yap�l�ncaya kadar d�ng� devam eder. */
	    printf("Hatal� secim! L�tfen ge�erli bir se�im yap�n (0-3 aras�nda bir say�): ");
	    while (getchar() != '\n'); //Yanl�� giri�lerin haf�zadan temizlenmesi i�in kullan�l�r.
	}
	
	return secim; //Kullan�c�n�n se�ti�i se�enek de�eri d�nd�r�l�r.
	}
	
	int main() {

system("color 70");

 


	int secim = menu(); //kullan�c�n�n se�im yapmas� i�in menu() fonksiyonu �a��r�l�r ve se�im de�eri secim de�i�kenine atan�r.
	
	while (secim != 0) { // Kullan�c� ��k�� yapana kadar se�im yapmas�n� sa�layan d�ng� ba�lat�l�r.
	    switch (secim) { //secim de�i�keninin de�erine g�re ilgili fonksiyonlar �a��r�l�r.
	        case 1:
	            hastaGiris();
	            break;
	        case 2:
	            sekreterGiris();
	            break;
	        case 3:
	            DoktorGiris();
	            break;
	
	    }
	
	    secim = menu(); //Kullan�c�n�n men�den se�im yapmas� i�in menu() fonksiyonu �a�r�l�r ve se�im de�eri secim de�i�kenine atan�r.
	}
	
	return 0;
	}
