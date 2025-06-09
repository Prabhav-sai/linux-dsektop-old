#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct node{
    int value;
    int length;
}node;

void dfs(vector<node> graph[] , long long int* visited_array,int element){
    queue<int> que;
    que.push(element);
    long long int temp,visit;
    while(!que.empty()){
        temp = que.front();
        que.pop();
        for(int j =0;j<graph[temp].size();j++){
            visit = graph[temp][j].value;
            // cout << visited_array[temp]+graph[temp][j].length << " ";
            if(visited_array[visit]==0&&visit!=1){
                que.push(visit);
                visited_array[visit]=visited_array[temp]+graph[temp][j].length;
            }
            else{
                if(visited_array[visit]>visited_array[temp]+graph[temp][j].length){
                    visited_array[visit]=visited_array[temp]+graph[temp][j].length;
                }
            }
        }
    }
    return ;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<node> graph[n+1];
    node u,v;
    for(int i =0;i<m;i++){
        cin >> u.value >> v.value >> u.length;
        v.length = u.length;
        // cout << u << v;
        // u;
        // v;
        graph[u.value].push_back(v);
        graph[v.value].push_back(u);
    }
    long long int l[k],p[k];
    for(int i =0;i<k;i++){
        cin >> l[i] >> p[i];
    }
    long long int visited_array[n+1];
    for(int i =0;i<n+1;i++){
        visited_array[i]=0;
    }
    dfs(graph,visited_array,1);
    long long int ans=0;
    for(int i=0;i<k;i++){
        if(visited_array[l[i]]<=p[i]) ans++;
    }
    // for(int i =1;i<n+1;i++){
    //     cout << i << ":" << visited_array[i] << " ";
    // }
    cout << ans << endl;
    // for(int i =1;i<n+1;i++){
    //     cout << i<< ": ";
    //     for(int j =0;j<graph[i].size();j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}