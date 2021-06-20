#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "hangman.h"


int main(){
        int essai,i,k,coups,*tab,choix=1,n,pos;
        FILE *fichier=NULL;
        char *motsecret,*motactu,ch;
        while(choix==1){
            printf("bienvenu dans le pendu \n");
            essai=10;
            coups=0;
            srand(time(0));
            fichier=fopen("dico.txt","r");
            if(fichier!=NULL){
                n=nbr_mot(fichier);
                pos=rand()%n; // to get a random number in range 0 n-1
                motsecret=getword(fichier,pos);
                k=strlen(motsecret);
                motactu=(char*)malloc(k*sizeof(char));
                for(i=0;i<k;i++){
                    motactu[i]='*';
                }
                motactu[k]='\0';
                fclose(fichier);
            }
            else{
                printf("sorry we have some problems try later \n");
                system("pause");
                exit(0);
            }

            do{
                    printf("IL VOUS RESTE %d COUPS A JOUER \n",essai);
                    printf("Quel est le mot secret ? %s\n",motactu);
                    printf("Proposez une lettre: ");
                    ch=lirecaractere();
                    if(apparence(motsecret,ch)>0){
                        tab=indices(motsecret,ch,apparence(motsecret,ch));
                        changeword(motactu,tab,ch);
                    }
                    else{
                        essai--;
                    }
                    coups++;

            }while(strcmp(motsecret,motactu)!=0 && essai>0);
            if(essai>0){
                printf("bravo le mot etais %s vous avez faire %d tentaives\n",motactu,coups);
            }
            else{
                printf("dommage le mot etais %s\n ",motsecret);
            }
            printf("une autre partie ? (1/0)\n");
            scanf("%d",&choix);
            system("cls");

        }

}
