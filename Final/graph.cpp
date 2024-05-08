#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;

class DSU { 
	int* parent; 
	int* rank; 

public: 
	DSU(int n) 
	{ 
		parent = new int[n]; 
		rank = new int[n]; 

		for (int i = 0; i < n; i++) { 
			parent[i] = -1; 
			rank[i] = 1; 
		} 
	} 

	// Find function 
	int find(int i) 
	{ 
		if (parent[i] == -1) 
            cout<<i<<"\n";
			return i; 

		return parent[i] = find(parent[i]); 
	}

	// Union function 
	void unite(int x, int y) 
	{ 
		int s1 = find(x); 
		int s2 = find(y); 

		if (s1 != s2) { 
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
			}
			else if (rank[s1] > rank[s2]) { 
				parent[s2] = s1; 
			}
			else { 
				parent[s2] = s1; 
				rank[s1] += 1; 
			} 
		} 
	} 
}; 

template<typename T>
class graph{
    public:
    unordered_map<T, set<pair<T, int>>> adj;
    set<T> node;
    vector<pair<T, T>> edges;
    vector<vector<T>> edgeList;

    void addEdge(T u, T v, int w){
        adj[u].insert(make_pair(v, w));
        adj[v].insert(make_pair(u, w));
        edges.push_back(make_pair(u, v));
        node.insert(u);
        node.insert(v);
    }

    void display(){
        for(auto i: node){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto j: edges){
            cout<<"("<<j.first<<", "<<j.second<<")"<<" ";
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<" : \n";
            for(auto j: i.second){
            cout<<i.first<<" -> "<<j.first<<" : "<<j.second<<" "<<endl;
            }
            cout<<endl;
        }
    }

    void bfs(T node,map<T, bool> &visited, vector<T> &ans){
        queue<T> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()){
            T front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto j: adj[front]){
                if(!visited[j.first]){
                    q.push(j.first);
                    visited[j.first] = 1;
                }
            }
        }
    }

    vector<T> BFS(){
        map<T, bool> visited;
        for(auto i: visited){
            cout<<i.first<<" "<<i.second<<" ";
        }
        vector<T> ans;

        for(auto i:adj){
            if(!visited[i.first]){
                bfs(i.first, visited, ans);
            }
        }
        return ans;
    }

    void dfs(T node,map<T, bool> &visited, vector<T> &ans){
        stack<T> st;
        st.push(node);
        visited[node] = 1;

        while(!st.empty()){
            T top = st.top();
            st.pop();
            ans.push_back(top);

            for(auto j: adj[top]){
                if(!visited[j.first]){
                    st.push(j.first);
                    visited[j.first] = 1;
                    break;
                }
            }
        }
    }

    vector<T> DFS(){
        map<T, bool> visited;
        vector<T> ans;
        for(auto i:adj){
            if(!visited[i.first]){
                dfs(i.first, visited, ans);
            }
        }
        return ans;
    }

void kruskals_mst() 
	{ 
		// Sort all edges 
		sort(edgelist.begin(), edgelist.end()); 

		// Initialize the DSU 
		DSU s(V); 
		int ans = 0; 
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl; 
		for (auto edge : edgelist) { 
			int w = edge[0]; 
			int x = edge[1]; 
			int y = edge[2]; 

			// Take this edge in MST if it does 
			// not forms a cycle 
			if (s.find(x) != s.find(y)) { 
				s.unite(x, y); 
				ans += w; 
				cout << x << " -- " << y << " == " << w 
					<< endl; 
			} 
		} 
		cout << "Minimum Cost Spanning Tree: " << ans; 
	} 

};

int main(){
    graph<string> air;

    int ncity;
    int nEdge;

    air.addEdge("Pune", "Mumbai", 4);
    air.addEdge("Pune", "Banglore", 8);
    air.addEdge("Banglore", "Mumbai", 8);
    air.addEdge("Banglore", "Delhi", 9);
    air.addEdge("Delhi", "Mumbai", 7);
    cout<<endl;

    cout<<"\nBFS : \n";
    vector<string> bfs = air.BFS();
    for(auto i: bfs){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"\nDFS : \n";
    vector<string> dfs = air.DFS();
    for(auto i: dfs){
        cout<<i<<" ";
    }
    cout<<endl;

    air.printAdjList();

    cout<<"\nDisplay";
    air.display();
    cout<<endl;

    // vector<pair<pair<string, string>, int>> answer;
    // answer = air.kruskals_mst();

    // for(auto i: answer){
    //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<" "<<endl;
    // }
    return 0;
}