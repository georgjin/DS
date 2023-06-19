#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void createBiTree(BiTree *T)
{
    char ch;
    scanf(" %c", &ch);
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        createBiTree(&(*T)->lchild);
        createBiTree(&(*T)->rchild);
    }
}

void copyBiTree(BiTree T, BiTree *NewT)
{
    if (T == NULL)
        *NewT = NULL;
    else
    {
        *NewT = (BiTree)malloc(sizeof(BiTNode));
        (*NewT)->data = T->data;
        copyBiTree(T->lchild, &(*NewT)->lchild);
        copyBiTree(T->rchild, &(*NewT)->rchild);
    }
}

int Depth(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int ldepth = Depth(T->lchild);
        int rdepth = Depth(T->rchild);
        return (ldepth > rdepth) ? (ldepth + 1) : (rdepth + 1);
    }
}

int NodeCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int lcount = NodeCount(T->lchild);
        int rcount = NodeCount(T->rchild);
        return lcount + rcount + 1;
    }
}

int main()
{
    BiTree T;
    printf("请输入一棵二叉树的先序遍历序列（'#'表示空节点）：");
    createBiTree(&T);
    printf("复制二叉树\n");
    BiTree NewT;
    copyBiTree(T, &NewT);
    printf("计算二叉树的深度：%d\n", Depth(T));
    printf("统计节点个数：%d\n", NodeCount(T));
    return 0;
}
