#include "hashtable.h"

int main() {
	QuadraticHashing *qh = new QuadraticHashing(1);
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

	delete qh;
 }