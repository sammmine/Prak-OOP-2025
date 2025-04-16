#include "Playlist.hpp"
#include "Playback.hpp"

int main() {
    // cek playlist

    Playlist p("sanctuary");
    Song satu("english love affair", "5sos");
    Song dua("white horse", "taylor swift");
    Song tiga("youll always find your way back home", "hannah montana");
    Song empat("lalali", "seventeen");

    cout << "Judul: " << p.getName() << endl;
    
    p.addSong(satu);
    p.addSong(dua);
    p.addSong(tiga);
    p.addSong(empat);

    cout << "Jumlah lagu: " << p.numberOfSongs() << endl;
    
    // p.removeSongByIndex(1); // "dua" dihapus
    p.removeSong(dua);
    
    cout << p; // "satu", "tiga", "empat"

    // cek playback

    Playback pb;
    Song lima("merkait", "yura yunita");

    pb.addToQueue(lima);
    pb.addToQueue(p); // "lima", "satu", "tiga", "empat" 

    cout << "Jumlah lagu di queue: " << pb.queueSize() << endl;
    pb.next(); // "lima" diputar, sisa "satu", "tiga", "empat" 
    pb.skip(); // "satu diskip", sisa "tiga", "empat"
    pb.next(); // "tiga" diputar, sisa "empat"

    cout << "Jumlah lagu di queue: " << pb.queueSize() << endl;
}