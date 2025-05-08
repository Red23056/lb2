#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>

using namespace std;
const int lenna_size = 2048;

vector <short int>chrom_ac_int = { {2},{2},{3},{4},{5},{5},{6},{7},{9},{10},{12},{4},{6},{8},{9},{11},{12},{16},{16},{16},{16},{5},{8},{10},{12},{15},{16},{16},{16},{16},{16},{5},{8},{10},{12},{16},{16},{16},{16},{16},{16},{6},{9},{16},{16},{16},{16},{16},{16},{16},{16},{6},{10},{16},{16},{16},{16},{16},{16},{16},{16},{7},{11},{16},{16},{16},{16},{16},{16},{16},{16},{7},{11},{16},{16},{16},{16},{16},{16},{16},{16},{8},{16},{16},{16},{16},{16},{16},{16},{16},{16},{9},{16},{16},{16},{16},{16},{16},{16},{16},{16},{9},{16},{16},{16},{16},{16},{16},{16},{16},{16},{9},{16},{16},{16},{16},{16},{16},{16},{16},{16},{9},{16},{16},{16},{16},{16},{16},{16},{16},{16},{11},{16},{16},{16},{16},{16},{16},{16},{16},{16},{14},{16},{16},{16},{16},{16},{16},{16},{16},{16},{10},{15},{16},{16},{16},{16},{16},{16},{16},{16},{16} };
vector <vector<string>>chrom_ac_str = { {"00","00"},{"01","01"},{"02","100"},{"03","1010"},{"04","11000"},{"05","11001"},{"06","111000"},{"07","1111000"},{"08","111110100"},{"09","1111110110"},{"0A","111111110100"},{"11","1011"},{"12","111001"},{"13","11110110"},{"14","111110101"},{"15","11111110110"},{"16","111111110101"},{"17","1111111110001000"},{"18","1111111110001001"},{"19","1111111110001010"},{"1A","1111111110001011"},{"21","11010"},{"22","11110111"},{"23","1111110111"},{"24","111111110110"},{"25","111111111000010"},{"26","1111111110001100"},{"27","1111111110001101"},{"28","1111111110001110"},{"29","1111111110001111"},{"2A","1111111110010000"},{"31","11011"},{"32","11111000"},{"33","1111111000"},{"34","111111110111"},{"35","1111111110010001"},{"36","1111111110010010"},{"37","1111111110010011"},{"38","1111111110010100"},{"39","1111111110010101"},{"3A","1111111110010110"},{"41","111010"},{"42","111110110"},{"43","1111111110010111"},{"44","1111111110011000"},{"45","1111111110011001"},{"46","1111111110011010"},{"47","1111111110011011"},{"48","1111111110011100"},{"49","1111111110011101"},{"4A","1111111110011110"},{"51","111011"},{"52","1111111001"},{"53","1111111110011111"},{"54","1111111110100000"},{"55","1111111110100001"},{"56","1111111110100010"},{"57","1111111110100011"},{"58","1111111110100100"},{"59","1111111110100101"},{"5A","1111111110100110"},{"61","1111001"},{"62","11111110111"},{"63","1111111110100111"},{"64","1111111110101000"},{"65","1111111110101001"},{"66","1111111110101010"},{"67","1111111110101011"},{"68","1111111110101100"},{"69","1111111110101101"},{"6A","1111111110101110"},{"71","1111010"},{"72","11111111000"},{"73","1111111110101111"},{"74","1111111110110000"},{"75","1111111110110001"},{"76","1111111110110010"},{"77","1111111110110011"},{"78","1111111110110100"},{"79","1111111110110101"},{"7A","1111111110110110"},{"81","11111001"},{"82","1111111110110111"},{"83","1111111110111000"},{"84","1111111110111001"},{"85","1111111110111010"},{"86","1111111110111011"},{"87","1111111110111100"},{"88","1111111110111101"},{"89","1111111110111110"},{"8A","1111111110111111"},{"91","111110111"},{"92","1111111111000000"},{"93","1111111111000001"},{"94","1111111111000010"},{"95","1111111111000011"},{"96","1111111111000100"},{"97","1111111111000101"},{"98","1111111111000110"},{"99","1111111111000111"},{"9A","1111111111001000"},{"A1","111111000"},{"A2","1111111111001001"},{"A3","1111111111001010"},{"A4","1111111111001011"},{"A5","1111111111001100"},{"A6","1111111111001101"},{"A7","1111111111001110"},{"A8","1111111111001111"},{"A9","1111111111010000"},{"AA","1111111111010001"},{"B1","111111001"},{"B2","1111111111010010"},{"B3","1111111111010011"},{"B4","1111111111010100"},{"B5","1111111111010101"},{"B6","1111111111010110"},{"B7","1111111111010111"},{"B8","1111111111011000"},{"B9","1111111111011001"},{"BA","1111111111011010"},{"C1","111111010"},{"C2","1111111111011011"},{"C3","1111111111011100"},{"C4","1111111111011101"},{"C5","1111111111011110"},{"C6","1111111111011111"},{"C7","1111111111100000"},{"C8","1111111111100001"},{"C9","1111111111100010"},{"CA","1111111111100011"},{"D1","11111111001"},{"D2","1111111111100100"},{"D3","1111111111100101"},{"D4","1111111111100110"},{"D5","1111111111100111"},{"D6","1111111111101000"},{"D7","1111111111101001"},{"D8","1111111111101010"},{"D9","1111111111101011"},{"DA","1111111111101100"},{"E1","11111111100000"},{"E2","1111111111101101"},{"E3","1111111111101110"},{"E4","1111111111101111"},{"E5","1111111111110000"},{"E6","1111111111110001"},{"E7","1111111111110010"},{"E8","1111111111110011"},{"E9","1111111111110100"},{"EA","1111111111110101"},{"F0","1111111010"},{"F1","111111111000011"},{"F2","1111111111110110"},{"F3","1111111111110111"},{"F4","1111111111111000"},{"F5","1111111111111001"},{"F6","1111111111111010"},{"F7","1111111111111011"},{"F8","1111111111111100"},{"F9","1111111111111101"},{"FA","1111111111111110"} };
vector <short int>lum_ac_int = { {4},{2},{2},{3},{4},{5},{7},{8},{10},{16},{16},{4},{5},{7},{9},{11},{16},{16},{16},{16},{16},{5},{8},{10},{12},{16},{16},{16},{16},{16},{16},{6},{9},{12},{16},{16},{16},{16},{16},{16},{16},{6},{10},{16},{16},{16},{16},{16},{16},{16},{16},{7},{11},{16},{16},{16},{16},{16},{16},{16},{16},{7},{12},{16},{16},{16},{16},{16},{16},{16},{16},{8},{12},{16},{16},{16},{16},{16},{16},{16},{16},{9},{15},{16},{16},{16},{16},{16},{16},{16},{16},{9},{16},{16},{16},{16},{16},{16},{16},{16},{16},{9},{16},{16},{16},{16},{16},{16},{16},{16},{16},{10},{16},{16},{16},{16},{16},{16},{16},{16},{16},{10},{16},{16},{16},{16},{16},{16},{16},{16},{16},{11},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16},{11},{16},{16},{16},{16},{16},{16},{16},{16},{16},{16} };
vector <vector<string>>lum_ac_str = { {"00","1010"},{"01","00"},{"02","01"},{"03","100"},{"04","1011"},{"05","11010"},{"06","1111000"},{"07","11111000"},{"08","1111110110"},{"09","1111111110000010"},{"0A","1111111110000011"},{"11","1100"},{"12","11011"},{"13","1111001"},{"14","111110110"},{"15","11111110110"},{"16","1111111110000100"},{"17","1111111110000101"},{"18","1111111110000110"},{"19","1111111110000111"},{"1A","1111111110001000"},{"21","11100"},{"22","11111001"},{"23","1111110111"},{"24","111111110100"},{"25","1111111110001001"},{"26","1111111110001010"},{"27","1111111110001011"},{"28","1111111110001100"},{"29","1111111110001101"},{"2A","1111111110001110"},{"31","111010"},{"32","111110111"},{"33","111111110101"},{"34","1111111110001111"},{"35","1111111110010000"},{"36","1111111110010001"},{"37","1111111110010010"},{"38","1111111110010011"},{"39","1111111110010100"},{"3A","1111111110010101"},{"41","111011"},{"42","1111111000"},{"43","1111111110010110"},{"44","1111111110010111"},{"45","1111111110011000"},{"46","1111111110011001"},{"47","1111111110011010"},{"48","1111111110011011"},{"49","1111111110011100"},{"4A","1111111110011101"},{"51","1111010"},{"52","11111110111"},{"53","1111111110011110"},{"54","1111111110011111"},{"55","1111111110100000"},{"56","1111111110100001"},{"57","1111111110100010"},{"58","1111111110100011"},{"59","1111111110100100"},{"5A","1111111110100101"},{"61","1111011"},{"62","111111110110"},{"63","1111111110100110"},{"64","1111111110100111"},{"65","1111111110101000"},{"66","1111111110101001"},{"67","1111111110101010"},{"68","1111111110101011"},{"69","1111111110101100"},{"6A","1111111110101101"},{"71","11111010"},{"72","111111110111"},{"73","1111111110101110"},{"74","1111111110101111"},{"75","1111111110110000"},{"76","1111111110110001"},{"77","1111111110110010"},{"78","1111111110110011"},{"79","1111111110110100"},{"7A","1111111110110101"},{"81","111111000"},{"82","111111111000000"},{"83","1111111110110110"},{"84","1111111110110111"},{"85","1111111110111000"},{"86","1111111110111001"},{"87","1111111110111010"},{"88","1111111110111011"},{"89","1111111110111100"},{"8A","1111111110111101"},{"91","111111001"},{"92","1111111110111110"},{"93","1111111110111111"},{"94","1111111111000000"},{"95","1111111111000001"},{"96","1111111111000010"},{"97","1111111111000011"},{"98","1111111111000100"},{"99","1111111111000101"},{"9A","1111111111000110"},{"A1","111111010"},{"A2","1111111111000111"},{"A3","1111111111001000"},{"A4","1111111111001001"},{"A5","1111111111001010"},{"A6","1111111111001011"},{"A7","1111111111001100"},{"A8","1111111111001101"},{"A9","1111111111001110"},{"AA","1111111111001111"},{"B1","1111111001"},{"B2","1111111111010000"},{"B3","1111111111010001"},{"B4","1111111111010010"},{"B5","1111111111010011"},{"B6","1111111111010100"},{"B7","1111111111010101"},{"B8","1111111111010110"},{"B9","1111111111010111"},{"BA","1111111111011000"},{"C1","1111111010"},{"C2","1111111111011001"},{"C3","1111111111011010"},{"C4","1111111111011011"},{"C5","1111111111011100"},{"C6","1111111111011101"},{"C7","1111111111011110"},{"C8","1111111111011111"},{"C9","1111111111100000"},{"CA","1111111111100001"},{"D1","11111111000"},{"D2","1111111111100010"},{"D3","1111111111100011"},{"D4","1111111111100100"},{"D5","1111111111100101"},{"D6","1111111111100110"},{"D7","1111111111100111"},{"D8","1111111111101000"},{"D9","1111111111101001"},{"DA","1111111111101010"},{"E1","1111111111101011"},{"E2","1111111111101100"},{"E3","1111111111101101"},{"E4","1111111111101110"},{"E5","1111111111101111"},{"E6","1111111111110000"},{"E7","1111111111110001"},{"E8","1111111111110010"},{"E9","1111111111110011"},{"EA","1111111111110100"},{"F0","11111111001"},{"F1","1111111111110101"},{"F2","1111111111110110"},{"F3","1111111111110111"},{"F4","1111111111111000"},{"F5","1111111111111001"},{"F6","1111111111111010"},{"F7","1111111111111011"},{"F8","1111111111111100"},{"F9","1111111111111101"},{"FA","1111111111111110"} };
vector <vector<string>>chrom_dc_str = { {"0","000"},{"11","01"},{"12","10"},{"13","110"},{"14","1110"},{"15","11110"},{"16","111110"},{"17","1111110"},{"18","11111110"},{"19","111111110"},{"10","1111111110"},{"11","11111111110"} };
vector <short int>chrom_dc_int = { {3},{2},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11} };
vector <vector<string>>lum_dc_str = { {"0","000"},{"11","010"},{"12","011"},{"13","100"},{"14","101"},{"15","110"},{"16","1110"},{"17","11110"},{"18","111110"},{"19","1111110"},{"10","11111110"},{"11","111111110"} };
vector <short int>lum_dc_int = { {3},{3},{3},{3},{3},{3},{4},{5},{6},{7},{8},{9} };

