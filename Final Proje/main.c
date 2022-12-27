#include <stdio.h>
#include <stdlib.h>

/* */

int main() 
{
	KarsilamaMetni();
		
	char kelime1[20];
	char kelime2[50];
	int telnum=0;
	int tostfiyati[4]={20,20,25,25};
	int icecekfiyati[3]={15,10,5};
	int tost;
	int toplamfiyat;
	int icecek;
	int icecekmenu=0;
	int menu=0;
	
	while(1)
{
	toplamfiyat=0;
	
	printf("Menuyu gormek icin 1'i tuslayiniz;\nCikmak icin 0'i tuslayiniz.\n");
	scanf("%d",&menu);
		if(menu>=2)
			{
				printf("Yanlis urun kodu girdiniz lutfen tekrar deneyiniz.\n");
				continue;	
			}	

	if(menu==1)
	{	
		tostmenu();
		scanf("%d",&tost);
			if(tost>=4)
			{
				printf("Yanlis urun kodu girdiniz lutfen tekrar deneyiniz.\n");
				continue;			
			}
			//siparisin ne olduðunu yazdýrabilirsin.**********************************
				  
		printf("Icecek istiyorsaniz 1'i tuslayiniz;\nistemiyorsaniz 0'i tuslayiniz\n");	
 		scanf("%d",&icecekmenu);
 		
			if(icecekmenu>=2)
			{
				printf("Yanlis urun kodu girdiniz lutfen tekrar deneyiniz.\n");
				continue;			
 			}
		 if(icecekmenu==1)
 		{
			icecekmenusu();
			scanf("%d",&icecek);		
				if(icecek==3)
					printf("Icecek almamayi sectiniz.\n");
				if(icecek>=4)
				{
					printf("Yanlis urun kodu girdiniz lutfen tekrar deneyiniz.\n");
					continue;			
				}	
		}
		else if(icecekmenu==0)
			icecekfiyati[icecek]=0;
			
		toplamfiyat=fiyathesapla(tostfiyati[tost],icecekfiyati[icecek]);
		
	gets(kelime1);
	printf("Lutfen telefon numarasi giriniz.\n");
	scanf("%d",&telnum);
	
	printf("Lutfen adres giriniz.\n");
	gets(kelime2);
    gets(kelime2);
	
	printf("Siparisiniz %d TL tutmustur.\n",toplamfiyat);
	printf("Sayin musterimiz %s adresine siparisiniz gonderilecektir.\nBizi tercih ettiginiz icin tesekkur ederiz.\n",kelime2);
	
	printf("Tekrar siparis vermek ister misiniz?(E;H)\n");	
	char siparistekrar;
	scanf("%c",&siparistekrar);
	if(siparistekrar=='E' || siparistekrar=='e')
	{
		continue;
	}
	else if(siparistekrar=='H' || siparistekrar=='h')
		printf("Yine bekleriz iyi gunler\n");
		break;
	}
	else if(menu==0)
		printf("Yine bekleriz iyi gunler\n");
		break;
}		
	return 0;
}	
void KarsilamaMetni()
{
	char ad[30];
	printf("Magazamiza Hosgeldiniz.\n");
	printf("Sayin musterimiz isminizi giriniz.\n");
	gets(ad);
}	
int fiyathesapla(int tostfiyati, int icecekfiyati)
{
	int hesap;
	hesap=tostfiyati+icecekfiyati;
	return hesap;
}
void tostmenu()
{
	FILE *dosya;

	int c=0;

	dosya=fopen("tostmenu.txt","r");

	if(dosya==NULL)
		printf("bu dosya yok\n");
	else
	{
		do
		{
			c=getc(dosya);
			putchar(c);
		}
		while(c!=EOF);
	}

	fclose(dosya);

	printf("\n");	

}
void icecekmenusu()
{
	FILE *dosya;

	int c=0;

	dosya=fopen("icecekmenu.txt","r");


	if(dosya==NULL)
		printf("bu dosya yok\n");
	else
	{
		do
		{
			c=getc(dosya);
			putchar(c);
		}
		while(c!=EOF);
	}

	fclose(dosya);

	printf("\n");	

}

