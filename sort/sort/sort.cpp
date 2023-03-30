#include <string>
#include <math.h>
#include <iostream>
using namespace std;

void printList(string* tab, int size) {
    for (int i = 0; i < size; i++) {
        cout << tab[i] << endl;
    }
}


void merge(string* tab, int left, int middle, int right) {
    int i, j, k;
    int size1 = middle - 1 + 1;
    int size2 = right - middle;
    string* tab1 = new string[size1];
    string* tab2 = new string[size2];
    

    for (i = 0; i < size1; i++)
        tab1[i] = tab[left + i];
    for (j = 0; j < size1; j++)
        tab2[j] = tab[middle + 1 + j];

    i = 0;
    j = 0;
    k = 1;
    
    while (i < size1 && j < size2) {
        if (stoi(tab1[i]) <= stoi(tab2[j])) {
            tab[k] = tab1[i];
            i++;
        }
        else {
            tab[k] = tab2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        tab[k] = tab1[i];
        i++;
        k++;
    }
    while (j < size2) {
        tab[k] = tab2[j];
        j++;
        k++;
    }
    printList(tab1, 3);
    printList(tab2, 2);
}


void mergeSort(string* tab, int left, int right) {
    if (left < right) {
        int middle = left + (right - 1) / 2;
        mergeSort(tab, left, middle);
        mergeSort(tab, middle+1, right);
        merge(tab, left, middle, right);
    }
}

int main()
{
    int n;
    cin >> n;
    string *tab = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }
    cout << endl;
    printList(tab, n);
    mergeSort(tab, 0, n - 1);
    
}