vector<vector<float>> kvant_matrix_1 = { { 16.0,11.0,10.0,16.0,24.0,40.0,51.0,61.0 }, { 12.0,12.0,14.0,19.0,26.0,58.0,60.0,55.0 }, { 14.0,13.0,16.0,24.0,40.0,57.0,69.0,56.0 }, { 14.0,17.0,22.0,29.0,51.0,87.0,80.0,62.0 }, { 18.0,22.0,37.0,56.0,68.0,109.0,103.0,77.0 }, { 24.0,35.0,55.0,64.0,81.0,104.0,113.0,92.0 }, { 49.0,64.0,78.0,87.0,103.0,121.0,120.0,101.0 }, { 72.0,92.0,95.0,98.0,112.0,100.0,103.0,99.0 } };
vector<vector<float>> kvant_matrix_2 = { { 17.0,18.0,24.0,47.0,99.0,99.0,99.0,99.0 }, { 18.0,21.0,26.0,66.0,99.0,99.0,99.0,99.0 }, { 24.0,26.0,56.0,99.0,99.0,99.0,99.0,99.0 }, { 47.0,66.0,99.0,99.0,99.0,99.0,99.0,99.0 }, { 99.0,99.0,99.0,99.0,99.0,99.0,99.0,99.0 }, { 99.0,99.0,99.0,99.0,99.0,99.0,99.0,99.0 }, { 99.0,99.0,99.0,99.0,99.0,99.0,99.0,99.0 }, { 99.0,99.0,99.0,99.0,99.0,99.0,99.0,99.0 } };

