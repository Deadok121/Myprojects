//
// Created by Roman Oborin on 2019-03-26.
//

#include <iostream>
#include "../Node.h"

using namespace std;

void printOptions() {
    cout << "1) Push element to queue" << endl;
    cout << "2) Pop element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Find harmonic mean" << endl;
    cout << "5) Exit" << endl;
};


Queue merge(Queue first, Queue second) {
    Queue result;
    result = first.getCopy();
    Queue secondCopy = second.getCopy();
    Node *iterator = result.getFirstNode();
    while (iterator->getNextNode() != nullptr) {
        iterator = iterator->getNextNode();
    }
    iterator->setNextNode(secondCopy.getFirstNode());
    return result;
}

void Queue::addNode(float value) {
    if (getFirstNode() == nullptr) {
        Node *firstNode = new Node();
        firstNode->setValue(value);
        setFirstNode(firstNode);
        incrementLenght();
        return;
    }

    Node *oldNode = getFirstNode();
    Node *newNode = new Node();
    while (oldNode->getNextNode() != nullptr) {
        oldNode = oldNode->getNextNode();
    }
    oldNode->setNextNode(newNode);
    newNode->setValue(value);
    incrementLenght();
}

float Queue::pop() {
    if (getFirstNode() == nullptr) {
        throw invalid_argument("Queue is empty!");
    }

    Node *node = getFirstNode();
    int deletingValue;
    if (node->getNextNode() == nullptr) {
        deletingValue = node->getValue();
        cout << "Deleted : " << deletingValue << " and queue is empty!";
        delete node;
        decrementLenght();
        return deletingValue;
    }

}

void Queue::display() {
    if (getFirstNode() == nullptr) {
        cout << "Queue is empty";
        return;
    }

    Node *node = getFirstNode();
    cout << " " << node->getValue() << " ";
    while (node->getNextNode() != nullptr) {
        node = node->getNextNode();
        cout << " " << node->getValue() << " ";
    }
    cout << endl;
}

Queue Queue::getCopy() {
    if (getFirstNode() == nullptr) {
        throw invalid_argument("Queue is empty!");
    }

    Node *node = getFirstNode();
    Queue queue;
    queue.addNode(node->getValue());
    while (node->getNextNode() != nullptr) {
        node = node->getNextNode();
        queue.addNode(node->getValue());
    }
    return queue;
}

float HarmonicQueue::findHarmonicMean() {
    int count = getLenght();
    if (count == 0) {
        return 0;
    }

    float invertedSum = 0;
    Node *node = getFirstNode();
    invertedSum += 1 / node->getValue();
    while (node->getNextNode() != nullptr) {
        node = node->getNextNode();
        invertedSum += 1 / node->getValue();
    }
    return count / invertedSum;
}



