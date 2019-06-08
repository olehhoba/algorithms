#include <iostream>
using namespace std;
struct FIFO
{
    struct FIFOel *begin;
    struct FIFOel *end;
};

////////////////////////////////////////////////////////////////////////////////////////

struct FIFOel
{
    struct FIFOel *next;
    int x;
};

/////////////////////////////////////////////////////////////////////////////////////////
//add  element  to the queue
struct FIFO *add(struct FIFO *queue, int element)
{
    struct FIFOel *new_element=new struct FIFOel;
    new_element->x=element;
    new_element->next=NULL;

    if(queue->end==NULL)
    {
        queue->begin=new_element;
        queue->end=new_element;
    }
    else
    {
        queue->end->next=new_element;
        queue->end=new_element;
    }
    return queue;
}

////////////////////////////////////////////////////////////////////////////////////////
//remove element
struct FIFO *remove(struct FIFO *queue, int *element)
{
    struct FIFOel *pom;
    *element=queue->begin->x;
    if(queue->begin!=queue->end)
    {
        pom=queue->begin->next;
        delete [](queue->begin);
        queue->begin=pom;
    }
    else
    {
        delete [](queue->begin);
        queue->begin=NULL;
        queue->end=NULL;
    }
    return queue;
}

//////////////////////////////////////////////////////////////////////////////////////////
//print
struct FIFO *print(struct FIFO *queue)
{
    if(queue->begin!=NULL)
    {
        int z;
        struct FIFO *queue2;
        queue2=new struct FIFO;
        queue2->begin=NULL;
        queue2->end=NULL;

        cout<<"\nThe beginning of the queue"<<endl;

        while(queue->begin!=NULL)
        {
            queue=remove(queue, &z);
            queue2=add(queue2, z);
            cout<<endl<<z;
        }

        cout<<endl<<"\nEnd of the queue!"<<endl;

        while(queue2->begin!=NULL)
        {
            queue2=remove(queue2, &z);
            queue=add(queue, z);
        }
    }
    else
    {
        cout<<endl<<"The queue is empty!"<<endl;
    }

    return queue;
}

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int element,choice;
    struct FIFO *queue=new struct FIFO;
    queue->begin=NULL;
    queue->end=NULL;
    do
    {
        system("cls");
        cout<<"\n1.Creating an empty queue."<<endl;
        cout<<"2.Adding an element to the queue."<<endl;
        cout<<"3.Removing an element from the queue."<<endl;
        cout<<"4.Print all elements of the queue."<<endl;
        cout<<"5.End of the program."<<endl;
        cout<<"\nYour choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                while(queue->begin)
                {
                    queue=remove(queue,&element);
                }
            break;

			case 2:
                cout<<"\nEnter new element: ";
                cin>>element;
                queue=add(queue,element);
			break;

			case 3:
                if(queue->begin!=NULL)
                {
                    queue=remove(queue,&element);
                    cout<<"\nRemoved: "<<element<<endl;
                }
                else
                {
                    cout<<"\nThe queue is empty, no elements to remove!"<<endl;
                }
                fflush(stdin);
                getchar();
	        break;

	        case 4:
                queue=print(queue);
                fflush(stdin);
                getchar();
	        break;
	    }
    }
    while(choice!=5);
    return 0;
}
