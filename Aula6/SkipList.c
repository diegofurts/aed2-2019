#include <stdio.h>
#include <stdlib.h>
#include "SkipList.h"

static int MaiorNivel;
static TipoLista Header;

// Nessa implementacao, estou mantendo uma coluna "boba"
// Ela facilita um pouco as coisas, mas exige mais memoria
void InicializaLista(TipoLista *L) {
	
	TipoApontador aux;
	
    aux = (TipoApontador) malloc(sizeof(TipoNo));
    if (aux == NULL) {
        printf("NAO FOI POSSIVEL INSERIR O ITEM: MEMORIA CHEIA\n");
        return;
    }
    
    TipoItem item;
    item.Chave = -1; // estou assumindo soh termos chaves >= 0
    
    aux->Item = item;
    aux->prox = NULL;
    aux->abaixo = NULL;
    aux -> Nivel = 0;
    
    MaiorNivel = 0;
    Header = aux;
    *L = Header;
    
    return;
	
}


TipoApontador PesquisaLista(TipoLista *L, TipoChave C) {

	TipoApontador P;
	
	P = *L;
	while(P != NULL) {
	
		//printf("Pesquisa passando por %d\n", P->Item.Chave);
		if (P->Item.Chave == C)
			return P;
			
		if (P->prox != NULL && C >= P->prox->Item.Chave) { // Pergunta: eu preciso verificar se C > P->Item.Chave?
		    P = P->prox;		    
		} else {
		    P = P->abaixo;
		}
		
	}
	
	return NAO_ENCONTRADO;
}


TipoApontador InsereLista(TipoLista *L, TipoItem I) {

	TipoApontador P;
	
	P = *L;
	while(P != NULL) {
	
		if (P->Item.Chave == I.Chave) {
		    printf("Ja existe a chave, meu consagrado!\n");
			return NULL;
		}
		
		if (P->prox != NULL && I.Chave >= P->prox->Item.Chave) { //Me mantenho no mesmo nível
		
		    P = P->prox;
		    
		} else {
		
		    if (P->abaixo != NULL) { // ainda nao eh o ultimo nivel
		
		        TipoApontador insere = InsereLista(&(P->abaixo), I);
    		    if (insere != NULL) {
    		    
    		        printf("Vai sortear\n");
    		        //sortear se insere nesse nivel tb
    		        int moeda = rand() % 2;
    		        if (moeda) {
    		        
    		            TipoApontador aux;
	
	                    aux = (TipoApontador) malloc(sizeof(TipoNo));
	                    if (aux == NULL) {
		                    printf("NAO FOI POSSIVEL INSERIR O ITEM: MEMORIA CHEIA\n");
		                    return 0;
	                    }
	                    
	                    aux->Item = I;
	                    aux->prox = P->prox;
	                    aux->abaixo = insere;
	                    aux->Nivel = aux->abaixo->Nivel + 1;
	                    P->prox = aux;
	                    
	                    if (aux->Nivel == MaiorNivel) {

                            //TODO Verificar se precisa de um novo nivel
                            
	                        
	                    } else {	                    
    	                    return aux;
	                    }
    		        
    		        } else {
    		            return NULL;
    		        }
    		    
    		    } else {
    		        return NULL;
		        }
    		    
		    } else {
		    
		        // inserir aqui
		        TipoApontador aux;
	
	            aux = (TipoApontador) malloc(sizeof(TipoNo));
	            if (aux == NULL) {
		            printf("NAO FOI POSSIVEL INSERIR O ITEM: MEMORIA CHEIA\n");
		            return NULL;
	            }
	            
	            aux->Item = I;
	            aux->prox = P->prox;
	            aux->abaixo = NULL;
	            aux -> Nivel = 0;
	            P->prox = aux;
	            
	            printf("Inserindo %d %d\n", P->prox->Item.Chave, P->Item.Chave);
	            
	            return aux;
		    
		    }
    		    
		}
        
	}
	
	return NULL;
	
}


