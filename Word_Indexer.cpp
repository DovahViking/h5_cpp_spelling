#include "Word_Indexer.h"

// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------
// ------------------------ THIS FILE IS NOT BEING USED AT ALL ------------------------

void Word_Indexer::replace_letter(string word, string letters, vector<string>* results)
{
	int letters_index = 0;
	char current_letter;
	char current_word_letter;

	for (int i = 0; i < letters.size(); i += 1)
	{
		current_letter = letters[i];

		int index = 0;

		for (int it = 0; it < word.size(); it += 1)
		{
			current_word_letter = word[index];
			word[index] = current_letter;
			results->push_back(word);

			word[index] = current_word_letter;

			index += 1;
		}
	}
}

void Word_Indexer::add_letter(string word, string letters, vector<string>* results)
{
	string word_copy;

	int letters_index = 0;
	char current_letter;

	for (int i = 0; i < letters.size(); i += 1)
	{
		current_letter = letters[i];
		int index = 0;

		for (int i = 0; i < word.size(); i += 1)
		{
			word_copy = word;
			word_copy.insert(i, 1, current_letter);
			results->push_back(word_copy);

			index += 1;
		}
	}
}

void Word_Indexer::remove_letter(string word, vector<string>* results)
{
	string word_copy;

	for (int i = 0; i < word.size(); i += 1)
	{
		word_copy = word;
		word_copy.erase(i, 1);
		results->push_back(word_copy);
	}
}

void Word_Indexer::swap_letter(string word, vector<string>* results)
{
	string word_copy;

	for (int i = 0; i < word.size(); i += 1)
	{
		word_copy = word;
		swap(word_copy[i], word_copy[i + 1]);
		results->push_back(word_copy);
	}
}

void Word_Indexer::print(vector<string> results)
{
	for (auto it = results.begin(); it != results.end(); it += 1)
	{
		cout << *it << endl;
	}
}