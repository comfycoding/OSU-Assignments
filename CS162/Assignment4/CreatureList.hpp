#ifndef CREATURELIST_HPP
#define CREATURELIST_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;

class CreatureList
{
protected:
    struct ActiveNode
    {
        // Creature object, Creature type, Creature name.
        string type;
        string name;
        Creature *fighter;
        ActiveNode *next;
        ActiveNode(Creature *c, string t, string n, ActiveNode *next1 = NULL)
        {
            fighter = c;
            type = t;
            name = n;
            next = next1;
        }
    };
    ActiveNode *head;
public:
    CreatureList() { head = NULL; };    // constructor

    void add(Creature *c, string t, string n);
    void remove();
    void printList();
    void moveNext();
    ActiveNode* getHead() { return head; }
    Creature* getCurrent() { return head->fighter; }
    void getName() { cout << head->name << " the " << head->type; }
    string getID() { return head->name; }
    string getType() { return head->type; }
};

#endif
