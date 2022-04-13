#include<stdio.h>
#include<stdlib.h>

/*les principale operations pour creer un arbre:
1) Initialiser l arbre
2) Creer un noeud
3) verifier si un arbre est vide
4) Enchainement des noeud + la choix de la racine
5) Parcours de l arbre 
*/
// definir la structure de nœud
typedef struct Node{
	int data;
	struct Node *leftChild;
	struct Node *rightChild;
}Node;


// la creation d un Noeud
Node *createNode(int data){
	Node *newNode;
	newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->leftChild=NULL;
	newNode->rightChild=NULL;
return newNode;}


// verifier si un arbre est vide


int isEmpty(Node *node){
	if(node==NULL)
        return 1;
	return 0;
}



//  Parcours l arbre en profondeur(Prefixe)

void prefixe(Node *node){

// traiter la racine de l arbre

if(node != NULL){
printf("%d \n",node->data);
prefixe(node->leftChild);
prefixe(node->rightChild);

}
}

//  Parcours l arbre en profondeur(Infixe)

void infixe(Node *node){

if(node != NULL){

infixe(node->leftChild);
printf("%d \n",node->data);
infixe(node->rightChild);

}
}

//  Parcours l arbre en profondeur(Postfixe)

void postfixe(Node *node){

if(node != NULL){

postfixe(node->leftChild);
postfixe(node->rightChild);
printf("%d \n",node->data);


}
}


void main(){
	
  Node *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9,*n10,*root;
  root=NULL;
  // printf("Arbre est vide %d\n",isEmpty(root));
   n1=createNode(1);
   n2=createNode(2);
   n3=createNode(3);
   n4=createNode(4);
   n5=createNode(5);
   n6=createNode(6);
   n7=createNode(7);
   n8=createNode(8);
   n9=createNode(9);
   n10=createNode(10);	
   // Enchainement des noeud + la choix de la racine
   root=n1;
   n1->leftChild=n2;
   n1->rightChild=n3;
   
   n2->leftChild=n4;
   n2->rightChild=n5;
   
   n3->leftChild=n6;
   n3->rightChild=n7;
    
   n5->leftChild=n8;
   
   n7->leftChild=n9;
   n7->rightChild=n10;
   
    //printf("Arbre est vide %d ",isEmpty(root));
    
    printf(" Parcours l arbre en profondeur(Prefixe) \n");
    prefixe(root);
    printf(" Parcours l arbre en profondeur(Infixe) \n");
    infixe(root);
   printf(" Parcours l arbre en profondeur(Postfixe) \n");
    postfixe(root);
     
   
   
	
}
