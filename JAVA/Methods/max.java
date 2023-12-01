package Methods;

/*public class max {
    static int max(int x,int y){
        if(x>y){
            return x;
        }
        else{
            return y;
        }
    }
    public static void main(String args[]){
        int a=10;
        int b=15;
        int c;

        c=max(a,b);
        System.out.println(c);
    }
}*/


//without uing static
public class max {
    int findMax (int x,int y){
        if(x>y){
            return x;
        }
        else{
            return y;
        }
    }
    public static void main(String args[]){
        int a=10;
        int b=15;

        max m=new max();
        int c=m.findMax(a,b);
        System.out.println(c);
    }
}


