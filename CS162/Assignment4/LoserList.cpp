#include "LoserList.hpp"
#include <iostream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;

void LoserList::add(Creature *c, string t, string n)
{
    // if the list is empty, the added creature is the head.
    if (!head)
        head = new LoserNode(c, t, n);

    // otherwise add the creature to the top of the list.
    else
    {
        LoserNode *tempNode;
        tempNode = new LoserNode(c, t, n);

        tempNode->next = head;
        head = tempNode;
    }
}

void LoserList::printList()
{
    if (!head)
        cout << "There are currently no active Creatures." << endl;
    else
    {
        LoserNode *readNode;
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

void LoserList::moveNext()
{
    if (head->next == NULL)
        return;
    else
    {
        LoserNode *searchNode, *tempNode;
        tempNode = head;
        head = tempNode->next;
        tempNode->next = NULL;

        searchNode = head;
        while (searchNode->next != NULL)
            searchNode = searchNode->next;
        searchNode->next = tempNode;
    }
}
