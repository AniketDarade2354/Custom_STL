/////////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


/////////////////////////////////////////////////////////////
//
//  Class Name : SinglyLNode
//  Description : This class is use to create new node for 
//                Singly Linear and Singly Circular LinkedList
//
/////////////////////////////////////////////////////////////
#pragma pack(1)
template <class A> 
class SinglyLNode
{
    public:
        A data;
        SinglyLNode* next;
        
        SinglyLNode(A value);
};

/////////////////////////////////////////////////////////////
//
//  Function name : SinglyLNode (Constructor)
//  Description :   This is constructor of SinglyLNode class
//                  which initialise the variables inside
//                  SinglyLNode class
//  Input :         value - data to be stored inside the node
//  Output :        None (initialises data and next)
//
/////////////////////////////////////////////////////////////
template <class A>
SinglyLNode<A> :: SinglyLNode(A value)
{
    this->data = value;
    this->next = NULL; 
}

/////////////////////////////////////////////////////////////
//
//  Class Name : DoublyLNode
//  Description : This class is use to create new node for 
//                Doubly Linear and Doubly Circular LinkedList
//
/////////////////////////////////////////////////////////////

#pragma pack(1)
template <class B>
class DoublyLNode
{
	public:
		B data;
		DoublyLNode * next;
        DoublyLNode * prev;

		DoublyLNode(B value);
};

/////////////////////////////////////////////////////////////
//
//  Function name : DoublyLNode (Constructor)
//  Description :   This is constructor of DoublyLNode class
//                  which initialise the variables inside
//                  DoublyLNode class
//  Input :         value - data to be stored inside the node
//  Output :        None (initialises data, next and prev)
//
/////////////////////////////////////////////////////////////
template <class B>
DoublyLNode<B> :: DoublyLNode(B value)
{
	this->data = value;
	this->next = NULL;
    this->prev = NULL;
}


/////////////////////////////////////////////////////////////
//
//  Class Name : BSTNode
//  Description : This class is use to create new node for
//                Binary Search Tree (BST)
//
/////////////////////////////////////////////////////////////
#pragma pack(1)
template <class A>
class BSTNode
{
    public:
        A data;
        BSTNode * lchild;
        BSTNode * rchild;

        BSTNode(A value);
};

/////////////////////////////////////////////////////////////
//
//  Function name : BSTNode (Constructor)
//  Description :   This is constructor of BSTNode class
//                  which initialise the variables inside
//                  BSTNode class
//  Input :         value - data to be stored inside the node
//  Output :        None (initialises data, lchild and rchild)
//
/////////////////////////////////////////////////////////////
template <class A>
BSTNode<A> :: BSTNode(A value)
{
    this->data = value;
    this->lchild = NULL;
    this->rchild = NULL;
}


