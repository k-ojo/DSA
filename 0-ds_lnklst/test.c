#include "lnklst.h"

int main(void)
{
    // Write C code here
    node *head = NULL;
    node *h2 = NULL;

    //populate list
    _linsert(&head, 25);
    _linsert(&head, 80);
    _lappend(head, 60);
    _lappend(head, 83);
    _lappend(head, 58);
    _linsertn(&head, 85, 5);
    _lprintlist(head);
    //_ldeleten(&head, 1);

    head = _lreversed(head);
    printf("Break :%p\n", head);
    //_lrprint(head);
    //
    _lprintlist(head);

    _lfreelist(head);
    return 0;
}