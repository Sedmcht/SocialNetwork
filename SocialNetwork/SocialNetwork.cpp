#include "Graph.h"

int main()
{
    Graph MyGraph;

    MyGraph.addPesron("Oleg");
    MyGraph.addPesron("Nikita");
    MyGraph.addPesron("Nastia");
    MyGraph.addPesron("Vanya");
    MyGraph.addPesron("Jenya");

    
   
    MyGraph.addFriendships("Oleg", "Nikita");
    MyGraph.addFriendships("Nikita", "Nastia");
    MyGraph.addFriendships("Nastia", "Vanya");
    MyGraph.addFriendships("Vanya", "Jenya");
    


    MyGraph.printFriends();
}

