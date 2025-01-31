	#include <iostream>
	#include <string>
	#include <vector>
	#include <fstream> // Untuk menyimpan struk pembayaran
	#include <cstdlib> // Untuk exit()
	
	// =========================================================
	// PROGRAM PEMESANAN RESTORAN
	// Dibuat oleh:
	// 1. Nama : Daffa Nur Hafidz (2400018127)
	// 2. Nama : Delicia Risa Hibatullah (2400018144)
	// =========================================================
	
	using namespace std;
	
	// Struct untuk item menu
	// Ditambahkan oleh Daffa Nur Hafidz
	struct MenuItem {
	    string name;
	    string description;
	    float price;
	};
	
	// Prototipe fungsi
	// Ditambahkan oleh Delicia Risa Hibatullah
	void displayWelcomeScreen();
	void displayMainMenu(bool showPaymentOption);
	void displaySubMenu(const vector<MenuItem>& menu, const string& category);
	float processOrder(const vector<MenuItem>& menu);
	void saveReceipt(float total);
	
	int main() {
	    // Ditulis oleh Daffa Nur Hafidz
	    displayWelcomeScreen();
	
	    string categories[] = {"Donuts", "Ice Cream", "Coffee", "Tea"};
	
	    vector<MenuItem> donatMenu = {
	        {"Alcapon", "Donat dengan lapisan coklat...", 12000},
	        {"Cheese Cakelicious", "Donat dengan keju cakelicious...", 14000},
	        {"Mr. Mokacha", "Donat yang kaya rasa mocha...", 13000},
	        {"Tiramisu", "Donat dengan rasa tiramisu...", 15000},
	        {"Why Nut", "Donat manis dengan isian kacang-kacangan...", 12500},
	        {"Don Mochino", "Donat dengan rasa mocha...", 14000},
	        {"Oreology", "Donat dengan lapisan coklat hitam...", 13500}
	    };
	
	    // Ditambahkan oleh Delicia Risa Hibatullah
	    vector<MenuItem> iceCreamMenu = {
	        {"Couple", "Es krim dengan dua rasa pilihan...", 20000},
	        {"Sharing", "Es krim dalam porsi besar...", 25000},
	        {"Single", "Es krim dengan satu rasa pilihan...", 15000},
	        {"To Go", "Es krim dalam kemasan praktis...", 18000}
	    };
	
	    // Daffa Nur Hafidz mengerjakan Coffee dan Tea
	    vector<MenuItem> coffeeMenu = {
	        {"Americano", "Kopi espresso yang disajikan...", 20000},
	        {"Caramel Jcoccino", "Kopi dengan rasa karamel...", 24000},
	        {"Hazelnut Latte", "Kopi latte yang lembut...", 23000},
	        {"Jcoccino", "Kopi yang dipadukan dengan susu...", 22000},
	        {"Latte", "Kopi espresso yang disajikan...", 25000},
	        {"Mocca Espresso", "Kopi espresso dengan sentuhan...", 27000}
	    };
	
	    vector<MenuItem> teaMenu = {
	        {"Lemon Tea", "Teh segar dengan rasa lemon...", 15000},
	        {"Tea", "Teh klasik yang harum...", 13000},
	        {"Green Tea", "Teh hijau dengan rasa yang lembut...", 16000}
	    };
	
	    vector<MenuItem>* menus[] = {&donatMenu, &iceCreamMenu, &coffeeMenu, &teaMenu};
	
	    int mainChoice;
	    float total = 0.0;
	    bool hasOrder = false; // Delicia Risa Hibatullah
	
	    do {
	        // Ditulis oleh Daffa Nur Hafidz
	        displayMainMenu(hasOrder);
	        cout << "Pilih kategori nomor yang tertera: ";
	        cin >> mainChoice;
	
	        if (mainChoice >= 1 && mainChoice <= 4) {
	            displaySubMenu(*menus[mainChoice - 1], categories[mainChoice - 1]);
	            total += processOrder(*menus[mainChoice - 1]);
	            hasOrder = true; // Delicia Risa Hibatullah
	        } else if (mainChoice == 5 && hasOrder) {
	            // Delicia Risa Hibatullah menambahkan fitur pembayaran
	            cout << "\n====================================\n";
	            cout << "TOTAL PEMBAYARAN\n";
	            cout << "====================================\n";
	            cout << "Total yang harus dibayar: Rp" << total << endl;
	            saveReceipt(total);
	            total = 0.0; // Reset total setelah pembayaran
	            hasOrder = false; // Reset status pesanan
	            cout << "\nTerima kasih telah memesan di restoran kami! Selamat menikmati.\n";
	            exit(0); // Program selesai setelah pembayaran
	        } else if (mainChoice == 0) {
	            cout << "\nAnda memilih untuk keluar dari aplikasi.\n";
	        } else {
	            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
	        }
	
	    } while (mainChoice != 0);
	
	    cout << "\nTerima kasih telah memesan di restoran kami! Selamat menikmati.\n";
	    return 0;
	}
	
	// Fungsi ditulis oleh Daffa Nur Hafidz
	void displayWelcomeScreen() {
	    cout << "====================================" << endl;
	    cout << "         SELAMAT DATANG            " << endl;
	    cout << "====================================" << endl;
	    cout << " Tekan Enter untuk melanjutkan...\n";
	    cin.sync();
	    cin.get();
	}
	
	// Fungsi ditulis oleh Delicia Risa Hibatullah
	void displayMainMenu(bool showPaymentOption) {
	    cout << "\n====================================" << endl;
	    cout << "            MENU UTAMA             " << endl;
	    cout << "====================================" << endl;
	    cout << "1. Donuts\n2. Ice Cream\n3. Coffee\n4. Tea\n";
	    if (showPaymentOption) {
	        cout << "5. Pembayaran\n";
	    }
	    cout << "0. Keluar\n";
	}
	
	// Fungsi untuk menampilkan sub-menu
	// Ditulis oleh Daffa Nur Hafidz
	void displaySubMenu(const vector<MenuItem>& menu, const string& category) {
	    cout << "\n====================================" << endl;
	    cout << "         MENU " << category << endl;
	    cout << "====================================" << endl;
	    for (size_t i = 0; i < menu.size(); i++) {
	        cout << i + 1 << ". " << menu[i].name << " - Rp" << menu[i].price << endl;
	        cout << "    " << menu[i].description << endl;
	    }
	    cout << menu.size() + 1 << ". Cancel\n";
	}
	
	// Ditulis oleh Delicia Risa Hibatullah
	float processOrder(const vector<MenuItem>& menu) {
	    int choice;
	    cout << "Pilih menu (1-" << menu.size() + 1 << "): ";
	    cin >> choice;
	
	    if (choice >= 1 && choice <= menu.size()) {
	        int quantity;
	        cout << "Berapa banyak yang ingin Anda pesan? ";
	        cin >> quantity;
	        float cost = menu[choice - 1].price * quantity;
	        cout << "\nAnda memesan " << quantity << " " << menu[choice - 1].name << " dengan total Rp" << cost << "\n";
	        return cost;
	    } else if (choice == menu.size() + 1) {
	        cout << "Pesanan dibatalkan.\n";
	    } else {
	        cout << "Pilihan tidak valid.\n";
	    }
	
	    return 0.0;
	}
	
	// Delicia Risa Hibatullah membuat fungsi ini
	void saveReceipt(float total) {
	    ofstream file("receipt.txt");
	    if (file.is_open()) {
	        file << "====================================\n";
	        file << "          STRUK PEMBAYARAN          \n";
	        file << "====================================\n";
	        file << "Total yang harus dibayar: Rp" << total << endl;
	        file << "====================================\n";
	        file << "Terima kasih telah memesan di restoran kami!\n";
	        file.close();
	        cout << "\nStruk pembayaran telah disimpan ke file 'receipt.txt'.\n";
	    } else {
	        cout << "\nGagal menyimpan struk pembayaran.\n";
	    }
	}

