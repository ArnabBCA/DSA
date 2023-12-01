package Methods;

public class gcd {
    static int findGCD(int m,int n){
        while (m!=n) {
            if(m>n) m=m-n;
            else n=n-m;
        }
        return m;//you can return m or n
    }
    public static void main(String[] args){
        System.out.println(findGCD(25, 15));
    }
}
