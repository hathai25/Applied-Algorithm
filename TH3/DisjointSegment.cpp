#include<bits/stdc++.h>
#include<vector>

using namespace std;

//Kiểu đoạn thẳng
typedef pair<int, int> segment;
//So sánh hai đoạn thẳng
bool compare_segment(segment seg1, segment seg2) {
    return (seg1.second == seg2.second) ? (seg1.first < seg2.first) : (seg1.second < seg2.second);
}

int main() {
    vector<segment> segment_set;
    int size, count = 1;

    cin >> size;

    for (int i = 0; i<size; i++) {
        int start, end;
        cin >> start >> end;
        segment_set.push_back(make_pair(start, end));
    }

    sort(segment_set.begin(), segment_set.end(), compare_segment);

    // for (int i = 0; i<size; i++) {
    //     cout << "(" << segment_set[i].first << ", " << segment_set[i].second << ")" << endl;
    // }
    // Nếu điểm đầu đoạn n lớn hơn điểm cuối đoạn đang xét thì có thêm kết quả
    // biến điểm cuối đoạn đang xét thành điểm cuối cho lần xét sau
    int segment1_end = segment_set[0].second;
    for (int i = 1; i<segment_set.size(); i++) {
        int current_segment_start = segment_set[i].first;
        int current_segment_end = segment_set[i].second;

        if (current_segment_start > segment1_end) {
            count++;
            segment1_end = current_segment_end;
        }
    }

    cout << count << endl;
    return 0;
}