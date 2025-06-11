import java.util.*;

interface Component {
    void draw();
}

final class Text implements Component {
    private String caption;

    public Text(String caption) {
        this.caption = caption;
    }

    public void draw() {
        System.out.println("Menggambar teks " + this.caption);
    }
}

final class Picture implements Component {
    private String fileName;

    public Picture(String fileName) {
        this.fileName = fileName;
    }

    public void draw() {
        System.out.println("Menggambar gambar " + fileName);
    }
}

abstract class GUI implements Component {
    protected List<Component> children = new ArrayList<>();

    public void add(Component c) {
        children.add(c);
    }

    public void draw() {
        for (Component c : children) {
            c.draw();
        }
    }
}

final class Panel extends GUI {
    public void draw() {
        System.out.println("Menggambar panel");
        super.draw();
    }
}

final class Window extends GUI {
    public void draw() {
        System.err.println("Menggambar window");
        super.draw();
    }
}

class Application {
    private Window window;

    public Application(Window w) {
        this.window = w;
    }

    public void run() {
        window.draw();
    }
}

class Main {
    public static void main(String[] args) {
        // Container 1
        Text t1 = new Text("Teks di Container 1");
        Picture p1 = new Picture("Picture di Container 1");
        Panel panel1 = new Panel();
        panel1.add(t1);
        panel1.add(p1);

        // Container 2
        Text t2 = new Text("Teks di Container 2");
        Picture p2 = new Picture("Picture di Container 2");
        Panel panel2 = new Panel();
        panel2.add(t2);
        panel2.add(p2);

        // Buat Window
        Window w = new Window();
        w.add(panel1);
        w.add(panel2);

        // Buat Application
        Application app = new Application(w);
        app.run();
    }
}