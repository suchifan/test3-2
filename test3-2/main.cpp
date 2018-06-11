//
//  main.cpp
//  test3-2
//
//  Created by suchao on 6/11/18.
//  Copyright © 2018 cs.nju. All rights reserved.
//

#include <iostream>




#include <iostream>
using namespace std;

struct Node
{
    int content;
    Node *next;
};

Node* del(Node *p);
void c(Node *p);

int main(int argc, const char * argv[]) {
    
    cout << "input:" << endl;
    Node *head = NULL;
    Node *p;
    p = new Node;
    int a;
    cin >> a;
    while (a != -1)
    {
        p->content = a;
        p->next = head;
        head = p;
        cin >> a;
        
        // here！
        p = new Node;
    }
    
    c(head);
    cout << endl;
    
    head = del(head);
    c(head);
    
    return 0;
}
Node* del(Node *p)
{
    
    if (p)
    {
        Node *current = p->next, *previous = p;
        while (current != NULL)
        {
            if (current->content == previous->content)
            {
                
                previous->next = current->next;
                free(current);
                current = previous->next;
                
            }
            else{
                current = current->next;
                previous = previous->next;
            }
        }
    }
    return p;
}

void c(Node *p)
{
    while (p)
    {
        cout << p->content;
        p = p->next;
    }
}
