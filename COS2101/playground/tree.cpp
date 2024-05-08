#include <iostream>
#include <string>

using namespace std;

// โหนด
struct node
{
    node *llink;
    int data;
    node *rlink;
};

// เพิ่มต้นไม้
void insertTree(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->llink = NULL;
        root->data = data;
        root->rlink = NULL;
    }
    else if (data < root->data)
    {
        insertTree(root->llink, data);
    }
    else
    {
        insertTree(root->rlink, data);
    }
}

// ท่องต้นไม้
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->llink);
        preOrder(root->rlink);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->llink);
        cout << root->data << " ";
        inOrder(root->rlink);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->llink);
        postOrder(root->rlink);
        cout << root->data << " ";
    }
}

int main()
{
    node *root;
    root = NULL;

    // แทรกโหนด ก่อน หลัง และ กลาง
    insertTree(root, 1);
    insertTree(root, 2);
    insertTree(root, 3);
    insertTree(root, 4);
    insertTree(root, 5);
    insertTree(root, 6);
    insertTree(root, 7);
    insertTree(root, 8);
    insertTree(root, 9);

    // ท่องต้นไม้
    cout << "Preorder : ";
    preOrder(root);
    cout << endl;

    cout << "Inorder : ";
    inOrder(root);
    cout << endl;

    cout << "Postorder : ";
    postOrder(root);
    cout << endl;

    return 0;
}