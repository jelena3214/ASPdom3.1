#include "hashtable.h"
#include <fstream>
#include <sstream>
//PROVERI ZA USLOV INSERTOVANJA I DELETE I TO DOKLE DA IDE size*baket???
void data(HashTable *ht) {
	ifstream MyReadFile;
	MyReadFile.open("students_50.csv");
	Student* st = nullptr;
	string key, line;
	getline(MyReadFile, key);
	vector<string> elems;
	while (getline(MyReadFile, line)) {
		stringstream ss(line);
		while (ss.good()) {
			string substring;
			getline(ss, substring, ',');
			elems.push_back(substring);
		}
		st = new Student(stoi(elems[0]), elems[1], "");
		elems.erase(elems.begin() + 0);
		elems.erase(elems.begin() + 0);
		while (!elems.empty()) {
			stringstream ss(elems[0]);
			while (ss.good()) {
				string substring;
				getline(ss, substring, ' ');
				if(!substring.empty())*st += substring;
			}
			elems.erase(elems.begin() + 0);
		}
		int k = ht->keyCount();
		cout << endl << k << endl;
		ht->insertKey(*st);
	}

	MyReadFile.close();
}

int main() {

	/*QuadraticHashing* qh = new QuadraticHashing(1);
	HashTable ht(25, 2, 2, qh);

	data(&ht);
	cout << ht;*/
	HashTable* ht = nullptr;
	QuadraticHashing* qh = nullptr;
	Student* st = nullptr;
	while (true) {
		string menu = "\nUnesite neku od opcija:\n"
			"1. Kreiraj hes tabelu \n"
			"2. Kreiraj studenta \n"
			"3. Dodajte studentu predmet \n"
			"4. Ubaci studenta u hes tabelu \n"
			"5. Izbrisi studenta iz hes tabele \n"
			"6. Pronadji studenta u tabeli i ispisi ga\n"
			"7. Isprazni hes tabelu \n"
			"8. Broj kljuceva u hes tabeli \n"
			"9. Velicina hes tabele \n"
			"10. Popunjenost hes tabele \n"
			"11. Ispisi hes tabelu \n"
			"12. Dodajte odredjenom studentu iz tabele predmet \n"
			"13. Kraj programa \n";
		cout << menu;
		int choice;
		cin >> choice;

		

		if (choice == 1) {
			int velicina, baket, p, c;
			cout << "Unesite velicinu tabele \n";
			cin >> velicina;
			cout << "Unesite velicinu baketa \n ";
			cin >> baket;
			cout << "Unesite p \n ";
			cin >> p;
			cout << "Unesite c \n ";
			cin >> c;
			qh = new QuadraticHashing(c);
			ht = new HashTable(velicina, baket, p, qh);
		}
		if (choice == 2) {
			int indeks;
			string ime, prezime;
			cout << "Unesite indeks studenta \n";
			cin >> indeks;
			cout << "Unesite ime studenta\n";
			cin >> ime;
			cout << "Unesite prezime studenta \n";
			cin >> prezime;
			st = new Student(indeks, ime, prezime);
		}
		if (choice == 3) {
			cout << "Unesite sifru predmeta \n";
			string sifra;
			cin >> sifra;
			*st += sifra;
		}
		if (choice == 4) {
			if (!ht->insertKey(*st)) cout << "Student je vec u hes tabeli" << endl;
		}
		if (choice == 5) {
			cout << "Unesite indeks studenta kojeg brisete iz tabele\n";
			int indeks;
			cin >> indeks;
			if (!ht->deleteKey(indeks))cout << "Nije moguce brisanje \n";
		}
		if (choice == 6) {
			int indeks;
			cout << "Unesite indeks studenta kog trazite u tabeli\n";
			cin >> indeks;
			Student* s = ht->findKey(indeks);
			if (s != nullptr)cout << *s << endl;
			else cout << "Nema tog studenta u tabeli \n";
		}
		if (choice == 7) {
			ht->clear();
		}
		if (choice == 8) {
			cout << ht->keyCount() << endl;;
		}
		if (choice == 9) {
			cout << ht->tableSize() << endl;
		}
		if (choice == 10) {
			cout << ht->fillRatio() << endl;
		}
		if (choice == 11) {
			cout << *ht << endl;
		}
		if (choice == 12) {
			int indeks;
			cout << "Unesite indeks studenta kome zelite da dodate predmet\n";
			cin >> indeks;
			Student* s = ht->findKey(indeks);
			if (s != nullptr) {
				cout << "Unesite sifru predmeta \n";
				string sifra;
				cin >> sifra;
				*s += sifra;
			}
			else {
				cout << "Ne postoji student u tabeli\n";
			}
		}
		if (choice == 13) {
			exit(0);
		}
	}
	/*QuadraticHashing* qh = new QuadraticHashing(1);
	HashTable ht(10, 2, 2, qh);
	Student s1(402, "Nikola", "Rakonjac");
	s1 += "13S111PP2";
	s1 += "19S51YP2";
	ht.insertKey(s1);
	//cout << ht <<endl;
	//cout << *ht.findKey(402);
	//ht.deleteKey(20190727);
	//ht.clear();
	//if(ht.findKey(20190727))cout << *ht.findKey(20190727);
	Student s2(406, "Jelena", "Cvetic"), s3(410, "Anica", "Blagojevic");
	ht.insertKey(s2);
	ht.insertKey(s3);
	if (ht.findKey(410))cout << *ht.findKey(410);
	cout << ht; 

	delete qh;*/
 }