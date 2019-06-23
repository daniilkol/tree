#include "kr.h"
int Fun(student_node*root)
{
    int i=0,j=0;
    if(root->get_left()||root->get_right())
    {
        if(root->get_left())i=Fun(root->get_left());
        if(root->get_right()) j=Fun(root->get_right());

    }
    else return 1;

    return i+j;
}

int main()
{
    student_node *root=0;
   // char buf[1000];
    int p;
    //int ans;
    //printf("1");
    root=root->gettree("a.txt");
   // if(root)std::cout << root->get_name() << " " <<root->get_value();
   // else std::cout<<"!!!!!!!!!!!!!!!!!!";
    //s.init(buf,p);
    //printarray(b);
    printf("\n\n");
    p=Fun(root);
    root->printtree(0);
    printf("\n\nAnswer=%d",p);
    root->Del();
    return 0;
}
