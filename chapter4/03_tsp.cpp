#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;

struct Node{
    vector<vector<int>> mat;
    vector<int> path;
    int cost;
    int vertex;
    int level;
};

int n = 4;

vector<vector<int>> graph = {
    {INF, 10, 15, 20},
    {10, INF, 35, 25},
    {15, 35, INF, 30},
    {20, 25, 30, INF}
};


// Row reduction
int rowReduce(vector<vector<int>>& mat){
    int reduction = 0;
    for(int i = 0; i < n; i++){
        int mn = INF;
        for(int j = 0; j < n; j++)
            mn = min(mn, mat[i][j]);
        if(mn != INF && mn != 0){
            reduction += mn;
            for(int j = 0; j < n; j++){
                if(mat[i][j] != INF)
                    mat[i][j] -= mn;
            }
        }
    }
    return reduction;
}


// Column reduction
int colReduce(vector<vector<int>>& mat){
    int reduction = 0;
    for(int j = 0; j < n; j++){

        int mn = INF;

        for(int i = 0; i < n; i++)
            mn = min(mn, mat[i][j]);

        if(mn != INF && mn != 0){
            reduction += mn;
            for(int i = 0; i < n; i++){
                if(mat[i][j] != INF)
                    mat[i][j] -= mn;
            }
        }
    }
    return reduction;
}


int reduceMatrix(vector<vector<int>>& mat){
    return rowReduce(mat) + colReduce(mat);
}


struct Compare{
    bool operator()(Node* a, Node* b){
        return a->cost > b->cost;
    }
};


int main(){

    priority_queue<Node*, vector<Node*>, Compare> pq;

    Node* root = new Node;
    root->path.push_back(0);
    root->mat = graph;
    root->level = 0;
    root->vertex = 0;
    root->cost = reduceMatrix(root->mat);
    pq.push(root);
    int finalCost = INF;
    vector<int> finalPath;
    
    while(!pq.empty()){
        Node* curr = pq.top();
        pq.pop();

        // all cities visited
        if(curr->level == n - 1){
            curr->path.push_back(0);
            finalPath = curr->path;
            finalCost = curr->cost;
            break;
        }
        int i = curr->vertex;
        for(int j = 0; j < n; j++){
            if(curr->mat[i][j] != INF){
                Node* child = new Node;
                child->mat = curr->mat;

                // set row INF
                for(int k = 0; k < n; k++)
                    child->mat[i][k] = INF;

                // set column INF
                for(int k = 0; k < n; k++)
                    child->mat[k][j] = INF;

                // avoid returning early
                child->mat[j][0] = INF;
                child->path = curr->path;
                child->path.push_back(j);
                child->level = curr->level + 1;
                child->vertex = j;
                int edgeCost = curr->mat[i][j];
                int reductionCost = reduceMatrix(child->mat);
                child->cost = curr->cost + edgeCost + reductionCost;
                pq.push(child);
            }
        }
    }

    cout << "Minimum Cost = " << finalCost << "\n";

    cout << "Path: ";
    for(int x : finalPath)
        cout << x << " ";

}