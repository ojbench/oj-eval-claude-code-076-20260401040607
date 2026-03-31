#ifndef MYLIST_HPP
#define MYLIST_HPP

#include <iostream>

template<typename ValueType>
class MyList
{
private:
    struct Node {
        ValueType data;
        Node* next;
        Node* prev;
        Node(const ValueType& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int list_size;

public:
    MyList() : head(nullptr), tail(nullptr), list_size(0) {}

    MyList(MyList &&obj) noexcept : head(obj.head), tail(obj.tail), list_size(obj.list_size)
    {
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.list_size = 0;
    }

    MyList(const MyList &obj) : head(nullptr), tail(nullptr), list_size(0)
    {
        Node* current = obj.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    MyList& operator=(const MyList &obj)
    {
        if (this != &obj) {
            clear();
            Node* current = obj.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    MyList& operator=(MyList &&obj) noexcept
    {
        if (this != &obj) {
            clear();
            head = obj.head;
            tail = obj.tail;
            list_size = obj.list_size;
            obj.head = nullptr;
            obj.tail = nullptr;
            obj.list_size = 0;
        }
        return *this;
    }

    ~MyList()
    {
        clear();
    }

    void push_back(const ValueType &value)
    {
        Node* new_node = new Node(value);
        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        list_size++;
    }

    void pop_back()
    {
        if (tail == nullptr) return;

        Node* old_tail = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete old_tail;
        list_size--;
    }

    void push_front(const ValueType &value)
    {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        list_size++;
    }

    void pop_front()
    {
        if (head == nullptr) return;

        Node* old_head = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete old_head;
        list_size--;
    }

    ValueType &front() const
    {
        return head->data;
    }

    ValueType &back() const
    {
        return tail->data;
    }

    void insert(int index, const ValueType &value)
    {
        if (index <= 0) {
            push_front(value);
            return;
        }
        if (index >= list_size) {
            push_back(value);
            return;
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        Node* new_node = new Node(value);
        new_node->prev = current->prev;
        new_node->next = current;
        if (current->prev) {
            current->prev->next = new_node;
        }
        current->prev = new_node;
        list_size++;
    }

    void erase(int index)
    {
        if (index < 0 || index >= list_size) return;

        if (index == 0) {
            pop_front();
            return;
        }
        if (index == list_size - 1) {
            pop_back();
            return;
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        delete current;
        list_size--;
    }

    int size() const
    {
        return list_size;
    }

    bool empty() const
    {
        return list_size == 0;
    }

    void clear()
    {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
        tail = nullptr;
        list_size = 0;
    }

    void link(const MyList &obj)
    {
        if (obj.empty()) return;

        Node* current = obj.head;
        while (current != nullptr) {
            Node* new_node = new Node(current->data);
            if (tail == nullptr) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
            list_size++;
            current = current->next;
        }
    }

    MyList cut(int index)
    {
        MyList result;

        if (index <= 0) {
            result.head = head;
            result.tail = tail;
            result.list_size = list_size;
            head = tail = nullptr;
            list_size = 0;
            return result;
        }

        if (index >= list_size) {
            return result;
        }

        Node* cut_point = head;
        for (int i = 0; i < index; i++) {
            cut_point = cut_point->next;
        }

        result.head = cut_point;
        result.tail = tail;
        result.list_size = list_size - index;

        tail = cut_point->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        cut_point->prev = nullptr;
        list_size = index;

        return result;
    }

    void print() const
    {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif // MYLIST_HPP
