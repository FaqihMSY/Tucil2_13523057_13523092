#include "input.hpp"
#include "output.hpp"

// "PRIVATE"
bool isValidPhoto(string s){
    string format = s.substr(s.find_last_of(".") + 1);

    vector<string> a = {"jpg", "jpeg", "png", "bmp", "tiff", "tif", "webp", "gif", "jp2"};
    
    int i = 0;
    while(i<a.size()){
        if(format == a[i]) return true;
        i+=1;
    }

    return false;
}

// "PUBLIC"
int input_number(string s, int dari, int sampai){
    string cmd;

    while(1){
        cout << s << endl;
        cout << "> ";

        try{
            cin >> cmd;
            int n = stoi(cmd);

            if(n >= dari && n <= sampai){
                return n;
            }else{
                cout << endl;
                cout << "Input tidak sesuai." << endl;
            }
        }catch(...){
            cout << endl;
            cout << "Input tidak sesuai." << endl;
        }
    }
}

int input_home(){
    string cmd;

    while(1){
        set_home();

        try{
            cin >> cmd;
            int n = stoi(cmd);

            if(n >= 0 && n <= 1){
                return n;
            }else{
                cout << endl;
                cout << "Input tidak sesuai." << endl;
            }
        }catch(...){
            cout << endl;
            cout << "Input tidak sesuai." << endl;
        }
    }
}

string input_image_address_import(){
    string s;

    getchar();
    while(1){
        set_image_address();

        getline(cin, s);
        if(fs::exists(s) && isValidPhoto(s)) return s;
        else image_not_found();
    }
}

int input_error_measurement_method(){
    string cmd;

    while(1){
        set_error_measurement_method();

        try{
            cin >> cmd;
            int n = stoi(cmd);

            if(n >= 1 && n <= 4){
                return n;
            }else{
                cout << endl;
                cout << "Input tidak sesuai." << endl;
            }
        }catch(...){
            cout << endl;
            cout << "Input tidak sesuai." << endl;
        }
    }
}

double input_threshold(int errorMeasurementMethod){
    string cmd;

    while(1){
        set_threshold();

        try{
            cin >> cmd;
            double n = stod(cmd);

            if(errorMeasurementMethod == 1 && n >= 0){
                return n;
            }else if(errorMeasurementMethod == 2 && n >= 0 && n <= 255){
                return n;
            }else if(errorMeasurementMethod == 3 && n >= 0 && n <= 765){
                return n;
            }else if(errorMeasurementMethod == 4 && n >= 0 && n <= 24){
                return n;
            }else{
                cout << endl;
                cout << "Metode pengukuran eror yang dipilih tidak men-support nilai threshold tersebut." << endl;
            }
        }catch(...){
            cout << endl;
            cout << "Input tidak sesuai." << endl;
        }
    }
}

int input_minimum_block_size(){
    string cmd;

    while(1){
        set_minimum_block_size();

        try{
            cin >> cmd;
            int n = stoi(cmd);

            if(n >= 1){
                return n;
            }else{
                cout << endl;
                cout << "Input tidak sesuai." << endl;
            }
        }catch(...){
            cout << endl;
            cout << "Input tidak sesuai." << endl;
        }
    }
}

double input_compression_percentage(){
    string cmd;

    while(1){
        set_compression_percentage();

        try{
            cin >> cmd;
            double n = stod(cmd);

            if(n >= 0 && n <= 1){
                return n;
            }else{
                cout << endl;
                cout << "Input tidak sesuai." << endl;
            }
        }catch(...){
            cout << endl;
            cout << "Input tidak sesuai." << endl;
        }
    }
}

string input_image_address_export(){
    string s;

    getchar();
    while(1){
        set_image_address();

        getline(cin, s);
        if(isValidPhoto(s)) return s;
        else cout << "Tolong input alamat lengkap gambar baru dengan benar.\n";
    }
}