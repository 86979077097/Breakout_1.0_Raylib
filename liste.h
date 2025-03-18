#ifndef LISTE_H
#define LISTE_H

struct ListNode
{
    int val1;
    ListNode *next1;
    ListNode *next2;
};
void afisare1(ListNode*);
void afisare2(ListNode*);
ListNode* eliminare_capete(ListNode*&);
void eliminare_intermediar(ListNode*);
ListNode* creere_linie();

#endif