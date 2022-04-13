#include<stdio.h>
#include<stdlib.h>
#include"QueueT.h"


TNode* newTNode(int data){
	TNode *MyTree = (TNode*) malloc(sizeof(TNode));
	MyTree->data = data;
	MyTree->left = MyTree->right = NULL;
	return MyTree;
}
Tree* newTree(){
	Tree *MyTree = (Tree*)malloc(sizeof(Tree));
	MyTree->root = NULL;
	return MyTree;
}

TNode* insert(TNode *root, int value){
    if(root == NULL){
        root = newTNode(value);
        return root;
    }else{
        if(value < root->data){
            root->left = insert(root->left, value);
        }else{
            if(value > root->data){
                root->right = insert(root->right, value);
            }
        }
        return root;
    }
};

void traiter(QNode *MyNode){
	printf("%d-",MyNode->Ndata.data );
}


void parcours_largeur(Tree *a){
	Queue *Q = newQueue();// pour mémoriser les noeud d'un même niveau 
	QNode* x=NULL; // pour pointeur le noeud à traiter 
	if(a->root!=NULL){
		Enqueue(Q,*(a->root)); // si l'arbre n'est pas vide, on enfile sa racine 
		while(Q->Head){
			// on défile le noeud courant puis on le traite 
			x=Dequeue(Q);
			traiter(x);
			//puts("HERE");
			// si le noeud défilé contient des fils, on les enfile à leur
			//tour dans la file
			if(x->Ndata.left!=NULL)
				Enqueue(Q,*(x->Ndata.left));
			if(x->Ndata.right!=NULL)
				Enqueue(Q,*(x->Ndata.right));
		}
		puts("");
	}
}


int main()
{
	Tree *T = newTree();
	int n=0, i=0, insertNode, limit;
	printf("How many nodes of the tree :");
    scanf("%d", &n);
    for(i = 0; i < n; i++ ){
        printf("Enter node : ");
        scanf("%d", &insertNode);
        T->root = insert(T->root, insertNode);
    }
	parcours_largeur(T);
	return 0;
}