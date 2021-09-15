/*
Nama        : Ihsanuddin Dwi P
NPM         : 140810190048
Kelas       : B
Deskripsi   : Shift Cipher
*/

#include <iostream>
#include <string.h>
using namespace std;

void encrypt(char input[], char cipherteks[], int key){         // Fungsi Enkripsi
    for (int i=0;i<strlen(input);i++){
        if(input[i] != ' '){                                    // Apabila bukan karakter spasi (' ')
            if(input[i] >= 'a' && input[i] <= 'z'){             // Huruf kecil
                cipherteks[i] = (((input[i] - 'a') + key) % 26) + 'a';               
            }
            else if(input[i] >= 'A' && input[i] <= 'Z'){        // Huruf kapital
                cipherteks[i] = (((input[i] - 'A') + key) % 26) + 'A';
            }
        }
        else{                                                   // Apabila spasi tidak dienkripsi
            cipherteks[i] = ' ';
        }
    }
}
void decrypt(char input[],char plainteks[], int key){           // Fungsi Dekripsi
    for (int i=0;i<strlen(input);i++){
        if(input[i] != ' '){                                    // Apabila bukan karakter spasi (' ')
            if(input[i] >= 'a' && input[i] <= 'z'){             // Huruf kecil
                plainteks[i] = (((input[i] - 'a') - key) % 26) + 'a';
                if (plainteks[i] < 'a')
                plainteks[i] = plainteks[i] + 26;
            }
            else if(input[i] >= 'A' && input[i] <= 'Z'){        // Huruf kapital
                plainteks[i] = (((input[i] - 'A') - key) % 26) + 'A';
                if (plainteks[i] < 'A')
                plainteks[i] = plainteks[i] + 26;
            }
        }
        else{                                                   // Apabila spasi tidak didekripsi
            plainteks[i] = ' ';
        }
    }
}

int main(){
    char input[50];
    char plainteks[50];
    char cipherteks[50];
    char loop = 'y';
    int key;
    int instruction;
    
    while(loop == 'Y' || loop == 'y'){                          //Loop untuk menjalankan program kembali
        memset(plainteks, 0, sizeof plainteks);                 //Mengosongkan char plainteks (apabila input lebih kecil dari input loop sebelumnya)
        memset(cipherteks, 0, sizeof cipherteks);               //Mengosongkan char cipherteks (apabila input lebih kecil dari input loop sebelumnya)
        cout << "----Shift Cipher----\n";
        cout << "Inputkan string : ";
        cin.getline(input,50);
        cout << "Inputkan key : ";
        cin >> key;
        cout << "Apa yang ingin anda lakukan?\n1. Enkripsikan\n2. Dekripsikan\nInput : ";
        cin >> instruction;
        switch(instruction){
            case 1:
            encrypt(input,cipherteks,key);
            cout << "Cipherteks = " << cipherteks;
            break;
            case 2:
            decrypt(input,plainteks,key);
            cout << "Plainteks = " << plainteks;
            break;
        }
        cout << "\nApakah akan diulang? [Y/N] : ";
        cin >> loop;
        cin.ignore();                                           //Agar input di loop berikutnya tidak ada yg terlewat
    }
}