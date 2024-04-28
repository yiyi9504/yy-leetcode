#include "../src/Array/1146.hh"

int main() {
    int length = 1;
    SnapshotArray* obj = new SnapshotArray(length);
    obj->set(0, 15);
    cout << obj->snap() << ' ';
    cout << obj->snap() << ' ';
    cout << obj->snap() << ' ';
    cout << obj->get(0, 2) << ' ';
    cout << obj->snap() << ' ';
    cout << obj->snap() << ' ';
    cout << obj->get(0, 0) << ' ';
    return 0;  
}