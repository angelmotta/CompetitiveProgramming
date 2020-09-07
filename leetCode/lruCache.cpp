#include <iostream>
#include <map>
#include <unordered_map>

class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    // Constructor
    Node() {
        prev = nullptr;
        next = nullptr;
        key = -1;
        value = -1;
    }

    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;     // most recently used
    Node* tail;     // least recently used
    // Default Constructor
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push_front(Node* node){
        if(head){
            Node* cpHead = head;
            head->prev = node;
            head = node;
            node->next = cpHead;
        }
        else {  // if does not exist head
            head = node;
            tail = node;
        }
    }

    void print(){
        std::cout << "** Printing Doubly Linked List **\n";
        Node* temp = head;
        while(temp){
            if(temp->next){
                std::cout << "( " << temp->key << ": " << temp->value << " ) <--> ";
            }
            else{
                std::cout << "( " << temp->key << ": " << temp->value << " ) --> ";
            }
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void printReverse(){
        std::cout << "** Printing in 'Reverse' the Doubly Linked List **\n";
        Node* temp = tail;
        std::cout << "Tail...";
        while(temp){
            if(temp->prev){
                std::cout << "( " << temp->key << ": " << temp->value << " ) <--> ";
            }
            else{
                std::cout << "( " << temp->key << ": " << temp->value << " ) ";
            }
            temp = temp->prev;
        }
        std::cout << "...Head\n";
    }
};

class LRUCache {
public:
    int currentSize;
    int maxSize;
    std::unordered_map<int, Node*> mapCache;
    DoublyLinkedList* dll;

    // Constructor
    LRUCache(int capacity) {
        currentSize = 0;
        maxSize = capacity;
        dll = new DoublyLinkedList();
    }

    int getMostRecentKey(){
        std::cout << "** getMostRecentKey: ** ";
        return dll->head->key;
    }

    int get(int key) {
        std::cout << "** get '" << key <<"' **\n";
        if(mapCache.find(key) != mapCache.end()){    // if we have the element requested
            std::cout << "(Key found: Update Cache Structure)\n";
            int valResult = mapCache[key]->value;
            // Update Node from given key in Cache Structure
            Node* node = mapCache[key];
            // Update structure if node is distinct to head
            // Move Node one position to the left because is recently used
            if(node != dll->head){
                // if node is located as second node in the dll update Head
                if(node->prev == dll->head){
                    std::cout << "(Case 1: node is located as second node)\n";
                    bool isRequiredUpdateTail = (node == dll->tail);    // ** Statement required to Fix Bug
                    Node* ptrHead = dll->head;
                    Node* ptrNextNode = node->next;
                    dll->head = node;
                    node->prev = nullptr;
                    node->next = ptrHead;
                    ptrHead->prev = node;
                    ptrHead->next = ptrNextNode;
                    if(ptrNextNode){        // If statement needed to fix bug (2 nodes)
                        ptrNextNode->prev = ptrHead;
                    }
                    if(isRequiredUpdateTail){
                        std::cout << "Update Tail Required\n";
                        dll->tail = ptrHead;
                    }
                }
                else{ // if node is located as third or higher in the dll
                    std::cout << "(Case 2: node is located as third node or higher)\n";
                    bool isRequiredUpdateTail = (node == dll->tail);
                    Node* ptrPrevNode = node->prev;
                    Node* ptrNextNode = node->next;
                    Node* ptrPrevPrevNode = node->prev->prev;
                    ptrPrevPrevNode->next = node;
                    node->prev = ptrPrevPrevNode;
                    node->next = ptrPrevNode;
                    ptrPrevNode->prev = node;
                    ptrPrevNode->next = ptrNextNode;
                    if(isRequiredUpdateTail){
                        std::cout << "Update Tail Required\n";
                        dll->tail = ptrPrevNode;
                    }
                    else {
                        std::cout << "Update Next - No Tail Required\n";
                        ptrNextNode->prev = ptrPrevNode;
                    }
                }
            }
            // Finally return result
            return valResult;
        }
        return -1;
    }

    void put(int key, int value) {
        std::cout << "** put: (" << key << ":" << value << ") ** \n";
        if(mapCache.find(key) != mapCache.end()){   // Update existing key
            std::cout << "Existing Key: Updating value\n";
            Node* node = mapCache[key];
            node->value = value;
        }
        else{ // Add new node
            std::cout << "New Key, Trying to add node (" << key << ":" << value << ")\n";
            Node* node = new Node(key, value);
            if(currentSize == maxSize){
                std::cout << "Full Capacity: First, We need delete the least recently used\n";
                if(dll->head == dll->tail){   // case 1: we have capacity = 1 
                    std::cout << "case 1: we have capacity = 1 \n";
                    auto itKey = mapCache.find(dll->tail->key);
                    mapCache.erase(itKey);
                    delete dll->tail;
                    dll->head = nullptr;
                    dll->tail = nullptr;
                    currentSize--;
                }
                else { // case 2: we have capacity >= 2
                    std::cout << "case 2: we have capacity >= 2 \n";
                    // Delete tail node to have space and Update Map
                    Node* copyTailPrev = dll->tail->prev;
                    // update map
                    auto itKey = mapCache.find(dll->tail->key);
                    mapCache.erase(itKey);
                    // delete least used and free the memory
                    delete dll->tail;
                    dll->tail = copyTailPrev;
                    dll->tail->next = nullptr;
                    currentSize--;   
                }
            }
            std::cout << "Adding new key-value inside node " << key << ":" << value << "\n";
            dll->push_front(node);
            mapCache[key] = node;
            currentSize++;
        }
    }

    void print(){
        std::cout << "** Printing map **\n";
        for(auto element : mapCache){
            std::cout << element.first << ": " << element.second->value << ", ";
        }
        std::cout << "\n";
    }

    void explainAnalyze(){
        std::cout << "** Check internal Structure **\n";
        print();
        dll->print();
        dll->printReverse();
        std::cout << "** --------------- **\n";
    }
};

int main() {
    // Test using 2 objects
    // LRUCache lruCacheObj(2);
    // lruCacheObj.put(1, 1);
    // lruCacheObj.put(2, 2);
    // //lruCacheObj.explainAnalyze();
    // //std::cout << lruCacheObj.getMostRecentKey() << "\n";   
    // std::cout << lruCacheObj.get(1) << "\n";   // Return 1 
    // lruCacheObj.explainAnalyze();
    // std::cout << lruCacheObj.getMostRecentKey() << "\n"; 
    // lruCacheObj.put(3, 3);     // cache maxSize reached; evicts key 2
    // lruCacheObj.explainAnalyze();
    // std::cout << lruCacheObj.get(2) << "\n";   // return -1; 'b' was evicted in the previous operation
    // lruCacheObj.explainAnalyze();
    // lruCacheObj.put(4, 4); // evicts key 1
    // lruCacheObj.explainAnalyze();
    // std::cout << lruCacheObj.get(1) << "\n"; // returns -1 (not found)
    // std::cout << lruCacheObj.get(3) << "\n";   // Return 3
    // std::cout << lruCacheObj.get(4) << "\n";   // Return 4
    
    // Leet test - 1 object
    /*
    LRUCache lruCacheObj(1);
    lruCacheObj.put(2,1);
    //lruCacheObj.explainAnalyze();
    std::cout << lruCacheObj.get(2) << "\n";
    //lruCacheObj.explainAnalyze();
    lruCacheObj.put(3,2);
    //lruCacheObj.explainAnalyze();
    std::cout << lruCacheObj.get(2) << "\n";
    //lruCacheObj.explainAnalyze();
    std::cout << lruCacheObj.get(3) << "\n";
    //lruCacheObj.explainAnalyze();
    */

    LRUCache LRUCacheObj(2);
    LRUCacheObj.put(2,1);
    LRUCacheObj.explainAnalyze();
    LRUCacheObj.put(1,1);
    LRUCacheObj.explainAnalyze();
    LRUCacheObj.put(2,3);   // Update ok
    LRUCacheObj.explainAnalyze();
    LRUCacheObj.put(4,1);
    LRUCacheObj.explainAnalyze();
    std::cout << LRUCacheObj.get(1) << "\n";
    LRUCacheObj.explainAnalyze();
    std::cout << LRUCacheObj.get(2) << "\n";
    LRUCacheObj.explainAnalyze();
    return 0;
}
