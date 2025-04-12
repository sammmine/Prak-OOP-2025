#include "Playlist.hpp"

Playlist::Playlist(string playlistName) {
    this->name = playlistName;
}

const string &Playlist::getName() const {
    return this->name;
}

const vector<Song> &Playlist::getSongs() const {
    return this->songs;
}

void Playlist::addSong(const Song &song) {
    for (int i=0; i<songs.size(); i++) {
        if (songs[i] == song) {
            return;
        }
    }
    songs[songs.size()] = song;
}

bool Playlist::removeSong(const Song &songToRemove) {
    int idx = -1;
    vector<Song> temp;
    for (int i=0; i<songs.size(); i++) {
        if (songs[i] == songToRemove) {
            idx = i;
            break;
        }
        temp[i] = songs[i];
    }
    if (idx > 0) { // artinya lagu yg mau dihapus ditemukan
        for (int i=idx+1; i<songs.size(); i++) {
            temp[temp.size()]=songs[i];
        }
        songs = temp; // songs diganti
        return true;
    }
    return false; // songs tidak diganti
}

void Playlist::removeSongByIndex(size_t index) {
    vector<Song> temp;
    if (index > songs.size()) {
        throw out_of_range("Index out of range");
    }
    if (index > 0) {
        for (int i=0; i<index-1; i++) { // kalau index bukan nol
            temp[temp.size()] = songs[i];
        }
    }
    for (int i=index+1; i<songs.size(); i++) {
        temp[temp.size()]=songs[i];
    }
    songs = temp;
}

size_t Playlist::numberOfSongs() const {
    return this->songs.size();
}

ostream& operator<<(ostream &os, const Playlist &pl) {
    vector<Song> a = pl.getSongs();
    cout << "Playlist: " << pl.getName() << " (" << a.size() << " lagu)" << endl;
    for (int i=0; i<a.size(); i++) {
        cout << i+1 << ".";
        cout << a[i].getTitle();
    }
    cout << endl;
}