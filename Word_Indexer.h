#pragma once

#include <iostream>
#include <vector>

using namespace std;

// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------

class Word_Indexer
{
public:
	vector<string> results;

	void replace_letter(string word, string letters, vector<string>* results);
	void add_letter(string word, string letters, vector<string>* results);
	void remove_letter(string word, vector<string>* results);
	void swap_letter(string word, vector<string>* results);
	void print(vector<string> results);
};

