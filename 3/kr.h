#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
class node
{
private:
     char* name;
     node *left,*right;
public:
    node(const char*in=0) {if(in)name=new char[strlen(in)+1];if(name) strcpy(name,in);left=0;right=0;}
    node() {name=0;left=0;right=0;}
    ~node(){if(name)delete[]name;left=0;right=0;}
    node* get_left() const {return left;}
    node* get_right() const {return right;}
    int operator<(const node*a){return strcmp(this->name,a->name);}
    node* add(node&a)
    {
        int k;
        if(this==0)
        {
           // student_node*p=new student_node;
          //  *p=a;
            a.left=a.right=0;
            return &a;
        }
        else
        {
            k=*this<a;
            if(k>=0) right=right->add(a);
            else left=left->add(a);
            return this;
        }
    }
    node*Search(node&a)
    {
        if(this ==0) return 0;
        if((*this<a)==0) return this;
        if(a<*this) return right->Search(a);
        else return left->Search(a);
    }
    void Walk()
    {
        if(this==0) return ;
      //  process(root); действие над элементом
      left->Walk();
      right->Walk();
    }
node* gettree(char*name)
{
    FILE *fp;
    char b[1000];
    node* q;
    node* root;
    if(!(fp=fopen(name,"r"))) return 0;
    if (fgets(b,1000,fp))
    {
        q=new node(b);
        root=this->add(*q);
    }
    while(fgets(b,1000,fp))
    {
        q=new student_node(b);
        root->add(*q);
        //printf("q=%s %d\n",q->get_name(),q->get_value());
    }
    if(!feof(fp))
        {
            fclose(fp);
            return 0;
        }
    fclose(fp);
    return root;
}
void Del()
    {
        if(this==0) return;
        left->Del();
        right->Del();
        delete this;
    }

    void printtree(int k)
    {

        if(this)
        {

            right->printtree(k+2);


            for(int i=0;i<k;i++) std::cout << "  ";
            std::cout << get_name() << " " << get_value()<<std::endl;


            left->printtree(k+2);

        }
        else {return;}
    }
        int Dlina()
        {
            int i=0,j=0;
        if(left||right)
        {
            if(left)i=left->Dlina();
            if(right) j=right->Dlina();

        }
        else return 1;

        return i+j;
        }
};
int Fun(node*root);