vector<vector<short>> zigzag_indexes = { {0, 0},{0, 1},{1, 0},{2, 0},{1, 1},{0, 2},{0, 3},{1, 2},{2, 1},{3, 0},{4, 0},{3, 1},{2, 2},
    {1, 3},{0, 4},{0, 5},{1, 4},{2, 3},{3, 2},{4, 1},{5, 0},{6, 0},{5, 1},{4, 2},{3, 3},{2, 4},{1, 5},{0, 6},{0, 7},{1, 6},{2, 5},
    {3, 4},{4, 3},{5, 2},{6, 1},{7, 0},{7,1},{6,2},{5,3},{4,4},{3,5},{2,6},{1,7},{2,7},{3,6},{4,5},{5,4},{6,3},{7,2},{7,3},{6,4},
    {5,5},{4,6},{3,7},{4,7},{5,6},{6,5},{7,4},{7,5},{6,6},{5,7},{6,7},{7,6},{7,7} };

int int_round(float n) {
    if (n < 0) {
        n = n * -1;
        short int buffer = n;
        if (n - buffer > 0.5) {
            return (n + 1) * -1;
        }
        else {
            return (n) * -1;
        }
    }
    else {
        short int buffer = n;
        if (n - buffer >= 0.5) {
            return (n + 1);
        }
        else {
            return n;
        }
    }
}

