#include <bits/stdc++.h>

#define fast() cin.tie(NULL),cout.tie(0),ios_base::sync_with_stdio(false)
#define endCode return 0
#define el << "\n"

using namespace std;

class Student {
public:
    string name;
    string id;
    double gpa{};
    bool operator < (const Student& s) const {
        return this->name < s.name;
    }
    bool operator <= (const Student& s) const {
        return this->name < s.name || this->name == s.name;
    }
};

map <string, int> m1, m2;

template<class T>
void PrintByGPA(vector<T>(s), clock_t start, string type) {
    m1[type]++;
    if (m1[type] > 1)
        return;
    ofstream outputFile("SortedByGPA.txt", ios::app);
    if (!outputFile)
    {
        cerr << "Error, can't open this InputFile!\n";
        cerr << "Note: \"SortedByGPA\" is the OutputFile name of your output OutputFile and his source is \".txt\"!\n";
    }
    clock_t end = clock();
    double duration = (end - start) * 1000.0 / CLOCKS_PER_SEC;
    outputFile << "Algorithm: " << type << " Sort" el
               << "Running Time: " << duration << " milliseconds" el;
    for (const auto& i : s)
        outputFile el << i.name el << i.id el << i.gpa el;
    outputFile << "\n------------------------------------------------------\n\n";

    outputFile.close();
}

template<class T>
void PrintByName(vector<T>(s), clock_t start, string type) {
    m2[type]++;
    if (m2[type] > 1)
        return;
    ofstream outputFile("SortedByName.txt", ios::app);
    if (!outputFile)
    {
        cerr << "Error, can't open this InputFile!\n";
        cerr << "Note: \"SortedByName\" is the OutputFile name of your output OutputFile and his source is \".txt\"!\n";
    }
    clock_t end = clock();
    double duration = (end - start) * 1000.0 / CLOCKS_PER_SEC;
    outputFile << "Algorithm: " << type << " Sort" el
               << "Running Time: " << duration << " milliseconds" el;
    for (const auto& i : s)
        outputFile el << i.name el << i.id el << i.gpa el;
    outputFile << "\n------------------------------------------------------\n\n";

    outputFile.close();
}

template<class T>
void InsertionSortByName(vector<T>& s) {
    clock_t start = clock();

    int n = s.size();
    for (int i = 1; i < n; i++) {
        T key = s[i];
        int j = i - 1;
        while (j >= 0 && key.operator<(s[j])) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
    PrintByName(s, start, "Insertion");
}

template<class T>
void InsertionSortByGPA(vector<T>& s) {
    clock_t start = clock();

    int n = s.size();
    for (int i = 1; i < n; i++) {
        T key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].gpa > key.gpa) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
    PrintByGPA(s, start, "Insertion");
}

template<class T>
void SelectionSortByName(vector<T>& s) {
    clock_t start = clock();

    int n = s.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (s[j].operator<(s[min_idx]))
                min_idx = j;
        swap(s[min_idx], s[i]);
    }
    PrintByName(s, start, "Selection");
}

template<class T>
void SelectionSortByGPA(vector<T>& s) {
    clock_t start = clock();

    int n = s.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (s[j].gpa < s[min_idx].gpa)
                min_idx = j;
        swap(s[min_idx], s[i]);
    }
    PrintByGPA(s, start, "Insertion");
}

template<class T>
void MergeByGPA(vector<T>& s, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeByGPA(s, left, mid);
        MergeByGPA(s, mid + 1, right);
        MergeSortGPA(s, left, mid, right);
    }
    else {
        return;
    }
}

template<class T>
void MergeSortGPA(vector<T>& s, int left, int mid, int right) {
    int const subArray1 = mid - left + 1;
    int const subArray2 = right - mid;
    vector<T> leftArray(subArray1), rightArray(subArray2);

    for (int i = 0; i < subArray1; i++)
        leftArray[i] = s[left + i];
    for (int j = 0; j < subArray2; j++)
        rightArray[j] = s[mid + 1 + j];

    int indexSubArray1 = 0, indexSubArray2 = 0, indexMerge = left;

    while (indexSubArray1 < subArray1 && indexSubArray2 < subArray2) {
        if (leftArray[indexSubArray1].gpa <= rightArray[indexSubArray2].gpa) {
            s[indexMerge] = leftArray[indexSubArray1];
            indexSubArray1++;
        } else {
            s[indexMerge] = rightArray[indexSubArray2];
            indexSubArray2++;
        }
        indexMerge++;
    }

    while (indexSubArray1 < subArray1) {
        s[indexMerge] = leftArray[indexSubArray1];
        indexSubArray1++;
        indexMerge++;
    }

    while (indexSubArray2 < subArray2) {
        s[indexMerge] = rightArray[indexSubArray2];
        indexSubArray2++;
        indexMerge++;
    }
}

