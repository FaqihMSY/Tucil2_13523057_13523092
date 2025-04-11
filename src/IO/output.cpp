#include "output.hpp"
#include "../Function/imagecompression.hpp"

void set_home(){
    cout << "\n";
    cout << "Selamat datang!\n";
    cout << "Program ini dapat membantu mengkompresi gambar. Ingin mencoba?\n";
    cout << "1. Iya\n";
    cout << "0. Keluar\n";
    cout << "> ";
}

void set_image_address(){
    cout << "\n";
    cout << "Masukkan alamat lengkap file: ";
}

void set_error_measurement_method(){
    cout << "\n";
    cout << "Silakan pilih metode pengukuran error berikut!\n";
    cout << "1. Variance\n";
    cout << "2. Mean Absolute Deviation\n";
    cout << "3. Max Pixel Difference\n";
    cout << "4. Entropy\n";
    cout << "> ";
}

void set_threshold(){
    cout << "\n";
    cout << "Silakan masukkan nilai ambang batas!\n";
    cout << "> ";
}

void set_minimum_block_size(){
    cout << "\n";
    cout << "Silakan masukkan nilai minimum dari ukuran blok!\n";
    cout << "> ";
}

void set_compression_percentage(){
    cout << "\n";
    cout << "Silakan masukkan nilai compression dari 0 sampai 1.0 (0% - 100%)\n";
    cout << "> ";
}

void goodbye(){
    cout << "\n";
    cout << "Sampai jumpa!\n";
    cout << "Terima kasih telah menggunakan layanan kami.\n";
}

void image_not_found(){
    cout << "\n";
    cout << "Gambar tidak ditemukan.\n";
    cout << "Catatan: Kami hanya menerima file dengan format .jpg, .jpeg, .png, .bmp, .tiff, .tif, .webp, .gif, dan .jp2.\n";
}

void compression_succeed(){
    cout << "\n";
    cout << "Gambar berhasil dikompresi!\n";
    cout << "Di mana Anda ingin menyimpannya?\n";
}

void save_succeed(){
    cout << "\n";
    cout << "Gambar berhasil disimpan!\n";
}

void process_information(long long duration, string addressOld, string addressNew){
    cout << "\n";
    cout << "Waktu eksekusi kompresi\t: " << duration << " ms\n";
    ifstream oldImage(addressOld, ios::binary | ios::ate);
    streamsize oldSize = oldImage.tellg();
    oldImage.close();

    ifstream newImage(addressNew, ios::binary | ios::ate);
    streamsize newSize = newImage.tellg();
    newImage.close();

    cout << "Ukuran gambar sebelum\t: " << oldSize << " bytes\n";
    cout << "Ukuran gambar sesudah\t: " << newSize << " bytes\n";
    double compressionRatio = ((float) newSize)/ ((float) oldSize);
    cout << "Persentase kompresi\t: " << (1.0 - compressionRatio) * 100.0 << "%\n";
    cout << "Kedalaman simpul\t: " << depth << endl;
    cout << "Banyak simpul pada pohon: " << verticesCount << endl;
}