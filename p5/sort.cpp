/*
 * CSc103 Project 5: Sorting with lists
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:Neso Academy(Youtube)
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:8
 */

#include <iostream>
#include <getopt.h>
#include <string>
using namespace std;

/* doubly linked list node: */
struct Node
{
    string data;
    Node *prev;
    Node *next;
    Node (string s = "", Node * p = NULL, Node * n = NULL):data (s), prev (p), next (n)
    {
    }
};

/* doubly linked list: */
struct List
{
    Node *head;
    Node *tail;
    List():head(NULL), tail(NULL)
    {
    }
};

/* function to insert a node into a sorted doubly linked list: */
void insert(List &L, Node *np, bool unique, bool reverse)
{
    if (L.head == NULL) // empty list
    {
        L.head = np;
        L.tail = np;
    }
    else if (np->data.compare(L.head->data) <= 0) // insert at beginning
    {
        np->next = L.head;
        L.head->prev = np;
        L.head = np;
    }
    else if (np->data.compare(L.tail->data) >= 0) // insert at end
    {
        np->prev = L.tail;
        L.tail->next = np;
        L.tail = np;
    }
    else // insert in middle
    {
        Node *temp = L.head;
        while (temp != NULL)
        {
            if (np->data.compare(temp->data) < 0)
            {
                np->next = temp;
                np->prev = temp->prev;
                temp->prev->next = np;
                temp->prev = np;
                break;
            }
            temp = temp->next;
        }
    }
    
    // remove duplicates if necessary
    if (unique)
    {
        Node *temp = L.head;
        while (temp != NULL)
        {
            if (temp->next != NULL && temp->data == temp->next->data)
            {
                temp->next = temp->next->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = temp;
                }
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    
    // reverse list if necessary
    if (reverse)
    {
        Node *temp = L.head;
        L.head = L.tail;
        L.tail = temp;
        while (temp != NULL)
        {
            Node *next = temp->next;
            temp->next = temp->prev;
            temp->prev = next;
            temp = next;
        }
    }
}

/* function to print a doubly linked list: */
void print(List L, bool reverse)
{
    if (reverse) // print in reverse order
    {
        Node *temp = L.tail;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->prev;
        }
    }
    else // print in original order
    {
        Node *temp = L.head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main(int argc, char *argv[]) {
    /* define long options */
    static int unique=0, reverse=0;
    static struct option long_opts[] = {
        {"unique",   no_argument,       &unique,   'u'},
        {"reverse",  no_argument,       &reverse,  'r'},
        {0,0,0,0} // this denotes the end of our options.
    };
    /* process options */
    char c; /* holds an option */
    int opt_index = 0;
    while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 'u':
                unique = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case '?': /* this will catch unknown options. */
                return 1;
        }
    }

    /* read input and insert into list */
    string s;
    List L;
    while (getline(cin, s)) {
        Node* np = new Node(s);
        insert(L, np, unique, reverse);
    }
    print(L, reverse);

    /* TODO: process the linked list according to the command line options */
    return 0;
}
