#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Salih Kuloğlu
//20010011061
typedef struct s{
    struct s *next;
    char data;

}yigin;

yigin* pop(yigin *bas)
{
    if(bas==NULL)
    {
        printf("Yigin bos");
        return -1;

    }
    yigin *temp;
    temp =bas;
    if(bas->next == NULL)
    {
        bas = NULL;
        free(temp);
        return bas;
    }
    else
    {
        bas = bas ->next;
        free(temp);
        return bas;
    }





}
yigin* push(yigin *bas,char veri)
{
    if(bas == NULL)
    {
        bas = (yigin*)malloc(sizeof(yigin));
        bas -> data =veri;
        bas -> next =NULL;
        return bas;
    }
    yigin *temp;
    temp = (yigin*)malloc(sizeof(yigin));
    temp ->next = bas;
    temp ->data =veri;
    bas =temp;
    return bas;


}
int deger(char temp)
{
    switch(temp)
    {
    case ')': return 5;
    case '(': return 5;
    case '^': return 4;
    case '*': return 3;
    case '/': return 3;
    case '+': return 2;
    case '-': return 2;

    default: return 0;
    }

}
void yigin_yazdir(yigin *gezici)
{
    if(gezici != NULL)
    {
        if(gezici->data == ')' || gezici->data == '^' || gezici->data == '*' || gezici->data == '/' || gezici->data == '+' || gezici->data == '-' || gezici->data == '(')
        {
            while(gezici != NULL)
                {
                    printf("%c",gezici->data);
                    gezici = gezici ->next;
                }
                printf("           ");
        }
        else
        {
            printf("            ");
        }

    }
    else
    {
        printf("            ");
    }


}

int main()
{
    int sayac=0;
    char infix[100];
    char posfix[100];
    int i=0, j=0;
    printf("infix ifade gir --> \n");
    printf(" INFIX - - - STACK - - - POSFIX\n");
    scanf("%s", &infix);
    yigin *tepe =NULL;

     for (i=0; i<strlen(infix); i++)
     {

         if(infix[i] == ')' || infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '(')
         {
             if(infix[i] == ')')
            {
                while(tepe->data != '(')
                {
                    posfix[j] = tepe->data;
                    j++;
                    tepe=pop(tepe);
                    sayac++;
                }
                tepe=pop(tepe);
            }
            else
            {
                if(tepe == NULL)
                {
                    tepe =push(tepe,infix[i]);
                }
                else
                {
                    if(deger(infix[i]) > deger(tepe->data))
                    {
                        tepe=push(tepe,infix[i]);
                    }
                    else
                    {
                        while( tepe != NULL)
                        {
                            if(deger(infix[i]) >! deger(tepe->data) && tepe ->data != '(')
                            {
                                posfix[j] = tepe->data;
                                j++;
                                tepe =pop(tepe);
                                sayac++;
                            }
                            else
                            {
                                break;
                            }

                        }
                        tepe=push(tepe,infix[i]);
                    }


                }
            }
         }
         else
         {
            posfix[j] = infix[i];
            j++;
            sayac++;
         }
         printf("%s         ",&infix);
         yigin_yazdir(tepe);
         printf("%s\n", &posfix);


     }
     while(tepe !=NULL)
     {
        posfix[j] = tepe->data;
        j++;
        tepe =pop(tepe);
     }

     printf("%s                     ",&infix);
     printf("%s\n", &posfix);

    return 0;
}