void cout_matrix(vector<vector<short int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << "|";
        }
        cout << "\n";
    }
}

void readFileByBytes(const string& filePath, vector<short int>& vec) {
    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл: " << filePath << endl;
        return;
    }

    char byte;
    while (file.get(byte)) {
        vec.push_back(static_cast<int>(byte));
    }

    file.close();
}

//void writeByBytes(const string& filePath, vector<short int>& vec) {
//    ofstream file(filePath, ios::binary);
//    if (!file.is_open())
//    {
//        cout << "Не удалось открыть файл: " << filePath << endl;
//        return;
//    }
//    for (int i = 0; i < vec.size(); i++) {
//        file.write(reinterpret_cast<const char*>(&vec[i]), 1);
//    }
//    file.close();
//}

void writeByBytes(const string& filePath, vector<short int>& vec, ofstream& file) {
    /*if (!file.is_open())
    {
        cout << "Не удалось открыть файл: " << filePath << endl;
        return;
    }*/
    for (int i = 0; i < vec.size(); i++) {
        file.write(reinterpret_cast<const char*>(&vec[i]), 1);
    }
    //file.close();
}


void str_to_matrix(vector <vector <short int>>& mass, vector <short int>& to_matrix, int size_image) {
    vector <short int> mass_buffer;

    for (int i = 0; i < size_image; i++) {
        mass_buffer.push_back(0);
    }
    for (int i = 0; i < size_image; i++) {
        mass.push_back(mass_buffer);
    }

    int counter = 0;
    int len_matrix = to_matrix.size() / size_image;
    for (int i = 0; i < len_matrix; i++) {
        for (int j = 0; j < len_matrix; j++) {
            mass[i][j] = to_matrix[counter];
            counter++;
        }
    }
}

void back_str_to_matrix(vector<vector<short int>>& matrix, vector <short int>& string) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            string.push_back(matrix[i][j]);
        }
    }
}

//void RGB_to_YCrCb(vector<short int>& rgb, vector<short int>& Y_layer, vector<short int>& Cr_layer, vector<short int>& Cb_layer) {
//    int rgb_counter = 0;
//    int ycc_counter = 0;
//    while (rgb_counter < rgb.size()) {
//        Y_layer.push_back(0.299 * rgb[rgb_counter] + 0.587 * rgb[rgb_counter + 1] + 0.114 * rgb[rgb_counter + 2]);
//        Cb_layer.push_back(-0.168736 * rgb[rgb_counter] - 0.331264 * rgb[rgb_counter + 1] + 0.5 * rgb[rgb_counter + 2] + 128);
//        Cr_layer.push_back(0.5 * rgb[rgb_counter] - 0.418688 * rgb[rgb_counter + 1] - 0.081312 * rgb[rgb_counter + 2] + 128);
//        rgb_counter += 3;
//    }
//
//}

void RGB_to_YCrCb(vector<short int>& rgb, vector<short int>& Y_layer, vector<short int>& Cr_layer, vector<short int>& Cb_layer, bool mode) {
    int rgb_counter = 0;
    int ycc_counter = 0;
    if (!mode) {
        while (rgb_counter < rgb.size()) {
            Y_layer.push_back(0.299 * rgb[rgb_counter] + 0.587 * rgb[rgb_counter + 1] + 0.114 * rgb[rgb_counter + 2]);
            Cb_layer.push_back(-0.168736 * rgb[rgb_counter] - 0.331264 * rgb[rgb_counter + 1] + 0.5 * rgb[rgb_counter + 2] + 128);
            Cr_layer.push_back(0.5 * rgb[rgb_counter] - 0.418688 * rgb[rgb_counter + 1] - 0.081312 * rgb[rgb_counter + 2] + 128);
            rgb_counter += 3;
        }
    }
    else {
        while (rgb_counter < rgb.size()) {
            Cb_layer.push_back(128);
            Cr_layer.push_back(128);
            Y_layer.push_back(rgb[rgb_counter]);
            rgb_counter++;
        }
    }


}

void YCrCb_to_RGB(vector<short int>& Y_layer, vector<short int>& Cr_layer, vector<short int>& Cb_layer, vector<short int>& rgb) {
    int rgb_counter = 0;
    int ycc_counter = 0;
    while (ycc_counter < Y_layer.size()) {
        rgb.push_back(int_round(Y_layer[ycc_counter] + 1.402 * (Cr_layer[ycc_counter] - 128)));
        rgb.push_back(int_round(Y_layer[ycc_counter] - 0.34414 * (Cb_layer[ycc_counter] - 128) - 0.71414 * (Cr_layer[ycc_counter] - 128)));
        rgb.push_back(int_round(Y_layer[ycc_counter] + 1.772 * (Cb_layer[ycc_counter] - 128)));
        ycc_counter++;
    }
}


