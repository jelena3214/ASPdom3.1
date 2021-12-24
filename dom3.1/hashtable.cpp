#include "hashtable.h"
//ENUM
Student* HashTable::findKey(long index)
{
	int position = 0, attempt = 0, addr, secondAdr = 0;

	for (int i = 0; i < size * baket; i++) {

		addr = getAdr(index);
		if (!secondAdr  && attempt < 2)position = addr;
		else position = collisionFunction->getAdress(0, addr, attempt-1, size), secondAdr = 1;
		attempt++;
		if (keysInPlace(position) == 0)return nullptr;

		for (int j = 0; j < baket; j++) {
			if (table[position][j]->key == index)
				return table[position][j]->st;
		}
	}
	return nullptr;
}

bool HashTable::insertKey(Student& st)
{
	int position = 0, attempt = 1, addr, secondAdr = 0;
	long index = st.indeks;

	if (keyCount() == size * baket)return false;

	for (int i = 0; i < size*baket; i++) {

		addr = getAdr(index);
		if (!secondAdr && attempt < 2)position = addr;
		else position = collisionFunction->getAdress(0, addr, attempt - 1, size), secondAdr = 1;
		attempt++;

		for (int j = 0; j < baket; j++) { //za umetanje vec postojeceg kljuca
			if (table[position][j]->key == index) {
				return false;
			}
			if (table[position][j]->key == -1 || table[position][j]->key == 0) { //deleted pozicija ili prazna pozicija
				table[position][j]->st = &st;
				table[position][j]->key = st.indeks;
				return true;
			}
		}

	}
	return false;
}

bool HashTable::deleteKey(long index)
{
	int position = 0, attempt = 0, addr, secondAdr = 0;

	for (int i = 0; i < size * baket; i++) {

		addr = getAdr(index);
		if (!secondAdr && attempt < 2)position = addr;
		else position = collisionFunction->getAdress(0, addr, attempt-1, size), secondAdr = 1;
		attempt++;
		if (table[position].empty())return false;

		for (int j = 0; j < baket; j++) {
			if (table[position][j]->key == index) {
				table[position][j]->key = -1;
				table[position][j]->st = nullptr;
				return true;
			}
		}
	}
	return false;
}

void HashTable::clear()
{
	for (int i = 0; i < size; i++) { //sve ih stavlja na empty
		for (int j = 0; j < baket; j++) {
			table[i][j]->key = 0;
			table[i][j]->st = nullptr;
		}
	}
}

int HashTable::keyCount()
{
	int keys = 0;
	for (int i = 0; i < size; i++) {
		keys += keysInPlace(i);
	}
	return keys;
}

int HashTable::tableSize()
{
	return size*baket;
}

ostream& operator<<(ostream& os, const HashTable& ht)
{
	for (int i = 0; i < ht.size; i++) {
		for (int j = 0; j < ht.baket; j++) {
			if (ht.table[i][j]->key == -1) os << "DELETED" << "  ";
			else if (ht.table[i][j]->key == 0) os << "EMPTY" << "  ";
			else os << ht.table[i][j]->key << "  ";
		}
		os << endl;
	}
	return os;
}

double HashTable::fillRatio()
{
	return size / keyCount();
}

int HashTable::keysInPlace(int i)
{
	int num = 0;
	for (int s = 0; s < baket; s++) {
		if ((table[i][s]->key != -1) && (table[i][s]->key != 0))num++;
	}
	return num;
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < baket; j++) {
			delete(table[i][j]);
		}
	}
}