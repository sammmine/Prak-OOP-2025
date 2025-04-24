class Goose {
    private String name;
    private int honk;

    public Goose() {
        this.name = "Horrible";
        this.honk = 1;
    }

    public Goose(String name, int honk) {
        this.name = name;
        this.honk = honk;
    }

    public void steal(String thing) {
        System.out.println(name + " steals " + thing);
    }

    public String toString() {
        String result = name + " goose";
        if (honk > 0) {
            result += " says honk";
            for (int i = 1; i < honk; i++) {
                result += " honk";
            }
        }
        return result;
    }

    // public static void main(String[] args) {
    //     Goose g = new Goose();
    //     Goose h = new Goose("Sung Jin-woo", 3);
    //     System.out.println(g);
    //     System.out.println(h);
    //     h.steal("dagger");
    //   }      
}