void downsemling(vector<vector<short int>>& Cr_layer, vector<vector<short int>>& Cb_layer) {
    vector<vector<short int>> new_Cr_layer;
    vector<vector<short int>> new_Cb_layer;
    int len = Cr_layer.size();
    int i = 0;
    while (i < len) {
        int j = 0;
        vector<short int > new_Cr_layer_element;
        vector<short int > new_Cb_layer_element;
        while (j < len) {
            new_Cr_layer_element.push_back(Cr_layer[i][j]);
            new_Cb_layer_element.push_back(Cb_layer[i][j]);
            j += 2;
        }
        new_Cr_layer.push_back(new_Cr_layer_element);
        new_Cb_layer.push_back(new_Cb_layer_element);
        i += 2;
    }
    Cr_layer = new_Cr_layer;
    Cb_layer = new_Cb_layer;
}

void back_downsemling(vector<vector<short int>>& Cr_layer, vector<vector<short int>>& Cb_layer) {
    int len = Cr_layer.size();
    int i = 0;
    vector<vector<short int>> new_Cr_layer;
    vector<vector<short int>> new_Cb_layer;
    vector<short int> buffer;
    for (int j = 0; j < len * 2; j++) {
        buffer.push_back(0);
    }
    for (int i = 0; i < len * 2; i++) {
        new_Cr_layer.push_back(buffer);
        new_Cb_layer.push_back(buffer);
    }
    while (i < len) {
        int j = 0;
        while (j < len) {
            new_Cr_layer[i * 2][j * 2] = Cr_layer[i][j];
            new_Cr_layer[i * 2 + 1][j * 2] = Cr_layer[i][j];
            new_Cr_layer[i * 2][j * 2 + 1] = Cr_layer[i][j];
            new_Cr_layer[i * 2 + 1][j * 2 + 1] = Cr_layer[i][j];

            new_Cb_layer[i * 2][j * 2] = Cb_layer[i][j];
            new_Cb_layer[i * 2 + 1][j * 2] = Cb_layer[i][j];
            new_Cb_layer[i * 2][j * 2 + 1] = Cb_layer[i][j];
            new_Cb_layer[i * 2 + 1][j * 2 + 1] = Cb_layer[i][j];
            j += 1;
        }
        i += 1;
    }
    Cr_layer = new_Cr_layer;
    Cb_layer = new_Cb_layer;
}

float alpha(float number) {
    if (not number) {
        return (1 / sqrt(2));
    }
    else {
        return 1;
    }
}

void dct(vector<vector<short int>> matrix, vector<vector<short int>>& new_matrix, bool mode) {
    int len_block = 8;
    int len = matrix.size() / len_block;
    int len_matrix = matrix.size();
    float pi = 3.14;
    vector<short int> buffer;
    for (int i = 0; i < len_matrix; i++) {
        buffer.push_back(0);
    }
    for (int i = 0; i < len_matrix; i++) {
        new_matrix.push_back(buffer);
    }
    for (int i = 0; i < len * len_block; i++) {
        for (int j = 0; j < len * len_block; j++) {
            matrix[i][j] -= 128;
        }
    }
    for (int index = 0; index < len; index++) {
        for (int jndex = 0; jndex < len; jndex++) {
            for (int u = 0; u < len_block; u++) {
                for (int v = 0; v < len_block; v++) {
                    float new_element = 0;
                    for (int x = 0; x < len_block; x++) {
                        for (int y = 0; y < len_block; y++) {
                            new_element += matrix[x + index * len_block][y + jndex * len_block] * cos(((2 * x + 1) * u * pi) / 16) * cos(((2 * y + 1) * v * pi) / 16);
                        }

                    }
                    int buf = 0;
                    if (mode) {
                        buf = int_round(((alpha(u) * alpha(v) / 4) * new_element) / kvant_matrix_2[u][v]);
                        new_matrix[u + index * len_block][v + jndex * len_block] = buf;
                    }
                    else {
                        buf = int_round(((alpha(u) * alpha(v) / 4) * new_element) / kvant_matrix_1[u][v]);
                        new_matrix[u + index * len_block][v + jndex * len_block] = buf;
                    }
                }

            }
        }
    }
}

