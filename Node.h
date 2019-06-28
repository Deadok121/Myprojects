#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

class Node {
private:
    Node *next;
    float value;
public:
    float getValue() {
        return value;
    };

    void setValue(int value) {
        this->value = value;
    }

    Node* getNextNode() {
        return next;
    }

    void setNextNode(Node *node) {
        next = node;
    }
};

class Queue {
private:
    Node *firstNode = nullptr;
    int lenght = 0;
public:
    int getLenght() {
        return lenght;
    }

    void incrementLenght() { lenght++; }

    void decrementLenght() { lenght--; }

    void addNode(float value);

    float pop();

    void display();

    Node *getFirstNode() {
        return firstNode;
    }

    void *setFirstNode(Node *node) { firstNode = node; }

    Queue getCopy();
};

class HarmonicQueue : public Queue {
public:
    float findHarmonicMean();
};

void printOptions();

Queue merge(Queue first,Queue second);

#endif //QUEUE_QUEUE_H
