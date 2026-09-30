#include <iostream>

using namespace std;

#pragma pack(1)
template <class B>
class node
{
	public:
		B data;
		node * next;
        node * prev;

		node(B value);
};

template <class B>
node<B> :: node(B value)
{
	this->data = value;
	this->next = NULL;
    this->prev = NULL;
}

#pragma pack(1)
template <class B>
class DoublyCL
{
	private:
		node<B> * first;
		node<B> * last;
		int iCount;

	public:
		DoublyCL();

		void Display();
        int Count();

        void InsertFirst(B value);
        void InsertLast(B value);
        void InsertAtPos(B value, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class B>
DoublyCL<B> :: DoublyCL()
{
        this->first = NULL;
		this->last = NULL;
        this->iCount = 0;
}

template <class B>
void DoublyCL<B> :: Display()
{
    node<B> * temp = NULL;

    if(first == NULL && last == NULL)
	{
		return;
	}
	
    temp = first;
    cout << " <=> ";
    do
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }while (temp != last->next);
    cout << "\n";
}

template <class B>
int DoublyCL<B> :: Count()
{
    return iCount;
}

template <class B>
void DoublyCL<B> :: InsertFirst(B value)
{
    node<B> * newn = NULL;

    newn = new node(value);

    if(first == NULL && last == NULL)
    {
        first = newn;
		last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    }
	last->next = first;
    first->prev = last;
    iCount++;
}

template <class B>
void DoublyCL<B> :: InsertLast(B value)
{
    node<B> * newn = NULL;

    newn = new node(value);

    if(first == NULL && last == NULL)
    {
        first = newn;
		last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;

		last = newn;
    }
	iCount++;
    last->next = first;
    first->prev = last;
}

template <class B>
void DoublyCL<B> :: InsertAtPos(B value, int iPos)
{
    int iCnt = 0;

    node<B> * newn = NULL;
    node<B> * temp = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout << "Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(value);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(value);
    }
    else
    {
        newn = new node(value);

        temp = first;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }

}

template <class B>
void DoublyCL<B> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
		last = NULL;
    }
    else
    {
        first = first->next;
        first->prev = last;

        delete last->next;

        last->next = first;
    }
    iCount--;
}

template <class B>
void DoublyCL<B> :: DeleteLast()
{
    if(first == NULL && last == NULL)
    {   
        return;
    }
    else if(first == last)
    {   
        delete first;
        first = NULL;
		last = NULL;
    }
    else
    {
        last = last->prev;

        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class B>
void DoublyCL<B> :: DeleteAtPos(int iPos)
{
    int iCnt = 0;

    node<B> * target = NULL;
    node<B> * temp = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        delete temp->next->prev;

        temp->next->prev = temp;

        iCount--;
    }
}


int main()
{
	DoublyCL<int> sobj;
    DoublyCL<char> sobj1;
    DoublyCL<float> sobj2;
    
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of nodes are : " << iRet << endl;

    sobj.DeleteFirst();
    
    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of nodes are : " << iRet << endl;
    
    sobj.DeleteLast();
    
    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of nodes are : " << iRet << endl;

    sobj.InsertAtPos(105, 4);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of nodes are : " << iRet << endl;

    sobj.DeleteAtPos(4);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of nodes are : " << iRet << endl;


    sobj1.InsertFirst('C');
    sobj1.InsertFirst('B');
    sobj1.InsertFirst('A');

    sobj1.InsertLast('D');
    sobj1.InsertLast('E');
    sobj1.InsertLast('F');

    sobj1.Display();
    iRet = sobj1.Count();
    cout << "Number of nodes are : " << iRet << endl;

    sobj1.DeleteFirst();
    
    sobj1.Display();
    iRet = sobj1.Count();
    cout << "Number of nodes are : " << iRet << endl;
    
    sobj1.DeleteLast();
    
    sobj1.Display();
    iRet = sobj1.Count();
    cout << "Number of nodes are : " << iRet << endl;

    sobj1.InsertAtPos('P', 4);

    sobj1.Display();
    iRet = sobj1.Count();
    cout << "Number of nodes are : " << iRet << endl;

    sobj1.DeleteAtPos(4);

    sobj1.Display();
    iRet = sobj1.Count();
    cout << "Number of nodes are : " << iRet << endl;

	return 0;
}