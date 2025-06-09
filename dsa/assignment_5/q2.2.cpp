#include<bits/stdc++.h>
#define maxnum 10000000000
using namespace std;

typedef pair<int,int> intpair;

void dijkstra(vector<intpair> graph[] , long long int* distance , int* shorest_found , int* prev_vertex , int* normal){
    priority_queue<intpair,vector<intpair>,greater<intpair>> heap;
    int top_of_heap,vertex,length;
    int d;
    heap.push({0,0});
    while(!heap.empty()){
        // while(shorest_found[heap.top().second]==1&&!heap.empty()){
        //     heap.pop();
        // }
        top_of_heap = heap.top().second;
        d = heap.top().first;
        // cout << top_of_heap << endl;
        heap.pop();
        // if(shorest_found[top_of_heap]==1)continue;   
        shorest_found[top_of_heap]=1;
        for(int i =0;i<graph[top_of_heap].size();i++){
            vertex = graph[top_of_heap][i].second;
            length = graph[top_of_heap][i].first;
            if(distance[top_of_heap]+length<distance[vertex]){
                // cout << "hi" << endl;
                distance[vertex]=distance[top_of_heap]+length;
                prev_vertex[vertex]= top_of_heap;
                heap.push({distance[vertex],vertex});
            }
        }
    }
    return;
}

// index is second , distance is first;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<intpair> graph[n+1];
    intpair u,v;
    int normal[n+1];
    for(int i =0;i<m;i++){
        cin >> u.second >> v.second >> u.first;
        v.first = u.first;
        u.second--;
        v.second--;
        if(u.second==0){
            normal[v.second]=1;
        }
        if(v.second==0){
            normal[u.second]=1;
        }
        graph[u.second].push_back(v);
        graph[v.second].push_back(u);
    }
    long long int distance[n+1];
    int shortest_found[n+1];
    int prev_vertex[n+1];
    for(int i =0;i<n+1;i++){
        shortest_found[i]=0;
        prev_vertex[i]=i;
        distance[i]= maxnum;
    }
    distance[0]=0;
    long long int l[k],p[k];
    for(int i =0;i<k;i++){
        cin >> l[i] >> p[i];
        u.second = --l[i];
        u.first = p[i];
        v.second = 0;
        v.first = u.first;
        graph[u.second].push_back(v);
        graph[v.second].push_back(u);
    }
    // distance[1]=0;
    // cout << "till here" << endl;
    dijkstra(graph,distance,shortest_found,prev_vertex,normal);
    int ans=0;
    // for(int i =0;i<n+1;i++){
    //     cout << i << ":" << distance[i] << ":" << prev_vertex[i] << endl;
    // }
    for(int i =0;i<k;i++){
        if(distance[l[i]]<p[i]) ans++;
        else if(distance[l[i]]==p[i]){
            if(prev_vertex[l[i]]==0){
                if(normal[l[i]]!=1){
                    ans++;
                }
            }
        }
        // cout << l[i] << endl;
    }
    cout << ans << endl;

    return 0;
}