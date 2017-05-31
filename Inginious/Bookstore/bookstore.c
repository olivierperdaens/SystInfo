#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellAuteur {
    char *auteur;
    struct cellLivre *Livres;
    struct cellAuteur *next;
} cellAuteur;

typedef struct cellLivre {
    char *titre;
    struct cellLivre *suiv;
} cellLivre;


cellAuteur *existe(cellAuteur *librairie, char *strAuteur){
    cellAuteur* tmp=librairie;
    while(tmp!=NULL){
        if(strcmp((const char*)tmp->auteur,(const char*) strAuteur)==0){
            return tmp;
        }
        tmp=tmp->next;
    }
    return NULL;
}

int compteOuvrage(cellAuteur* librairie, char *strAuteur){
    cellAuteur* auteur=existe(librairie, strAuteur);
    if(auteur==NULL)return 0;
    int count=0;
    cellLivre* livres=auteur->Livres;
    while(livres !=NULL){
        count++;
        livres=livres->suiv;
    }
    return count;
}

void add(cellAuteur *librairie, char * strAuteur, char* strTitre){
    cellAuteur* auteur=existe(librairie, strAuteur);
    cellLivre* livres=auteur->Livres;
    while(livres !=NULL){
        if(strcmp((const char*) strTitre, (const char*) livres->titre)==0){
            return;
        }
        livres=livres->suiv;
    }
    cellLivre* new=(cellLivre*)malloc(sizeof(cellLivre));
    new->titre=strTitre;
    new->suiv=NULL;
    livres=new;
}

void supprimer(cellAuteur **librairie, char *strAuteur){
    cellAuteur *current, *previous;
    previous=NULL;
    /*
     *Visit each node
     */
    for(current=*librairie;current!=NULL;previous=current, current=current->next){
        if(strcmp((const char*)tmp->auteur,(const char*) strAuteur)==0){
            if(previous==NULL) *librairire=current->next;
            else{
                previous->next=current->next;
            }
            free(current);
            return;
        }
    }
}
