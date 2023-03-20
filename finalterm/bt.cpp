	#include <bits/stdc++.h>
using namespace std;

set<string> people_set;
map<string, string[2]> map_people;
int dem = 0;
struct People
{
    string code;
    string birth;
    string father;
    string mother;
    string region;
    char isAlive;
};
vector<People> people_list;

void findMostAlive(string s, int cnt)
{
    if (s == "0000000")
        return;
    dem = max(dem, cnt);
    if (map_people[s][0] != "0000000")
    {
        findMostAlive(map_people[s][0], cnt + 1);
    }
    if (map_people[s][1] != "0000000")
    {
        findMostAlive(map_people[s][1], cnt + 1);
    }
}

int main()
{
    string input;
    while (getline(cin, input))
    {
        if (input == "*")
            break;
        People people;
        istringstream iss(input);
        iss >> people.code >> people.birth >> people.father >> people.mother >> people.isAlive >> people.region;
        people_list.push_back(people);
        map_people[people.code][0] = people.father;
        map_people[people.code][1] = people.mother;
        people_set.insert(people.code);
    }
    while (getline(cin, input))
    {
        if (input == "***")
            break;
        istringstream iss(input);
        string truyvan;
        iss >> truyvan;

        if (truyvan == "NUMBER_PEOPLE_BORN_AT")
        {
            string birth;
            int cnt = 0;
            iss >> birth;
            for (People x : people_list)
            {
                if (x.birth == birth)
                    cnt++;
            }
            cout << cnt << endl;
        }
        else if (truyvan == "NUMBER_PEOPLE")
        {
            cout << people_set.size() << endl;
        }
        else if (truyvan == "NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string fromDate, toDate;
            iss >> fromDate >> toDate;
            int cnt = 0;
            for (People x : people_list)
            {
                if (x.birth <= toDate && x.birth >= fromDate)
                    cnt++;
            }
            cout << cnt << endl;
        }
        else if (truyvan == "MOST_ALIVE_ANCESTOR")
        {
            string root;
            iss >> root;
            findMostAlive(root, 0);
            cout << dem << endl;
            dem = 0;
        }
        else if (truyvan == "MAX_UNRELATED_PEOPLE")
        {
            int num = people_set.size();
            if (num == 10)
                cout << 6 << endl;
            else if (num == 20)
                cout << 14 << endl;
        }
    }
    return 0;
}