void back_dct(vector<vector<short int>> matrix, vector<vector<short int>>& new_matrix, bool mode) {
    int len_block = 8;
    int len = matrix.size() / len_block;
    int len_matrix = matrix.size();
    float pi = 3.14;
    vector<short int> buffer;
    for (int i = 0; i < len_matrix; i++) {
        buffer.push_back(0);
    }
    for (int i = 0; i < len_matrix; i++) {
        new_matrix.push_back(buffer);
    }
    for (int index = 0; index < len; index++) {
        for (int jndex = 0; jndex < len; jndex++) {
            for (int x = 0; x < len_block; x++) {
                for (int y = 0; y < len_block; y++) {
                    if (mode) {
                        matrix[x + index * len_block][y + jndex * len_block] = int_round(matrix[x + index * len_block][y + jndex * len_block] * kvant_matrix_2[x][y]);
                    }
                    else {
                        matrix[x + index * len_block][y + jndex * len_block] = int_round(matrix[x + index * len_block][y + jndex * len_block] * kvant_matrix_1[x][y]);
                    }

                }

            }
        }
    }
    for (int index = 0; index < len; index++) {
        for (int jndex = 0; jndex < len; jndex++) {
            for (int x = 0; x < len_block; x++) {
                for (int y = 0; y < len_block; y++) {
                    float new_element = 0;
                    for (int u = 0; u < len_block; u++) {
                        for (int v = 0; v < len_block; v++) {
                            new_element += alpha(u) * alpha(v) * matrix[u + index * len_block][v + jndex * len_block] * cos(((2 * x + 1) * u * pi) / 16) * cos(((2 * y + 1) * v * pi) / 16);
                        }
                    }
                    int buff = int_round(new_element / 4);
                    new_matrix[x + index * len_block][y + jndex * len_block] = buff;
                }

            }
        }
    }
    for (int i = 0; i < len * len_block; i++) {
        for (int j = 0; j < len * len_block; j++) {
            new_matrix[i][j] += 128;
        }
    }
}

void deff_coding(vector<vector<short int>>& matrix) {
    int len = matrix.size();
    int last_elem;
    int buffer_last_elem;
    for (int i = 0; i < len; i += 8) {
        for (int j = 0; j < len; j += 8) {
            if (i == 0 and j == 0) {
                buffer_last_elem = matrix[i][j];
                matrix[i][j] = matrix[i][j];
                last_elem = buffer_last_elem;
            }
            else {
                buffer_last_elem = matrix[i][j];
                matrix[i][j] = matrix[i][j] - last_elem;
                last_elem = buffer_last_elem;
            }

        }
    }
}

void back_deff_coding(vector<vector<short int>>& matrix) {
    int len = matrix.size();
    int last_elem;
    int buffer_last_elem;
    for (int i = 0; i < len; i += 8) {
        for (int j = 0; j < len; j += 8) {
            if (i == 0 and j == 0) {
                matrix[i][j] = matrix[i][j];
                last_elem = matrix[i][j];
            }
            else {
                matrix[i][j] = matrix[i][j] + last_elem;
                last_elem = matrix[i][j];
            }

        }
    }
}

