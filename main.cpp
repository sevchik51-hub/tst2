#include <iostream>
#include <cstdio>

const int32_t sixseven = 67;

// int main(int argc, char** argv) {

//     for (int i = 0; i < argc; ++i) {
//         char* str = argv[i];
//         while (*str != '\0') {
//             std::cout << *str;
//             ++str;
//         }
//         std::cout << '\n';
//     }

// }

// int main(int argc, char** argv) {
//     //const char data[9] = "data.txt";

//     // int data[4] = {1, 2, 3, 4};
//     // int* ptr = data;
//     // std::cout << *(ptr+1) << std::endl;
//     // std::cout << ptr[2] << std::endl;



//     //int* ptr = data;
//     //FILE* f = fopen("data.txt", "r");

//     //std::cout << "Hello world!" << '\n';
//     //std::cout << data;



//     // FILE* f = fopen("data.txt", "r");

//     // int c = fgetc(f);

//     // while (c != EOF) {
//     //     std::cout << (char)c;
//     //     c = fgetc(f);
//     // }




//     // FILE* f = fopen("data.txt", "r");
//     // int c;
//     // while ((c = fgetc(f)) != EOF) {
//     //     std::cout << (char)c;
//     // }


//     // FILE* f = fopen("data.txt", "r");

//     // int a;
//     // int b;

//     // b = (a = 5);

//     // std:cout << a << ' ' << b << '\n';


//     FILE* f = fopen("data.txt", "r");

//     int max_cnt;
//     char char_with_max_cnt;

//     int current_cnt;
//     int prev_char = -1;
//     int current_char;


//     while ((current_char = fgetc(f)) != EOF) {
//         if (current_char != prev_char) {
//             if (current_cnt > max_cnt) {
//                 max_cnt = current_cnt;
//                 char_with_max_cnt = (char)prev_char;
//             }
//             prev_char = current_char;
//             current_cnt = 1;
//         } else {
//             current_cnt++;
//         }
//     }
    
//     if (current_cnt > max_cnt) {
//         max_cnt = current_cnt;
//         char_with_max_cnt = (char)prev_char;
//     }

//     if (max_cnt == -1) {
//         std::cout << "Empty file!" << '\n';
//         return 1;
//     }
    
//     std::cout << char_with_max_cnt << ' ' << max_cnt << '\n';


//     return 0;
// }



int main(int argc, char** argv) {

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " data.txt" << '\n';
        return 1;
    }
    
    FILE* f = fopen("data.txt", "r");

    if (!f) {
        std::cout << "Can not read that file!" << '\n';
    }

    int max_cnt;
    char char_with_max_cnt;

    int current_cnt;
    int prev_char = -1;
    int current_char;


    while ((current_char = fgetc(f)) != EOF) {
        if (std::isspace(current_char)) {
            continue;
        }
        if (current_char == prev_char) {
            current_cnt++;
            continue;
        }

        if (current_cnt > max_cnt) {
            max_cnt = current_cnt;
            char_with_max_cnt = (char)prev_char;
        }
        prev_char = current_char;
        current_cnt = 1;
    }
    

    if (current_cnt > max_cnt) {
        max_cnt = current_cnt;
        char_with_max_cnt = (char)prev_char;
    }


    fclose(f);


    if (max_cnt == -1) {
        std::cout << "Empty file!" << '\n';
        return 1;
    }


    std::cout << char_with_max_cnt << ' ' << max_cnt << '\n';


    return 0;

}
// почему это работает