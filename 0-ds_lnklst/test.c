#include "lnklst.h"

int main(void)
{
    // Write C code here
    node *head = NULL;
    node *h2 = NULL;

    //populate list
    _insert(&head, 25);
    _insert(&head, 80);
    _append(head, 60);
    _append(head, 83);
    _append(head, 58);
    _insertn(&head, 85, 5);
    _printlist(head);
    //_deleten(&head, 1);

    head = _reversed(head);
    printf("Break :%p\n", head);
    //_rprint(head);
    //
    _printlist(head);

    _freelist(head);
    return 0;
}