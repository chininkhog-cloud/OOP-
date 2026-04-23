#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int size = 5;

    //Create list of 5 words (char**)
    char **list = new char*[size];

    const char *words[] = {"alpha", "bravo", "charlie", "delta", "echo"};

    //Allocate memory for each word
    for (int i = 0; i < size; i++) {
        list[i] = new char[strlen(words[i]) + 1];
        strcpy(list[i], words[i]);
    }

    //Print original list
    cout << "[Original List]" << endl;
    for (int i = 0; i < size; i++) {
        cout << list[i] << endl;
    }

    // Search for "delta"
    cout << "\n[Search Result]" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], "delta") == 0) {
            cout << "Found 'delta' at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Word not found" << endl;
    }

    //Modify index 1 ("bravo" → "blueberry")
    delete[] list[1]; // free old memory
    list[1] = new char[strlen("blueberry") + 1];
    strcpy(list[1], "blueberry");

    cout << "\n[After Modification]" << endl;
    for (int i = 0; i < size; i++) {
        cout << list[i] << endl;
    }

    //Delete "charlie"
    int deleteIndex = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], "charlie") == 0) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex != -1) {
        delete[] list[deleteIndex]; 

        for (int i = deleteIndex; i < size - 1; i++) {
            list[i] = list[i + 1];
        }

        size--; 
    }

    cout << "\n[After Deletion]" << endl;
    for (int i = 0; i < size; i++) {
        cout << list[i] << endl;
    }

    // Free all remaining memory
    for (int i = 0; i < size; i++) {
        delete[] list[i];
    }
    delete[] list;

    return 0;
}