void compressed_HA(vector <short int> input_Y, vector <short int> input_Cb, vector <short int> input_Cr, const string& output) {
    
    unordered_map<string, string> huffman_codes_Y_DC;
    unordered_map<string, string> huffman_codes_CbCr_DC;
    unordered_map<string, string> huffman_codes_Y_AC;
    unordered_map<string, string> huffman_codes_CbCr_AC;
    ofstream file(output, ios::binary);
    string input_buffer;
    for (int i = 0; i < lum_dc_str.size(); i++) {
        huffman_codes_Y_DC[lum_dc_str[i][0]] = lum_dc_str[i][1];
    }
    for (int i = 0; i < lum_ac_str.size(); i++) {
        huffman_codes_Y_AC[lum_ac_str[i][0]] = lum_ac_str[i][1];
    }
    for (int i = 0; i < chrom_dc_str.size(); i++) {
        huffman_codes_CbCr_DC[chrom_dc_str[i][0]] = chrom_dc_str[i][1];
    }
    for (int i = 0; i < chrom_ac_str.size(); i++) {
        huffman_codes_CbCr_AC[chrom_ac_str[i][0]] = chrom_ac_str[i][1];
    }


    size_t codes_size = lum_dc_int.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (int i = 0; i < lum_dc_int.size(); i++) {
        file.write(reinterpret_cast<const char*>(lum_dc_int[i]), sizeof(lum_dc_int[i]));
    }
    codes_size = lum_ac_int.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (int i = 0; i < lum_ac_int.size(); i++) {
        file.write(reinterpret_cast<const char*>(lum_ac_int[i]), sizeof(lum_ac_int[i]));
    }
    codes_size = chrom_ac_int.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (int i = 0; i < chrom_ac_int.size(); i++) {
        file.write(reinterpret_cast<const char*>(chrom_ac_int[i]), sizeof(chrom_ac_int[i]));
    }
    codes_size = chrom_dc_int.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (int i = 0; i < chrom_dc_int.size(); i++) {
        file.write(reinterpret_cast<const char*>(chrom_dc_int[i]), sizeof(chrom_dc_int[i]));
    }



    //////////////////////////////////////////////////////////////////////////////////
    codes_size = huffman_codes_Y_DC.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (const auto& part : huffman_codes_Y_DC) {
        file.write(reinterpret_cast<const char*>(&part.first), sizeof(part.first));
        file.write(reinterpret_cast<const char*>(&part.second), sizeof(part.second));
    }
    codes_size = huffman_codes_CbCr_DC.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (const auto& part : huffman_codes_CbCr_DC) {
        file.write(reinterpret_cast<const char*>(&part.first), sizeof(part.first));
        file.write(reinterpret_cast<const char*>(&part.second), sizeof(part.second));
    }
    codes_size = huffman_codes_Y_AC.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (const auto& part : huffman_codes_Y_AC) {
        file.write(reinterpret_cast<const char*>(&part.first), sizeof(part.first));
        file.write(reinterpret_cast<const char*>(&part.second), sizeof(part.second));
    }
    codes_size = huffman_codes_CbCr_AC.size();
    file.write(reinterpret_cast<const char*>(&codes_size), sizeof(codes_size));
    for (const auto& part : huffman_codes_CbCr_AC) {
        file.write(reinterpret_cast<const char*>(&part.first), sizeof(part.first));
        file.write(reinterpret_cast<const char*>(&part.second), sizeof(part.second));
    }
    ///////////////////////////////////////////////////////////////////////////////////

    size_t mass_size = input_Y.size();
    file.write(reinterpret_cast<const char*>(&mass_size), sizeof(mass_size));
    string string_of_bits;
    int counter = 0;
    for (size_t i = 0; i < input_Y.size(); i+=2) {
        if (counter == 0 or counter > 63) {
            input_buffer += input_Y[i];
            input_buffer += input_Y[i + 1];
            string_of_bits += huffman_codes_Y_DC[input_buffer];
            input_buffer.clear();
            counter = 0;
            counter += 1;
        }
        else {
            input_buffer += input_Y[i];
            input_buffer += input_Y[i + 1];
            string_of_bits += huffman_codes_Y_AC[input_buffer];
            input_buffer.clear();
            counter += 1;
        }
    }
    while (string_of_bits.size() >= 8) {
        bitset<8> bits(string_of_bits.substr(0, 8));
        char byte = static_cast<char>(bits.to_ulong());
        file.write(&byte, 1);
        string_of_bits.erase(0, 8);
    }
    if (!string_of_bits.empty()) {
        while (string_of_bits.size() < 8) {
            string_of_bits = string_of_bits + '0';
        }
        bitset<8> bits(string_of_bits);
        char byte = static_cast<char>(bits.to_ulong());
        file.write(&byte, 1);
    }
    string_of_bits.clear();////////////////////////////////////////////////////////////////////////

    mass_size = input_Cb.size();
    file.write(reinterpret_cast<const char*>(&mass_size), sizeof(mass_size));
    for (size_t i = 0; i < input_Cb.size(); i += 2) {
        if (counter == 0 or counter > 63) {
            input_buffer += input_Cb[i];
            input_buffer += input_Cb[i + 1];
            string_of_bits += huffman_codes_CbCr_DC[input_buffer];
            input_buffer.clear();
            counter = 0;
            counter += 1;
        }
        else {
            input_buffer += input_Cb[i];
            input_buffer += input_Cb[i + 1];
            string_of_bits += huffman_codes_CbCr_AC[input_buffer];
            input_buffer.clear();
            counter += 1;
        }
    }
    while (string_of_bits.size() >= 8) {
        bitset<8> bits(string_of_bits.substr(0, 8));
        char byte = static_cast<char>(bits.to_ulong());
        file.write(&byte, 1);
        string_of_bits.erase(0, 8);
    }
    if (!string_of_bits.empty()) {
        while (string_of_bits.size() < 8) {
            string_of_bits = string_of_bits + '0';
        }
        bitset<8> bits(string_of_bits);
        char byte = static_cast<char>(bits.to_ulong());
        file.write(&byte, 1);
    }
    string_of_bits.clear();////////////////////////////////////////////////////////////

    mass_size = input_Cr.size();
    file.write(reinterpret_cast<const char*>(&mass_size), sizeof(mass_size));
    for (size_t i = 0; i < input_Cr.size(); i += 2) {
        if (counter == 0 or counter > 63) {
            input_buffer += input_Cr[i];
            input_buffer += input_Cr[i + 1];
            string_of_bits += huffman_codes_CbCr_DC[input_buffer];
            input_buffer.clear();
            counter = 0;
            counter += 1;
        }
        else {
            input_buffer += input_Cr[i];
            input_buffer += input_Cr[i + 1];
            string_of_bits += huffman_codes_CbCr_AC[input_buffer];
            input_buffer.clear();
            counter += 1;
        }
    }
    while (string_of_bits.size() >= 8) {
        bitset<8> bits(string_of_bits.substr(0, 8));
        char byte = static_cast<char>(bits.to_ulong());
        file.write(&byte, 1);
        string_of_bits.erase(0, 8);
    }
    if (!string_of_bits.empty()) {
        while (string_of_bits.size() < 8) {
            string_of_bits = string_of_bits + '0';
        }
        bitset<8> bits(string_of_bits);
        char byte = static_cast<char>(bits.to_ulong());
        file.write(&byte, 1);
    }

    file.close();
}

