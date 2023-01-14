//Salih Kuloðlu
//20010011061



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct listeler{

struct listeler *sonraki;
struct listeler *onceki;
int data;
}liste;


int main()
{
    int boyut;
    printf("Boyut Gir\n");
    scanf("%d",&boyut);
    bool kontrol=true; //true ise eklenecek liste tek sayý listesi deðilse eklenecek liste çift sayý listesi
    liste *list1 = NULL; //girilen boyuta kadar olan tek sayýlarý tutacak
    liste *list2 = NULL; //girilen boyuta kadar olan çift sayýlarý tutacak
    liste *gezici1;
    liste *gezici2;
    for(int i=0; i<(boyut*2); i++)
    {
        if(kontrol)
        {
            if(list1==NULL) //list1 boþsa
            {
                list1 = (liste*)malloc(sizeof(liste));
                list1 ->data =(i+1);
                list1 ->sonraki =NULL;
                list1 ->onceki =NULL;
                gezici1=list1;
                kontrol = false;
            }
            else            //list1 boþ deðilse
            {
                liste *temp = (liste*)malloc(sizeof(liste));
                temp -> data = (i+1);
                temp -> onceki= gezici1;
                gezici1 ->sonraki = temp;
                temp ->sonraki = NULL;
                gezici1 =temp;
                kontrol = false;
            }

        }
        else
        {
            if(list2==NULL) //list2 boþsa
            {
                list2 =(liste*)malloc(sizeof(liste));
                gezici2 = list2;
                list2 ->data = (i+1);
                list2 ->onceki = NULL;
                list2 ->sonraki = NULL;
                kontrol = true;
            }
            else //list2 boþ deðilse
            {
                 liste *temp = (liste*)malloc(sizeof(liste));
                 temp ->data =i+1;
                 temp ->onceki = gezici2;
                 gezici2 ->sonraki =temp;
                 temp -> sonraki =NULL;
                 gezici2=temp;
                 kontrol = true;

            }
        }
    }

    liste *gez1 = list1;
    liste *gez2 = list2;
    int sira1 =1;
    int sira2 =1;
    printf("\n------------------Birinci liste----------------- \n\n");
    while(gez1 != NULL)
    {
        printf("1. Listenin %d. elemani -> %d , Adresi --> %d\n", sira1,gez1->data,&gez1->data); //list1'i yazdýrma
        gez1 = gez1 ->sonraki;
        sira1++;
    }
    printf("\n-------------------Ikinci liste----------------- \n\n");
    while(gez2 != NULL)
    {
        printf("2. Listenin %d. elemani -> %d , Adresi --> %d\n", sira2,gez2->data,&gez2->data); //list2'yi yazdýrma
        gez2 = gez2 ->sonraki;
        sira2++;
    }
    gez1 =list1;
    gez2 =list2;
    sira1 =1;
    sira2 =1;
    printf("\n-----Iki listenin adres sirasina gore yazimi----- \n\n");


    for(int i=0; i<(boyut*2);i++)
    {
        if(i%2==0)
        {
            printf("1. Listenin %d. elemani -> %d , Adresi --> %d\n", sira1,gez1->data,&gez1->data);
            gez1 = gez1 ->sonraki;
            sira1++;
        }                                                                                               //2 listeyide adres sýrasýyla yazdýrma
        else
        {
            printf("2. Listenin %d. elemani -> %d , Adresi --> %d\n", sira2,gez2->data,&gez2->data);
            gez2 = gez2 ->sonraki;
            sira2++;
        }
    }

    liste *birlestir1 = list1;
    liste *temp1=list1->sonraki;
    liste *temp2=list2->sonraki;
    liste *birlestir2 = list2;
    bool son = true;
    while(son)
    {
        birlestir1 ->sonraki = birlestir2;
        birlestir2 ->onceki = birlestir1;
        birlestir2 ->sonraki = temp1;
        if(temp1 != NULL)
        {
            temp1 ->onceki = birlestir2;
            birlestir1 = temp1;
            birlestir2 = temp2;
            temp1= temp1->sonraki;
            temp2 = temp2->sonraki;
        }
        else
        {
            son = false;
        }


    }
    printf("\n----------------Listeler Birlestirildikten Sonra---------------------\n\n");
    liste *yazdir = list1;
    int sirala =1;
    while(yazdir != NULL)
    {

        printf("Yeni listenin %d. elemani -> %d , Adresi--> %d\n" ,sirala ,yazdir->data,&yazdir->data);
        sirala++;
        yazdir = yazdir->sonraki;

    }
    liste *arka = NULL; //degistirilcek düðümün öncesini tutmak için
    liste *on = list1;
    liste *bas;
    while(on != NULL)
    {
        arka = on->onceki;
        on ->onceki = on->sonraki;      //reverse iþlemi
        on ->sonraki = arka;
        bas = on;
        on = on->onceki;
    }
    printf("\n---------------------Reverse Isleminden Sonra------------------------ \n\n");
    yazdir = bas;
    sirala =1;
    while(yazdir != NULL)
    {

        printf("Reverse listenin %d. elemani -> %d , Adresi--> %d\n" ,sirala ,yazdir->data,&yazdir->data);
        sirala++;
        yazdir = yazdir->sonraki;

    }









    return 0;
}
