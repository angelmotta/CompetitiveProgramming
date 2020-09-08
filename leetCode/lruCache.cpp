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
        key = 'a';
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

    void updatePositionNode(Node* node){
        Node* ptrPrevNode = node->prev;
        if(node == dll->tail){
            ptrPrevNode->next = nullptr;
            dll->tail = ptrPrevNode;
        }
        else { // adelante hay nodo
            ptrPrevNode->next = node->next;
            node->next->prev = ptrPrevNode;
        }
        // Update head
        node->next = dll->head;
        node->prev = nullptr;
        dll->head->prev = node;
        dll->head = node;
    }

    int get(int key) {
        std::cout << "** getValueFromKey '" << key <<"' **\n";
        if(mapCache.find(key) != mapCache.end()){    // if we have the element requested
            std::cout << "(Key found: Update Cache Structure)\n";
            int valResult = mapCache[key]->value;
            // Update Cache structure if node is distinct to head
            Node* node = mapCache[key];
            if(node != dll->head){
                updatePositionNode(node);
            }
            return valResult;
        }
        return -1;
    }

    void put(int key, int value) {
        std::cout << "** insertKeyValuePair: (" << key << ":" << value << ") ** \n";
        if(mapCache.find(key) != mapCache.end()){   // Update existing key
            std::cout << "Existing Key: Updating value and position\n";
            Node* node = mapCache[key];
            node->value = value;
            // Update position
            if(node != dll->head){
                updatePositionNode(node);
            }
        }
        else{ // Add new node
            std::cout << "New Key, Trying to add node (" << key << ":" << value << ")\n";
            Node* node = new Node(key, value);
            if(currentSize == maxSize){
                std::cout << "Full Capacity: First, We need delete the least recently used\n";
                // Delete tail node to have space and Update Map
                // Delete tail entry from map
                auto itKey = mapCache.find(dll->tail->key);
                mapCache.erase(itKey);
                // delete least used and free the memory
                Node* ptrTailPrev = dll->tail->prev;
                delete dll->tail;
                dll->tail = ptrTailPrev;
                if(dll->tail){
                    dll->tail->next = nullptr;
                }
                else {
                    dll->head = nullptr;
                }
                currentSize--;
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
