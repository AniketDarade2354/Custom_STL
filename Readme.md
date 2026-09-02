# Custom_STL — A Hand-Built STL-Style Data Structure Library in C++

A generic, template-based data structure library written from scratch in C++, mirroring the design philosophy of the real C++ Standard Template Library: reusable, type-agnostic containers built with templates rather than hardcoded types.

Every structure here — from node to container — was implemented manually with raw pointers, without relying on `<list>`, `<stack>`, `<queue>`, or any STL container internally.

## What's inside

| Class 	| Structure 		      | Description 						 |
|---------------|-----------------------------|----------------------------------------------------------|
| `SinglyLL<A>` | Singly Linear Linked List   | Head-only traversal, `NULL`-terminated 			 |
| `SinglyCL<A>` | Singly Circular Linked List | Tracks `first` and `last`, wraps around via `last->next` |
| `DoublyLL<B>` | Doubly Linear Linked List   | Bidirectional traversal via `next`/`prev` 		 |
| `DoublyCL<B>` | Doubly Circular Linked List | Bidirectional + circular, tracks `first` and `last` 	 |
| `BST<A>` 	| Binary Search Tree 	      | Standard BST ordering, recursive traversal and counting  |

Every container is a **template class** (`template <class A>` / `template <class B>`), so any data type — `int`, `float`, `char`, or a custom struct with `operator<`/`operator>` — works without rewriting the container.

## Design details

### Node classes
Each linked-list family shares a node type:
- `SinglyLNode<A>` — used by both `SinglyLL` and `SinglyCL`
- `DoublyLNode<B>` — used by both `DoublyLL` and `DoublyCL`
- `BSTNode<A>` — dedicated node for `BST`, with `lchild`/`rchild` pointers

### Consistent operation set across all four linked-list variants
Every linked list class (`SinglyLL`, `SinglyCL`, `DoublyLL`, `DoublyCL`) exposes the same interface:

```cpp
void Display();
int  Count();

void InsertFirst(A value);
void InsertLast(A value);
void InsertAtPos(A value, int iPos);

void DeleteFirst();
void DeleteLast();
void DeleteAtPos(int iPos);
```

Position-based operations (`InsertAtPos`, `DeleteAtPos`) use 1-based indexing and delegate to `InsertFirst`/`InsertLast`/`DeleteFirst`/`DeleteLast` at the boundaries, falling through to direct pointer manipulation for the general case.

### Circular list bookkeeping
`SinglyCL` and `DoublyCL` additionally track a `last` pointer (not just `first`), since operations at the tail need to stay O(1) and the circular wraparound (`last->next == first`, and for `DoublyCL`, `first->prev == last`) has to be maintained on every insert/delete.

### BST
`BST<A>` supports:
```cpp
void Insert(A value);
void Inorder();   // Left -> Data -> Right
void Preorder();  // Data -> Left -> Right
void Postorder(); // Left -> Right -> Data
int  Count();
int  CountLeaf();
int  CountParent();
bool Search(A value);
```
Duplicate values on `Insert` are rejected with a message rather than silently ignored or overwritten. `Count`, `CountLeaf`, and `CountParent` are implemented as pure return-based recursion (no static state), so they're safe to call repeatedly without stale results.

## Build

This is a header-only library — include it directly:

```cpp
#include "Custom_STL.h"

int main()
{
    SinglyLL<int> list;
    list.InsertLast(10);
    list.InsertLast(20);
    list.Display();

    BST<int> tree;
    tree.Insert(11);
    tree.Insert(5);
    tree.Insert(17);
    tree.Inorder();

    return 0;
}
```

```bash
g++ -std=c++11 your_file.cpp -o your_program
```

## Author

**Aniket Utreshwar Darade**
[GitHub](https://github.com/AniketDarade2354) · [LinkedIn](https://www.linkedin.com/in/aniket-u-darade/)
