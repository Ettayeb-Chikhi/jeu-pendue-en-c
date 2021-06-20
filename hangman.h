#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int apparence(char* word, char c){
    int nmb_vue=0,i,k;
    k=strlen(word);
    for(i=0;i<k;i++){
        if(c==word[i]){
            nmb_vue++;
        }
    }
    return nmb_vue;
}
char lirecaractere(){
     char c;
     c=getchar();
     c=toupper(c);
     while(getchar()!='\n');
     return c;

}

int *indices(char *word,char c,int n){
    int *arr=(int*)malloc(n*sizeof(int)); // n will be the number of apparences of caracter in the word
    int i,k,j=0;
    k=strlen(word);
    for(i=0;i<k;i++){
        if(word[i]==c){
            arr[j]=i;
            j++;
        }
    }
    return arr;
}

void changeword(char *word,int *arr,char c){
    int i,j=0,k=strlen(word);
    for(i=0;i<k;i++){
        if(i==arr[j]){
            word[i]=c;
            j++;
        }
    }
}
int nbr_mot(FILE *flot){
    char c=fgetc(flot);
    int nombre_mots=0;
    while(c!=EOF){
        if(c=='\n'){
            nombre_mots++;
        }
        c=fgetc(flot);
    }
    rewind(flot);
    return nombre_mots;
}

char *getword(FILE *flot,int pos){
    char* mot=(char*)malloc(sizeof(char));
    char c=fgetc(flot);
    int i=0;
    while(i!=pos){
        if(c=='\n'){
            i++;
        }
        c=fgetc(flot);
    }
    fseek(flot,-1,SEEK_CUR); // because i did fgetc before while so i left one character behind
    fgets(mot,100,flot);
    mot[strlen(mot)-1]='\0'; // the last character will be \n which i dont want
    rewind(flot);
    return mot;

}
