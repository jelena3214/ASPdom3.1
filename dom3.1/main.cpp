#include "hashtable.h"

int main() {
	HashTable ht(10, 2, 2, 1);
	Student s1(20190727, "Nikola", "Rakonjac");
	s1 += "13S111PP2";
	s1 += "19S51YP2";
	ht.insertKey(s1);
	cout << ht <<endl;
	cout << *ht.findKey(20190727);
	//ht.deleteKey(20190727);
	ht.clear();
	if(ht.findKey(20190727))cout << *ht.findKey(20190727);
	cout << ht.keyCount(); 
 }