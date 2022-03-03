// CPP_Word_Letter_Indexer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<string> dictionary = {"fire", "truck", "car", "cat", "hat", "rat", "dog", "cut", "meter", "centimeter", "kilometer", "elbow", "try", "finger", "but", "hole", "goat", "jacket", "giant", "if", "only", "I", "had", "a", "jumping", "ahead", "praise", "Elden", "Ring"}; 
string new_word;
chrono::milliseconds duration;

void replace_letter(string word, string letters, vector<string>* results)
{
	string word_copy;

	int letters_index = 0;
	char current_letter;

	for (size_t i = 0; i < letters.size(); i += 1)
	{
		current_letter = letters[i];
		int index = 0;

		for (size_t i = 0; i < word.size(); i += 1)
		{
			word_copy = word;
			word_copy.erase(i, 1);
			word_copy.insert(i, 1, current_letter);
			results->push_back(word_copy);

			index += 1;
		}
	}
	//int letters_index = 0;
	//char current_letter;
	//char current_word_letter;

	//for (int i = 0; i < letters.size(); i += 1)
	//{
	//	current_letter = letters[i];

	//	int index = 0;

	//	for (int it = 0; it < word.size(); it += 1)
	//	{
	//		current_word_letter = word[index];
	//		word[index] = current_letter;
	//		results->push_back(word);

	//		word[index] = current_word_letter;

	//		index += 1;
	//	}
	//}
}

void add_letter(string word, string letters, vector<string>* results)
{
	string word_copy;

	int letters_index = 0;
	char current_letter;

	for (size_t i = 0; i < letters.size(); i += 1)
	{
		current_letter = letters[i];
		int index = 0;

		for (size_t i = 0; i < word.size() + 1; i += 1)
		{
			word_copy = word;
			word_copy.insert(i, 1, current_letter);
			results->push_back(word_copy);

			index += 1;
		}
	}
}

void remove_letter(string word, vector<string>* results)
{
	string word_copy;

	for (size_t i = 0; i < word.size(); i += 1)
	{
		word_copy = word;
		word_copy.erase(i, 1);
		results->push_back(word_copy);
	}
}

void swap_letter(string word, vector<string>* results)
{
	string word_copy;

	for (size_t i = 0; i < word.size() - 1; i += 1)
	{
		word_copy = word;
		swap(word_copy[i], word_copy[i + 1]);
		results->push_back(word_copy);
	}
}

void process_word(string word, string characters, vector<string>* results) 
{
	swap_letter(word, results);
	replace_letter(word, characters, results);
	remove_letter(word, results);
	add_letter(word, characters, results);
}

void squared(string word, string letters, vector<string>* candidates)
{
	auto start = chrono::high_resolution_clock::now();

	process_word(word, letters, candidates);
	int count = candidates->size();
	for (int i = 0; i < count; i += 1) 
	{
		process_word(candidates->at(i), letters, candidates);
		
		for (int x = 0; x < dictionary.size(); x += 1)
		{
			if (dictionary[x] == candidates->at(i))
			{
				new_word = dictionary[x];
			}
		}
	}

	auto stop = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "new word: " << new_word << " ... " << "milliseconds: " << duration.count() << endl;
}

void print(vector<string> results)
{
	for (auto it = results.begin(); it != results.end(); it += 1)
	{
		cout << *it << endl;
	}
}
