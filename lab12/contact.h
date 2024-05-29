#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


enum class TipContact {
    Acquaintance, Friend, Colleague
};

class Contact {
private:
    std::string name;
public:
    Contact(const std::string& name) : name(name) {};
    virtual ~Contact() {}

    std::string getNume() const {
        return name;
    }
    virtual TipContact getTipContact() const = 0;
};

class Friend : public Contact {
private:
    std::string data_nastere;
    std::string tel_number;
    std::string adresa;
public:
    Friend(const std::string& name, const std::string& data_nastere, const std::string& tel_number, const std::string& adresa) : Contact(name), data_nastere(data_nastere), tel_number(tel_number), adresa(adresa) {};
    TipContact getTipContact() const override {
        return TipContact::Friend;
    }
    std::string getDataNasterii() const { 
        return data_nastere; 
    }
    std::string getTelNumber() const { 
        return tel_number; 
    }
    std::string getAdresa() const { 
        return adresa; 
    }
};

class Acquaintance : public Contact {
private:
    std::string tel_number;
public:
    Acquaintance(const std::string& name, const std::string& tel_number) : Contact(name), tel_number(tel_number) {};
    TipContact getTipContact() const override { 
        return TipContact::Acquaintance; 
    }
    std::string getTelNumber() const { 
        return tel_number; 
    }
};

class Colleague : public Contact {
private:
    std::string tel_number;
    std::string company;
    std::string adresa;
public:
    Colleague(const std::string& name, const std::string& tel_number, const std::string& company, const std::string& adresa) : Contact(name), tel_number(tel_number), company(company), adresa(adresa) {};
    TipContact getTipContact() const override { 
        return TipContact::Colleague; 
    }
    std::string getTelNumber() const{ 
        return tel_number; 
    }
    std::string getCompany() const { 
        return company; 
    }
    std::string getAdresa() const { 
        return adresa; 
    }
};

class AddressBook {
private:
    std::vector<Contact*> contacts;

public:
    AddressBook() {}

    ~AddressBook() {
        for (Contact* contact : contacts) {
            if (contact) {
                delete contact;
            }
        }
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    Contact* findByName(const std::string& name) const {
        for (Contact* contact : contacts) {
            if (contact->getNume() == name) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<Friend*> getFriends() const {
        std::vector<Friend*> friends;
        for (Contact* contact : contacts) {
            if (contact->getTipContact() == TipContact::Friend) {
                friends.push_back(static_cast<Friend*>(contact));
            }
        }
        return friends;
    }

    void deleteContactByName(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); it++) {
            if ((*it)->getNume() == name) {
                delete* it;
                *it = nullptr; 
                contacts.erase(it);
                break;
            }
        }
    }
};
