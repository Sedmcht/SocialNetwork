#include "Graph.h"

int Graph::getPersonId(string name)
{
	for (int i = 0; i < names.size(); i++)
	{
		if (name == names[i])
			return i;
	}

	return -1;
};

void Graph::addPesron(string name)
{
	names.push_back(name);
	persons.push_back(vector<int>());
};

void Graph::addFriendships(string friend1, string friend2)
{
	int person1 = getPersonId(friend1);
	int person2 = getPersonId(friend2);

	if (person1 != -1 && person2 != -1)
	{
		persons[person1].push_back(person2);
		persons[person2].push_back(person1);
	}

};

void Graph::printFriends()
{
	bool** pairs = new bool* [names.size()];
	for (int i = 0; i < names.size(); i++)
	{
		pairs[i] = new bool[names.size()];
		for (int j = 0; j < names.size(); j++)
			pairs[i][j] = false;
	}

	for (int i = 0; i < names.size(); i++)
	{
		bool* visited = new bool[names.size()];
		for (int i = 0; i < names.size(); i++)
			visited[i] = false;

		visited[i] = true;

		int handshakes = 3;
		walker(visited, handshakes, i, pairs[i]);

		delete[] visited;
	}



	for (int i = 0; i < names.size(); i++)
		for (int j = 0; j < names.size(); j++)
			if (pairs[i][j] == true)
			{
				cout << names[i] << " - " << names[j] << endl;
				pairs[j][i] = false;
			}

	for (int i = 0; i < names.size(); i++)
		delete[] pairs[i];

	delete[] pairs;
};



void Graph::walker(bool* visited, int handshakes, int id, bool* pairs)
{
	for (auto mate : persons[id])
	{
		if (visited[mate] == false)
		{
			if (handshakes)
			{
				pairs[mate] = true;
				visited[mate] = true;
				walker(visited, handshakes - 1, mate, pairs);

			}
			else
				visited[id] = false;
		}
	}

};