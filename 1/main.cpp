#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
class student
{
private:
    char*name;
    int value;
public:
    student(const char*in=0,int iv=0);
    student(const student&i);
    ~student();
    student& operator=(const student&rhs);
    int get_value()const{return value;}
     const char* get_name()const {return (const char*)name;}
    int operator<(const student&b)const;
    bool operator==(const student&b)const;
    void swaps(student&b);
    int init(const char*in=0,int iv=0);
};
class Node: public student
{
    private:
    student d;
    Node* left;
    Node* right;
    public:
        Node* first (student d);
        Node* search_insert (Node* root, student d);
        void print_tree (Node* p, int level);
        Node* goto_left (Node* root) {if (root->left) { root=root->left; return root;} return 0;}
        Node* goto_right (Node* root) {if (root->right){root=root->right; return root;} return 0;}
        const char* name () const { return d.get_name();}
        int value () const { return d.get_value();}
};
bool student::operator== (const student&b) const
{
    return strcmp(name,b.name)==0;
}
int student::operator<(const student&b) const
{
    return strcmp(name,b.name)<0;
}
int student::init(const char*in,int iv)
{
    value=iv;
    if(in)
    {
        name = new char[strlen(in)+1];
        if(name) strcpy(name,in);
        else return 1;
    }
    return 0;
}

student::student(const char*in,int iv)
{
    init(in,iv);
}

student::student(const student&rhs)
{
    init(rhs.name,rhs.value);
}

student::~student()
{
    if(name) delete [] name;
    name=0;value=0;
}

student& student::operator=(const student&rhs)
{
    this->student::~student();
    init(rhs.name,rhs.value);
    return *this;
}



void student::swaps(student&b)
{
    char*n;int v;
    n=b.name;b.name=name;name=n;
    v=b.value;b.value=value;value=v;
}
Node* Node:: first (student d)
{
    Node* pv=new Node;
    pv->d=d;
    pv->left=0;
    pv->right=0;
    return pv;
}
Node* Node::search_insert (Node* root, student d)
{
    Node* pv=root,*prev;
    bool found=false;
    while (pv&&!found)
    {
        prev=pv;
        if (d==pv->d) found=true;
        else if (d< pv->d) pv=pv->left;
        else               pv=pv->right;
    }
    if (found) return pv;
    Node *pnew=new Node;
    pnew->d=d;
    pnew->left=0;
    pnew->right=0;
    if (d<prev->d)
        prev->left=pnew;
    else
        prev->right=pnew;
    return pnew;
}
void Node::print_tree (Node* p, int level)
{
    if (p)
    {
        print_tree(p->left,level+1);
        for (int i=0;i<level;i++) printf("   ");
        printf("%s %d\n",p->name(),p->value());
        print_tree(p->right,level+1);
    }
}
int solve (Node* root)
{
    int m=0,n=0;
    if(root->goto_left(root)||root->goto_right(root))
    {
        if(root->goto_left(root))
            m=solve(root->goto_left(root));
        if(root->goto_right(root))
         n=solve(root->goto_right(root));

    }
    else return 1;

    return m+n;
}
int main ()
{
    FILE *fp;
    int c;
    student tmp;
    char b[1000];
    int otvet;
    if(!(fp=fopen("a.txt","r"))) return -1;
    if(fscanf(fp,"%s%d",b,&c)!=2)
    {

        return -3;
    }
    tmp.init(b,c);
    Node* root;
    root=root->first(tmp);
    while(fscanf(fp,"%s%d",b,&c)==2)
    {
        tmp.init(b,c);
        root->search_insert(root,tmp);

    }
    if(!feof(fp))
        {
            fclose(fp);
            return -2;
        }
    fclose(fp);
    root->print_tree(root,0);
    otvet=solve(root);
    printf("Otvet=%d\n",otvet);
    return 0;

}
