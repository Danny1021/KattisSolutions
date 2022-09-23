#include <bits/stdc++.h>

using namespace std;

void print(int bruh[]) {
    for (int i = 0; i < 10; i++) {
        cout << bruh[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<string> RAM;
    int registers[10];
    int count = 0;

    for (int i = 0; i < 10; i++)
        registers[i] = 0;

    string ram;

    while (cin >> ram) {
        RAM.push_back(ram);
    }
    while (RAM.size() != 1000)
        RAM.push_back("000");

    for (int i = 0; i < 1000; i++) {

        int first = stoi(RAM[i].substr(0,1));
        int second = stoi(RAM[i].substr(1,1));
        int third = stoi(RAM[i].substr(2,1));

        count++;

        if (first == 1) {
            cout << count;
            return 0;
        }

        else if (first == 2) {
            registers[second] = third;
            registers[second] %= 1000;
        }

        else if (first == 3) {
            registers[second] += third;
            registers[second] %= 1000;
        }

        else if (first == 4) {
            registers[second] *= third;
            registers[second] %= 1000;
        }

        else if (first == 5) {
            registers[second] = registers[third];
            registers[second] %= 1000;
        }

        else if (first == 6) {
            registers[second] += registers[third];
            registers[second] %= 1000;
        }

        else if (first == 7) {
            registers[second] *= registers[third];
            registers[second] %= 1000;
        }

        else if (first == 8) {
            registers[second] = stoi(RAM[registers[third]]);
            registers[second] %= 1000;
        }

        else if (first == 9) {
            string s = to_string(registers[second]);
            while (s.length() != 3)
                s = "0" + s;
            RAM[registers[third]] = s;
        }

        else if (first == 0 && registers[third] != 0) {
            i = registers[second]-1;
        }

    }

    return 0;
}
