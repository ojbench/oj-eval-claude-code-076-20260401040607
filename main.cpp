#include <iostream>
#include <string>
#include "src.hpp"
using namespace std;

int main()
{
    int n;
    cin >> n;

    MyList<int> lists[105];

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "new") {
            int id;
            cin >> id;
            lists[id] = MyList<int>();
        }
        else if (cmd == "push_back") {
            int id, value;
            cin >> id >> value;
            lists[id].push_back(value);
        }
        else if (cmd == "pop_back") {
            int id;
            cin >> id;
            lists[id].pop_back();
        }
        else if (cmd == "push_front") {
            int id, value;
            cin >> id >> value;
            lists[id].push_front(value);
        }
        else if (cmd == "pop_front") {
            int id;
            cin >> id;
            lists[id].pop_front();
        }
        else if (cmd == "insert") {
            int id, index, value;
            cin >> id >> index >> value;
            lists[id].insert(index, value);
        }
        else if (cmd == "erase") {
            int id, index;
            cin >> id >> index;
            lists[id].erase(index);
        }
        else if (cmd == "size") {
            int id;
            cin >> id;
            cout << lists[id].size() << endl;
        }
        else if (cmd == "empty") {
            int id;
            cin >> id;
            cout << (lists[id].empty() ? 1 : 0) << endl;
        }
        else if (cmd == "clear") {
            int id;
            cin >> id;
            lists[id].clear();
        }
        else if (cmd == "link") {
            int id1, id2;
            cin >> id1 >> id2;
            lists[id1].link(lists[id2]);
        }
        else if (cmd == "cut") {
            int id1, index, id2;
            cin >> id1 >> index >> id2;
            lists[id2] = lists[id1].cut(index);
        }
        else if (cmd == "print") {
            int id;
            cin >> id;
            if (lists[id].empty()) {
                cout << endl;
            } else {
                lists[id].print();
            }
        }
        else if (cmd == "front") {
            int id;
            cin >> id;
            cout << lists[id].front() << endl;
        }
        else if (cmd == "back") {
            int id;
            cin >> id;
            cout << lists[id].back() << endl;
        }
    }

    return 0;
}
