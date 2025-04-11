// kurs_algorithm.cpp : Первый вариант.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct dot {
    int x;
    int y;
};
struct rect {
    dot first;
    dot second;
    dot third;
    dot fourth;
};


static void print_rect(vector<rect> rects) {
    cout << "-----------------------------------" << endl;
    cout << "Прямоугольник номер 1" << endl;
    for (int i = 0; i < rects.size(); i++) {
        cout << "(" << rects[i].third.x << "," << rects[i].third.y << ")" << "          " << "(" << rects[i].fourth.x << "," << rects[i].fourth.y << ")" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "(" << rects[i].first.x << "," << rects[i].first.y << ")" << "          " << "(" << rects[i].second.x << "," << rects[i].second.y << ")" << endl;
        cout << "-----------------------------------" << endl;
        if (i != rects.size()-1) { cout << "Прямоугольник номер " << i + 2 << endl; }
    }
}


static vector<dot> init() {
    vector<dot> dotts;
    int counter = 1;
    bool flag = false;
    string input;
    dot d;
    while (!flag) {
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (!(((int)input[i] >= 48 && (int)input[i] <= 57) || (int)input[i] == 45)) {
                flag = true;
            }
        }

        if(!flag && counter % 2 == 0){
            d.y = stoi(input);
            dotts.push_back(d);
            counter += 1;
        }
        else if (!flag) {
            counter += 1;
            d.x = stoi(input);
        }
        
    }
    return dotts;
}


static vector<dot> sort_x(vector<dot> sorted) {
    vector<dot> result;
    for (int j = 0; j < sorted.size();) {
        int smallest = sorted[0].x;
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].x < smallest) { smallest = sorted[i].x; } 
        }
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].x == smallest) { smallest = i; break; }
        }
        result.push_back(sorted[smallest]);
        sorted.erase(sorted.begin() + smallest);
    }
    return result;
}

static vector<dot> sort_y(vector<dot> sorted) {
    vector<dot> result;
    for (int j = 0; j < sorted.size();) {
        int smallest = sorted[0].y;
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].y < smallest) { smallest = sorted[i].y; }
        }
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].y == smallest) { smallest = i; }
        }
        result.push_back(sorted[smallest]);
        sorted.erase(sorted.begin() + smallest);
    }
    return result;
}

static vector<rect> search(vector<dot> bsearch) {
    vector<int> width;
    dot temp_d;
    dot poss_d;
    rect final_rect;
    vector<dot> temp_search = bsearch;
    vector<dot> possible;
    vector<rect> result;
    rect temp_r;
    for (int i = 0; i < bsearch.size()-1; i++) {
        width.clear();
        possible.clear();
        temp_d = bsearch[i];
        temp_search.erase(temp_search.begin());
        for (int j = 0; j < temp_search.size(); j++) {
            if (temp_d.y == temp_search[j].y) { width.push_back(abs(temp_d.x - temp_search[j].x)); }

        }

        for (int count = 0; count < width.size(); count++) {
            for (int j = 0; j < temp_search.size(); j++) {
                if (temp_d.x == temp_search[j].x) {
                    poss_d.x = temp_d.x + width[count];
                    poss_d.y = temp_search[j].y;
                    possible.push_back(poss_d);
                }
            }
        }
        for (int j = 0; j < possible.size(); j++) {
            for (int o = 0; o < temp_search.size(); o++) {
                if ((possible[j].x == temp_search[o].x) && (possible[j].y == temp_search[o].y)) {
                        final_rect.first = temp_d;
                        final_rect.second.y = temp_d.y;
                        final_rect.second.x = possible[j].x;
                        final_rect.third.x = temp_d.x;
                        final_rect.third.y = possible[j].y;
                        final_rect.fourth = possible[j];
                        result.push_back(final_rect);
                }
            }
        }
        
    }
    return result;
}


int main()
{   
    setlocale(0, "");
    vector<dot> dots;
    vector<rect> rects;
    dots = init();
    dots = sort_x(dots);
    rects = search(dots);
    print_rect(rects);
}
