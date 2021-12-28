// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____

#include "liststack.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
    if (empty(p)) return nullptr;
    Node* curr = p;
    while (curr != nullptr) {
        Node* zap = curr;
        curr = curr->next;
        delete zap;
    }
    cout << "\n\tCleared...\n";
    return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
    if (empty(p)) return 0;
    int count = 0;
    while (p != nullptr){
        count += 1;
        p = p -> next;
    }
    return count;
}


// sets the min and max values that are passed as references in the list
void minmax(pNode p, int& min, int& max) {
    if (empty(p)) {
        min = max = 0;
        return;
    }
    min = p -> data;
    max = p-> data;
    while(p!= nullptr){
        
        if(max < p -> data){
            max = p ->data;
        }
        if(min > p -> data){
            min = p ->data;
        }
        p = p -> next;

    }
    /*do{
        p = p -> next;
        if(max < p -> data){
            max = p ->data;
        }
        if(min > p -> data){
            min = p ->data;
        }
    }
    while (p -> next != nullptr);*/

    return;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
    return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by N.
pNode push(pNode p, int val, int N) {
    DPRINT(cout << ">push val=" << val << " N="<< N << endl;);
    pNode q = p;
    for(int i = 0; i < N; i++){
        q = new Node{val, q};
        //q -> next = p;
        val++;
        p = q;
        
    }

    DPRINT(cout << "<push size=" << size(p) << endl;);
    return p;
}

// removes N nodes in the list and returns the new first node.
// This deallocates the removed node, effectively reduces its size by N.
pNode pop(pNode p, int N) {
    DPRINT(cout << ">pop size=" << size(p) << " N="<< N << endl;);
    if (empty(p)) return nullptr;
    
    if( N > size(p)){
        Node* curr = p;
        while (curr != nullptr) {
            Node* zap = curr;
            curr = curr->next;
            delete zap;
        }
        return nullptr;
    }
    

    for(int i = 0; i < N; i++){
        p = p -> next;
    }

    DPRINT(cout << "<pop size=" << size(p) << endl;);
    return p;
}

// returns the first node in the list. This does not destroy the node.
pNode top(pNode p) {
    if (empty(p)) return nullptr;
    return p;
}

// shows the first and the last show_n items in the list if all is false.
void show(pNode p, bool all, int show_n) {
    DPRINT(cout << "show(" << size(p) << ")\n";);
    if (empty(p)) {
        cout << "\n\tThe list is empty.\n";
        return;
    }

    int i;
    pNode curr;
    const int N = size(p);
    cout << endl << "TOP ";
    if (all || N <= show_n * 2) {
        for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
            cout << "\t" << curr->data;
            if (i % show_n == 0) cout << endl;
        }
        return;
    }
    
    // print the first show_n items
    pNode y =p;
    for(int i = 0; i < show_n ; i++) {
        cout << "\t" << y -> data;
        y = y -> next;
    }
    



    cout << "\n...left out...\n";

    // print the last show_n items
    // Firstly, move the pointer to the place where show_n items are left.
    int idx = 0;
    pNode x = p;
    while(x != nullptr) {
        x = x -> next;
        idx += 1;
    }

    for(int i = 0; i < idx - show_n ; i++) {
        p = p -> next;
    }
    
    while(p != nullptr) {
        cout << "\t" << p -> data;
        p = p -> next;
    }

    cout << endl;
}
