#include <algorithm>
#include <vector>
#include "contact.h"

int main() {

    AddressBook agenda;

    Friend* f1 = new Friend("Abel", "06/10/2003", "0751232323", "Baltati");
    Friend* f2 = new Friend("Miruna", "07/08/2004", "0761232323", "Iasi");
    Acquaintance* a1 = new Acquaintance("MirunaAlina", "0781232323");
    Colleague* c1 = new Colleague("AbelAdm", "0741232323", "SC Mirabel SRL", "Strada Decebal, Nr. 21");

    agenda.addContact(f1);
    agenda.addContact(f2);
    agenda.addContact(a1);
    agenda.addContact(c1);

    std::cout << "Lista prieteni:\n";
    std::vector<Friend*> prieteni = agenda.getFriends();
    for (const auto& prieten : prieteni) {
        std::cout << prieten->getNume() << "\n";
    }

    std::cout << "\nCautare contact:\n";
    std::string numeCautat = "Abel";
    Contact* contactCautat = agenda.findByName(numeCautat);
    if (contactCautat) {
        std::cout << "Contact gasit: " << contactCautat->getNume() << "\n";
    }
    else {
        std::cout << "Contactul " << numeCautat << " nu a fost gasit.\n";
    }

    std::cout << "\nStergere contact:\n";
    std::string numeStergere = "Oscar";
    agenda.deleteContactByName(numeStergere);
    contactCautat = agenda.findByName(numeStergere);
    if (!contactCautat) {
        std::cout << "Contactul " << numeStergere << " a fost sters cu succes.\n";
    }
    else {
        std::cout << "Eroare la stergerea contactului " << numeStergere << ".\n";
    }

    /*for (auto contact : agenda.getFriends()) {
        delete contact;
    }
    delete c1; delete a1;*/

    return 0;
}