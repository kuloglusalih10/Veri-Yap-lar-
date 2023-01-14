
// SALIH KULOGLU
// 20010011061


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
typedef struct a
{
    int data;
    struct a *sol;
    struct a *sag;
}agac;

int node_say(agac* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + node_say(root->sol) + node_say(root->sag);
}

agac *ekle(agac * root, int x)
{
    if(root == NULL)
    {
        agac*iter = (agac*)malloc(sizeof(agac));
        iter->data =x;
        iter -> sol = NULL;
        iter ->sag =NULL;
        return iter;
    }
    if(root -> data < x)
    {
        root->sag=ekle(root->sag,x);
    }
    else
    {
        root->sol=ekle(root ->sol ,x);
    }
}


void inorder(agac *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->sol);
    printf("%d - ",root ->data);
    inorder(root ->sag);
}
int uzunluk(agac *root)
{
    if (root == NULL)
        return 0;
    else {

        int sol_derinlik = uzunluk(root->sol);
        int sag_derinlik = uzunluk(root->sag);


        if (sol_derinlik > sag_derinlik)
            return (sol_derinlik + 1);
        else
            return (sag_derinlik+ 1);
    }
}

int min(agac *root)
{
    while(root->sol != NULL)
    {
        root=root ->sol;
    }
    return root->data;
}

int max(agac *root)
{
    while(root ->sag != NULL)
    {
        root = root ->sag;
    }
    return root ->data;

}
agac *sil(agac *root , int x)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root -> data == x)
    {
        if(root ->sag == NULL && root ->sol ==NULL)
        {
            return NULL;
        }
        if(root ->sag != NULL)
        {
            root ->data = min(root ->sag);
            root ->sag = sil(root ->sag,min(root->sag));
            return root;

        }
        else
        {
            root ->data = max(root ->sol);
            root ->sol = sil(root->sol,max(root->sol));
            return root;
        }
    }
    if(root ->data < x)
    {
        root->sag=sil(root ->sag , x);
        return root;
    }
    else
    {
        root ->sol = sil(root ->sol , x);
        return root;
    }

}
bool ful_kontrol (agac *root)
{
    if (root == NULL)
        return true;
    if (root->sol == NULL && root->sag == NULL)
        return true;
    if ((root->sol) && (root->sag))
        return (ful_kontrol(root->sol) && ful_kontrol(root->sag));
    return false;
}

bool compilete_control(agac *root)
{
    if (root == NULL)
        return true;
    if (root->sol == NULL && root->sag == NULL)
        return true;
    if (((root->sol) && (root->sag)) || (root ->sol != NULL))
        return (compilete_control(root->sol) && compilete_control(root->sag));
    return false;


}



int main()
{
    agac  * kok =NULL;
    bool kontrol =true;
    int secim,deger;
    while (kontrol)
    {
        menu :
        printf("\n1 --> Ekleme\n2 --> Inorder Siralama\n3 --> Silme\n4 --> Yukseklik\n5 --> Full Kontrol\n6 --> Compilete Kontrol\n7 --> Node Sayisini Goster\n8 --> Cikis\n\n");
        scanf("%d" , &secim);
        if(secim < 1 || secim > 7)
        {
            system("CLS");
            printf("\nHatali Bir secim Yaptiniz...\n");
        }
        else
        {
            if(secim == 1)
            {
                printf("\nEklenecek Deger -->  ");
                scanf("%d",&deger);
                kok = ekle(kok,deger);
                system("CLS");


            }
            if(secim == 2)
            {

                system("CLS");
                printf("\n");
                inorder(kok);
                printf("\n");


            }
            if(secim == 3)
            {
                printf("\nSilinecek Deger -->  ");
                scanf("%d",&deger);
                kok = sil(kok,deger);
                system("CLS");
                goto menu;
            }
            if(secim == 4)
            {
                system("CLS");
                printf("\nYukseklik --> %d\n",uzunluk(kok)-1);
            }
            if(secim == 5)
            {
                if(ful_kontrol(kok))
                {
                    system("CLS");
                    printf("\n--> Full\n");
                }
                else
                {
                    system("CLS");
                    printf("\n--> Full Degil\n");
                }

            }
            if(secim == 6)
            {
                if(compilete_control(kok))
                {
                    system("CLS");
                    printf("\n--> Complete\n");
                }
                else
                {
                    system("CLS");
                    printf("\n--> Complete Degil\n");
                }

            }
            if(secim == 7)
            {
                printf("Node Sayisi : %d",node_say(kok));
            }
            if(secim == 8)
            {
                kontrol = false;
            }

        }

    }


    return 0;
}
