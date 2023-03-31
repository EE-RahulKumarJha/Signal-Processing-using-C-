#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Define a simple low-pass filter
vector<double> lowpass_filter(vector<double> signal, double alpha) {
    vector<double> filtered_signal(signal.size());
    filtered_signal[0] = signal[0];
    for (int i = 1; i < signal.size(); i++) {
        filtered_signal[i] = alpha * signal[i] + (1 - alpha) * filtered_signal[i-1];
    }
    return filtered_signal;
}

int main() {
    // Open the input file
    ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        cerr << "Error: could not open input file" << endl;
        return 1;
    }

    // Read in the signal
    vector<double> signal;
    double value;
    while (input_file >> value) {
        signal.push_back(value);
    }

    // Close the input file
    input_file.close();

    // Apply the low-pass filter
    vector<double> filtered_signal = lowpass_filter(signal, 0.5);

    // Open the output file
    ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        cerr << "Error: could not open output file" << endl;
        return 1;
    }

    // Write the filtered signal to the output file
    for (int i = 0; i < filtered_signal.size(); i++) {
        output_file << filtered_signal[i] << endl;
    }

    // Close the output file
    output_file.close();

    return 0;
}

