//
// Created by mini on 17.08.21.
//

#ifndef BMLC_CSV_H
#define BMLC_CSV_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
class csv {

private:
    std::string COMMA_DELIMITER = ",";

    std::map<std::string, std::vector<std::string>> records;
    std::map<int, std::string> index;
public:
    csv(std::string filename) {
        std::ifstream fin(filename);

        if(!fin) {
            std::cout << "Error: could not open file " << filename << std::endl;
            return;
        }

        std::string line;
        getline(fin, line);
        int counter = 0;
        size_t pos = 0;
        std::string token;
        while((pos = line.find(COMMA_DELIMITER)) != std::string::npos) {
            token = line.substr(0, pos);
            index.insert(std::pair<int, std::string>(counter++, token));
            records.emplace(token, std::vector<std::string>());
            line.erase(0, pos + COMMA_DELIMITER.length());
        }
        index.insert(std::pair<int, std::string>(counter, line));
        records.emplace(line, std::vector<std::string>());

        int c = 0;
        while (getline(fin, line)) {
            counter = 0;
            while((pos = line.find(COMMA_DELIMITER)) != std::string::npos) {
                token = line.substr(0, pos);
                records.at(index.at(counter++)).push_back(token);
                line.erase(0, pos + COMMA_DELIMITER.length());
            }
            records.at(index.at(counter)).push_back(line);
        }
        fin.close();

    }

    std::map<std::string, std::vector<std::string>> getRecords() {
        return records;
    }

    std::map<int, std::string> getIndex() {
        return index;
    }


};


#endif //BMLC_CSV_H
