package ClassAndObjects;

class Rectangle{
    public double length;
    public double breadth;

    public double area(){
        return length*breadth;
    }
    public double perimeter(){
        return 2*(length+breadth);
    }
    public boolean isSquare(){
        return length==breadth;
    }
}
public class Rectangle1 {
    public static void main(String[] args){
        Rectangle r=new Rectangle();
        r.length=10.5;
        r.breadth=5.5;

        System.out.println(r.area());
        System.out.println(r.perimeter());
        System.out.println(r.isSquare());

    }
    
}