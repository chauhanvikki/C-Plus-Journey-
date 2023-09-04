#include <iostream>
#include <vector>

using namespace std;

void findIntersection(int* arr1, int size1, int* arr2, int size2, int& sizeIntersection, int* intersection) {
    vector<int> commonIds;

    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            commonIds.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    sizeIntersection = commonIds.size();

    if (sizeIntersection == 0) {
        cout << "No common IDs found." << endl;
    } else {
        for (int i = 0; i < sizeIntersection; ++i) {
            intersection[i] = commonIds[i];
        }
    }
}

int main() {
    int size1, size2;
    cin >> size1;
    int arr1[size1];

    for (int i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }

    cin >> size2;
    int arr2[size2];

    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    int sizeIntersection;
    int intersection[max(size1, size2)]; // Assuming the maximum possible size

    findIntersection(arr1, size1, arr2, size2, sizeIntersection, intersection);

    if (sizeIntersection > 0) {
        for (int i = 0; i < sizeIntersection; ++i) {
            cout << intersection[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
