#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define TUR  (3)
FILE*odev;
int telefon(char x[12]);
char cho1, ad[60];
int a,menu;
struct rehber
{
char isim[80];
char soyad[80];
char no[12];
}info;
void kisisil();
void geridon();
void kisidegistir();

void kisiekleme()
{

odev=fopen("kayit.txt","a");

system("cls");
printf("Kisinin adi:\t \n");
scanf("%s",&info.isim);

printf("Kisinin Soyadi:\t \n");
scanf("%s",&info.soyad);

printf("Kisinin Cep tel nosu:\t \n");
scanf("%s",&info.no);

fprintf(odev,"%s %s %s ",info.isim,info.soyad,info.no);

fclose(odev);
bas:
printf("Kayit yapildi. Ana menu icin 6, Cikis icin 5'e basiniz.");
scanf("%d",&a);
if (a==6)
{
  main();
}
else if(a==5)
{
    exit(1);
}
else{
    geridon();
}
}
void geridon()
{
	printf("Yalnis tuslama yaptiniz tekrar deneyiniz\n");
	sleep(3);
    kisiekleme();
}

void secim()
{

char x;
            printf("Boyle biri yoktur\n");
            printf("Tekrar denemek ister misiniz E/H\n");
            scanf(" %c",&x);
            if(x == 'e'|| x == 'E')
            {
            	kisisil();
			}
             if(x=='h' || x=='H');
            {
                main();
            }
        }

        void secim2()
{

char x;
            printf("Boyle biri yoktur\n");
            printf("Tekrar denemek ister misiniz E/H\n");
            scanf(" %c",&x);
            if(x == 'e'|| x == 'E')
            {
            	kisidegistir();
			}
             if(x=='h' || x=='H');
            {
                main();
            }
        }

void kisisil(char isim[80])
{
  while(1){

  system("cls");
  FILE*odev,*temp;
  char a='b';
  odev=fopen("kayit.txt","r");
  temp=fopen("kayit1.txt","w");
  if(odev == NULL)
  {
      printf("Rehberiniz bostur\n");
      sleep(2000);
      main();
  }
    else
    {
        rewind(odev);

        printf("Silmek istediginiz kisinin ismini giriniz\n");
        _flushall();
        gets(ad);
        while(!feof(odev))
        {
            fscanf(odev,"%s %s %s",&info.isim,&info.soyad,&info.no);
             if(!strcmp(info.isim,ad))
             {
                 printf("Islem basariyla tamamlanmistir\n");
                 a='c';
             }
             else{
                fprintf(temp,"%s %s %s\n",info.isim,info.soyad,info.no);
             }

        }
        _fcloseall();
        remove("kayit.txt");
        rename("kayit1.txt","kayit.txt");
        if(a=='b')
        {
           secim();
        }
        else{
            printf("Menuye gidiliyor\n");
            Sleep(3000);
            main();
        }



    }
}
}
void gorme()
{

odev = fopen("kayit.txt","r");
rewind(odev);
char k;
if(odev == NULL)
{

    printf("Rehberiniz bos\n");
    printf("Rehberinize yeni biri eklemek ister misiniz?E/H");
    scanf(" %c",&k);

    if(k=='E' || k=='e')
    {
        kisiekleme();
    }
    else if(k=='h' || k=='H')
    {
        main();
    }


}

else
{
    system("cls");


    printf("\t\t\t\t\t\t\tREHBER\n");
    while(fscanf(odev,"%s%s%s",&info.isim,&info.soyad,&info.no) !=EOF)
    {

        printf("\n\t\t\tIsim: %s\t\t\tSoyad: %s\t\t\tNo: %s\n",info.isim,info.soyad,info.no);

    }
}

fclose(odev);
getch();
printf("\nMenu icin 6 tusuna basiniz, cikmak icin 5 tusuna basiniz\n ");
scanf("%d",&a);
if(a==6)
{
    main();
}
else if(a==5)
{
    exit(1);
}
else
{
    printf("Yanlis tuslama Menuye yonlendiriliyorsunuz");
    sleep(3000);
    main();
}

}

