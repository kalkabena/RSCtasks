#include <array>
#include <iostream>
#include <string>
using namespace std;

class contact {
    private:
    string name;
    string address;
    string email;
    int phone;
    int fax;
    public:
    contact() {};
    contact(string u, string w, string x, int y, int z) {
        name = u;
        address = w;
        email = x;
        phone = y;
        fax = z;
    };
    void setName(string n) {
        name = n;
    };
    string getName() {
        return name;
    }
    void setAddress(string n) {
        address = n;
    };
    string getAddress() {
        return address;
    }
    void setEmail(string n) {
        email = n;
    };
    string getEmail() {
        return email;
    }
    void setPhone(int n) {
        phone = n;
    };
    int getPhone() {
        return phone;
    }
    void setFax(int n) {
        fax = n;
    };
    int getFax() {
        return fax;
    }
};

class phoneBook {
    private:
    array<contact, 8> contacts;
    int id;
    public:
    phoneBook(array<contact, 8> cts) {
        contacts = cts;
        id = 0;
    }
    void add(string name, string address, string email, int phone, int fax) {
        if (id <= 7) {
            contacts[id] = contact(name, address, email, phone, fax);
            id++;
        } else {
            for (int i = 0; i < 7; i++) {
                contacts[i] = contacts[i + 1];
            };
            contacts[7] = contact(name, address, email, phone, fax);
        };
    };
    void disp() {
        for (int i = 0; i < 8; i++) {
            cout << i + 1 << ") " << contacts[i].getName() << endl;
        }
    };
    void search(string n) {
        int flag = 0;
        for (int i = 0; i < 8; i++) {
            if (n == contacts[i].getName()) {
                flag = 1;
                cout << "\nName   : " << contacts[i].getName() << endl;
                cout << "Address: " << contacts[i].getAddress() << endl;
                cout << "Email  : " << contacts[i].getEmail() << endl;
                cout << "Phone  : " << contacts[i].getPhone() << endl;
                cout << "Fax    : " << contacts[i].getFax() << endl;
            }
        }
        if (flag == 0) {
            cout << "Person not found\n";
        }
    }
    void replace(string n) {
        int flag = 0;
        for (int i = 0; i < 8; i++) {
            if (n == contacts[i].getName()) {
                flag = 1;
                string nm, dd, ml;
                int ph, fx;
                cout << "New Name   : ";
                cin >> nm;
                cout << "New Address: ";
                cin >> dd;
                cout << "New Email  : ";
                cin >> ml;
                cout << "New Phone  : ";
                cin >> ph;
                cout << "New Fax    : ";
                cin >> fx;
                contacts[i] = contact(nm, dd, ml, ph, fx);
                break;
            }
        }
        if (flag == 0) {
            cout << "Person not found\n";
        };
    };
    ~phoneBook() {
        cout << "Phonebook is kil";
    }
};

int main()
{
    array<contact, 8> cts;
    phoneBook pb(cts);
    string in, nm, ml, dd;
    int ph, fx;
    while (true) {
        cout << "\nEnter: ";
        cin >> in;
        if (in == "add") {
            cout << "Name   : ";
            cin >> nm;
            cout << "Address: ";
            cin >> dd;
            cout << "Email  : ";
            cin >> ml;
            cout << "Phone  : ";
            cin >> ph;
            cout << "Fax    : ";
            cin >> fx;
            pb.add(nm, dd, ml, ph, fx);
        } else if (in == "search") {
            pb.disp();
            cout << "Look up: ";
            cin >> in;
            pb.search(in);
        } else if (in == "replace") {
            pb.disp();
            cout << "Replace: ";
            cin >> in;
            pb.replace(in);
        } else if (in == "exit") {
            break;
        }
    };
    return 0;
}
