//SALÝH KULOÐLU
//20010011061
//DAÝRESEL BAÐLI LÝSTE ÝLE TELEFON REHBERÝ


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct n{
    char ad[20];
    char soyad[30];
    char no[11];
    struct n *next;

}kayit;




int main()
{
    int secim,secim2;
    char isim_ara[20];
    char isim[20], soyisim[30];
    char no[11],no_ara[11];
    kayit *ilk=NULL;
    char no_sorgu[20];
    int kontrol = 1;
    int kontrol2 = 0;
    while(kontrol)
    {
        menu:
        printf("1-) Ekleme\n2-) Arama\n3-) Listeleme\n4-) Silme");
        scanf("%d", &secim);
        if(secim==1)
        {


            if(ilk == NULL)
            {
                ilk = (kayit *)malloc(sizeof(kayit));
                ilk -> next = ilk;
                printf("Lutfen Eklemek istediginiz Numarayi giriniz :");
                scanf("%s", &ilk->no);
                printf("Lutfen Eklemek istediginiz Ismi giriniz :");
                scanf("%s", &(ilk->ad));
                printf("Lutfen Eklemek istediginiz Soyismi giriniz :");
                scanf("%s", &(ilk->soyad));


            }
            else
            {
                kayit *gezici = ilk;
                printf("Lutfen Eklemek istediginiz Numarayi giriniz :");
                scanf("%s" ,&no_sorgu);
                if(strcmp(gezici -> no ,no_sorgu)==0)
                {
                    printf("\n\nBU NUMARA KAYITLI\n\n");
                    goto menu;
                }
                else
                {
                    gezici = gezici ->next;
                    while(gezici != ilk)
                    {
                        if(strcmp(gezici -> no ,no_sorgu)==0)
                        {
                            printf("\n\nBU NUMARA KAYITLI\n\n");
                            goto menu;
                        }
                        else
                        {
                            gezici= gezici->next;
                        }
                    }
                }




                while(gezici -> next != ilk)
                {
                    gezici = gezici -> next;
                }
                gezici -> next = (kayit *)malloc(sizeof(kayit));
                printf("Lutfen Eklemek istediginiz Ismi giriniz :");
                scanf("%s", &gezici->next ->ad);
                printf("Lutfen Eklemek istediginiz Soyismi giriniz :");
                scanf("%s", &gezici->next->soyad);
                printf("Lutfen Eklemek istediginiz Numarayi Tekrar giriniz :");
                scanf("%s", &gezici->next->no);
                gezici -> next ->next = ilk;
                ilk = gezici -> next;
                gezici = gezici -> next;


            }



        }
        if(secim==3)
        {

            kayit *gezici =ilk;
            printf("-->%s\n", ilk->ad);
            printf("-->%s\n", ilk->soyad);
            printf("-->%s\n\n\n\n\n", ilk->no);
            gezici = gezici -> next;
            while (gezici != ilk)
            {
                printf("-->%s\n", gezici->ad);
                printf("-->%s\n", gezici->soyad);
                printf("-->%s\n\n\n\n\n", gezici->no);
                gezici = gezici -> next;
            }
        }
        if(secim==2)
        {
            printf("\n1-->AD'a GORE ARAMA \n2-->TEL'e GORE ARAMA");
            scanf("%d",&secim2);
            if(secim2==1)
            {
                printf("Lütfen aramak istediginiz ismi giriniz :\n");
                scanf("%s", &isim_ara);
                kayit *gezici = ilk;
                if(strcmp(gezici->ad,isim_ara)== 0)
                    {
                        printf("\n\nKayit Bulundu :\n\nIsim-->%s \nSoyisim-->%s \nNumara-->%s \n",gezici->ad,gezici->soyad,gezici->no);
                        kontrol2 = 1;


                    }
                    else
                    {
                        gezici = ilk -> next;
                    }
                while(gezici != ilk)
                {
                    if(strcmp(gezici->ad,isim_ara)== 0)
                    {
                        printf("\n\nKayit Bulundu :\n\nIsim-->%s \nSoyisim-->%s \nNumara-->%s \n",gezici->ad,gezici->soyad,gezici->no);
                        kontrol2 =1;
                        break;

                    }
                    else
                    {

                        gezici = gezici -> next;

                    }



                }

                if (kontrol2 == 0)
                {
                    printf("\n\n--------KAYIT BULUNAMADI---------\n\n");
                }



            }
            if(secim2 == 2)
            {
                printf("\n\nLutfen aramak istediginiz numarayi giriniz\n");
                scanf("%s", &no_ara);
                kayit *gezici = ilk;
                if(strcmp(gezici->no,no_ara)== 0)
                    {
                        printf("\n\nKayit Bulundu :\n\nIsim-->%s \nSoyisim-->%s \nNumara-->%s \n",gezici->ad,gezici->soyad,gezici->no);
                        kontrol2 = 1;


                    }
                    else
                    {
                        gezici = ilk -> next;
                    }
                while(gezici != ilk)
                {
                    if(strcmp(gezici->no,no_ara)== 0)
                    {
                        printf("\n\nKayit Bulundu :\n\nIsim-->%s \nSoyisim-->%s \nNumara-->%s \n",gezici->ad,gezici->soyad,gezici->no);
                        kontrol2 =1;
                        break;

                    }
                    else
                    {

                        gezici = gezici -> next;

                    }



                }

                if (kontrol2 == 0)
                {
                    printf("\n\n--------KAYIT BULUNAMADI---------\n\n");
                }


            }
        }
        if(secim==4)
        {
            kayit *onceki;
            kayit *gezici=ilk;
            kayit *bas = ilk;
            char sil_no[11];
            printf("Lutfen silmek istediginiz numarayi giriniz");
            scanf("%s", &sil_no);
            while (gezici -> next != ilk)
            {
                gezici = gezici -> next;
            }
            onceki = gezici;
            gezici = gezici -> next;
            if(strcmp(gezici->no,sil_no)==0)
            {
                onceki -> next = gezici -> next;
                free(gezici);
                ilk = gezici ->next;
                goto menu;
            }
            else
            {
                gezici= gezici -> next;
                onceki = onceki -> next;
            }
            while(gezici != ilk)
            {
                if(strcmp(gezici->no,sil_no)==0)
                    {
                        onceki -> next = gezici -> next;
                        free(gezici);
                        ilk = bas;
                        goto menu;
                    }
                else
                    {
                        gezici= gezici -> next;
                        onceki = onceki -> next;
                    }
            }
            printf("\n\nNumara Bulunmadi\n\n");


        }
    }





    return 0;
}
