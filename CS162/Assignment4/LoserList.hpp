#ifndef LOSERLIST_HPP
#define LOSERLIST_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;

class LoserList
{
protected:
    struct LoserNode
    {
        // Creature object, Creature type, Creature name.
        string type;
        string name;
        Creature *fighter;
        LoserNode *next;
        LoserNode(Creature *c, string t, string n, LoserNode *next1 = NULL)
        {
            fighter = c;
            type = t;
            name = n;
            next = next1;
        }
    };
    LoserNode *head;
public:
    LoserList() { head = NULL; };    // constructor

    void add(Creature *c, string t, string n);
    void remove();
    void printList();
    void moveNext();
    LoserNode* getHead() { return head; }
    Creature* getCurrent() { return head->fighter; }
    void getName() { cout << head->name << " the " << head->type; }
    string getID() { return head->name; }
    string getType() { return head->type; }
};

#endif
