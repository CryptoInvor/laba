// kurs_algorithm.cpp : Второй вариант.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;


struct dot {
    int x;
    int y;
};


struct triangle {
    dot first;
    dot second;
    dot third;
};


static void print_triangle(vector<triangle> triangles) {
    cout << "-----------------------------------" << endl;
    cout << "Треугольник номер 1" << endl;
    for (int i = 0; i < triangles.size(); i++) {
        cout << "(" << triangles[i].third.x << "," << triangles[i].third.y << ")" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "(" << triangles[i].first.x << "," << triangles[i].first.y << ")" << "          " << "(" << triangles[i].second.x << "," << triangles[i].second.y << ")" << endl;
        cout << "-----------------------------------" << endl;
        if (i != triangles.size() - 1) { cout << "Треугольник номер " << i + 2 << endl; }
    }
}


static vector<triangle> combine(vector<triangle> first, vector<triangle> second) {
    for (int i = 0; i < second.size(); i++) {
        first.push_back(second[i]);
    }
    return first;
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

        if (!flag && counter % 2 == 0) {
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


static vector<dot> sort_x_min(vector<dot> sorted) {
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


static vector<dot> sort_x_max(vector<dot> sorted) {
    vector<dot> result;
    for (int j = 0; j < sorted.size();) {
        int biggest = sorted[0].x;
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].x > biggest) { biggest = sorted[i].x;}
        }
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].x == biggest) { biggest = i; break; }
        }

        result.push_back(sorted[biggest]);
        sorted.erase(sorted.begin() + biggest);
    }
    return result;
}


static vector<dot> sort_y_min(vector<dot> sorted) {
    vector<dot> result;
    for (int j = 0; j < sorted.size();) {
        int smallest = sorted[0].y;
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].y < smallest) { smallest = sorted[i].y; }
        }
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i].y == smallest) { smallest = i; break; }
        }
        result.push_back(sorted[smallest]);
        sorted.erase(sorted.begin() + smallest);
    }
    return result;
}


static vector<triangle> search(vector<dot> bsearch) {
    dot temp_d;
    triangle poss_d;
    vector<dot> temp_search = bsearch;
    vector<triangle> possible;
    bool flag = false;
    for (int i = 0; i < bsearch.size(); i++) {
        temp_d = bsearch[i];
        for (int j = 0; j < temp_search.size(); j++) {
            if ((temp_d.y == temp_search[j].y) && (temp_d.x != temp_search[j].x)) {
                poss_d.first = temp_d;
                poss_d.second = temp_search[j];
                for(int p = 0; p < temp_search.size(); p++){
                    if ((temp_d.x == temp_search[p].x) && (temp_d.y != temp_search[p].y)) {
                        poss_d.third = temp_search[p];
                        possible.push_back(poss_d);
                    }
                }
            }

        }
    }
    return possible;
}


int main()
{
    setlocale(0, "");
    vector<dot> dots;
    vector<triangle> triangles_x;
    vector<triangle> triangles_y;
    dots = init();
    dots = sort_x_min(dots);
    triangles_x = search(dots);
    //dots = sort_x_max(dots);
    //triangles_y = search(dots);
    //print_triangle(combine(triangles_x,triangles_y));
    print_triangle(triangles_x);
}
