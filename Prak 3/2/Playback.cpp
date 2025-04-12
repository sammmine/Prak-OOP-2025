#include "Playback.hpp"

void Playback::addToQueue(const Song &song){
    playbackQueue.push(song);
}

void Playback::addToQueue(const Playlist &playlist){
    vector<Song> songs = playlist.getSongs();
    for (int i=0; i<songs.size(); i++) {
        playbackQueue.push(songs[i]);
    }
}

void Playback::next() {
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
        return;
    }
    cout << "Memutar: " << playbackQueue.front() << endl;
    playbackQueue.pop();
}

void Playback::playAll() {
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
        return;
    }
    int size = playbackQueue.size();
    for (int i=0; i<size; i++) {
        cout << "Memutar: " << playbackQueue.front() << endl;
        playbackQueue.pop();
    }
}

void Playback::skip() {
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
        return;
    }
    playbackQueue.pop();
}

void Playback::clearQueue() {
    int size = playbackQueue.size();
    for (int i=0; i<size; i++) {
        playbackQueue.pop();
    }
}

bool Playback::isEmpty() const {
    return (playbackQueue.size() == 0);
}

size_t Playback::queueSize() const {
    return playbackQueue.size();
}