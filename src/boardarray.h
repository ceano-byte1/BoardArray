#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            int pos = 0;
            for (pos = 0; pos < index; pos++) {
                if (entry->compare(&array[pos])) {
                    break;
                }
            }

            if (index == SIZE && pos == SIZE) {
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
            }

            int lastIndex;
            if (index < SIZE) {
                lastIndex = index;
            } else {
                lastIndex = SIZE - 1;
            }

            for (int i = lastIndex - 1; i >= pos; i--) {
                array[i + 1] = array[i];
            }

            array[pos] = *entry;

            if (index < SIZE) {
                index++;
            }

        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
                return;
            }
        }
};