void kisiarama(){
	FILE *d1;
system("CLS");
			printf("Aranacak kisinin numarasini giriniz\n");
			scanf("%s",&info.no);
			printf("\n");
			printf("Aradiginiz kisiye su an ulasilamiyor lutfen daha sonra tekrar deneyiniz\n\n");
			d1=fopen("aramalar.txt","a");
			fprintf(d1,"%s\n",info.no);
			fclose(d1);
			sleep(3);
			main();
}
void aranannumaralar(){
	FILE *d1;
	char k1;
	d1=fopen("aramalar.txt","r");
			system("CLS");
			printf("Arayanlar Listesi\n");
			do{

			k1=getc(d1);

			putchar(k1);

			}while(!feof(d1));
			fclose(d1);
}
 void kisidegistir(int numara)
{
  while(1){

  system("cls");
  FILE*odev,*temp;
  char a='b';
  odev=fopen("kayit.txt","r");
  temp=fopen("kayit1.txt","w");
  if(odev == NULL)
  {
      printf("Rehberiniz bostur\n");
      sleep(2000);
      main();
  }
    else
    {
        rewind(odev);

        printf("Degistirmek istediginiz kisinin numarasini giriniz\n");
        _flushall();
        gets(numara);
        while(!feof(odev))
        {
            fscanf(odev,"%s %s %s",&info.isim,&info.soyad,&info.no);
             if(!strcmp(info.no,numara))
             {
             	 printf("Kisinin adi : ");
                 scanf("%s",&info.isim);
                 printf("Kisinin soyadi : ");
                 scanf("%s",&info.soyad);
                 printf("Kisinin cep tel nosu : ");
                 scanf("%s",&info.no);
                 printf("\n");
                 printf("Islem basariyla tamamlanmistir\n");
                 fprintf(temp,"%s %s %s\n",info.isim,info.soyad,info.no);
                 a='c';
             }
             else{
                fprintf(temp,"%s %s %s\n",info.isim,info.soyad,info.no);
             }

        }
        _fcloseall();
        remove("kayit.txt");
        rename("kayit1.txt","kayit.txt");
        if(a=='b')
        {
           secim2();
        }
        else{
            printf("Menuye gidiliyor\n");
            Sleep(3000);
            main();
        }



    }
}
}
void oyun(){
	system("cls");
	int nn,x,y,tahmin,sayi,q,w,bosluksayisi=45,oyunsecim;
	printf("Oynayacagimiz bu oyun sayi tahmin etme oyunudur.\n\n\n");
	sleep(2);
	printf("Ben aklimdan bir sayi tutacagim ve sen onu bilmeye calisacaksin.\n\n\n");
	sleep(2);
	printf("Benim sececegim bu sayi x ve y sayilari arasinda olacaktir.\n");
	printf("Not: x ve y dahil !\n\n\n");
	sleep(2);
	printf("Lutfen x sayisini gir\t");
	scanf("%d",&x);
	printf("\n");
	printf("Lutfen y sayisini gir\t");
	scanf("%d",&y);
	printf("\n");
	srand(time(0));
	if(x>y)
	{
		printf("x sayisi y sayisinden kucuk olmalidir,lutfen bir daha giriniz");
		sleep(3);
		oyun();
	}
	else if(x<=y)
	{
	printf("Tahminin nedir?\t");
	scanf("%d",&tahmin);
	sayi=x + rand() % y-x+1;
	if(sayi==tahmin)
	{
		system("cls");
		for(q=1;q<=20;q++)
		{
			for(w=1;w<=bosluksayisi;w++)
			{
				printf(" ");
			}
			bosluksayisi--;
			for(w=1;w<=2*q-1;w++)
			{
				printf("*");
			}printf("\n");
		}
		printf("\n\t\t\t\t    Tebrikler Dogru Cevap\n\n");
		printf("\n\n");
		printf("Bir daha denemek icin 1'e, Ana menuye donmek icin 2'ye basiniz \n");
		scanf("%d",&oyunsecim);

		if(oyunsecim==1)
		{
			oyun();
		}
		else if(oyunsecim==2)
		{
			main();
		}

	}
	else
	{
		printf("Bilemediniz\n\n");
		printf("Bir daha denemek icin 1'e, Ana menuye donmek icin 2'ye basiniz \n");
		scanf("%d",&oyunsecim);
		if(oyunsecim==1)
		{
			oyun();
		}
		else if(oyunsecim==2)
		{
			main();
		}
		else
		{
			exit(1);
		}
	}
	}
}

void oyunbaslangici(){
		system("cls");
		int n;
		printf("Birinin aramasini bekliyorsaniz eger, biraz vakit gecirmek icin oyun oynayabilirsin.\n\n");
		sleep(2);
		printf("Devam etmek icin 1'e, menuye geri donmek icin 2'ye basiniz \n");
		scanf("%d",&n);
		if(n==1)
		{
			oyun();
		}
		else if(n==2)
		{
			main();
		}
	}

int main()
{
	time_t zaman;
	struct tm *ptm;
	time (&zaman);
	ptm = gmtime(&zaman);

    system("cls");



    printf("\n\t\t\t\t\t\t   REHBER OTOMASYONU \n");	//
    printf("\n\t\t\t\t\t\t Saat : %0.2d:%0.2d \n",ptm->tm_hour + TUR, ptm->tm_min);	//
	printf("\t\t\t\t\t\t************************** \n");
	printf("\t\t\t\t\t\t# 1. Kisi Ekle           #\n");
	printf("\t\t\t\t\t\t# 2. Kisi sil            #\n");
	printf("\t\t\t\t\t\t# 3. Rehberi Goruntule   #\n");
	printf("\t\t\t\t\t\t# 4. Kisi arama yap      #\n");
	printf("\t\t\t\t\t\t# 5. Aranan Numaralar    #\n");
	printf("\t\t\t\t\t\t# 6. Kisi Degistir       #\n");
	printf("\t\t\t\t\t\t# 7. Mini Oyun           #\n");
	printf("\t\t\t\t\t\t# 8. Cikis               #\n");
	printf("\t\t\t\t\t\t************************** \n");
	printf("\t\t\t Seciniz: ");
	scanf("%d",&cho1);


	if(cho1== 1 || cho1==2 || cho1==3 || cho1==4 || cho1==5 || cho1 ==6 || cho1 == 7 )
    {
        switch (cho1)
        {
            case 1: kisiekleme();
            break;
            case 2: kisisil(ad);
            break;
            case 3:gorme();
            break;
            case 4: kisiarama();
            break;
            case 5: aranannumaralar();
            break;
            case 6: kisidegistir(ad);
            break;
            case 7: oyunbaslangici();
            break;

        }
    }

















}




