#include "CreatureList.hpp"
#include <iostream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;

void CreatureList::add(Creature *c, string t, string n)
{
    // if the list is empty, the added creature is the head.
    if (!head)
        head = new ActiveNode(c, t, n);

    // otherwise add the creature to the end of the list.
    else
    {
        ActiveNode *tempNode, *searchNode;
        tempNode = new ActiveNode(c, t, n);
        searchNode = head;

        while (searchNode->next != NULL)
            searchNode = searchNode->next;
        searchNode->next = tempNode;
    }
}

void CreatureList::remove()
{
    if (!head->next)
        head = NULL;
    else
    {
        ActiveNode *tempNode = head;
        head = head->next;
        delete tempNode;
    }
}

void CreatureList::printList()
{
    if (!head)
        cout << "There are currently no active Creatures." << endl;
    else
    {
        ActiveNode *readNode;
        readNode = head;
        int count = 1;

        do
        {
            cout << "Active creature #" << count << ": " << endl;
            cout << "\t" << readNode->name << " the " << readNode->type << "." << endl;
            count++;
            readNode = readNode->next;
        } while (readNode);
    }
}

void CreatureList::moveNext()
{
    if (head->next == NULL)
        return;
    else
    {
        ActiveNode *searchNode, *tempNode;
        tempNode = head;
        head = tempNode->next;
        tempNode->next = NULL;

        searchNode = head;
        while (searchNode->next != NULL)
            searchNode = searchNode->next;
        searchNode->next = tempNode;
    }
}
