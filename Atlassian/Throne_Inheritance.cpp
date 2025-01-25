//Throne Inheritance

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> map;
    unordered_set<string> dead;
    string nameOfKing;
    
    ThroneInheritance(string kingName) {
        nameOfKing= kingName;
    }
    
    void birth(string par, string child) {
        map[par].push_back(child);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    
    void helper(string par, vector<string> &ans){
        if(dead.count(par)==0) ans.push_back(par);
        for(auto child:map[par]) helper(child, ans);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        helper(nameOfKing, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

/*
 * Definition:
 * The problem simulates a royal family tree where members can be born or die,
 * and we need to maintain an accurate order of inheritance based on these events.
 *
 * Approach:
 * - Use an unordered map to represent parent-child relationships in the family tree.
 * - Use an unordered set to keep track of deceased members.
 * - Implement a depth-first search (DFS) approach to construct the inheritance order,
 *   skipping any deceased members during traversal.
 *
 * Complexity:
 * - Time Complexity: O(N), where N is the total number of members in the family tree. 
 *   Each member is processed once during DFS traversal.
 * - Space Complexity: O(N), used for storing the family tree structure and tracking 
 *   deceased members.
 */
