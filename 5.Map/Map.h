#include <vector>
#include <iostream>

using namespace std;

template <typename Key, typename Value>
class Map {
private:
    struct Node {
        Key key;
        Value value;
        Node* next;

        Node(const Key& k, const Value& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;

public:
    Map() : head(nullptr) {}

    Map(const Map& other) : head(nullptr) {
        Node* otherCurrent = other.head;
        while (otherCurrent != nullptr) {
            add(otherCurrent->key, otherCurrent->value);
            otherCurrent = otherCurrent->next;
        }
    }

    ~Map() {
        clear();
    }

    void add(const Key& key, const Value& value) {
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    Value* find(const Key& key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return &(current->value);
            }
            current = current->next;  
        }
        return nullptr; 
    }


    void remove(const Key& key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        }
    }

  
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    friend ostream& operator<<(ostream& os, const Map& map) {
        Node* current = map.head;
        while (current != nullptr) {
            os << current->key << "\n" << current->value << std::endl;
            current = current->next;
        }
        return os;
    }

    Map& operator=(const Map& other) {
        if (this != &other) {
            clear();
            Node* otherCurrent = other.head;
            while (otherCurrent != nullptr) {
                add(otherCurrent->key, otherCurrent->value);
                otherCurrent = otherCurrent->next;
            }
        }
        return *this;
    }
    
   
};
