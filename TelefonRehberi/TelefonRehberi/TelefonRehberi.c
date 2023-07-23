#include<stdio.h>
#include<stdlib.h>

int main(void) {

    int* yildiz, yld;
    yildiz = &yld;
    printf("%d\n", yildiz);
    yildiz = yildiz + 1;
    printf("%d\n", yildiz);


    char isim[25][20]; ///isimlerin tutulduğu array
    char soyIsim[25][20]; ///soyisimlerin tutuldugu array
    long long int numara[25]; ///numaraların tutuldugu array
    int i = 0, kisiSayisi = 1;

    printf("\n---TELEFON REHBERI---\n");

    printf("\nKac kisi girmek istiyorsunuz (max 25 kisi girebilirsiniz) :\n");
    scanf_s("%d", &kisiSayisi);

    if (kisiSayisi > 25) {
        kisiSayisi = 25; ///kisi sayısını 25 e getiren kontrol
    }
    else if (kisiSayisi <= 0) {
        kisiSayisi = 1;
    }

    for (i = 0; i < kisiSayisi; i++) { ///kisilerin rehbere girildigi döngü

        printf("isim giriniz :\n");
        scanf_s(" %s", &isim[i], 20);


        printf("soyisim giriniz :\n");
        scanf_s(" %s", &soyIsim[i], 20);

        printf("%s icin telefon numarasi giriniz :\n", isim[i]);
        scanf_s(" %lld", &numara[i]);

        printf("Kisi basari ile kayit edildi ! \n\n");

    }

    long long int arananNo = 0;
    long long int temp3;
    long long int yeniNo;
    int islem , silmeIslemi = 0, aramaIslemi = 1;
    int bulma = 0;
    int listeBastırma = 1;
    int z, j, k;
    int cevirme;
    int durum;
    int sıralama = 0;
    char arananIsim[20];
    char yeniIsim[20];
    char isimSil[20];
    char temp[20];
    char temp2[20];


    printf("Kisileri:\nIsimlerine gore siralama \t-1-\nsoyisimlerine gore siralama \t-2-\nnumaralarina gore siralama \t-3-\n\n");

    scanf_s(" %d", &sıralama); /// sıralama değişkeni 3. döngünün içinde switch yapısında kullanılarak hangi veriye göre sıralma yapılacagı belirleniyor


    while (1) { ///sonsuz döngü çıkış yapılana kadar döner

        if (listeBastırma == 1) { 

            /// BUBBLE SORT kullanarak sıralama

            for (z = 0; z < kisiSayisi - 1; z++) { /// bu komut baloncuk gönderiyor
                cevirme = 0;
                for (i = 0; i < kisiSayisi - 1; i++) { /// bu komut baloncugu ilerletiyor

                    for (j = 0; j < 20; j++) {  /// bu komut baloncugun kendisi. Burada kelimelere harf harf bakılıyor ve kücük olan ileri alınacak sekilde yer değiştiriliyor

                        durum = 2;
                        switch (sıralama) { /// yukarıda bahsedilen switch yapısı hangi veriye göre sıralama yapılacağını belirliyor
                        case 1:
                            if ((int)(isim[i][j]) > (int)(isim[i + 1][j])) { /// burada durum 1 i.verinin i + 1 dan küçük oldugunu dolayısıyla yer değiştirme olması gerektiğini söylüyor
                                durum = 1;                                   /// durum 0 ise zaten i + 1. verinin i. veriden küçük oldugunu söylüyor ve herhangi bir değişiklik yapmadan baloncuk devam ediyor
                            }
                            else if ((int)(isim[i][j]) < (int)(isim[i + 1][j])) {
                                durum = 0;
                            }
                            break;
                        case 2:
                            if ((int)(soyIsim[i][j]) > (int)(soyIsim[i + 1][j])) {
                                durum = 1;
                            }
                            else if ((int)(soyIsim[i][j]) < (int)(soyIsim[i + 1][j])) {
                                durum = 0;
                            }
                            break;
                        case 3:
                            if (numara[i] > numara[i + 1]) {
                                durum = 1;
                            }
                            else if (numara[i] < numara[i + 1]) {
                                durum = 0;
                            }
                            break;
                        }


                        if (durum == 1) {///bu kısımda strcpy() kullanılamadıgı için her bir kelime harf harf yer değiştirilmiştir
                            cevirme = 1; ///cevirme değişkenin 1 olması sıralma işleminin bitmedigini gösterir
                            for (k = 0; k < 20; k++)
                            {
                                temp[k] = isim[i + 1][k]; ///isimin tempe atılması
                            }
                            for (k = 0; k < 20; k++)
                            {
                                temp2[k] = soyIsim[i + 1][k]; ///soyisimin tempe atılması
                            }
                            temp3 = numara[i + 1]; ///numaranın tempe atılması

                            for (k = 0; k < 20; k++)
                            {
                                isim[i + 1][k] = isim[i][k];
                            }
                            for (k = 0; k < 20; k++)
                            {
                                soyIsim[i + 1][k] = soyIsim[i][k];
                            }
                            numara[i + 1] = numara[i];


                            for (k = 0; k < 20; k++)
                            {
                                isim[i][k] = temp[k];
                            }
                            for (k = 0; k < 20; k++)
                            {
                                soyIsim[i][k] = temp2[k];
                            }
                            numara[i] = temp3;
                            break;
                        }

                        else if (durum == 0) {
                            break;
                        }

                    }

                }
                if (cevirme == 0) { /// bu komut bubble sort da fazladan islem yapmamak icin daha önceki turda bir cevirme islemi olmamıssa donguyu sonlandırmaya yaramaktadır
                    break;
                }
            }

            int a = 0;
            for (a = 0; a < kisiSayisi; a++) { ///listeyi ekrana bastıran döngü
                printf("%d - %s %s\t\t%lld\n", a + 1, isim[a], soyIsim[a], numara[a]);
            }
            printf("\n");
            listeBastırma = 0;
            sıralama = 1;
        }
        ///BUBBLE SORT



        printf("Yapacaginiz islemi secin:\nYeni kayit yapma \t-1-\nKayitli kisi Bulma  \t-2-\n");
        printf("Cikis yapma \t\t-0-\n");
        scanf_s(" %d", &islem); ///yapılcak işlem buradan alınılıyor

        switch (islem) {
        case 1: ///yeni kayıt işlemi

            printf("isim giriniz :\n");
            scanf_s(" %s", &isim[kisiSayisi], 20);


            printf("soyisim giriniz :\n");
            scanf_s(" %s", &soyIsim[kisiSayisi], 20);

            printf("%s icin telefon numarasi giriniz :\n", isim[kisiSayisi]);
            scanf_s(" %lld", &numara[kisiSayisi]);

            printf("Kisi basari ile kayit edildi ! \n\n");
            kisiSayisi += 1;
            listeBastırma = 1;
            break;

        case 2:
            printf("Neye gore arama yapacaginizi girin:\nIsme gore arama yapma \t\t-1-\nSoyisme gore arama yapma \t-2-\nNumaraya gore arama yapma \t-3-\n");
            scanf_s("%d", &aramaIslemi);
            if (aramaIslemi == 1) {
                ///İsme göre arama --- Lineer search algoritması
                printf("Aranan ismi giriniz :\n");
                scanf_s(" %s", &arananIsim, 20);
                bulma = 0;
                for (i = 0; i < kisiSayisi; i++) {
                    for (j = 0; j < 20; j++) {
                        if (arananIsim[j] != isim[i][j]) {
                            bulma = 0;
                            break;
                        }
                        bulma = 1;///bulma değişkeninin 1 olması aranan kişinin bulundugunu haber verir aksi halde kişi bulunamamıştır yazısı gözükür
                    }
                    if (bulma == 1) {
                        printf("Aradiginiz isimin bilgileri :\n");
                        printf("%s %s   %lld\n\n", isim[i], soyIsim[i], numara[i]);
                        break;
                    }
                }
                if (bulma == 0) {
                    printf("Aradiginiz kisi bulunamamistir ! \n\n");
                }
            }
            else if (aramaIslemi == 2) {
                ///Soyisme göre arama
                printf("Aranan soyismi giriniz :\n");
                scanf_s(" %s", &arananIsim, 20);
                bulma = 0;
                for (i = 0; i < kisiSayisi; i++) {
                    for (j = 0; j < 20; j++) {
                        if (arananIsim[j] != soyIsim[i][j]) {
                            bulma = 0;
                            break;
                        }
                        bulma = 1;
                    }
                    if (bulma == 1) {
                        printf("Aradiginiz soyisimin bilgileri :\n");
                        printf("%s %s   %lld\n\n", isim[i], soyIsim[i], numara[i]);
                        break;
                    }
                }
                if (bulma == 0) {
                    printf("Aradiginiz kisi bulunamamistir ! \n\n");
                }
            }
            else if (aramaIslemi == 3) {
                ///numaraya göre arama
                printf("Aranan numarayi giriniz :\n");
                scanf_s("%lld", &arananNo);
                bulma = 0;
                for (i = 0; i < kisiSayisi; i++) {
                    if (numara[i] == arananNo) {
                        bulma = 1;
                        printf("\nAradiginiz numaranin bilgileri :\n");
                        printf("%s %s   %lld\n\n", isim[i], soyIsim[i], numara[i]);
                        break;
                    }
                }
                if (bulma == 0) {
                    printf("Aradiginiz numara bulunamamistir\n\n");
                }
            }

            if (bulma != 0) {///bulma değişkeni yukarıda aranan kişinin bulunduğunu yani bilgi değiştirme ve silme işlemlerinin yapılabileceğini  haber verir
                printf("Bilgilerde degisiklik \t-1-\nKisiyi silme \t\t-2-\nGeri donme \t\t-0-\n");
                scanf_s("%d", &islem);
                switch (islem) {
                case 1:
                    printf("Degistirmek istediginiz bilgiyi tuslayin :\nIsim icin \t-1-\nSoyisim icin \t-2-\nNumara icin \t-3-\n");
                    scanf_s("%d", &islem); ///değiştirilmek istenilen bilgiyi alan komut
                    switch (islem) {
                    case 1:
                        printf("Yeni isim giriniz\n");
                        scanf_s(" %s", &yeniIsim, 20); ///basit değiştirme işlemleri
                        for (k = 0; k < 20; k++)
                        {
                            isim[i][k] = yeniIsim[k];
                        }
                        printf("Isim basari ile degistirilmistir\n\n");
                        listeBastırma = 1;
                        break;
                    case 2:
                        printf("Yeni soyisim giriniz\n");
                        scanf_s(" %s", &yeniIsim, 20);
                        for (k = 0; k < 20; k++)
                        {
                            soyIsim[i][k] = yeniIsim[k];
                        }
                        printf("Soyisim basari ile degistirilmistir\n\n");
                        listeBastırma = 1;
                        break;
                    case 3:
                        printf("Yeni bir numara giriniz\n");
                        scanf_s("%lld", &yeniNo);
                        numara[i] = yeniNo;
                        printf("Numara basari ile degistirilmistir\n\n");
                        listeBastırma = 1;
                        break;
                    }
                    break;
                case 2:
                    printf("Dikkat bu islem geri alinamaz yinede onayliyor musunuz ?\nEvet \t-1-\nHayir \t-0-\n");
                    scanf_s("%d", &silmeIslemi);
                    if (silmeIslemi == 1) { ///silme işlemi

                        for (i = i; i < kisiSayisi - 1; i++) {
                            ///kisi sayısından bir az olacak kez alttaki kisi üsttekine yapıştırılıyor ve sonda en alttaki kisiden 2 tane olacagından en son kisi siliniyor
                            for (k = 0; k < 20; k++)
                            {
                                isim[i][k] = isim[i + 1][k];
                            }
                            for (k = 0; k < 20; k++)
                            {
                                soyIsim[i][k] = soyIsim[i + 1][k];
                            }
                            numara[i] = numara[i + 1];

                        }///son kişinin silinmesi
                        for (k = 0; k < 20; k++)
                        {
                            isim[i][k] = '\0';
                        }
                        for (k = 0; k < 20; k++)
                        {
                            soyIsim[i][k] = '\0';
                        }
                        numara[i] = '\0';

                        printf("Kisi basari ile silinmistir !\n\n");
                        listeBastırma = 1;
                        kisiSayisi -= 1;///kişi sayısının azaltılması
                    }
                    break;

                }
                islem = 1;
            }
        }
        if (islem == 0) { ///çıkış işlemi
            break;
        }
    }
    return 0;
}

