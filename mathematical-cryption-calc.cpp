#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <math.h>



int upccheck(std::string a){
    if(a.length() != 12){
        std::cout << "Invalid UPC code" << std::endl;
        return 0;
    }
    int odd = 0;
    int even = 0;
    for(int i = 0; i < 12; i++){
        if(i % 2 == 0){
            odd += a[i];
        }
        else{
            even += a[i];
        }
    }
    int total = (odd * 3) + even;
    int check = total % 10;
    if(check == 0){
        std::cout << "Valid UPC code" << std::endl;
        return 0;
    }
    else{
        std::cout << "Invalid UPC code" << std::endl;
        return 0;
    }

}


int isbncheck(std::string a){
    if(a.length() != 10){
        std::cout << "Invalid ISBN code" << std::endl;
        return 0;
    }
    int b[10];
    int total = 0;
    for(int i = 0; i < 10; i++){
        b[i] = stoi(a.substr(i, 1));
    }
    for(int i = 0; i < 10; i++){
        total += (b[i] * (i+1));
    }
    if(total % 11 == 0){
        std::cout << "Valid ISBN code" << std::endl;
        return 0;
    }
    else{
        std::cout << "Invalid ISBN code" << std::endl;
        return 0;
    }
}


int isbncontrolcheck(std::string a){
    if(a.length() != 10){
        std::cout << "Invalid ISBN code" << std::endl;
        return 0;
    }
    int b[10];
    for(int i = 0; i < 10; i++){
        if(a[i] == 'X' || a[i] == 'x'){
            b[i] = 0;
        }
        else{
            b[i] = stoi(a.substr(i, 1));
        }
    }
    int total = 0;
    for(int i = 0; i < 10; i++){
        total += (b[i] * (i+1));
    }
    int check = total % 11;
    std::cout << "ISBN control number: " << check << std::endl;
    return 0;
}


int rsacryption1(std::string f, double buyukkilitasal1, double buyukkilitasal2, double kucukkilit){
    double x = (buyukkilitasal1) * (buyukkilitasal2);
    double d = pow(stoi(f), kucukkilit);
    double n = fmod(d, x);
    std::cout << n << std::endl;
    return 0;
}

int rsacryption2(std::string f, double e, double n){
    double m = stoi(f);
    double c = fmod(pow(m, n), e);
    std::cout << "Encrypted message: " << c << std::endl;
    return 0;
}

int rsadecryption(std::string f, double buyukkilitasal1, double buyukkilitasal2, double kucukkilit){
    double d = (buyukkilitasal1 - 1) * (buyukkilitasal2 - 1);
    double x = buyukkilitasal1 * buyukkilitasal2;
    int e = 0;
    while(fmod((e * kucukkilit), d) != 1){
        e++;
    }
    double c = stoi(f);
    double m = 1;
    for(int i = 0; i < e; i++){
        m = fmod((m * c), x);
    }
    std::cout << "Decrypted message: " << m << std::endl;
    std::cout << "password decoding power: " << e << std::endl;
    return 0;
}


int exitProgram() {
    std::cout << "Exiting program" << std::endl;
    return 0;
}


int main() {
    std::cout << "1. upc check " << std::endl;
    std::cout << "2. ISBN check " << std::endl;
    std::cout << "3. rsa cryption " << std::endl; 
    std::cout << "4. rsa decryption " << std::endl;
    std::cout << "5. find ISBN control number " << std::endl;
    std::cout << "6. exit " << std::endl;
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    switch(x) {
        case 1: {
            // Get input for upcCheck function
            std::string upc = "";
            std::cout << "Enter UPC code: ";
            std::cin >> upc;
            // Call upcCheck function with input
            upccheck(upc);
            break;
        }
        case 2: {
            // Get input for isbnCheck function
            std::string a = "";
            std::cout << "Enter ISBN code: ";
            std::cin >> a;
            // Call isbnCheck function with input
            isbncheck(a);
            break;
        }
        case 3: {
            // Get inputs for rsaEncrypt function
            std::string f = "";
            double buyukkilitasal1, buyukkilitasal2, kucukkilit;
            std::cout << "Enter the 4 digit numbers to be encrypted: ";
            std::cin >> f;
            std::cout << "Is it with prime numbers? (y/n): ";
            char asal = '0';
            std::cin >> asal;
            
            if(asal == 'y' || asal == 'Y'){
            std::cout << "Enter the big keys 1. prime number: ";
            std::cin >> buyukkilitasal1;
            std::cout << "Enter the big keys 2. prime number: ";
            std::cin >> buyukkilitasal2;
            std::cout << "Enter the small key:  ";
            std::cin >> kucukkilit;
            // Call rsaEncrypt function with inputs
            rsacryption1(f, buyukkilitasal1, buyukkilitasal2, kucukkilit);
            break;
            }
            else{
            std::cout << "Enter the big key: ";
            double buyukkilit;
            std::cin >> buyukkilit;
            std::cout << "Enter the small key: ";
            std::cin >> kucukkilit;
            // Call rsaEncrypt function with inputs
            rsacryption2(f, buyukkilit, kucukkilit);
            break;
            }
        }
        case 4: {
            // Get inputs for rsaDecrypt function
            std::string f = "";
            int buyukkilitasal1, buyukkilitasal2, kucukkilit;
            std::cout << "Enter the 4 digit crypted message: ";
            std::cin >> f;
            std::cout << "Enter the big keys 1. prime number: ";
            std::cin >> buyukkilitasal1;
            std::cout << "Enter the big keys 2. prime number: ";
            std::cin >> buyukkilitasal2;
            std::cout << "Enter the small key: ";
            std::cin >> kucukkilit;
            // Call rsaDecrypt function with inputs
            rsadecryption(f, buyukkilitasal1, buyukkilitasal2, kucukkilit);
            break;
        }
        case 5: {
            // Get input for isbnControlCheck function
            std::string a = "";
            std::cout << "Enter ISBN code, type the missing digit with x: ";
            std::cin >> a;
            // Call isbnControlCheck function with input
            isbncontrolcheck(a);
            break;
        }
        case 6:{
            // Call exitProgram function
            exitProgram();
            break;
        }
        default:
            std::cout << "Invalid selection" << std::endl;
            break;
    }

    return 0;
}
    


