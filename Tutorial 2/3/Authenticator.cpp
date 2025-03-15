#include "User.hpp"
#include "AdminUser.hpp"
#include "Authenticator.hpp"

Authenticator::Authenticator() : userCount(0), currentUser(nullptr), secretResource("Ini adalah data rahasia!") {}

void Authenticator::registerUser(const string &username, const string &password, bool idAdmin){
    bool found = false;
    if (userCount >= MAX_USERS){
        cout << "Gagal: Kapasitas user penuh!" << endl;
        return;
    } else {
        for (int i=0; i<userCount; i++){
            if (users[i]->getUsername() == username){
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Gagal: Username sudah digunakan!" << endl;
            return;
        } else {
            if (idAdmin) {
                users[userCount] = new AdminUser(username, password);
            } else {
                users[userCount] = new User(username, password);
            }
            userCount++;
            cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
        }
    }
}

void Authenticator::login(const string &username, const string &password){
    bool found = false;
    for (int i=0; i<userCount; i++){
        if (users[i]->getUsername() == username && users[i]->checkPassword(password)){
            found = true;
            currentUser = users[i];
            break;
        }
    }
    if (!found){
        cout << "Gagal: Username atau password salah!" << endl;
        return;
    } else {
        cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
    }
}

void Authenticator::logout(){
    if (currentUser==nullptr){
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
        return;
    } else {
        cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << endl;
        currentUser = nullptr;
    }
}

void Authenticator::accessResource() const{
    if (currentUser==nullptr){
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
        return;
    } else {   
        cout << "Resource: " << secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource){
    if (currentUser==nullptr){
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
        return;
    } else {
        if (currentUser->isAdmin()){
            secretResource = newResource;
            cout << "Sukses: Resource telah diperbarui oleh " << currentUser->getUsername() << "." << endl;
        } else {
            cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
        }
    }
}

Authenticator::~Authenticator(){
    for (int i=0; i<userCount; i++){
        delete users[i];
    }
}