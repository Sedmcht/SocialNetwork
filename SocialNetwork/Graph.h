#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Graph
{
public:

    void addPesron(string name);
    void addFriendships(string friend1, string friend2);
    void printFriends();

private:
    int getPersonId(string name);
    void walker(bool* visited, int handshakes, int id, bool* pairs);


    vector<string> names;
    vector<vector<int>> persons;

};

