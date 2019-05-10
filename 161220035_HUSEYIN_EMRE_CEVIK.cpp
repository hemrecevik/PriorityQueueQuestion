#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
 
 typedef struct akademisyen
 {
 	int sicilNo;
 	char *ad;
 	char *soyad;
 	int unvanID;
 	int unvanYili;
 	struct akademisyen *sonraki;
 }Akademisyenler;
 
 Akademisyenler *ilk=NULL,*son=NULL,*Akademisyen,*gecici;
 
 void Silme(int sicil){
 	Akademisyenler *gecici,*bironceki;
 	gecici=ilk;
 	bironceki=NULL;
 	while(gecici!=NULL){
 		if(gecici->sicilNo==sicil)break;
 		bironceki=gecici;
 		gecici=gecici->sonraki;
	 }
	 if(gecici==NULL)printf("Listede silinmek istenen eleman yok...");
	 else
	 {
	 	if(gecici==ilk){
	 		if(ilk==son){
	 			ilk=NULL;
	 			son=NULL;
			 }
			 else
			 {
			 	ilk=ilk->sonraki;
			 }
		 }
		else
		{
			if(gecici==son)
			{
				son=bironceki;
				son->sonraki=NULL;
			}
			else
			{
				bironceki->sonraki=gecici->sonraki;
			}
		}
		switch(gecici->unvanID)
    {
    case 1 :printf("Prof.Dr.%s %s Listeden Silindi...\n",gecici->ad,gecici->soyad);break;
    case 2:printf("Doc.Dr.%s %s Listeden Silindi...\n",gecici->ad,gecici->soyad);break;
 	case 3:printf("Dr..Ogr.Uyesi%s %s Listeden Silindi...\n",gecici->ad,gecici->soyad);break;
 	case 4:printf("Ars.Gor.%s %s Listeden Silindi...\n",gecici->ad,gecici->soyad);break;
}
		free(gecici);
	 }
	 
 }
 void SondanSil(){
 	Akademisyenler *gecici,*bironceki;
 	gecici=ilk;
 	bironceki=NULL;
 	if(ilk->sonraki==NULL){
 		ilk=NULL;
		son=NULL;	
	 }
	 while(gecici!=son){
	 bironceki=gecici;
	 gecici=gecici->sonraki;
	 }
	
	 son=bironceki;
	 son->sonraki=NULL;
	 free(gecici);
 }
 
 void Gorevlendir(Akademisyenler *gecici){
 			gecici=ilk;
 			while(gecici!=son){
 				gecici=gecici->sonraki;
			 }
			 printf("  %d ", gecici->sicilNo);
			 switch(gecici->unvanID){
			case 1: printf("Prof.Dr.");break;
			case 2:printf("Doc.Dr.");break;
			case 3:printf("Dr.Ogr.Uyesi");break;
			case 4:printf("Ars.Gor.");break;
		}
            printf(" %s ", gecici->ad);
            printf(" %s ", gecici->soyad);
            //printf("  %d ", gecici->unvanID);
            printf(" %d \n\n", gecici->unvanYili);
            SondanSil();  		
 }
 
 
 void ekle(Akademisyenler *Akademisyen) {
 
    //Liste bos ise
    if (ilk == NULL) {
        ilk = Akademisyen;
        son =Akademisyen;
    } else {
        //Girilen sayi ilk sayidan kucuk ise
        if ((ilk->unvanID) > (Akademisyen->unvanID)) {
            Akademisyen->sonraki=ilk;
            son=ilk;
            ilk = Akademisyen;
        } 
        else if((ilk->unvanID) == (Akademisyen->unvanID)&& (ilk->unvanYili)>(Akademisyen->unvanYili)){
        	Akademisyen->sonraki=ilk;
            son=ilk;
            ilk = Akademisyen;
		}
		else {
            gecici = ilk;
            while (gecici != NULL) {
                //gecici elemaninin sonraki null ise ve son elemandan buyukse
                if (gecici->sonraki == NULL && (gecici->unvanID) <= (Akademisyen->unvanID)) {
                    Akademisyen->sonraki = NULL;
                    gecici->sonraki = Akademisyen;
                    son=Akademisyen;
                    break;
                }
                if((gecici->sonraki->unvanID)==(Akademisyen->unvanID) && (gecici->sonraki->unvanYili)>(Akademisyen->unvanYili))
                {
                	Akademisyen->sonraki = gecici->sonraki;
                    gecici->sonraki=Akademisyen;
                    break;
				}/*
				if((gecici->unvanID)==(Akademisyen->unvanID) && (gecici->unvanYili)<(Akademisyen->unvanYili))
                {
                	if((gecici->sonraki->unvanID)==(Akademisyen->unvanID)&&(gecici->sonraki->unvanYili)>(Akademisyen->unvanYili))
                	{
                		Akademisyen->sonraki=gecici->sonraki;
                		gecici->sonraki=Akademisyen;
					}
					if((gecici->sonraki->unvanID)==(Akademisyen->unvanID)&&(gecici->sonraki->unvanYili)>(Akademisyen->unvanYili))
                	{
                		Akademisyen->sonraki=gecici->sonraki;
                		gecici->sonraki=Akademisyen;
					}
				}*/
                if ((gecici->sonraki->unvanID) > (Akademisyen->unvanID)) {
                    Akademisyen->sonraki = gecici->sonraki;
                    gecici->sonraki = Akademisyen;
                    break;
                }
                gecici = gecici->sonraki;
            }
        }
    }switch(Akademisyen->unvanID)
    {
    case 1 :printf("Prof.Dr.%s %s Listeye Eklendi...\n",Akademisyen->ad,Akademisyen->soyad);break;
    case 2:printf("Doc.Dr.%s %s Listeye Eklendi...\n",Akademisyen->ad,Akademisyen->soyad);break;
 	case 3:printf("Dr..Ogr.Uyesi%s %s Listeye Eklendi...\n",Akademisyen->ad,Akademisyen->soyad);break;
 	case 4:printf("Ars.Gor.%s %s Listeye Eklendi...\n",Akademisyen->ad,Akademisyen->soyad);break;
}
}
void listele() {
    //liste bos ise
    if (ilk == NULL) {
        printf("Liste Bos\n");
    } else {
        //ilk degeri kaybetmemek icin gecici kullanildi
        gecici = ilk;
        while (gecici != NULL) {
            printf("  %d ", gecici->sicilNo);
            switch(gecici->unvanID){
			case 1: printf("Prof.Dr.");break;
			case 2:printf("Doc.Dr.");break;
			case 3:printf("Dr.Ogr.Uyesi ");break;
			case 4:printf("Ars.Gor.");break;
		}
		
            printf("%s ", gecici->ad);
            printf("%s", gecici->soyad);
            //printf("  %d ", gecici->unvanID);
            printf(" %d \n\n", gecici->unvanYili);
            gecici = gecici->sonraki;
        }
    }
   
}
 
 Akademisyenler *Olustur(int *Numaralar,char *Karakterler){
 	int sicilno,unvanid,unvanyili,i=0,q=0,k=0;
 	char ad[9]={0},soyad[9]={0};
 	
	 Akademisyen=(Akademisyenler *)malloc(sizeof(Akademisyenler));
 	sicilno=Numaralar[0]*1000+Numaralar[1]*100+Numaralar[2]*10+Numaralar[3];
 	unvanid=Numaralar[4];
 	unvanyili=Numaralar[5]*1000+Numaralar[6]*100+Numaralar[7]*10+Numaralar[8];
 	while(i<20){
 		if(Karakterler[i]=='+'){
 			i++;
 			while(i<20){
 				if(Karakterler[i]==0)break;
 				soyad[k]=Karakterler[i];
 				k++;
 				i++;
			 }
			 break;
		 }
 		ad[q]=Karakterler[i];
 		q++;
 		i++;
	 }
	 char ad2[q],soyad2[k];
	 for(int p=0;p<q;p++){
	 	ad2[p]=ad[p];
	 }
	 for(int z=0;z<k;z++){
	 	soyad2[z]=soyad[z];
	 }
	 
	Akademisyen->ad=(char *)malloc(sizeof(char)*q);
	Akademisyen->soyad=(char *)malloc(sizeof(char)*k);
	strcpy(Akademisyen->ad, ad2);
	strcpy(Akademisyen->soyad, soyad2);
	Akademisyen->sicilNo=sicilno;
	Akademisyen->unvanID=unvanid;
	Akademisyen->unvanYili=unvanyili;
	Akademisyen->sonraki=NULL;
	return Akademisyen;
 }
 
 
 
 int main(){
 	char dizi[80]={0},karakterler[20]={0};
 	int Numaralar[9],k=0,l=0,sayac=0,i=0,n=0;
 	FILE *fp;
 	 if ((fp=fopen("Akademisyen.txt", "r")) == NULL) {
      printf("Dosya acilamadi!\n");
      exit(1);
  }
  while(!feof(fp)){
  
 	fgets(dizi,79,fp);
 	while(i<80){
 		if(dizi[i]==0)break;
		if(dizi[i]=='#'){
			i++;
			break;
		}
		Numaralar[k]=dizi[i]-'0';
		k++;
		i++;
	 }
	 
	 while(i<80){
	 	if(dizi[i]==0)break;
	 	if(dizi[i]=='#'&& sayac==1){
	 		i++;
	 		break;
		 }
		if(dizi[i]=='#'&& sayac==0)
		{	sayac++;
		karakterler[l]='+';
			l++;
			i++;
		}
			karakterler[l]=dizi[i];
			l++;
			i++;
	 }
	 
	 sayac=0;
	 while(i<80){
 		if(dizi[i]==0)break;
 		if(dizi[i]=='#'&& sayac==1)break;
		if(dizi[i]=='#'&& sayac==0)
		{	sayac++;
			i++;
		}
		Numaralar[k]=dizi[i]-'0';
		k++;
		i++;
	 }
 	Akademisyen=Olustur(Numaralar,karakterler);
 	ekle(Akademisyen);
 	dizi[80]={0};
 	karakterler[20]={0};
 	k=0,l=0,sayac=0,i=0;
}
	
 int secim,gorev,sayi1,c=0,Numara[4],v=0,silsicil;
 while(1){
	
	printf(" \n 1-Listeleme \n 2-Gorevlendirme \n 3-Ekleme \n 4-Silme \n 5-Cikis\n");
	scanf("%d",&secim);
	switch(secim)
	{
		case 1: listele(); break;
		case 2: printf("Kac kisi gorevlendirilecek?\n");
				scanf("%d",&gorev);
				for(int m=0;m<gorev;m++){
					Gorevlendir(gecici);
				}break;
		case 3:printf("Sicil no giriniz= \n");scanf("%d",&sayi1);
				while(sayi1>0){
					Numara[v]=sayi1%10;
					sayi1=sayi1/10;
					v++;
				}
				v--;
				for(int u=0;u<4;u++){
					Numaralar[u]=Numara[v];
					v--;
				}
				fflush(stdin);
				printf("Ad ve Soyad giriniz= \n");gets(karakterler);
				while(karakterler[n]!=' '){
					n++;
				}
				karakterler[n]='+';
				c=4;
				v=0;
				printf("UnvanID giriniz = \n");scanf("%d",&Numaralar[c]);c++;
				printf("Unvan yilini giriniz = \n");scanf("%d",&sayi1);
				while(sayi1>0){
					Numara[v]=sayi1%10;
					sayi1=sayi1/10;
					v++;
				}
				v--;
				for(int o=5;o<9;o++){
					Numaralar[o]=Numara[v];
					v--;
				}
				
				Akademisyen=Olustur(Numaralar,karakterler);
 				ekle(Akademisyen);
 				break;
 		case 4:printf("Silmek istediginiz sicil no yu giriniz= ");
 				scanf("%d",&silsicil);
 				Silme(silsicil);
 				break;
 		case 5:exit(0);
 		
	}
	
 }
 
 }