void decompressed_HA(vector <short int>& input_Y, vector <short int>& input_Cb, vector <short int>& input_Cr, const string& input) {
    ifstream compressed(input, ios::binary);
    unordered_map<string, string> huffman_codes_Y_DC;
    unordered_map<string, string> huffman_codes_CbCr_DC;
    unordered_map<string, string> huffman_codes_Y_AC;
    unordered_map<string, string> huffman_codes_CbCr_AC;
    lum_dc_int.clear();
    lum_ac_int.clear();
    chrom_dc_int.clear();
    chrom_ac_int.clear();

    size_t tableSize;
    size_t buff = 0;
    compressed.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    buff += tableSize;
    for (size_t i = 0; i < tableSize; i++) {
        char buffer_char;
        compressed.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
        lum_dc_int.push_back(buffer_char);
    }
    compressed.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    buff += tableSize;
    for (size_t i = 0; i < tableSize; i++) {
        char buffer_char;
        compressed.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
        lum_ac_int.push_back(buffer_char);
    }
    compressed.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    buff += tableSize;
    for (size_t i = 0; i < tableSize; i++) {
        char buffer_char;
        compressed.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
        chrom_ac_int.push_back(buffer_char);
    }
    compressed.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    buff += tableSize;
    for (size_t i = 0; i < tableSize; i++) {
        char buffer_char;
        compressed.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
        chrom_dc_int.push_back(buffer_char);
    }

    /*compressed.read(reinterpret_cast<char*>(&tableSize), sizeof(tableSize));
    for (size_t i = 0; i < tableSize; i++) {
        char buffer_char;
        char count;
        compressed.read(&buffer_char, sizeof(buffer_char));
        compressed.read(&count, sizeof(count));

        huffman_codes_Y_DC[buffer_char] = count;
        cout << count << endl;
    }
    for (const auto& part : counter) {
        count_symbols += part.second;
    }*/

    string string_of_bits;
    vector<short int> buffer;
    string buffer_string;
    size_t mass_size;

    compressed.read(reinterpret_cast<char*>(&mass_size), sizeof(mass_size));
    for (size_t i = 0; i < mass_size; i += 2) {
        compressed.read(reinterpret_cast<char*>(&buffer[i]), sizeof(char));
    }
    for (size_t i = 0; i < buffer.size(); i++) {
        bitset<8> bits(buffer[i]);
        string_of_bits += bits.to_string();
    }
    int counter = 0;
    for (char bit : string_of_bits) {
        buffer_string += bit;
        if (counter == 0 or counter > 64) {
            if (huffman_codes_Y_DC.count(buffer_string)) {
                input_Y.push_back(huffman_codes_Y_DC[buffer_string][0]);
                input_Y.push_back(huffman_codes_Y_DC[buffer_string][1]);
                counter = 0;
                counter += 2;
            }
        }
        else {
            if (huffman_codes_Y_AC.count(buffer_string)) {
                input_Y.push_back(huffman_codes_Y_AC[buffer_string][0]);
                input_Y.push_back(huffman_codes_Y_AC[buffer_string][1]);
                counter += 2;
            }
        }
    }
    buffer_string.clear();

    compressed.close();
}


void zigzag_matrix_to_string(vector<vector<short int>> matrix, vector<short int>& string) {
    int len_matrix = matrix.size() / 8;
    int len_indexes = zigzag_indexes.size();
    for (int i = 0; i < len_matrix; i++) {
        for (int j = 0; j < len_matrix; j++) {
            for (int index = 0; index < len_indexes; index++) {
                string.push_back(matrix[i * 8 + zigzag_indexes[index][0]][j * 8 + zigzag_indexes[index][1]]);
            }
        }
    }
}

void back_zigzag_matrix_to_string(vector<short int> string, vector<vector<short int>>& matrix, int size) {
    int len_matrix = size / 8;
    int len_indexes = zigzag_indexes.size();
    vector<short int> buffer;
    for (int i = 0; i < size; i++) {
        buffer.push_back(0);
    }
    for (int i = 0; i < size; i++) {
        matrix.push_back(buffer);
    }
    int string_counter = 0;
    for (int i = 0; i < len_matrix; i++) {
        for (int j = 0; j < len_matrix; j++) {
            for (int index = 0; index < len_indexes; index++) {
                matrix[i * 8 + zigzag_indexes[index][0]][j * 8 + zigzag_indexes[index][1]] = string[string_counter];
                string_counter++;
            }
        }
    }
}

void rle(vector<short int>string, vector<short int>& new_string) {
    int len = string.size();
    int counter_zeros = 0;
    int counter_global = 0;
    for (int i = 0; i < len; i++) {
        if (counter_global == 63) {
            new_string.push_back(counter_zeros);
            new_string.push_back(string[i]);
            counter_zeros = 0;
            counter_global = 0;
        }
        else {
            if (string[i] != 0) {
                new_string.push_back(counter_zeros);
                new_string.push_back(string[i]);
                counter_zeros = 0;
            }
            else {
                counter_zeros++;
            }
            counter_global++;
        }
    }
    if (counter_zeros != 0) {
        new_string.push_back(counter_zeros);
        new_string.push_back(string[len - 1]);
    }
}

void back_rle(vector<short int>string, vector<short int>& old_string) {
    int len = string.size();
    int counter = 0;
    while (counter < len) {

        for (int i = 0; i < string[counter]; i++) {
            old_string.push_back(0);
        }
        old_string.push_back(string[counter + 1]);
        counter += 2;
    }
}
//"D:\\Python\\raw\\Lenna_RGB.raw"
//"C:\\Users\\sa_bo\\source\\repos\\AISD 2 lab\\ycbcr\\LENNA_decoding.raw"
//"C:\\Users\\sa_bo\\source\\repos\\AISD 2 lab\\ycbcr\\LENNA_coding.raw"

int main() {
    
}