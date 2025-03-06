#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string name;
    int grade;
};

void SortDocuments(vector<Student>& matched_documents) {
    sort(matched_documents.begin(), matched_documents.end(),
        [](const Student& lhs, const Student& rhs) {
            return lhs.grade > rhs.grade;
        });
}

int main() {

    setlocale(LC_ALL, "Russian");

    vector<Student> students;

    string name;
    int grade;

    cout << "Введите имена и оценки студентов (просто нажмите 0 для завершения ввода):" << endl;

    while (true) {

        cout << "Имя: ";
        cin >> name;

        if (name == "0") break;

        cout << "Оценка: ";
        cin >> grade;

        students.push_back({ name, grade });

    }

    SortDocuments(students);

    cout << "\nРезультаты:\n";

    for (const auto& student : students) {

        cout << student.name << " получает балл равный - " << student.grade << endl;

    }

    return 0;

}

/****** Задание 3:
* 
* enum class Status {

    ACTUAL,
    EXPIRED,
    DELETED

};

struct Document {

    int id;
    Status status;
    double relevance;
    int rating;

};

void SortDocuments(vector<Document>& matched_documents) {
    sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {
            if (lhs.status != rhs.status) {
                return lhs.status < rhs.status;
            }
            if (lhs.rating != rhs.rating) {
                return lhs.rating > rhs.rating;
            }
            return lhs.relevance > rhs.relevance;
        });
}

int main() {

    vector<Document> documents = {

    {100, Status::ACTUAL, 0.5, 4},
    {101, Status::EXPIRED, 0.5, 4},
    {102, Status::ACTUAL, 1.2, 4},
    {103, Status::DELETED, 1.2, 4},
    {104, Status::ACTUAL, 0.3, 5},

    };

    SortDocuments(documents);

    for (const Document& document : documents) {

        cout << document.id << ' '
            << static_cast<int>(document.status) << ' '
            << document.relevance << ' '
            << document.rating << endl;

    }
}
*/


/****** Задание 2:
* 
* struct Document {
    int id;
    double relevance;
    int rating;
};

void SortDocuments(vector<Document>& matched_documents) {
    sort(matched_documents.begin(), matched_documents.end(),
        [](const Document& lhs, const Document& rhs) {
            return make_pair(lhs.relevance, lhs.rating)
                < make_pair(rhs.relevance, rhs.rating);
        });
}

int main() {
    vector<Document> documents = {
        {100, 0.5, 4},
        {101, 1.2, 4},
        {102, 0.3, 5}
    };

    SortDocuments(documents);

    for (const Document& document : documents) {
        cout << document.id << ' '
            << document.relevance << ' '
            << document.rating << endl;
    }

    return 0;
}
*/


/****** Задание 1:
* 
*   struct Document {
        int id;
        double relevance;
        int rating;
    };

    void SortDocuments(vector<Document>& matched_documents) {
        sort(matched_documents.begin(), matched_documents.end(),
            [](const Document& lhs, const Document& rhs) {
                if (lhs.rating == rhs.rating) {
                    return lhs.relevance > rhs.relevance;
                }
                else {
                    return lhs.rating > rhs.rating;
                }
            });
    }

    int main() {
        vector<Document> documents = {
            {100, 0.5, 4},
            {101, 1.2, 4},
            {102, 0.3, 5}
        };

        SortDocuments(documents);

        for (const Document& document : documents) {
            cout << document.id << ' '
                << document.relevance << ' '
                << document.rating << endl;
        }

        return 0;
    }
*/