/////////////////////////////////////////////////////////////
//  SinglyLL  (Singly Linear LinkedList)
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//
//  Class Name : SinglyLL
//  Description : This class is use to implement all 
//                funtcions required for singly linear
//                linkedlist
//
/////////////////////////////////////////////////////////////
template <class A> 
class SinglyLL
{
    private:
        SinglyLNode<A> * first;
        int iCount;
        
    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(A value);
        void InsertLast(A value);
        void InsertAtPos(A value, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

/////////////////////////////////////////////////////////////
//
//  Function name : SinglyLL (Constructor)
//  Description :   Initialises the head pointer and node
//                  count for an empty singly linear list
//  Input :         None
//  Output :        None (initialises first = NULL, iCount = 0)
//
/////////////////////////////////////////////////////////////
template <class A>
SinglyLL<A> :: SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////
//
//  Function name : Display
//  Description :   Traverses the list from first to last
//                  node and prints the data of every node
//                  followed by NULL
//  Input :         None
//  Output :        None (prints list contents to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyLL<A> :: Display()
{
    SinglyLNode<A> * temp = NULL;

    temp = first;
    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////
//
//  Function name : Count
//  Description :   Returns the total number of nodes
//                  currently present in the list
//  Input :         None
//  Output :        int - current node count (iCount)
//
/////////////////////////////////////////////////////////////
template <class A>
int SinglyLL<A> :: Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertFirst
//  Description :   Inserts a new node containing the given
//                  value at the beginning of the list and
//                  updates the head pointer (first)
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyLL<A> :: InsertFirst(A value)
{
    SinglyLNode<A> * newn = NULL;

    newn = new SinglyLNode(value);

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertLast
//  Description :   Inserts a new node containing the given
//                  value at the end of the list by
//                  traversing till the last node
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyLL<A> :: InsertLast(A value)
{
    SinglyLNode<A> * newn = NULL;
    SinglyLNode<A> * temp = NULL;

    newn = new SinglyLNode(value);

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        
    }
    iCount++;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertAtPos
//  Description :   Inserts a new node containing the given
//                  value at the specified position (1-based
//                  indexing). Delegates to InsertFirst or
//                  InsertLast at the boundaries, otherwise
//                  inserts in the middle of the list
//  Input :         value - data to be inserted
//                  iPos  - 1-based position at which to insert
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyLL<A> :: InsertAtPos(A value, int iPos)
{
    int iCnt = 0;

    SinglyLNode<A> * newn = NULL;
    SinglyLNode<A> * temp = NULL;

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
        newn = new SinglyLNode(value);

        temp = first;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }

}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteFirst
//  Description :   Deletes the first node of the list and
//                  updates the head pointer (first) to the
//                  next node. Handles empty list and
//                  single-node list as special cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyLL<A> :: DeleteFirst()
{
    SinglyLNode<A> * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        first = first->next;

        delete temp;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteLast
//  Description :   Deletes the last node of the list by
//                  traversing till the second-last node and
//                  freeing the final node. Handles empty list
//                  and single-node list as special cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyLL<A> :: DeleteLast()
{
    SinglyLNode<A> * temp = NULL;

    if(first == NULL)
    {   
        return;
    }
    else if(first->next == NULL)
    {   
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteAtPos
//  Description :   Deletes the node present at the specified
//                  position (1-based indexing). Delegates to
//                  DeleteFirst or DeleteLast at the boundaries,
//                  otherwise unlinks the target node from the
//                  middle of the list
//  Input :         iPos - 1-based position of node to delete
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyLL<A> :: DeleteAtPos(int iPos)
{
    int iCnt = 0;

    SinglyLNode<A> * target = NULL;
    SinglyLNode<A> * temp = NULL;

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

        target = temp->next;

        temp->next = target->next;

        delete target;

        iCount--;
    }
}


/////////////////////////////////////////////////////////////
//  SinglyCL  (Singly Circular LinkedList)
/////////////////////////////////////////////////////////////
#pragma pack(1)
template <class A>
class SinglyCL
{
	private:
		SinglyLNode<A> * first;
		SinglyLNode<A> * last;
		int iCount;

	public:
		SinglyCL();

		void Display();
        int Count();

        void InsertFirst(A value);
        void InsertLast(A value);
        void InsertAtPos(A value, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

/////////////////////////////////////////////////////////////
//
//  Function name : SinglyCL (Constructor)
//  Description :   Initialises the first pointer, last
//                  pointer, and node count for an empty
//                  singly circular list
//  Input :         None
//  Output :        None (initialises first = last = NULL,
//                  iCount = 0)
//
/////////////////////////////////////////////////////////////
template <class A>
SinglyCL<A> :: SinglyCL()
{
        this->first = NULL;
		this->last = NULL;
        this->iCount = 0;
}

/////////////////////////////////////////////////////////////
//
//  Function name : Display
//  Description :   Traverses the circular list starting from
//                  first and printing each node's data until
//                  it wraps back to first (i.e. reaches
//                  last->next), since there is no NULL
//                  terminator in a circular list
//  Input :         None
//  Output :        None (prints list contents to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyCL<A> :: Display()
{
    SinglyLNode<A> * temp = NULL;

	if(first == NULL && last == NULL)
	{
		return;
	}

    temp = first;
    do
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }while (temp != last->next);
    cout << "\n";
}

/////////////////////////////////////////////////////////////
//
//  Function name : Count
//  Description :   Returns the total number of nodes
//                  currently present in the circular list
//  Input :         None
//  Output :        int - current node count (iCount)
//
/////////////////////////////////////////////////////////////
template <class A>
int SinglyCL<A> :: Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertFirst
//  Description :   Inserts a new node at the beginning of the
//                  circular list, updates the first pointer,
//                  and reconnects last->next to maintain the
//                  circular link
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyCL<A> :: InsertFirst(A value)
{
    SinglyLNode<A> * newn = NULL;

    newn = new SinglyLNode(value);

    if(first == NULL && last == NULL)
    {
        first = newn;
		last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
	last->next = first;
    iCount++;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertLast
//  Description :   Inserts a new node at the end of the
//                  circular list, updates the last pointer,
//                  and reconnects last->next to first to
//                  maintain the circular link
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyCL<A> :: InsertLast(A value)
{
    SinglyLNode<A> * newn = NULL;

    newn = new SinglyLNode(value);

    if(first == NULL && last == NULL)
    {
        first = newn;
		last = newn;
    }
    else
    {
        last->next = newn;
		last = newn;
    }
	last->next = first;
    iCount++;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertAtPos
//  Description :   Inserts a new node at the specified
//                  position (1-based indexing) in the circular
//                  list. Delegates to InsertFirst or InsertLast
//                  at the boundaries, otherwise inserts in the
//                  middle of the list
//  Input :         value - data to be inserted
//                  iPos  - 1-based position at which to insert
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyCL<A> :: InsertAtPos(A value, int iPos)
{
    int iCnt = 0;

    SinglyLNode<A> * newn = NULL;
    SinglyLNode<A> * temp = NULL;

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
        newn = new SinglyLNode(value);

        temp = first;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }

}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteFirst
//  Description :   Deletes the first node of the circular
//                  list and reconnects last->next to the new
//                  first node. Handles empty list and
//                  single-node list as special cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyCL<A> :: DeleteFirst()
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

		delete last->next;

		last->next = first;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteLast
//  Description :   Deletes the last node of the circular list
//                  by traversing till the second-last node,
//                  updating the last pointer, and reconnecting
//                  last->next to first. Handles empty list and
//                  single-node list as special cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyCL<A> :: DeleteLast()
{
    SinglyLNode<A> * temp = NULL;

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
        temp = first;

        while (temp->next->next != last->next)
        {
            temp = temp->next;
        }

        delete temp->next;

        last = temp;

		last->next = first;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteAtPos
//  Description :   Deletes the node present at the specified
//                  position (1-based indexing) in the circular
//                  list. Delegates to DeleteFirst or DeleteLast
//                  at the boundaries, otherwise unlinks the
//                  target node from the middle of the list
//  Input :         iPos - 1-based position of node to delete
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class A>
void SinglyCL<A> :: DeleteAtPos(int iPos)
{
    int iCnt = 0;

    SinglyLNode<A> * target = NULL;
    SinglyLNode<A> * temp = NULL;

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

        target = temp->next;

        temp->next = target->next;

        delete target;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//  DoublyLL  (Doubly Linear LinkedList)
/////////////////////////////////////////////////////////////

template <class B> 
class DoublyLL
{
    private:
        DoublyLNode<B> * first;
        DoublyLNode<B> * last;
        int iCount;
        
    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(B value);
        void InsertLast(B value);
        void InsertAtPos(B value, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

/////////////////////////////////////////////////////////////
//
//  Function name : DoublyLL (Constructor)
//  Description :   Initialises the head pointer and node
//                  count for an empty doubly linear list
//  Input :         None
//  Output :        None (initialises first = NULL, iCount = 0)
//
/////////////////////////////////////////////////////////////
template <class B>
DoublyLL<B> :: DoublyLL()
{
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
}

/////////////////////////////////////////////////////////////
//
//  Function name : Display
//  Description :   Traverses the list from first to last
//                  node, printing each node's data with
//                  bidirectional (<=>) markers between NULL
//                  terminators
//  Input :         None
//  Output :        None (prints list contents to console)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyLL<B> :: Display()
{
    DoublyLNode<B> * temp = NULL;

    temp = first;
    cout << "NULL <=> ";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////
//
//  Function name : Count
//  Description :   Returns the total number of nodes
//                  currently present in the list
//  Input :         None
//  Output :        int - current node count (iCount)
//
/////////////////////////////////////////////////////////////
template <class B>
int DoublyLL<B> :: Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertFirst
//  Description :   Inserts a new node at the beginning of the
//                  list, links it to the old first node via
//                  next/prev, and updates the head pointer
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyLL<B> :: InsertFirst(B value)
{
    DoublyLNode<B> * newn = NULL;

    newn = new DoublyLNode(value);

    if(first == NULL)
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
    iCount++;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertLast
//  Description :   Inserts a new node at the end of the list
//                  by traversing till the last node and
//                  linking it via next/prev pointers
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyLL<B> :: InsertLast(B value)
{
    DoublyLNode<B> * newn = NULL;

    newn = new DoublyLNode(value);

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;

        last = newn;
    }
    iCount++;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertAtPos
//  Description :   Inserts a new node at the specified
//                  position (1-based indexing), updating both
//                  next and prev pointers of the surrounding
//                  nodes. Delegates to InsertFirst or
//                  InsertLast at the boundaries
//  Input :         value - data to be inserted
//                  iPos  - 1-based position at which to insert
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyLL<B> :: InsertAtPos(B value, int iPos)
{
    int iCnt = 0;

    DoublyLNode<B> * newn = NULL;
    DoublyLNode<B> * temp = NULL;

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
        newn = new DoublyLNode(value);

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

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteFirst
//  Description :   Deletes the first node of the list,
//                  updates the head pointer, and clears the
//                  new first node's prev pointer. Handles
//                  empty list and single-node list as special
//                  cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyLL<B> :: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;

        delete first->prev;

        first->prev = NULL;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteLast
//  Description :   Deletes the last node of the list by
//                  traversing till the second-last node and
//                  freeing the final node. Handles empty list
//                  and single-node list as special cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyLL<B> :: DeleteLast()
{
    DoublyLNode<B> * temp = NULL;

    if(first == NULL)
    {   
        return;
    }
    else if(first->next == NULL)
    {   
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        
    }
    iCount--;
}

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteAtPos
//  Description :   Deletes the node present at the specified
//                  position (1-based indexing), relinking the
//                  next and prev pointers of the surrounding
//                  nodes. Delegates to DeleteFirst or
//                  DeleteLast at the boundaries
//  Input :         iPos - 1-based position of node to delete
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyLL<B> :: DeleteAtPos(int iPos)
{
    int iCnt = 0;

    DoublyLNode<B> * target = NULL;
    DoublyLNode<B> * temp = NULL;

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

/////////////////////////////////////////////////////////////
//  DoublyCL  (Doubly Circular LinkedList)
/////////////////////////////////////////////////////////////

#pragma pack(1)
template <class B>
class DoublyCL
{
	private:
		DoublyLNode<B> * first;
		DoublyLNode<B> * last;
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

/////////////////////////////////////////////////////////////
//
//  Function name : DoublyCL (Constructor)
//  Description :   Initialises the first pointer, last
//                  pointer, and node count for an empty
//                  doubly circular list
//  Input :         None
//  Output :        None (initialises first = last = NULL,
//                  iCount = 0)
//
/////////////////////////////////////////////////////////////
template <class B>
DoublyCL<B> :: DoublyCL()
{
        this->first = NULL;
		this->last = NULL;
        this->iCount = 0;
}

/////////////////////////////////////////////////////////////
//
//  Function name : Display
//  Description :   Traverses the circular list starting from
//                  first, printing each node's data with
//                  bidirectional (<=>) markers, until it
//                  wraps back to first (i.e. reaches
//                  last->next)
//  Input :         None
//  Output :        None (prints list contents to console)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyCL<B> :: Display()
{
    DoublyLNode<B> * temp = NULL;

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

/////////////////////////////////////////////////////////////
//
//  Function name : Count
//  Description :   Returns the total number of nodes
//                  currently present in the circular list
//  Input :         None
//  Output :        int - current node count (iCount)
//
/////////////////////////////////////////////////////////////
template <class B>
int DoublyCL<B> :: Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////
//
//  Function name : InsertFirst
//  Description :   Inserts a new node at the beginning of the
//                  circular list, updates the first pointer,
//                  and reconnects both last->next and
//                  first->prev to maintain the circular link
//                  in both directions
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyCL<B> :: InsertFirst(B value)
{
    DoublyLNode<B> * newn = NULL;

    newn = new DoublyLNode(value);

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

/////////////////////////////////////////////////////////////
//
//  Function name : InsertLast
//  Description :   Inserts a new node at the end of the
//                  circular list, updates the last pointer,
//                  and reconnects both last->next and
//                  first->prev to maintain the circular link
//                  in both directions
//  Input :         value - data to be inserted
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyCL<B> :: InsertLast(B value)
{
    DoublyLNode<B> * newn = NULL;

    newn = new DoublyLNode(value);

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

/////////////////////////////////////////////////////////////
//
//  Function name : InsertAtPos
//  Description :   Inserts a new node at the specified
//                  position (1-based indexing) in the doubly
//                  circular list, updating next/prev pointers
//                  of the surrounding nodes. Delegates to
//                  InsertFirst or InsertLast at the boundaries
//  Input :         value - data to be inserted
//                  iPos  - 1-based position at which to insert
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyCL<B> :: InsertAtPos(B value, int iPos)
{
    int iCnt = 0;

    DoublyLNode<B> * newn = NULL;
    DoublyLNode<B> * temp = NULL;

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
        newn = new DoublyLNode(value);

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

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteFirst
//  Description :   Deletes the first node of the circular
//                  list, updates the first pointer, and
//                  reconnects last->next and the new first
//                  node's prev to maintain circularity.
//                  Handles empty list and single-node list as
//                  special cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteLast
//  Description :   Deletes the last node of the circular list
//                  by moving the last pointer to last->prev
//                  and reconnecting last->next and first->prev
//                  to maintain circularity. Handles empty list
//                  and single-node list as special cases
//  Input :         None
//  Output :        None (list is modified in place)
//
/////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////
//
//  Function name : DeleteAtPos
//  Description :   Deletes the node present at the specified
//                  position (1-based indexing) in the doubly
//                  circular list, relinking next/prev pointers
//                  of the surrounding nodes. Delegates to
//                  DeleteFirst or DeleteLast at the boundaries
//  Input :         iPos - 1-based position of node to delete
//  Output :        None (list modified in place; prints
//                  "Invalid position" if iPos is out of range)
//
/////////////////////////////////////////////////////////////
template <class B>
void DoublyCL<B> :: DeleteAtPos(int iPos)
{
    int iCnt = 0;

    DoublyLNode<B> * target = NULL;
    DoublyLNode<B> * temp = NULL;

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

/////////////////////////////////////////////////////////////
//  BST (Binary Search Tree)
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//
//  Class Name : BST
//  Description : This class is use to implement all
//                functions required for Binary Search Tree
//
/////////////////////////////////////////////////////////////
template <class A>
class BST
{
    private:
        BSTNode<A> * root;

        void Inorder(BSTNode<A> * temp);
        void Preorder(BSTNode<A> * temp);
        void Postorder(BSTNode<A> * temp);
        int Count(BSTNode<A> * temp);
        int CountLeaf(BSTNode<A> * temp);
        int CountParent(BSTNode<A> * temp);
        bool Search(BSTNode<A> * temp, A value);

    public:
        BST();

        void Insert(A value);
        void Inorder();
        void Preorder();
        void Postorder();
        int Count();
        int CountLeaf();
        int CountParent();
        bool Search(A value);
};

/////////////////////////////////////////////////////////////
//
//  Function name : BST (Constructor)
//  Description :   Initialises the root pointer for an
//                  empty Binary Search Tree
//  Input :         None
//  Output :        None (initialises root = NULL)
//
/////////////////////////////////////////////////////////////
template <class A>
BST<A> :: BST()
{
    this->root = NULL;
}

/////////////////////////////////////////////////////////////
//
//  Function name : Insert (public wrapper)
//  Description :   Inserts a new value into the BST by
//                  walking from root and placing the new
//                  node according to BST ordering (left if
//                  smaller, right if larger). Duplicate
//                  values are rejected
//  Input :         value - data to be inserted
//  Output :        None (tree modified in place; prints
//                  message if value is a duplicate)
//
/////////////////////////////////////////////////////////////
template <class A>
void BST<A> :: Insert(A value)
{
    BSTNode<A> * newn = NULL;
    BSTNode<A> * temp = NULL;

    newn = new BSTNode<A>(value);

    if(root == NULL)
    {
        root = newn;
        return;
    }

    temp = root;

    while(1)
    {
        if(value > temp->data)
        {
            if(temp->rchild == NULL)
            {
                temp->rchild = newn;
                break;
            }
            temp = temp->rchild;
        }
        else if(value < temp->data)
        {
            if(temp->lchild == NULL)
            {
                temp->lchild = newn;
                break;
            }
            temp = temp->lchild;
        }
        else
        {
            cout << "Unable to insert as element is duplicate\n";
            delete newn;
            break;
        }
    }
}

/////////////////////////////////////////////////////////////
//
//  Function name : Inorder (private helper)
//  Description :   Recursively traverses the tree in
//                  Left -> Data -> Right order and prints
//                  each node's data
//  Input :         temp - current node in the recursion
//  Output :        None (prints data to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void BST<A> :: Inorder(BSTNode<A> * temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout << temp->data << "\n";
        Inorder(temp->rchild);
    }
}

/////////////////////////////////////////////////////////////
//
//  Function name : Inorder (public wrapper)
//  Description :   Starts an inorder traversal from the root
//  Input :         None
//  Output :        None (prints data to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void BST<A> :: Inorder()
{
    Inorder(root);
}

/////////////////////////////////////////////////////////////
//
//  Function name : Preorder (private helper)
//  Description :   Recursively traverses the tree in
//                  Data -> Left -> Right order and prints
//                  each node's data
//  Input :         temp - current node in the recursion
//  Output :        None (prints data to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void BST<A> :: Preorder(BSTNode<A> * temp)
{
    if(temp != NULL)
    {
        cout << temp->data << "\n";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

/////////////////////////////////////////////////////////////
//
//  Function name : Preorder (public wrapper)
//  Description :   Starts a preorder traversal from the root
//  Input :         None
//  Output :        None (prints data to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void BST<A> :: Preorder()
{
    Preorder(root);
}

/////////////////////////////////////////////////////////////
//
//  Function name : Postorder (private helper)
//  Description :   Recursively traverses the tree in
//                  Left -> Right -> Data order and prints
//                  each node's data
//  Input :         temp - current node in the recursion
//  Output :        None (prints data to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void BST<A> :: Postorder(BSTNode<A> * temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout << temp->data << "\n";
    }
}

/////////////////////////////////////////////////////////////
//
//  Function name : Postorder (public wrapper)
//  Description :   Starts a postorder traversal from the root
//  Input :         None
//  Output :        None (prints data to console)
//
/////////////////////////////////////////////////////////////
template <class A>
void BST<A> :: Postorder()
{
    Postorder(root);
}

/////////////////////////////////////////////////////////////
//
//  Function name : Count (private helper)
//  Description :   Recursively counts total nodes in the
//                  subtree rooted at temp. Uses a plain
//                  return-based accumulation (no static
//                  variable), so repeated calls always give
//                  a fresh, correct result
//  Input :         temp - current node in the recursion
//  Output :        int - number of nodes in this subtree
//
/////////////////////////////////////////////////////////////
template <class A>
int BST<A> :: Count(BSTNode<A> * temp)
{
    if(temp == NULL)
    {
        return 0;
    }

    return 1 + Count(temp->lchild) + Count(temp->rchild);
}

/////////////////////////////////////////////////////////////
//
//  Function name : Count (public wrapper)
//  Description :   Returns the total number of nodes in
//                  the entire BST
//  Input :         None
//  Output :        int - total node count
//
/////////////////////////////////////////////////////////////
template <class A>
int BST<A> :: Count()
{
    return Count(root);
}

/////////////////////////////////////////////////////////////
//
//  Function name : CountLeaf (private helper)
//  Description :   Recursively counts leaf nodes (nodes with
//                  no children) in the subtree rooted at temp
//  Input :         temp - current node in the recursion
//  Output :        int - number of leaf nodes in this subtree
//
/////////////////////////////////////////////////////////////
template <class A>
int BST<A> :: CountLeaf(BSTNode<A> * temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    if(temp->lchild == NULL && temp->rchild == NULL)
    {
        return 1;
    }
    return CountLeaf(temp->lchild) + CountLeaf(temp->rchild);
}

/////////////////////////////////////////////////////////////
//
//  Function name : CountLeaf (public wrapper)
//  Description :   Returns the total number of leaf nodes
//                  in the entire BST
//  Input :         None
//  Output :        int - total leaf node count
//
/////////////////////////////////////////////////////////////
template <class A>
int BST<A> :: CountLeaf()
{
    return CountLeaf(root);
}

/////////////////////////////////////////////////////////////
//
//  Function name : CountParent (private helper)
//  Description :   Recursively counts parent nodes (nodes
//                  with at least one child) in the subtree
//                  rooted at temp
//  Input :         temp - current node in the recursion
//  Output :        int - number of parent nodes in this
//                  subtree
//
/////////////////////////////////////////////////////////////
template <class A>
int BST<A> :: CountParent(BSTNode<A> * temp)
{
    if(temp == NULL)
    {
        return 0;
    }
    int iCurrent = (temp->lchild != NULL || temp->rchild != NULL) ? 1 : 0;
    return iCurrent + CountParent(temp->lchild) + CountParent(temp->rchild);
}

/////////////////////////////////////////////////////////////
//
//  Function name : CountParent (public wrapper)
//  Description :   Returns the total number of parent nodes
//                  in the entire BST
//  Input :         None
//  Output :        int - total parent node count
//
/////////////////////////////////////////////////////////////
template <class A>
int BST<A> :: CountParent()
{
    return CountParent(root);
}

/////////////////////////////////////////////////////////////
//
//  Function name : Search (private helper)
//  Description :   Iteratively searches for a value starting
//                  from the given node, moving left or right
//                  based on BST ordering
//  Input :         temp  - node to start the search from
//                  value - data to search for
//  Output :        bool - true if value is found, else false
//
/////////////////////////////////////////////////////////////
template <class A>
bool BST<A> :: Search(BSTNode<A> * temp, A value)
{
    while(temp != NULL)
    {
        if(value == temp->data)
        {
            return true;
        }
        else if(value > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    return false;
}

/////////////////////////////////////////////////////////////
//
//  Function name : Search (public wrapper)
//  Description :   Searches for a value in the entire BST
//                  starting from the root
//  Input :         value - data to search for
//  Output :        bool - true if value is found, else false
//
/////////////////////////////////////////////////////////////
template <class A>
bool BST<A> :: Search(A value)
{
    return Search(root, value);
}
