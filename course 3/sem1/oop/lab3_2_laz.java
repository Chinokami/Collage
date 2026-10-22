class Vector {
    private float x;
    private float y;
    private float z;
    private int state;

    private static int count = 0;

    public Vector() {
        this.x = 0;
        this.y = 0;
        this.z = 0;
        this.state = 0;
        count++;
    }

    public Vector(float val) {
        this.x = val;
        this.y = val;
        this.z = val;
        this.state = 0;
        count++;
    }

    public Vector(float[] arr) {
        count++;
        if (arr == null || arr.length < 3) {
            this.x = 0;
            this.y = 0;
            this.z = 0;
            this.state = 1;
        } else {
            this.x = arr[0];
            this.y = arr[1];
            this.z = arr[2];
            this.state = 0;
        }
    }

    public Vector(Vector other) {
        this.x = other.x;
        this.y = other.y;
        this.z = other.z;
        this.state = other.state;
        count++;
    }

    public void destroy() {
        System.out.println("State: " + state);
    }

    public void assign(Vector other) {
        this.x = other.x;
        this.y = other.y;
        this.z = other.z;
        this.state = other.state;
    }

    public void setComponent(int index, float val) {
        if (index == 0) this.x = val;
        else if (index == 1) this.y = val;
        else if (index == 2) this.z = val;
    }

    public void setComponent(int index) {
        setComponent(index, 0.0f);
    }

    public float getComponent(int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        return 0;
    }

    public void print() {
        System.out.printf("Vector(%.2f, %.2f, %.2f) | State: %d\n", x, y, z, state);
    }

    public Vector add(Vector other) {
        Vector res = new Vector();
        res.x = this.x + other.x;
        res.y = this.y + other.y;
        res.z = this.z + other.z;
        return res;
    }

    public Vector subtract(Vector other) {
        Vector res = new Vector();
        res.x = this.x - other.x;
        res.y = this.y - other.y;
        res.z = this.z - other.z;
        return res;
    }

    public Vector crossProduct(Vector other) {
        Vector res = new Vector();
        res.x = this.y * other.z - this.z * other.y;
        res.y = this.z * other.x - this.x * other.z;
        res.z = this.x * other.y - this.y * other.x;
        return res;
    }

    public void divide(short val) {
        if (val == 0) {
            this.state = 2;
            return;
        }
        this.x /= val;
        this.y /= val;
        this.z /= val;
    }

    private double length() {
        return Math.sqrt(x * x + y * y + z * z);
    }

    public boolean isGreater(Vector other) {
        return this.length() > other.length();
    }

    public boolean isLess(Vector other) {
        return this.length() < other.length();
    }

    public boolean isEqual(Vector other) {
        return this.x == other.x && this.y == other.y && this.z == other.z;
    }

    public static int getCount() {
        return count;
    }

    public int getState() {
        return state;
    }
}

public class Main {
    public static void main(String[] args) {
        Vector v1 = new Vector();
        v1.print();

        Vector v2 = new Vector(3.5f);
        v2.print();

        float[] arr = {1.0f, 2.0f, 3.0f};
        Vector v3 = new Vector(arr);
        v3.print();

        Vector vNull = new Vector((float[]) null);
        vNull.print();

        Vector vCopy = new Vector(v3);
        vCopy.print();

        System.out.println(Vector.getCount());

        v1.setComponent(0, 5.0f);
        v1.setComponent(1);
        v1.setComponent(2, 4.0f);
        v1.print();
        System.out.println(v1.getComponent(0));

        Vector v4 = new Vector();
        v4.assign(v1);
        v4.print();

        Vector vAdd = v3.add(v2);
        vAdd.print();

        Vector vSub = v3.subtract(v2);
        vSub.print();

        Vector vCross = v3.crossProduct(v2);
        vCross.print();

        short divisor = 2;
        v3.divide(divisor);
        v3.print();

        short zeroDivisor = 0;
        v3.divide(zeroDivisor);
        v3.print();

        System.out.println(v1.isGreater(v2));
        System.out.println(v1.isLess(v2));
        System.out.println(v1.isEqual(v4));

        v1.destroy();
        vNull.destroy();
    }
}
