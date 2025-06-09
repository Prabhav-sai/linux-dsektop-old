#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int> graph[] , int* visited_array,int element){
    // if(visited_array[element]==1) return ;
    visited_array[element]=1;
    for(int j =0;j<graph[element].size();j++){
            // cout << graph[element][j] << " ";
            if(visited_array[graph[element][j]]==0){
                dfs(graph,visited_array,graph[element][j]);
            }
        }
    return ;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> graph[n+1];
    int u,v;
    for(int i =0;i<m;i++){
        cin >> u >> v;
        // cout << u << v;
        // u;
        // v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int visited_array[n+1];
    for(int i =0;i<n+1;i++){
        visited_array[i]=0;
    }
    int ans=0;
    int ans_array[n+1];
    for(int i =1;i<n+1;i++){
        if(visited_array[i]==0){
            ans_array[ans]=i;
            ans++;
            dfs(graph,visited_array,i);
        }
    }
    cout << ans-1 << endl;
    for(int i =0;i+1<ans;i++){
        cout << ans_array[i] << " " << ans_array[i+1] << endl;
        // printf("%d",visited_array[i]);
    }
    // for(int i =1;i<n+1;i++){
    //     cout << i<< ": ";
    //     for(int j =0;j<graph[i].size();j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

