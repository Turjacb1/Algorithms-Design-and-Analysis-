#include <iostream>
#include <string>
#include <vector>

std::vector<int> stringmatch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> match;

   
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
       
        if (j == m) {
            match.push_back(i);
        }
    }
    return match;
}

int main() {
    std::string text = "AABAACAADA";
    std::string pattern = "AA";
    
    std::vector<int> result = stringmatch(text, pattern);
    
    if (result.empty()) {
        std::cout << "No matches found." << std::endl;
    } else {
        std::cout << "Pattern found at indices: ";
        for (int index : result) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}