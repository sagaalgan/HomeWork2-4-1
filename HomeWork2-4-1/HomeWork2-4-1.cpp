#include <iostream>
#include <fstream>
#include <string>


class Address 
{
private:
    std::string city;
    std::string street;
    std::string house;
    std::string flat;
public:
    Address() {}
    Address(std::string city, std::string street, std::string house, std::string flat) 
    {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }
    std::string to_string() 
    {
        return city + ", " + street + ", " + house + ", " + flat;
    }
};

int main() 
{
    std::ifstream input_file("in.txt");
    std::ofstream output_file("out.txt");
    int n;
    input_file >> n;
    output_file << n << std::endl;
    Address* addresses = new Address[n];
    std::string city, street, house, flat;
    
    for (int i = 0; i < n; i++) 
    {        
            input_file >> city >> street >> house >> flat;
            addresses[i] = Address(city, street, house, flat);        
    }

    for (int i = n  - 1; i >= 0; i--) 
    {
        output_file << addresses[i].to_string() << std::endl;
    }
    delete[] addresses;
    input_file.close();
    output_file.close();
    return 0;
}