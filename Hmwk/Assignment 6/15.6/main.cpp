#include <iostream>
using namespace std;

class GradedActivity {
protected:
    double score;

public:
    GradedActivity() { score = 0; }
    GradedActivity(double s) { score = s; }

    void setScore(double s) { score = s; }
    double getScore() { return score; }

    char getGrade() {
        if (score >= 90) return 'A';
        if (score >= 80) return 'B';
        if (score >= 70) return 'C';
        if (score >= 60) return 'D';
        return 'F';
    }
};

// Essay Class

class Essay : public GradedActivity {
private:
    double gram;   // Grammar (0–30)
    double spel;   // Spelling (0–20)
    double len;    // Correct length (0–20)
    double cont;   // Content (0–30)

public:
    Essay() : GradedActivity() {
        gram = spel = len = cont = 0;
    }

    Essay(double g, double s, double l, double c) {
        setEssay(g, s, l, c);
    }

    void setEssay(double g, double s, double l, double c) {
        gram = g;
        spel = s;
        len = l;
        cont = c;

        score = gram + spel + len + cont;
    }

    double getGram() { return gram; }
    double getSpel() { return spel; }
    double getLen() { return len; }
    double getCont() { return cont; }
};



int main() {
    double g, s, l, c;

    cout << "Grammar (0-30): ";
    cin >> g;

    cout << "Spelling (0-20): ";
    cin >> s;

    cout << "Length (0-20): ";
    cin >> l;

    cout << "Content (0-30): ";
    cin >> c;

    Essay e(g, s, l, c);

    cout << "\nTotal Score: " << e.getScore() << endl;
    cout << "Grade: " << e.getGrade() << endl;

    return 0;
}
