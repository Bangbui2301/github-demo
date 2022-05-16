#include <iostream>
using namespace std;

typedef struct tagTNode{
    int Key;
    struct tagTNode *pLeft;
    struct tagTNode *pRight;
}TNode;

typedef TNode *TREE;

void NLR(TREE Root){
    if(Root!=NULL){
        cout<<Root->Key<<" "; // <Xử lý Root>
        NLR(Root->pLeft);
        NLR(Root->pRight);
    }
}

void LNR(TREE Root){
    if(Root!=NULL){
        
        NLR(Root->pLeft);
        cout<<Root->Key<<" "; // <Xử lý Root>
        NLR(Root->pRight);
    }
}

void LRN(TREE Root){
    if(Root!=NULL){
        NLR(Root->pLeft);
        NLR(Root->pRight);
        cout<<Root->Key<<" "; // <Xử lý Root>
    }
}

TNode * CreateTreeNode(int x){
    TNode * temp;
    if(temp==NULL) return NULL;
    temp->Key = x;
    temp->pLeft = NULL;
    temp->pRight = NULL;
    return temp;
}

void CreateTree(TREE &t){
    t = NULL;
}

int insertTreeNode(TREE &t, int x){
    if(t!=NULL){
        if(t->Key== x) return 0;
        if(t->Key > x) return insertTreeNode(t->pLeft, x);
        else return insertTreeNode(t->pRight, x);
    }
    t = new TNode;
    if(t == NULL) return -1;
    t->Key  = x;
    t->pRight = t->pLeft = NULL;
    return 1;
}

// Dùng vòng lặp

TNode * SearchNode(TREE Root, int x){
    TNode * p = Root;
    while(p!=NULL){
        if(p->Key == x) return p;
        if(p->Key > x) p = p->pLeft;
        else p = p->pRight;
    }
    return NULL;
}

TNode * SearchTNode(TREE t, int x){
    if(t!=NULL){
        if(t->Key == x){
            return t;
        }
        if(t->Key > x) return SearchTNode(t->pLeft, x);
        else return SearchTNode(t->pRight, x);

    }
    return NULL;
}

void ThayThe1(TREE &p, TREE &t){
    if(t->pLeft!=NULL){
        ThayThe1(p,t->pLeft);
    }
    else{
        p->Key = t->Key;
        p = t;
        t = t->pRight;
    }
} 

void DeleteNodeX1(TREE &t, int x)
{
    if(t!=NULL){
        if(t->Key<x) DeleteNodeX1(t->pRight, x);
        else{
            if(t->Key > x ) DeleteNodeX1(t->pLeft, x);
            else{ // Tim thay Node co gia tri x
                TNode *p;
                p = t;
                if(t->pLeft == NULL) t = t->pRight;
                else{
                    if(t->pRight == NULL) t=t->pLeft;
                    else ThayThe1(p,t);
                }
                delete p;
            }
        }
    }
    else cout<<"Khong tim thay phan tu can xoa\n";
}
int main(){    
}