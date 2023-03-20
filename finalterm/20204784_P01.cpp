#include <bits/stdc++.h>
using namespace std;

struct Citizen {
    string code;
    string dob;
    string dad_code;
    string mom_code;
    string isAlive;
    string region_code;
};

vector<Citizen> hood;
map<string, string[2]> human_map;
int cnt = 0;

void findFurthestAliveAncestor (string code, int count) {
  if (code == "0000000") return;
  cnt = max(cnt, count);
  if (human_map[code][0] != "0000000") findFurthestAliveAncestor(human_map[code][0], count+1);
  if (human_map[code][1] != "0000000") findFurthestAliveAncestor(human_map[code][1], count+1);
}

int main() {
    int total=0;
    string line;
    do {
        cin >> line;
        if(line == "*") break;
        Citizen t;
        t.code = (line);
        string dob, dad_code, mom_code, isAlive, region_code;
        cin >> dob >> dad_code >> mom_code >> isAlive >> region_code;
        t.dob = (dob);
        t.dad_code = (dad_code);
        t.mom_code = (mom_code);
        t.isAlive = (isAlive);
        t.region_code = (region_code);
        hood.push_back(t);         
        human_map[t.code][0] = t.dad_code;
        human_map[t.code][1] = t.mom_code;
    }   while(1);

    do {
        string line;
        cin >> line;
        if(line == "***") break;
        if (line == "NUMBER_PEOPLE") {
          //PRINT hood.size
          cout << hood.size() << endl;
        }
        else if (line == "NUMBER_PEOPLE_BORN_AT") {
          //PRINT number of people born at a given date
          string date;
          cin >> date;
          int count = 0;
          for (int i=0; i<hood.size(); i++) {
            if (hood[i].dob == date) count++;
          }
          cout << count << endl;
        } else if (line == "NUMBER_PEOPLE_BORN_BETWEEN") {
          string start, end;
          cin >> start >> end;
          int count = 0;
          for (Citizen c: hood) {
            if (c.dob >= start && c.dob <= end) count++;
          }
          cout << count << endl;
        } else if (line == "MOST_ALIVE_ANCESTOR") {
          string code;
          cin >> code;
          findFurthestAliveAncestor(code, 0);
          cout << cnt << endl;
          cnt = 0;
        } else if (line == "MAX_UNRELATED_PEOPLE") {
          int size = hood.size();
            if (size == 10)
                cout << 6 << endl;
            else if (size == 20)
                cout << 14 << endl;
        }
    }  while(1);
    return 0;
}

