#include <iostream>
#include "liste.h"

void afisare1(ListNode *p)
{
    while(p)
    {
        std::cout << p->val1 << " ";
        p = p->next1;
    }
    std::cout << std::endl;
}
void afisare2(ListNode *p)
{
    while(p)
    {
        std::cout << p->val1 << " ";
        p = p->next2;
    }
    std::cout << std::endl;
}

ListNode* eliminare_capete(ListNode *&p)
{
    ListNode *q = nullptr;
    if(!p->next1 && !p->next2)q = nullptr;
    if(!p->next2)
    {
        q = p->next1;
        q->next2 = nullptr;
        delete[] p;
        
    }
    if(!p->next1)
    {
        q = p->next2;
        q->next1 = nullptr;
        delete[] p;
    
    }
    return q;
}

void eliminare_intermediar(ListNode *p)
{
    ListNode *q = p->next1;
    q->next2 = p->next2;
    p->next2->next1 = q;
}

ListNode* creere_linie()
{
    ListNode *prim = new ListNode;
    ListNode *cap = nullptr;
    prim->next1 = cap;
    cap = prim;
    prim->val1 = 0;
    for(int i = 100; i < 800; i += 100)
    {
        ListNode *p = new ListNode;//p->val = x_rect
        p->val1 = i;
        p->next1 = cap;
        cap->next2 = p;
        cap = p;
    }
    cap->next2 = nullptr;
    return prim;

}