template<class T>
void MergeByName(vector<T>& s, int left, int right) {
    clock_t start = clock();
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeByName(s, left, mid);
        MergeByName(s, mid + 1, right);
        MergeSortName(s, left, mid, right);
    }
    else
        return;
}

template<class T>
void MergeSortName(vector<T>& s, int left, int mid, int right) {
    int const subArray1 = mid - left + 1;
    int const subArray2 = right - mid;
    vector<T> leftArray(subArray1), rightArray(subArray2);
    for (auto i = 0; i < subArray1; i++)
        leftArray[i] = s[left + i];
    for (auto j = 0; j < subArray2; j++)
        rightArray[j] = s[mid + 1 + j];
    auto indexSubArray1 = 0, indexSubArray2 = 0, indexMerge = left;
    while (indexSubArray1 < subArray1 && indexSubArray2 < subArray2) {
        if (leftArray[indexSubArray1].name <= rightArray[indexSubArray2].name) {
            s[indexMerge] = leftArray[indexSubArray1];
            indexSubArray1++;
        }
        else {
            s[indexMerge] = rightArray[indexSubArray2];
            indexSubArray2++;
        }
        indexMerge++;
    }
    while (indexSubArray1 < subArray1) {
        s[indexMerge] = leftArray[indexSubArray1];
        indexSubArray1++;
        indexMerge++;
    }
    while (indexSubArray2 < subArray2) {
        s[indexMerge] = rightArray[indexSubArray2];
        indexSubArray2++;
        indexMerge++;
    }
}

template<class T>
void QuickSortByGPA (int l, int r, vector <T>& s) {
    clock_t start = clock();
    if (l < r)
    {
        int piv = partitionG(l, r, s);
        QuickSortByGPA(l, piv-1, s);
        QuickSortByGPA(piv+1, r, s);
    }
    else
    {
        PrintByGPA(s, start, "Quick");
    }
}

template<class T>
void MergeSortByName(vector <T> s, clock_t start) {
    MergeByName(s, 0, s.size() - 1);
    PrintByName(s, start, "Merge");
}

template<class T>
void MergeSortByGPA(vector <T> s, clock_t start) {
    MergeByName(s, 0, s.size() - 1);
    PrintByGPA(s, start, "Merge");
}

template<class T>
void QuickSortByName (int l, int r, vector <T>& s) {
    clock_t start = clock();
    if (l < r)
    {
        int piv = partitionN(l, r, s);
        QuickSortByName(l, piv-1, s);
        QuickSortByName(piv+1, r, s);
    }
    else
        PrintByName(s, start, "Quick");
}

template<class T>
void CountSortByGPA (vector <T>& s) {
    clock_t start = clock();
    vector <T> sorted(s.size());
    int m = 0;
    for (int i = 0; i < s.size(); ++i)
        m = max(int(s[i].gpa * 10), m);

    vector<int> count(m + 1, 0);
    for (int i = 0; i < s.size(); ++i)
        count[int(s[i].gpa*10)]++;

    for (int i = 1; i <= m; ++i)
        count[i] += count[i - 1];

    for (int i = 0; i < s.size(); ++i)
    {
        sorted[count[int(s[i].gpa * 10)] - 1] = s[i];
        count[int(s[i].gpa * 10)]--;
    }
    PrintByGPA(s, start, "Count");
}

template<class T>
void CountSortByName (vector <T>& s) {
    clock_t start = clock();
    vector <T> sorted(s.size());
    int m = 0;
    for (const auto& i : s)
        m = max(m, int(i.name[0]));

    vector<int> count(m+1,0);
    for (const auto& i : s)
        count[int(i.name[0])]++;

    int d = 0;
    for (int i = 65; i < m+1; ++i)
    {
        if (count[i] > 1)
            d++;
        count[i] += count[i - 1];
    }

    for (const auto& i : s)
    {
        sorted[count[int(i.name[0])] - 1] = i;
        count[int(i.name[0])]--;
    }
    for (int i = 1; d > 0 && i < s.size(); ++i)
    {
        if (sorted[i].operator<(sorted[i-1]))
            swap(sorted[i], sorted[i-1]);
    }
    PrintByName(s, start, "Count");
}

