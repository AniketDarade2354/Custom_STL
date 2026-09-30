#include <iostream>
#include "Custom_STL.h"

using namespace std;

int main()
{
    SinglyLL<int> sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    
    sobj.Display();

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    
    sobj.Display();

    sobj.InsertAtPos(91, 4);

    sobj.Display();

    sobj.DeleteAtPos(4);

    sobj.Display();

    int iRet = sobj.Count();

    cout << iRet << endl;

    ///////////////////////////

    SinglyCL<int> sobj1;

    sobj1.InsertFirst(51);
    sobj1.InsertFirst(21);
    sobj1.InsertFirst(11);
    
    sobj1.Display();

    sobj1.InsertLast(101);
    sobj1.InsertLast(111);
    sobj1.InsertLast(121);
    
    sobj1.Display();

    sobj1.InsertAtPos(91, 4);

    sobj1.Display();

    sobj1.DeleteAtPos(4);

    sobj1.Display();

    iRet = sobj1.Count();

    cout << iRet << endl;

    /////////////////////////////

    DoublyLL<int> dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    
    dobj.Display();

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    
    dobj.Display();

    dobj.InsertAtPos(91, 4);

    dobj.Display();

    dobj.DeleteAtPos(4);

    dobj.Display();

    iRet = dobj.Count();


    cout << iRet << endl;

    /////////////////////////////

    DoublyCL<int> dobj1;

    dobj1.InsertFirst(51);
    dobj1.InsertFirst(21);
    dobj1.InsertFirst(11);
    
    dobj1.Display();

    dobj1.InsertLast(101);
    dobj1.InsertLast(111);
    dobj1.InsertLast(121);
    
    dobj1.Display();

    dobj1.InsertAtPos(91, 4);

    dobj1.Display();

    dobj1.DeleteAtPos(4);

    dobj1.Display();

    iRet = dobj1.Count();


    cout << iRet << endl;
 
    return 0;
}