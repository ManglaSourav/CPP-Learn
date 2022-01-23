/*
 * C++ Program to Implement Singly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*start;

/*
 * Class Declaration
 */
class Linked_List
{

public:

    Linked_List()
    {
        start = NULL;
    }

    //Creating Node
    struct node* create_node(int value)
    {
        struct node *temp;
        temp = new node;
        if (temp == NULL)
        {
            cout<<"Memory not allocated "<<endl;
            return 0;
        }
        else
        {
            temp->info = value;
            temp->next = NULL;
            return temp;
        }
    }



    //Inserting element in beginning

    void insert_begin()
    {
        int value;
        cout<<"Enter the value to be inserted: ";
        cin>>value;
        struct node *temp, *p;
        temp = create_node(value);
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            p = start;
            start = temp;
            start->next = p;
        }
        cout<<"Element Inserted at the beginning"<<endl;
    }


    // Inserting Node at last

    void insert_end()
    {
        int value;
        cout<<"Enter the value to be inserted: ";
        cin>>value;
        struct node *temp, *s;
        temp = create_node(value);
        s = start;
        while (s->next != NULL)
        {
            s = s->next;
        }
        temp->next = NULL;
        s->next = temp;
        cout<<"Element Inserted at the end"<<endl;
    }


// Insertion of node at a given position
    void insert_at_pos()
    {
        int value, pos, counter = 0;
        cout<<"Enter the value to be inserted: ";
        cin>>value;
        struct node *temp, *s, *ptr;
        temp = create_node(value);
        cout<<"Enter the postion at which node to be inserted: ";
        cin>>pos;
        int i;
        s = start;
        while (s != NULL)
        {
            s = s->next;
            counter++;
        }
        if (pos == 1)
        {
            if (start == NULL)
            {
                start = temp;
                start->next = NULL;
            }
            else
            {
                ptr = start;
                start = temp;
                start->next = ptr;
            }
        }
        else if (pos > 1  && pos <= counter)
        {
            s = start;
            for (i = 1; i < pos; i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = temp;
            temp->next = s;
        }
        else
        {
            cout<<"Positon out of range"<<endl;
        }
    }


    // Delete element at a given position

    void delete_at_pos()
    {
        int pos, i, counter = 0;
        if (start == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        cout<<"Enter the position of value to be deleted: ";
        cin>>pos;
        struct node *s, *ptr;
        s = start;
        if (pos == 1)
        {
            start = s->next;
        }
        else
        {
            while (s != NULL)
            {
                s = s->next;
                counter++;
            }
            if (pos > 0 && pos <= counter)
            {
                s = start;
                for (i = 1; i < pos; i++)
                {
                    ptr = s;
                    s = s->next;
                }
                ptr->next = s->next;
            }
            else
            {
                cout<<"Position out of range"<<endl;
                return;
            }
            cout<<"Element Deleted"<<endl;
        }
    }


//Searching an Element
    void search()
    {
        int value, pos = 0;
        bool flag = false;
        if (start == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        cout<<"Enter the value to be searched: ";
        cin>>value;
        struct node *s;
        s = start;
        while (s != NULL)
        {
            pos++;
            if (s->info == value)
            {
                flag = true;
                cout<<"Element "<<value<<" is found at position "<<pos<<endl;
            }
            s = s->next;
        }
        if (!flag)
            cout<<"Element "<<value<<" not found in the list"<<endl;
    }



//Display element of Linked list
    void display()
    {
        struct node *temp;
        if (start == NULL)
        {
            cout<<"The List is Empty"<<endl;
            return;
        }
        temp = start;
        cout<<"Elements of list are: "<<endl;
        while (temp != NULL)
        {
            cout<<temp->info<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


int main(){
    int choice;//, nodes, element, position, i;
    Linked_List sl;
    while (1)
    {
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at End"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4..Delete a Particular Node"<<endl;
        cout<<"5.Search Element"<<endl;
        cout<<"6.Display Linked List"<<endl;
        cout<<"7.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insert_end();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insert_at_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Delete a particular node: "<<endl;
            sl.delete_at_pos();
            break;
        case 5:
            cout<<"Search element in Link List: "<<endl;
            sl.search();
            cout<<endl;
            break;
        case 6:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 7:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}