template<class T>
void BubbleSortByName(vector<T>& s, int e) {
    clock_t start = clock();
    if (e > 0)
    {
        for (int i = 1; i < e; ++i)
        {
            if (s[i].operator<(s[i-1]))
                swap(s[i], s[i-1]);
        }
        BubbleSortByName(s, e-1);
    }
    else
    {
        PrintByName(s, start, "Bubble");
    }
}

template<class T>
void BubbleSortByGPA(vector<T>& s, int e) {
    clock_t start = clock();
    if (e > 0)
    {
        for (int i = 1; i < e; ++i)
        {
            if (s[i].gpa < s[i-1].gpa)
                swap(s[i], s[i-1]);
        }
        BubbleSortByGPA(s, e-1);
    }
    else
    {
        PrintByGPA(s, start, "Bubble");
    }
}

template<class T>
int partitionG (int l, int r, vector <T>& s)
{
    double piv = s[r].gpa;
    int c = l - 1;
    for(int i = l; i <= r; i++)
    {
        if(s[i].gpa < piv)
        {
            c++;
            swap(s[c], s[i]);
        }
    }
    swap(s[c + 1], s[r]);
    return (c + 1);
}

template<class T>
int partitionN (int l, int r, vector <T>& s)
{
    string piv = s[r].name;
    int c = l - 1;
    for(int i = l; i <= r; i++)
    {
        if(s[i].name < piv)
        {
            c++;
            swap(s[c], s[i]);
        }
    }
    swap(s[c + 1], s[r]);
    return (c + 1);
}

void ShellSortByName(vector<Student>& s) {
    clock_t start = clock();
    int n = s.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            Student temp = s[i];
            int j;
            for (j = i; j >= gap && s[j - gap].name > temp.name; j -= gap) {
                s[j] = s[j - gap];
            }
            s[j] = temp;
        }
    }
    PrintByName(s, start, "Shell");
}

void ShellSortByGPA(vector<Student>& s) {
    clock_t start = clock();
    int n = s.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            Student temp = s[i];
            int j;
            for (j = i; j >= gap && s[j - gap].gpa > temp.gpa; j -= gap) {
                s[j] = s[j - gap];
            }
            s[j] = temp;
        }
    }
    PrintByGPA(s, start, "Shell");
}

int main()
{
    fast();

    ifstream InputFile("students.txt");

    if (!InputFile)
    {
        cerr << "Error, can't open this InputFile!\n";
        cerr << "Note: \"students\" is the InputFile name of your input InputFile and his source is \".txt\"!\n";
        return 1;
    }

    string tmp;
    int i, c = 0;
    getline(InputFile, tmp);
    i = stoi(tmp);
    vector <Student> s(i);
    i = 0;
    while (getline(InputFile, tmp))
    {
        if (c == 0)
        {
            s[i].name = tmp;
            c++;
        }
        else if (c == 1)
        {
            s[i].id = tmp;
            c++;
        }
        else if (c == 2)
        {
            s[i].gpa = stod(tmp);
            c = 0;
            i++;
        }
    }
    InputFile.close();

    ofstream outputFile1("SortedByName.txt", ios::trunc);
    ofstream outputFile2("SortedByGPA.txt", ios::trunc);

    outputFile1.close();
    outputFile2.close();

    InsertionSortByGPA(s);
    InsertionSortByName(s);
    SelectionSortByGPA(s);
    SelectionSortByName(s);
    BubbleSortByName(s, s.size());
    BubbleSortByGPA(s, s.size());
    ShellSortByGPA(s);
    ShellSortByName(s);
    clock_t start = clock();
    MergeSortByGPA(s, start);
    start = clock();
    MergeSortByName(s, start);
    QuickSortByGPA(0, s.size()-1, s);
    QuickSortByName(0, s.size()-1, s);
    CountSortByGPA(s);
    CountSortByName(s);

    endCode;
}