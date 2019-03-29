//
// Created by Roman Oborin on 2019-03-26.
//

#include <iostream>
#include "Node.h"

using namespace std;

int main() {
    HarmonicQueue queue;
    printOptions();
    int choice;
    do {
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                float value;
                cout << "Value : " << endl;
                cin >> value;
                queue.addNode(value);
                break;
            case 2:
                queue.pop();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "\nHarmonic mean : " << queue.findHarmonicMean() << endl;
                break;
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    cin.get();
    return 0;
}
