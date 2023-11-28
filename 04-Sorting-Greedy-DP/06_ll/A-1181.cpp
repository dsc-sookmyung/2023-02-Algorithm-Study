#include <iostream>
using namespace std;

struct word {
    char letter[51];
    int length;
};

bool operator < (word& a, word& b) {
    if (a.length == b.length) {
        int index = 0;
        while (a.letter[index] == b.letter[index]) {
            index++;
            if (index == a.length) return false;
        }
        return a.letter[index] < b.letter[index];
    }
    else {
        return a.length < b.length;
    }
}

bool operator == (word& a, word& b) {
    if (a.length == b.length) {
        int index = 0;
        while (a.letter[index] == b.letter[index]) {
            index++;
            if (index == a.length) return true;
        }
    }
    return false;
}

template <typename T>
void swap(T arr[], int a, int b) {
    T temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

template<typename T>
void heapify(T arr[], int index) {
    if (index == 0) return;
    if (arr[(index - 1) / 2] < arr[index]) {
        swap(arr, (index - 1) / 2, index);
        heapify(arr, (index - 1) / 2);
    }
}

template <typename T>
void heap_sort(T arr[], int index) {
    if (index == 0) return;
    int a = 0, b = 1;
    swap(arr, a, index);
    while (b < index) {
        if (b + 1 < index && arr[b] < arr[b + 1]) b = b + 1;
        if (arr[a] < arr[b]) {
            swap(arr, a, b);
            a = b;
            b = 2 * b + 1;
        }
        else {
            break;
        }
    }
    heap_sort(arr, index - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    word arr[20000];
    int length = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].letter;
        while (arr[i].letter[length] != '\0') length++;
        arr[i].length = length;
        length = 0;

        heapify(arr, i);
    }

    heap_sort(arr, N - 1);

    for (int i = 0; i < N; i++) {
        if (i != 0 && arr[i] == arr[i - 1]) {}
        else {
            cout << arr[i].letter << '\n';
        }
    }

    return 0;
}