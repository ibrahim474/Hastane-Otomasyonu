	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <locale.h>
	#include <conio.h>
	#include <time.h>
	#include <windows.h>

	
	struct hasta {    // hasta  yapısı (struct) tanımlaması
	
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
	
	struct doktor {    //  doktor  yapısı (struct) tanımlaması
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
    int sonuc = 0; //// Sonuc değişkeni, doktor bulunup bulunmadığını kontrol etmek için kullanılır

    printf("HASTA KAYIT EKRANI\n");
    printf("TC        : ");  scanf("%d", &h1.tc); // Kullanıcıdan T.C. numarası alınır ve h1.tc değişkenine atanır
    printf("AD        : "); scanf(" %[^\n]s", h1.ad);
    printf("SOYAD     : "); scanf(" %[^\n]s", h1.soyad);
    printf("GSM       : "); scanf("%d", &h1.tel);
      char cevap;
        printf("Randevu ALMAK İSTER MİSİNİZ? (E/H): ");
        
        scanf(" %c", &cevap); //// Kullanıcının cevabı alınır
        if(cevap == 'E' || cevap == 'e') {
           printf("Randevu tarihi : "); scanf(" %[^\n]s", h1.rtarih);

printf("Saati : 09.00, 10.00, 11.00, 12.00, 13.00, 14.00, 15.00, 16.00, 17.00\n"); printf("Saati: ");  scanf(" %[^\n]s", &h1.rsaat);
printf("Klinikler : 1-KBB, 2-Fizik Tedavi , 3-cocuk hastaliklari, 4-noroloji, 5-dahiliye, 6-Kadin hastaliklari , 7-Dis Hastalikları, 8- ortopedi, 9- Genel Cerrahi, 10- goz hastaliklari \n") ;
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
                    printf("DOKTOR NO : "); scanf("%d", &h1.doktorNo); //scanf" fonksiyonu, kullanıcının girdiği tamsayıyı okur ve "%d" biçimlendirme karakteri, scanf'in okuyacağı verinin tamsayı olduğunu belirtir
                    h1.durum = 0;
                    FILE *hPtr = fopen("hasta.dat", "a+b");
                    FILE *hPtr2 = fopen("yedek.dat", "wb");
                    fwrite(&h1, sizeof(struct hasta), 1, hPtr);
                   printf("RANDEVUNUZ ONAYLANDI.  GECMİS OLSUN!");
                    fclose(hPtr);
                }
                
                
            
        } else if (cevap == 'H' || cevap == 'h') {
            char cevap1;
            printf("RANDEVUSUZ SEKİLDE HASTA KAYDİNİZ YAPILSİN Mİ ? SİRA NUMARASİ VERİLECEKTİR. (E/H): ");
            
            scanf(" %c", &cevap1);
            if(cevap1 == 'E' || cevap1 == 'e') {

                printf("Klinikler : 1-KBB, 2-Fizik Tedavi , 3-cocuk hastaliklari, 4-noroloji, 5-dahiliye, 6-Jinekoloji , 7-Dis Hastalikları, 8- ortopedi, 9- Genel Cerrahi, 10- goz hastaliklari \n") ;
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
                if(sonuc == 0) { //// eğer sonuç hala 0 ise (yani doktor bulunamadıysa)
                    printf("Bu bolumun doktoru yok. Bu klinik icin Doktor Kayit islemi Oldugu zaman kayit islemi gerceklesecektir. ilginiz icin Tesekkurler. !!!\n");
                } else {
                    printf("DOKTOR NO : "); scanf("%d", &h1.doktorNo);
                    h1.durum = 0; // hasta durumu 0 olarak atanır
                    FILE *hPtr = fopen("hastarandevusuz1.dat", "a+b");
                    FILE *hPtr2 = fopen("yedek.dat", "wb");
                    fwrite(&h1, sizeof(struct hasta), 1, hPtr);
                    printf("HASTA KAYDİNİZ GERCEKLESMİSTİR. GEÇMİS OLSUN! ");
                     srand(time(NULL)); // rastgele sayı üretmek için time fonksiyonu kullanılır
                int siraNo = rand() % 100 + 1; // 1 ile 100 arasında rastgele bir sayı üretir
                printf("Sıra numaranız: %d\n", siraNo);
                                

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
    printf("RANDEVU ARAMA/İPTAL ETME! \n");
    printf("Lutfen T.C kimlik numaranızı giriniz.      : ");scanf("%d", &tc);
    FILE *ptr = fopen("hasta.dat", "r+b"); //// hastalar dosyası açılır (okuma ve yazma modunda)
    FILE *ptr2 = fopen("yedekdosya1.dat", "w+b"); //// yedek dosyası açılır (yazma modunda)

    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) {
        if (tc != h1.tc) //"tc" değişkeninin "h1.tc" değişkeninin değerine eşit olmadığını kontrol ediyor.
            fwrite(&h1, sizeof(struct hasta), 1, ptr2); // hastanın bilgileri yedek dosyaya yazılır
        else { // eğer hastanın TC kimlik numarası eşleşirse
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
        printf(" RANDEVU TARİHİ  : %s \n", h1.rtarih);
        printf(" RANDEVU SAATİ  : %s \n", h1.rsaat);
         printf("DOKTOR NO :  %d \n", h1.doktorNo);
        char cevap1;
        printf("RANDEVUNUZ İPTAL EDİLSİN Mİ ? (E/H): ");
        scanf(" %c", &cevap1);

        if (cevap1 == 'E' || cevap1 == 'e') {
            ptr = fopen("hasta.dat", "r+b");
            ptr2 = fopen("yedekdosya1.dat", "w+b");

            sonuc = 0; // sonuc değişkenini sıfırla

            while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) {
                if (tc != h1.tc)
                    fwrite(&h1, sizeof(struct hasta), 1, ptr2);
                    
                    
                else
                    sonuc = 1;
                    
            }

            fclose(ptr);
            fclose(ptr2);

            if (sonuc == 0) { //// eğer sonuç hala 0 ise (yani hastanın kaydı bulunamadıysa)
                printf("%d T.C Nolu Hasta Kaydi  bulunamadi \n", tc);
            } else {
                remove("hasta.dat");
                rename("yedekdosya1.dat", "hasta.dat"); //// yedekdosya1.dat dosyası hasta.dat olarak yeniden adlandırılıyor
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
		printf("Klinikler : 1-KBB, 2-Fizik Tedavi , 3-cocuk hastaliklari, 4-noroloji, 5-dahiliye, 6-Jinekoloji , 7-Dis Hastalikları, 8- ortopedi, 9- Genel Cerrahi, 10- goz hastaliklari \n") ;
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

    FILE* mPtr = fopen(dosyaAdi, "a"); //ekleme modunda açılıyor.
    if (mPtr == NULL) { //// Dosya açılamazsa hata mesajı verilir ve fonksiyondan çıkılır.
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("\nBekleyen Hastalar\n\n");
    FILE* ptr = fopen("hasta.dat", "r+b"); // "hasta.dat" dosyası açılıyor ve okuma-yazma modunda açılıyor.
       
    if (ptr == NULL) {
        printf("Dosya acilamadi!\n");
        fclose(mPtr);
        return;
    }

    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) { // Dosyadaki her hasta için kontrol yapılır.
        if (d1.doktorNo == h1.doktorNo && h1.durum == 0) { // Dosyadan bir hasta okunur ve işlem yapılır
            sonuc = 1; // En az bir hasta varsa sonuc değişkeni 1 olur.
            printf("Hasta bilgileri:\n");
            printf("Ad: %s\nSoyad: %s\nTC: %d\nRandevu tarihi: %s\nRandevu saati: %s\n", h1.ad, h1.soyad, h1.tc, h1.rtarih, h1.rsaat);
            printf("%s hastasinin muayene sonucu:", h1.ad);
            scanf(" %[^\n]s", aciklama); // Muayene sonucu kullanıcı tarafından girilir.
            h1.durum = 1; // Hasta durumu güncellenir.
            fprintf(mPtr, "%d\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, aciklama);
            fseek(ptr, (sayac)*sizeof(struct hasta), SEEK_SET); // Dosya konumu ayarlanır.
            fwrite(&h1, sizeof(struct hasta), 1, ptr); // Hasta bilgileri dosyaya yazdırılır.
            break;
        }
        sayac++; // Dosya konumunu güncelle.
    }

    fclose(ptr);
    fclose(mPtr);

    if (sonuc == 0) { // En az bir hasta yoksa, "Bekleyen hastaniz kalmadi!" mesajı yazdırılır.
 
    } else {  // En az bir hasta varsa, muayeneEt fonksiyonu tekrar çağrılır.
        muayeneEt(d1);
    }

    sonuc = 0; // Değişkenler sıfırlanır.
    sayac = 0;
    FILE* ptr2 = fopen("hastarandevusuz1.dat", "r+b");
        printf("RANDEVUSUZ ");
    if (ptr2 == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }

    while (fread(&h1, sizeof(struct hasta), 1, ptr2) > 0) { // Dosyadaki her hasta için kontrol yapılır.
        if (d1.doktorNo == h1.doktorNo && h1.durum == 0) { // Doktor numarası ve durumu kontrol edilir.
            sonuc = 1; // En az bir hasta varsa sonuc değişkeni 1 olur.
            printf("Hasta bilgileri:\n");
            printf("Ad: %s\nSoyad: %s\nTC: %d\n", h1.ad, h1.soyad, h1.tc);
            printf("%s hastasinin muayene sonucu:", h1.ad);
            scanf(" %[^\n]s", aciklama); // Muayene sonucu kullanıcı tarafından girilir.
            h1.durum = 1; // Hasta durumu güncellenir.
            fprintf(mPtr, "%d\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, aciklama);
            fseek(ptr2, (sayac)*sizeof(struct hasta), SEEK_SET); // Dosya konumu ayarlanır.
            fwrite(&h1, sizeof(struct hasta), 1, ptr2); // Hasta bilgileri dosyaya yazdırılır.
            break;
        }
        sayac++; // Dosya konumunu güncelle.
    }

    fclose(ptr2);
    fclose(mPtr);

    if (sonuc == 0) { // En az bir hasta yoksa, "Bekleyen hastaniz kalmadi!" mesajı yazdırılır.
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
      
    if (ptr == NULL) { // Dosya açılamazsa hata mesajı yazdırılır ve fonksiyondan çıkılır.
        printf("Dosya acilamadi!\n");
        return;
    }

    printf("TC\tAd\tSoyad\tRandevu tarihi\tRandevu saati\n");

    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) { // Dosyadaki her hasta için kontrol yapılır.
        if (d1.doktorNo == h1.doktorNo && h1.durum == 0) { // Doktor numarası ve durumu kontrol edilir.
            sonuc = 1; // En az bir hasta varsa sonuc değişkeni 1 olur.
            printf("%d\t%s\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, h1.rtarih, h1.rsaat);
        }
    }

    fclose(ptr);

    FILE* hPtr = fopen("hastarandevusuz1.dat", "rb");

    if (hPtr == NULL) {  // Dosya açılamazsa hata mesajı yazdırılır ve fonksiyondan çıkılır
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
        muayeneEt(d1); // Bekleyen hasta varsa muayeneEt() fonksiyonu çağrılır.
    }
}
	void doktorGiris()
	{
	
	system("cls") ;
	setlocale(LC_ALL, "Turkish");
	struct doktor d1; //d1 adında struct doktor tipinde bir veri yapısı oluşturur.
	
	char tc[11], sifre[20];  //tc ve sifre adında karakter dizileri oluşturur ve sonuc değişkenini sıfır olarak ayarlar.
	int sonuc=0;
	
	printf("Doktor giris ekrani \n") ;
	printf("TC : ") ; scanf(" %[^\n]s", tc ) ;
	printf("Parola : ") ; scanf(" %[^\n]s", sifre ) ;
	
	FILE *ptr= fopen("doktor.dat", "r+b") ; //doktor.dat dosyasını okuma ve yazma modunda açar.

	while( fread ( &d1, sizeof(struct doktor), 1, ptr ) >0 ) //ptr dosya işaretçisinden struct doktor boyutunda veri okur ve d1 yapısına yazar
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
		printf("DOĞUM TARİHİNİZ      : ") ; scanf(" %[^\n]s", dtarih ) ;
		int sonuc= 0;
	
		FILE *ptr  = fopen( "doktor.dat", "r+b" ) ;
	
	
		while (fread(&d1, sizeof(d1), 1, ptr) == 1)  //ptr dosya işaretçisinden struct doktor boyutunda veri okur ve d1 yapısına yazar
		{
			if( strcmp( tc ,d1.tc )==0 && strcmp( dtarih, d1.dtarih  ) ==0  ) //Eğer tc ve dtarih değerleri d1 yapısındaki tc ve dtarih alanları ile eşleşirse, sonuc değişkeninin değeri bir yapılır ve while döngüsünden çıkılır.
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
		struct doktor d1; //d1 adında struct doktor tipinde bir veri yapısı oluşturur.

		int adet=0; //adet değişkenini sıfır olarak ayarlar 
	
		printf("%s\t%s\t%s\t%s\t%s\t%s\n", "kNo", "dNo", "T.C", "AD", "SOYAD","DOGUM TARİHİ" ) ; //kNo, dNo, T.C, AD ve SOYAD sütun başlıklarıyla birlikte bir tablo başlığı ekrana yazdırır.
	
		FILE *ptr= fopen("doktor.dat", "r+b") ;
		while( fread( &d1, sizeof(struct doktor), 1, ptr ) >0  ) //d1 yapısına dosyadan struct doktor boyutunda veri okur. Dosyada okunacak veri kalmadığı sürece while döngüsü devam eder.
		{
			adet++; //adet değişkeninin değerini bir artırır
			printf("%d\t%d\t%s\t%s\t%s\t%s\n", d1.klinikNo, d1.doktorNo, d1.tc, d1.ad, d1.soyad,d1.dtarih) ; //d1 yapısındaki klinikNo, doktorNo, tc, ad ve soyad alanları ekrana yazdırır.
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
    printf("HASTALARİ LİSTELEME EKRANI ! \n");
    printf("%s\t%s\t%s\t%s\n", "TC", "AD", "SOYAD", "TEL");

    FILE *ptr = fopen("hasta.dat", "rb"); // hasta.dat dosyasından hasta bilgilerini oku ve ekrana yazdır
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
    printf("Hasta Sayisi: %d\n", adet); // Toplam hasta sayısını ekrana yazdır
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

    int sonuc=0, sayac=0; // Sonuç ve sayac değişkenlerini tanımlar.
    printf("HASTALARI GÜNCELLEME EKRANI\n");
    printf("Güncelleme yapmak istediğiniz hastanın T.C kimlik NOsu: ");
    scanf("%d", &tc_yeni);

    FILE *ptr = fopen("hasta.dat", "r+b"); // Hasta dosyasını okuma ve yazma modunda açar.
    FILE *hPtr = fopen("hastarandevusuz1.dat", "r+b");
    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0)
    {
        if (tc_yeni == h1.tc) //// T.C kimlik numarası eşleşirse,
        {
            sonuc=1; // // Sonuc değişkenini 1 yapar.
            printf("%d\t%s\t%s\t%d\n", h1.tc, h1.ad, h1.soyad, h1.tel); // Hasta bilgilerini ekrana yazdırır.
            break;
        }
        sayac++; // Sayac değişkenini arttırır.
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

    if (sonuc == 0) // Sonuç değişkeni hala 0 ise, kayıt yoktur
    {
        printf("%d TC NUMARALI KAYIT YOK!\n", tc_yeni);
        fclose(ptr);
    }
    else // Kayıt varsa,
    {
        printf("TC: ");
        scanf("%d", &tc_yeni);
        printf("AD: ");
        scanf(" %[^\n]s", ad_yeni);
        printf("SOYAD: ");
        scanf(" %[^\n]s", soyad_yeni);

        while (1) { // Geçerli bir GSM numarası girilene kadar döngü devam eder.
            printf("GSM: ");
            int ret = scanf("%d", &tel_yeni);
            if (ret == 1) {  // Geçerli bir girdi varsa, döngü sona ere
                break;
            }
            printf("Geçersiz giris. Lütfen geçerli  sayi degeri giriniz.\n");
                while (getchar() != '\n');
        }

        rewind(ptr); //
                 // Yeni hasta bilgileri, hasta yapısına aktarılır.

        h1.tc = tc_yeni;
        strcpy(h1.ad, ad_yeni);
        strcpy(h1.soyad, soyad_yeni);
        h1.tel = tel_yeni;

        fseek(ptr, (sayac - 1) * sizeof(struct hasta), 0); // Dosya konum göstergesini belirtilen kayda getirir.
        fwrite(&h1, sizeof(struct hasta), 1, ptr); // Dosyaya yeni verileri yazar.
        fclose(ptr);
        printf("Güncelleme işlemi başarıyla tamamlandı.\n");
    }

    printf("0- Ana menüye dön\n");
    printf("Seçiminiz: ");
    scanf("%d", &secim);
    switch (secim)
    {
        case 0:
            break;
        default:
            printf("Hatalı seçim yaptınız, ana menüye yönlendiriliyorsunuz.\n");
            break;
    }
}
	
void Kayitsilme()
{
    system("cls");
    int secim;
    struct hasta h1;
    int tc, sonuc = 0; // tc numarası ve sonuç değişkenleri tanımlanır
    printf("KAYIT SİLME EKRANI !\n");
    printf("SİLMEK İSTEDİGINIZ VATANDASIN T.C KIMLIK NUMARASI: ");
    scanf("%d", &tc);
    FILE *ptr = fopen("hasta.dat", "r+b");
    FILE *hPtr = fopen("hastarandevusuz1.dat", "rb");
    FILE *ptr2 = fopen("yedekdosya.dat", "w+b");
    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) // hasta.dat dosyasındaki tüm kayıtlar okunur
    {
        if (tc != h1.tc) //"tc" değişkeninin "h1.tc" değişkeninin değerine eşit olmadığını kontrol ediyor.
        {
            fwrite(&h1, sizeof(struct hasta), 1, ptr2); // h1 yapısı yedekdosya.dat dosyasına yazılır
        }
        else
        {
            sonuc = 1; // eğer aranan tc numarası h1.tc numarasına eşitse sonuc değişkeni 1 olur
        }
    }
    while (fread(&h1, sizeof(struct hasta), 1, hPtr) > 0) // hastarandevusuz1.dat dosyasındaki tüm kayıtlar okunur
    {
        if (tc != h1.tc)
        {
            fwrite(&h1, sizeof(struct hasta), 1, ptr2);
        }
        else
        {
            sonuc = 1; // eğer aranan tc numarası h1.tc numarasına eşitse sonuc değişkeni 1 olur
        }
    }
    fclose(ptr);
    fclose(hPtr);
    fclose(ptr2);
    if (sonuc == 0) // eğer sonuc değişkeni hala 0 ise
    {
        printf("%d T.C Nolu Hasta Kaydi bulunamadi \n", tc);
    }
    else
    {
        remove("hasta.dat"); // hasta.dat dosyası silinir
        remove("hastarandevusuz1.dat");
        rename("yedekdosya.dat", "hasta.dat");
        printf("Hasta Kaydi Silindi\n");
    }
    printf("0- Ana menuye don\n");
    printf("Seciminiz: ");
    scanf("%d", &secim);
    switch (secim)
    {
    case 0:  // eğer seçim 0 ise
        break;
    default:
        printf("Hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz\n");
    }
}
	void hastaara()
{
    system("cls");
    
    struct hasta h1;
    int tc, sonuc = 0; // tc numarası ve sonuç değişkenleri tanımlanır
    printf("HASTA KAYIT ARAMA EKRANI ! \n");
    printf("ARAMAK ISTEDIGINIZ VATANDASIN T.C KIMLIK NUMARASI: ");
    scanf("%d", &tc);
    
    FILE *ptr = fopen("hasta.dat", "rb");
    FILE *hPtr = fopen("hastarandevusuz1.dat", "rb");
    
    while (fread(&h1, sizeof(struct hasta), 1, ptr) > 0) // hasta.dat dosyasındaki tüm kayıtlar okunur
    {
        if (tc == h1.tc) // eğer aranan tc numarası h1.tc numarasına eşitse
        {
            sonuc = 1; // sonuc değişkeni 1 olur
            break;
        }
    }
    
    if (sonuc == 0) // eğer sonuc değişkeni hala 0 ise
    {
        while (fread(&h1, sizeof(struct hasta), 1, hPtr) > 0) // hastarandevusuz1.dat dosyasındaki tüm kayıtlar okunur
        {
            if (tc == h1.tc) // eğer aranan tc numarası h1.tc numarasına eşitse
            {
                sonuc = 1;
                break;
            }
        }
    }
    
    if (sonuc == 0) // eğer sonuc değişkeni hala 0 ise
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
		printf("1- RANDEVU AL /HASTA KAYİT \n") ;
		printf("2- RANDEVULARIM / RANDEVU İPTAL ET! \n");
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
		printf("  SEKRETER GİRİS EKRANI\n\n") ;
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
			case 1: hastaKayit(); break; // Hasta kaydı yapmak için hastaKayit() fonksiyonunu çağırır.
			case 2: DoktoryeniKayit() ; break;
			case 3: doktorlariListele(); break;
		    case 4: hastalariListele(); break;
		    case 5: hastaara(); break;
		    case 6: HastaKayitGuncelleme(); break;
		    case 7: Kayitsilme (); break;
		 
			case 0:  break; //Kullanıcının çıkış yapmak istediği durumda programı sonlandırır.
			default : printf("hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz \n") ;
		}
	}
	
	int menu() {
	setlocale(LC_ALL, "Turkish");
	int secim; //Kullanıcının seçtiği menü seçeneğini tutmak için bir değişken tanımlanır.
	
	printf("\n\n HASTANE OTOMASYON PROGRAMI \n\n");
	
	printf("   1-  HASTA GİRİŞ \n");
	printf("   2-  SEKRETER GİRİŞ \n");
	printf("   3-  DOKTOR GİRİŞ \n");
	printf("   0- Programi Kapat \n");
	printf("   Seciminiz :  ");
	
	while (scanf("%d", &secim) != 1 || (secim != 0 && secim != 1 && secim != 2 && secim != 3)) {  /* Kullanıcının geçerli bir seçim yapması için while döngüsü kullanılır.
	                                                                                             scanf() fonksiyonuyla kullanıcının seçimi okunur ve geçerli bir seçim yapılıncaya kadar döngü devam eder. */
	    printf("Hatalı secim! Lütfen geçerli bir seçim yapın (0-3 arasında bir sayı): ");
	    while (getchar() != '\n'); //Yanlış girişlerin hafızadan temizlenmesi için kullanılır.
	}
	
	return secim; //Kullanıcının seçtiği seçenek değeri döndürülür.
	}
	
	int main() {

system("color 70");

 


	int secim = menu(); //kullanıcının seçim yapması için menu() fonksiyonu çağırılır ve seçim değeri secim değişkenine atanır.
	
	while (secim != 0) { // Kullanıcı çıkış yapana kadar seçim yapmasını sağlayan döngü başlatılır.
	    switch (secim) { //secim değişkeninin değerine göre ilgili fonksiyonlar çağırılır.
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
	
	    secim = menu(); //Kullanıcının menüden seçim yapması için menu() fonksiyonu çağrılır ve seçim değeri secim değişkenine atanır.
	}
	
	return 0;
	}
