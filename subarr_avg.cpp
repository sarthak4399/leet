#include <iostream>
#include <vector>
using namespace std;

double calculateAvg(const vector<int>& arr, int start, int end) {
    double sum = 0;
    int count = end - start + 1;
    for (int i = start; i <= end; ++i) {
        sum += arr[i];
    }
    return sum / count;
}

int main() {
    string input = "2,4,2,6,6,8";
    vector<int> arr;
    int num = 0;

    for (char c : input) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == ',') {
            arr.push_back(num);
            num = 0;
        }
    }
    arr.push_back(num);

    int n = arr.size();
    bool found = false;

    for (int i = 0; i < n && !found; ++i) {
        for (int j = i; j < n && !found; ++j) {
            for (int k = 0; k < n && !found; ++k) {
                for (int l = k; l < n && !found; ++l) {
                    if (i != k || j != l) {
                        if (calculateAvg(arr, i, j) == calculateAvg(arr, k, l)) {
                            cout << "Subarray A: [";
                            for (int m = i; m <= j; ++m) {
                                cout << arr[m] << (m == j ? "" : ", ");
                            }
                            cout << "] and Subarray B: [";
                            for (int m = k; m <= l; ++m) {
                                cout << arr[m] << (m == l ? "" : ", ");
                            }
                            cout << "] have the same average." << endl;
                            found = true;
                        }
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "No such subarrays found." << endl;
    }

    return 0;
}