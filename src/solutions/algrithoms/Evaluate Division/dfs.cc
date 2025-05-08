class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<string>> routes;
        unordered_map<string, double> route_values;
        for (int i = 0; i < equations.size(); i++) {
            vector<string>& equation = equations[i];
            routes[equation[0]].push_back(equation[1]);
            routes[equation[1]].push_back(equation[0]);
            route_values[equation[0] + " = " + equation[1]] = static_cast<double>(values[i]);
            route_values[equation[1] + " = " + equation[0]] = 1.0 / values[i];
        }
        vector<double> ress;
        unordered_map<string, bool> visited;
        for (const auto& query : queries) {
            string cur = query[0], target = query[1];
            double res = 1.0;
            bool found = false;
            visited[cur] = true;
            dfs(routes, route_values, visited, cur, target, res, found, 1.0);
            visited.erase(visited.find(cur));
            cout << found << endl;
            ress.push_back(found ? res : -1.0);
        }
        return ress;
    }
    void dfs(unordered_map<string, vector<string>>& routes, unordered_map<string, double>& route_values, unordered_map<string, bool>& visited, string cur, string target, double& res, bool& found, double tmp) {
        if (routes.count(cur) == 0) {
            return;
        }
        if (cur == target) {
            res = tmp;
            found = true;
            return;
        }
        for (const auto& next : routes[cur]) {
            if (visited.count(next) == 1) {
                continue;
            }
            visited[next] = true;
            dfs(routes, route_values, visited, next, target, res, found, tmp * route_values[cur + " = " + next]);
            visited.erase(visited.find(next));
        }
    }
};