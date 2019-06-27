#include <iostream>
#include <stdio.h>

using namespace std;

class node
{
  public:
    int info;
    node *link;
};

node *start = NULL;

class LL
{
  public:
    void display(node *start)
    {
        node *p;
        if(start == NULL)
        {
            cout << "\nList is Empty\n";
            return;
        }
        p = start;
        while(p != NULL)
        {
            cout << p->info << " ";
            p = p->link;
        }
    }
    
    int length(node *start)
    {
        int len = 0;
        node *p = start;
        if(p == NULL)
            return 0;
        while(p != NULL)
        {
            p = p->link;
            len++;
        }
        return len;
        
    }
    
    node *addatbeg(node *start, int data)
    {
        node *tmp;
        tmp = new node();
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        return start;
    }
    
    node *addatend(node *start, int data)
    {
        node *p, *tmp;
        tmp = new node();
        tmp->info = data;
        p = start;
        while(p->link != NULL)
            p = p->link;
            
        p->link = tmp;
        tmp->link = NULL;
        return start;
    }
    
    node *addatpos(node *start, int data, int pos)
    {
        if(pos == 1)
        {
            start = addatbeg(start, data);
            return start;
        }
        if(pos == length(start) + 1)
        {
            start = addatend(start, data);
            return start;
        }
        node *p, *tmp;
        p = start;
        for(int i = 1; i < pos && p != NULL; i++)
            p = p->link;
            
        tmp = new node();
        tmp->info = data;
        tmp->link = p->link;
        p->link = tmp;
        return start;
    }
    
    node *del(node *start, int data)
    {
        node *tmp, *p;
        if(start == NULL)
        {
            cout << "List is Empty\n";
            return start;
        }
        if(start->info == data)            /*Deletion of First Node*/
        {
            tmp = start;
            start = start->link;
            delete(tmp);
            return start;
        }
        
        p = start;                        /*Deletion in Between or in the end*/
        while(p->link != NULL)
        {
            if(p->link->info == data)
            {
                tmp = p->link;
                p->link = tmp->link;
                delete(tmp);
                return start;
            }
        }
        cout << "Element Not Found\n";
        return start;
    }
    
    
};

int main()
{
    LL obj;
    obj.display(start);
    start = obj.addatbeg(start, 10);
    start = obj.addatpos(start, 20, 2);
    start = obj.addatend(start, 30);
    obj.display(start);
    start = obj.del(start, 10);
    start = obj.del(start, 20);
    start = obj.del(start, 30);
    obj.display(start);
    return 0;
    
}