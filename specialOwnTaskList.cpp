#include <iostream>
#include <vector>

struct Node {
    Node* next;
    Node* previous;
    int data;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~DoublyLinkedList()
    {
        delete head;
        delete tail;
    }
    void add(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->previous = nullptr;
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
        }
        tail = newNode;
    }

    void insertAdd(int value, int index)
    {
        if (index < 0) {
            std::cout << "Nieprawidlowy index." << std::endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        if (index == 0) {
            newNode->next = head;
            newNode->previous = nullptr;
            if (head != nullptr)
            {
                head->previous = newNode;
            }
            head = newNode;
        } else {
            Node* current = head;
            int currentIndex = 0;
            while (current != nullptr && currentIndex < index - 1)
            {
                current = current->next;
                currentIndex++;
            }
            if (current == nullptr)
            {
                std::cout << "Nieprawidlowy index." << std::endl;
                return;
            }
            newNode->next = current->next;
            newNode->previous = current;
            if (current->next != nullptr)
            {
                current->next->previous = newNode;
            }
            current->next = newNode;
        }
    }

    int elementAt(int index)
    {
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index)
        {
            current = current->next;
            currentIndex++;
        }
        if (current == nullptr)
        {
            std::cout << "Invalid index." << std::endl;
            return -1;
        }
        return current->data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void print()
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data;
            if (current->next != nullptr)
            {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main() {
    DoublyLinkedList list;
    std::vector<int> listOfNumbers {1,2,3,4,5,6,7,8,9};
    for(int i : listOfNumbers)
    {
        list.add(i);
    }
    list.print();
    list.insertAdd(19, 1);
    list.insertAdd(40, 3);
    list.print();
    std::cout << "Indeks 1 : " << list.elementAt(1) ;
    list.clear();

    return 0;
}
