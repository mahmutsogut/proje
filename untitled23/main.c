#include <stdio.h>

int main() {
    int peynirsayısı = 8;
    int ailesayısı = 10;
    int puanlar[peynirsayısı][ailesayısı];
    int i,j;
    int toplam_peynirpuani[8] = {0} ;
    int toplam_ailepuani[10] = {0} ;
    char girdi[100];
    char cikti[100];

    printf("Puanlarin tutuldugu dosyanin adini giriniz :");  //Girdi dosyasının adı girilir
    scanf("%s", girdi);

    printf("Sonuclar hangi dosyaya kaydedilsin  :");      //Çıktı dosyasının adı girilir
    scanf("%s", cikti);

    FILE *puan = fopen(girdi,"r");   // Puan Dosyasını açar

     if (puan == NULL){     //Puan dosyasının açılıp açılmadığını kontrol eder
        printf("Puan dosyasi acilamadi.");
        return 1;
    }

     for (i = 0; i < peynirsayısı; i++) {
        for (j = 0; j < ailesayısı; j++) {
            fscanf(puan,"%d" , &puanlar[i][j]);  // Puanları ilgili değişkenlere atar
        }
    }
    fclose(puan);  //Puan dosyasını kapatır

    int maxpuan = 0;
    int encokbegenilen = 0;
    for (i = 0; i < peynirsayısı; i++) {
        for (j = 0; j < ailesayısı; j++) {
            toplam_peynirpuani[i] += puanlar[i][j]; //Peynirlere verilen toplam puanı hesaplar
        }
        if (toplam_peynirpuani[i] > maxpuan) {   //En yüksek puan alan peyniri bulur
            maxpuan = toplam_peynirpuani[i];
            encokbegenilen = i + 1; //En çok beğenilen peynir numarası
        }
    }
    int minailepuan = 100;
    int minbegenen = 0;
    for (j = 0; j < ailesayısı; j++) {
        for (i = 0; i < peynirsayısı; i++) {
            toplam_ailepuani[j] += puanlar[i][j];    //Ailelerin toplam verdiği puanı hesaplar
        }
        if (toplam_ailepuani[j] < minailepuan) {  //En az beğenen aile numarası bulur
            minailepuan = toplam_ailepuani[j];
            minbegenen = j + 1;   //En az beğenen aile numarası
        }

    }
    FILE *sonuc = fopen(cikti,"w");  //Sonuc dosyasını açar
    if(sonuc ==NULL){       //Sonuç dosyasının açılıp açılmadığını kontrol eder
        printf("Sonuc dosyası acilamadi.");
        return 1;
    }
    fprintf(sonuc,"En çok beğenilen ürün no:  %d \n", encokbegenilen);
    fprintf(sonuc,"En az beğenen aile no:  %d  \n" ,  minbegenen);
    fclose(sonuc);     //Sonuç dosyasını kapatır
    printf("Sonuc dosyasi basariyla olusturuldu.");
    return 0;
}





