#include <bits/stdc++.h>

using namespace std;
vector<int> v;

void insert(int data) {
    v.push_back(data);
    int index = v.size() - 1;
    int parent = index / 2;

    while (index > 1 && v[parent] < v[index]) {
        swap(v[index], v[parent]);
        index = parent;
        parent = parent / 2;
    }

}

void heapify(int i) {
    int left, right;
    left = 2 * i;
    right = 2 * i + 1;
    int maxIndex = i;
    if (left < v.size() && v[left] > v[i])
        maxIndex = left;

    if (right < v.size() && v[right] > v[maxIndex])
        maxIndex = right;

    if (maxIndex != i) {
        swap(v[i], v[maxIndex]);
        heapify(maxIndex);
    }
}

void pop() {
    int last = v.size() - 1;

    swap(v[1], v[last]);
    v.pop_back();
    heapify(1);
}

void showTop() {
    cout << v[1] << endl;
}

void levelOrder_Display() {
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout<<"\n";
}

int main()
{
    v.push_back(-1);        /*Element at Index '0' is not to be used*/

    insert(54);
    insert(45);
    insert(36);
    insert(27);
    insert(29);
    insert(18);
    insert(21);
    insert(11);
    showTop();
    levelOrder_Display();
    pop();
    showTop();
    levelOrder_Display();
    return 0;
}
