#include "dblnklst.h"

int main(void)
{
    dnode *head = NULL;

    _dinsert(&head, 45);
    _dinsert(&head, 56);
    _dinsert(&head, 9);
    _dinsert(&head, 78);
 

    _dprintls(head);
    head = _dreversed(head);
    _dprintls(head);
    _dfreels(head);

    return (0);
}