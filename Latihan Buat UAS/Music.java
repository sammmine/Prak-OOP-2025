// Kelas legacy (tidak bisa diubah)
class OldWAVPlayer {
    public void playWAV(String filename) {
        System.out.println("Memutar file WAV: " + filename);
    }
}

// Kelas modern yang hanya dukung MP3
class ModernMusicPlayer implements MusicPlayer {
    public void playMP3(String filename) {
        System.out.println("Memutar file MP3: " + filename);
    }

    // Implementasi interface MusicPlayer
    public void play(String filename) {
        if (filename.endsWith(".mp3")) {
            playMP3(filename);
        } else {
            System.out.println("Format tidak didukung oleh ModernMusicPlayer.");
        }
    }
}

// Interface umum
interface MusicPlayer {
    void play(String filename);
}

// Adapter agar OldWAVPlayer bisa digunakan sebagai MusicPlayer
class WAVAdapter implements MusicPlayer {
    private OldWAVPlayer wavPlayer = new OldWAVPlayer();

    public void play(String filename) {
        if (filename.endsWith(".wav")) {
            wavPlayer.playWAV(filename);
        } else {
            System.out.println("WAVAdapter hanya mendukung file .wav");
        }
    }
}

// Main class
public class Music {
    public static void main(String[] args) {
        MusicPlayer mp3Player = new ModernMusicPlayer();
        mp3Player.play("lagu1.mp3");

        MusicPlayer wavPlayer = new WAVAdapter();
        wavPlayer.play("lagu2.wav");
    }
}
