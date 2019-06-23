#include "../student_node.h"
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
