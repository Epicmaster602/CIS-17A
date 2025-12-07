#include <iostream>
#include <string>
using namespace std;

struct MovieData {
    string title;
    string director;
    int year;
    int runtime; // minutes
};

// function prototype
void showMovie(const MovieData &m);

int main() {
    int n;
    cout << "How many movies? ";
    cin >> n;
    cin.ignore(); // clear newline

    MovieData *movies = new MovieData[n]; // dynamic array

    for (int i = 0; i < n; i++) {
        cout << endl<<"Movie #" << (i+1) << ":"<<endl;

        cout << "Title: ";
        getline(cin, movies[i].title);

        cout << "Director: ";
        getline(cin, movies[i].director);

        cout << "Year Released: ";
        cin >> movies[i].year;

        cout << "Running Time (minutes): ";
        cin >> movies[i].runtime;
        cin.ignore(); // clear newline
    }

    cout << endl<<"Movie Information"<<endl;
    for (int i = 0; i < n; i++) {
        showMovie(movies[i]);

    }

    delete[] movies;
    return 0;
}

void showMovie(const MovieData &m) {
    cout << "Title: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Year Released: " << m.year << endl;
    cout << "Running Time: " << m.runtime << " minutes"<<endl;
}
