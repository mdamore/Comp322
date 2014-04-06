//
//  wikiFinalStudent.cpp
//  322Assignment4
//
//  Created by Marco d'Amore on 4/5/14.
//  Copyright (c) 2014 Marco d'Amore. All rights reserved.
//

#include "wikiFinal.h"
#include <cstdlib>


Graph::Edge Graph::sampleEdge(list<Edge> lst) const{
    // random int between 0 and (total weight - 1)
    int totalWeight = 0;
    for(auto it = lst.begin(); it!=lst.end(); it++) {
        totalWeight += it->weight;
    }
    
    int random = rand();
    while(random > totalWeight-1) {
        random = rand();
    }

    vector<int> cumul;
    cumul.resize(lst.size());
    cumul[0] = lst.begin()->weight;
    auto it = lst.begin();
    it++;
    
    for(int i = 1; i < cumul.size(); i++,it++) {
        cumul[i] = cumul[i-1] + it->weight;
    }
    it = lst.begin();
    
    for(int k = 0; k < lst.size(); k++, it++) {
        try {
            if(it->weight <= 0)
                throw; //*****
        } catch (int e) {
            cout << "Edge with invalid weight detected" << endl;
        }
        if((cumul[k-1] < random) && (cumul[k] >= random))
            return Graph::Edge {it->origin, it->destination, it->weight};
    }
    return Graph::Edge {NULL, NULL, NULL};
}

map<int,int> Graph::random_walks(int start_node) const{
    map<int,int> toReturn;
    try {
        if(start_node > adj_list.size() - 1)
            throw; //******
        for(int i = 0; i < adj_list.size() - 1; i ++) {
            toReturn[i] = 0;
        }
        int currentNode = start_node;
        
        for (int i = 0; i < get_num_walks(); i++) {
            for(int k = 0; k < get_walk_length(); k++) {
                toReturn[currentNode]++;
                currentNode = sampleEdge(adj_list[currentNode]).destination;
            }
        }
    }
    return toReturn;
}


list<int> Graph::breadth_first_search(int start_node, int number_nodes) const{
    
}




