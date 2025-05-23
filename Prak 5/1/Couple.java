public class Couple<K,V> {
    private K key;
    private V value;

    public Couple (K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return this.key;
    }

    public V getVal() {
        return this.value;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public void setVal(V value) {
        this.value = value;
    }

    public boolean isEqual(Couple c) {
        if (this.key.equals(c.key) && this.value.equals(c.value)) {
            return true;
        }
        return false;
    }

    public int nearEQ(Couple couple) {
        if (this.key.equals(couple.getKey()) && this.value.equals(couple.getVal())) {
            return 3;
        } else if (this.key.equals(couple.getKey()) && !this.value.equals(couple.getVal())) {
            return 1;
        } else if (!this.key.equals(couple.getKey()) && this.value.equals(couple.getVal())) {
            return 2;
        } else {
            return 0;
        }
    }

    // public static void main (String[] args) {
    //     Couple c = new Couple(3,2);
    //     Couple d = new Couple(3,2);
    //     System.out.println(c.getKey());
    //     System.out.println(c.getVal());
    //     System.out.println(c.nearEQ(d));
    // }
} 